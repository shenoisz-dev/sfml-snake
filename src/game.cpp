#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "game.hpp"


Game::Game(int width, int height, sf::String title) : 
    window(sf::VideoMode(width, height), title)
{
    this->width = width;
    this->height = height;
}


void Game::init()
{
    score = 0;
    blocks = new Blocks(width, height, 40.f);
    snake = new Snake(width, height, 40.f);
    int area[4] = {width, height, 2, 3};
    lostText = new sh::Text(32, area, "You lost!");
}


void Game::events()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        snake->events();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            snake->restart();
            blocks->randPos();
            snake->diration = -1;
        } 
    }
}

void Game::collision()
{
    unsigned int blockX = blocks->currentRect().getPosition().x;
    unsigned int blockY = blocks->currentRect().getPosition().y;
    unsigned int snakeX = snake->main().getPosition().x;
    unsigned int snakeY = snake->main().getPosition().y;

    if (blockX == snakeX && blockY == snakeY)
    {
        blocks->randPos();
        snake->add();
        score++;
    }

    for (int i = 0; i < snake->vrect.size(); i++)
    {
        blockX = blocks->currentRect().getPosition().x;
        blockY = blocks->currentRect().getPosition().y;
        snakeX = snake->vrect[i].getPosition().x;
        snakeY = snake->vrect[i].getPosition().y;

        if (blockX == snakeX && blockY == snakeY)
        {
            blocks->randPos();
        }

        if (snakeX < 0 || snakeX >= width)
        {
            snake->diration = -2;
        }

        if (snakeY < 0 || snakeY >= height)
        {
            snake->diration = -2;
        }
    }
}


void Game::update()
{
    blocks->update();
    snake->update();
}


void Game::draw()
{
    if (snake->diration != -2) 
    {
        blocks->draw(&window);
        snake->draw(&window);
    }
    else
    {
        lostText->draw(&window);
        // score
        int area2[4] = {width, height, 2, 2};
        std::string text = std::string("Your score is ") + std::to_string(score) + ".";
        scoreText = new sh::Text(32, area2, text);
        scoreText->draw(&window);
    }
}


void Game::clear()
{
    if (snake->diration == -2)
    {
        window.clear(sf::Color(150, 50, 250));
    } 
    else 
    {
        window.clear(sf::Color::Black);
    }
}


void Game::show() 
{
    window.display();
    snake->show();
}


void Game::run() 
{
    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / 5.f);

    init();

    while (window.isOpen())
    {
        events();
        clear();

        while (accumulator > ups)
        {
            accumulator -= ups;
            update();
            collision();
        }
        
        draw();
        show();

        accumulator += clock.restart();
    }
}
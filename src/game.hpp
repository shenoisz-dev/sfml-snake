#ifndef __GAME__
#define __GAME__

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "snake.hpp"
#include "blocks.hpp"
#include "text.hpp"


class Game 
{
public:
    Game(int width, int height, sf::String title);
    void init();
    void events();
    void collision();
    void update();
    void draw();
    void clear();
    void show();
    void run();
private:
    sf::RenderWindow window;
    int width;
    int height;
    int score;
    Blocks* blocks;
    Snake* snake;
    sh::Text* lostText;
    sh::Text* scoreText;
};

#endif
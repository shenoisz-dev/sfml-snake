#include "snake.hpp"


Snake::Snake(int width, int height, float w)
{
    x = w;
    y = w;
    this->width = width;
    this->height = height;
    diration = -1;
    lastDiration = -1;
    this->w = w;
    rectCount = 0;
    add();
}


void Snake::add()
{
    sf::RectangleShape rectangle(sf::Vector2f(w, w));
    rectangle.setFillColor(sf::Color(150, 50, 250));
    if (vrect.size() > 0) 
    {
        float x = vrect[0].getPosition().x;
        float y = vrect[0].getPosition().y;
        rectangle.setPosition(sf::Vector2f(x, y));
    } 
    else 
    {
        rectangle.setPosition(sf::Vector2f(0, 0));
    }
    vrect.push_back(rectangle);
}


sf::RectangleShape Snake::main()
{
    return vrect[0];
}


void Snake::restart()
{
    sf::RectangleShape rectangle(sf::Vector2f(w, w));
    rectangle.setFillColor(sf::Color(150, 50, 250));
    rectangle.setPosition(sf::Vector2f(0, 0));
    vrect.clear();
    vrect.push_back(rectangle);
}


void Snake::events()
{
    if (diration != -2)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            diration = 0;
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            diration = 1;
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            diration = 2;
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            diration = 3;
        }
    }    
}

bool Snake::checkCollition(float posx, float posy)
{
    sf::RectangleShape rect = vrect[0];
    rect.move(posx, posy);
    float rectx = rect.getPosition().x;
    float recty = rect.getPosition().y; 

    for (int i = 0; i < vrect.size(); i++)
    {
        float vrectx = vrect[i].getPosition().x;
        float vrecty = vrect[i].getPosition().y;

        if (vrectx == rectx && vrecty == recty)
        {
            return true;
        }
    }

    return false;
}

void Snake::updateNail()
{
    std::vector<sf::RectangleShape> vrect2 = vrect;
    for (int i = 0; i < vrect2.size(); i++)
    {
        float vrectx = vrect2[i].getPosition().x;
        float vrecty = vrect2[i].getPosition().y;
        int next = i + 1;
        if (next < vrect2.size())
            vrect[next].setPosition(sf::Vector2f(vrectx, vrecty));
    }
}


void Snake::update()
{ 
    switch (diration)
    {
        case 0: // left
        {
            if (lastDiration != 1)
            {
                if (!checkCollition(-x, 0.f))
                {
                    updateNail();
                    vrect[0].move(-x, 0.f);
                    lastDiration = diration;
                } 
                else 
                {
                    diration = -2;
                }  
            } else {
                diration = 1;
            }
            break;
        }
        case 1: // right
        {
            if (lastDiration != 0)
            {
                if (!checkCollition(x, 0.f))
                {
                    updateNail();
                    vrect[0].move(x, 0.f);
                    lastDiration = diration;
                } 
                else 
                {
                    diration = -2;
                } 
            } else {
                diration = 0;
            }
            break;
        }
        case 2: // up
        {
            if (lastDiration != 3)
            {
                if (!checkCollition(0.f, -y))
                {
                    updateNail();
                    vrect[0].move(0.f, -y);
                    lastDiration = diration;
                } 
                else 
                {
                    diration = -2;
                }
            } else {
                diration = 3;
            }  
            break;
        }
        case 3: // down
        {
            if (lastDiration != 2)
            {
                if (!checkCollition(0.f, y))
                {
                    updateNail();
                    vrect[0].move(0.f, y);
                    lastDiration = diration;
                } 
                else 
                {
                    diration = -2;
                }
            } else {
                diration = 2;
            }
            break;
        }
        default:
            break;
    }
}


void Snake::draw(sf::RenderWindow* window)
{
    for (int i = 0; i < vrect.size(); i++)
    {
        window->draw(vrect[i]);
    }
}


void Snake::show()
{
    if (diration == -1)
    {
        diration = 1;
        lastDiration = 1;
    }
}
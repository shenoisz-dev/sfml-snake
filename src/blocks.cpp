#include "blocks.hpp"


Blocks::Blocks(int width, int height, float w)
{
    // 800 / 40 = 20
    // 600 / 40 = 15
    float x = 0.f;
    float y = 0.f;

    for (float i = 0.f; i < (width / w) * (height / w); i++)
    {
        sf::RectangleShape rectangle(sf::Vector2f(w, w));
        rectangle.setFillColor(sf::Color(16, 16, 16));
        rectangle.setPosition(sf::Vector2f(x, y));
        vrect.push_back(rectangle);

        if (x < width - w)
        {
            x += w;
        } 
        else 
        {
            x = 0.f;
            y += w;
        }
    }

    this->width = width;
    this->height = height;
    this->w = w;
    upRect = true;
    lastRect = -1;
}


sf::RectangleShape Blocks::rect(int index)
{
    return vrect[index];
}


int Blocks::size()
{
    return vrect.size();
}


void Blocks::update()
{
    if (upRect)
    {
        if (lastRect != -1) 
        {
            if (lastRect != pIndex)
                vrect[lastRect].setFillColor(sf::Color(16, 16, 16));
            lastRect = -1;
        }
        const int max = (int)((width / w) * (height / w));
        int random = (int)(rand() % max);
        vrect[random].setFillColor(sf::Color(150, 50, 250));
        upRect = false;
        lastRect = random;
    }
}


void Blocks::randPos()
{
    upRect = true;
}


void Blocks::setColor(int index, sf::Color color)
{
    pIndex = index;
    vrect[index].setFillColor(color);
}


void Blocks::draw(sf::RenderWindow* window)
{
    for (int i = 0; i < size(); i++)
    {
        window->draw(vrect[i]);
    }
}


sf::RectangleShape Blocks::currentRect()
{
    return rect(lastRect);
}
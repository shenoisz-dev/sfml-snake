#include "text.hpp"


// int w, int h, int dx, int dy
sh::Text::Text(int fontSize, int area[4], std::string title)
{
    this->fontSize = fontSize;
    this->w = area[0];
    this->h = area[1]; 
    this->dx = area[2]; 
    this->dy = area[3]; 
    this->title = title;
}


void sh::Text::draw(sf::RenderWindow* window) 
{   
    sf::Text text;
    sf::Font font;
    if (font.loadFromFile("resources/andarilho-font.ttf"))
    {
        float posx = (w / dx) - fontSize * (int)(title.size() / 3);
        float posy = (h / dy) - fontSize;
        text.setFont(font);
        text.setString(title);
        text.setCharacterSize(fontSize);
        text.setPosition(sf::Vector2f(posx, posy));
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
        window->draw(text);
    }
}

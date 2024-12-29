#ifndef __BLOCKS__
#define __BLOCKS__

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>


class Blocks
{
public:
    explicit Blocks(int width, int height, float w);
    int size();
    void update();
    void randPos();
    void setColor(int index, sf::Color color);
    void draw(sf::RenderWindow* window);
    sf::RectangleShape rect(int index);
    sf::RectangleShape currentRect();
private:
    int width;
    int height;
    float w;
    bool upRect;
    int lastRect;
    int pIndex;
    std::vector<sf::RectangleShape> vrect;
};

#endif
#ifndef __SNAKE__
#define __SNAKE__

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


class Snake
{
public:
    Snake(int width, int height, float w);
    void add();
    void events();
    void update();
    void show();
    void restart();
    void draw(sf::RenderWindow* window);
    sf::RectangleShape main();
    std::vector<sf::RectangleShape> vrect;
    short diration;
private:
    float w;
    float x;
    float y;
    int width;
    int height;
    short lastDiration;
    int rectCount;
    void updateNail();
    bool checkCollition(float posx, float posy);
};

#endif
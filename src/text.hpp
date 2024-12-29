#ifndef __TEXT__
#define __TEXT__

#include <SFML/Graphics.hpp>

namespace sh
{
    class Text
    {
    public:
        Text(int fontSize, int area[4], std::string title);
        void draw(sf::RenderWindow* window);
    private:
        int fontSize; 
        int w;
        int h;
        int dx;
        int dy;
        std::string title;
    };
}
#endif
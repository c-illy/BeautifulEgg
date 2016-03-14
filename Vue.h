#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>

#define RESSOURCES "./"

class Vue
{
    public:
        Vue(sf::RenderWindow& window);
        virtual ~Vue();

        virtual void draw() const = 0;

    protected:
        sf::RenderWindow& m_window;
};

#endif // VIEW_H

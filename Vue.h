#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>

#define RESSOURCES "./"

#define TAILLE_FENETRE_X 1400
#define TAILLE_FENETRE_Y 800

class Vue
{
    public:
        Vue(sf::RenderWindow& window);
        virtual ~Vue();

        virtual void update(sf::Time deltaTemps) = 0;
        virtual void draw() const = 0;

    protected:
        sf::RenderWindow& m_window;
};

#endif // VIEW_H

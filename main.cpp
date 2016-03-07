#include <SFML/Graphics.hpp>
#include "Personnage.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
<<<<<<< HEAD
*/


/*

    Personnage perso1("p1"),perso2("p2");

    perso1.attaquer(perso2);

    perso1.afficher();
*/



=======

    Personnage perso1();
//    Personnage perso2;
>>>>>>> 3946cd9727d47154dd96566895209082949d0009
    return 0;
}

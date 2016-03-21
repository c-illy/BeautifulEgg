
#include <SFML/Graphics.hpp>
#include "Personnage.h"
#include "Case.h"

#include "Modeles.h"
#include "Vues.h"


int main()
{
    Modeles::init();
    Vues::init();

    sf::Clock clock;
    while (Vues::m_window.isOpen())
    {
        sf::Event event;
        while (Vues::m_window.pollEvent(event))
        {
              if (event.type == sf::Event::Closed)
                Vues::m_window.close();
        }
        Vues::update(clock.restart());
        Vues::draw();
    }

    return 0;
}

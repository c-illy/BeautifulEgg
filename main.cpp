
#include <SFML/Graphics.hpp>
#include "Personnage.h"
#include "Monstre.h"
#include "Case.h"

#include "Modeles.h"
#include "Vues.h"


int main()
{
    Modeles::init();
    Vues::init();

    sf::Event event;
    sf::Clock clock;
    while (Vues::m_window.isOpen())
    {
        sf::Time deltaTemps(clock.restart());
        Modeles::m_phaseDeltaTempsMs += deltaTemps.asMilliseconds();

        //fermeture
        if (Vues::m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Vues::m_window.close();
        }

        ///TODO intro (cinematique)
        if (Modeles::m_phase == Modeles::PRET)
        {
            if (Vues::m_window.pollEvent(event))///TODO controleur
            {
                Modeles::updatePhasePret();
            }
        }
        if (Modeles::m_phase == Modeles::ACTION_PJ)
        {
            Modeles::updatePhasePJ();
        }
        if (Modeles::m_phase == Modeles::ACTION_PNJ)
        {
            Modeles::updatePhasePNJ();
        }
        ///TODO FIN (cinematique)

        Vues::update(deltaTemps);
        Vues::draw();

        Modeles::m_nouvellePhase = false;
    }

    return 0;
}

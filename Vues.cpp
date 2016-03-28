#include "Vues.h"

RoyaumeView Vues::m_royaumeView(Vues::m_window);
IHMView Vues::m_IHMView(Vues::m_window);
PersonnagesView Vues::m_personnagesView(Vues::m_window);

sf::RenderWindow Vues::m_window(sf::VideoMode(TAILLE_FENETRE_X, TAILLE_FENETRE_Y), "EGG");

void Vues::init()
{
    m_window.setFramerateLimit(60);
    m_personnagesView.init();
}

void Vues::update(sf::Time deltaTemps)
{
    m_royaumeView.update(deltaTemps);
    m_personnagesView.update(deltaTemps);
    m_IHMView.update(deltaTemps);
}

void Vues::draw()
{
    m_window.clear();

    m_royaumeView.draw();
    m_personnagesView.draw();
    m_IHMView.draw();

    m_window.display();
}

#include "Vues.h"

RoyaumeView Vues::m_royaumeView(Vues::m_window);
IHMView Vues::m_IHMView(Vues::m_window);
PersonnagesView Vues::m_personnagesView(Vues::m_window);

sf::RenderWindow Vues::m_window(sf::VideoMode(800, 600), "Vues works!");

void Vues::draw()
{
    m_window.clear();

    m_royaumeView.draw();
    m_personnagesView.draw();
    m_IHMView.draw();

    m_window.display();
}

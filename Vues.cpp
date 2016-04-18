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

    sf::View view = m_window.getDefaultView();
    const Position& posJoueur = Modeles::m_joueur.getPosition();
    view.setCenter(positionToVect2f(posJoueur));
    //view.zoom(2.f);
    m_window.setView(view);

    m_royaumeView.draw();
    m_personnagesView.draw();
    m_IHMView.draw();

    m_window.display();
}


sf::Vector2f Vues::positionToVect2f(const Position& position)
{
    return sf::Vector2f(position.getPositionX() * TAILLE_CASE_X, position.getPositionY() * TAILLE_CASE_Y);
}

Position Vues::vect2fToPosition(const sf::Vector2f& vect)
{
    return Position(vect.x / TAILLE_CASE_X, vect.y * TAILLE_CASE_Y);
}

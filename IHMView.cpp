#include "IHMView.h"
#include "Modeles.h"

IHMView::IHMView(sf::RenderWindow& window) :
    Vue(window),
    m_fond(sf::Vector2f(100.f, 10.f))
{
    m_fond.setFillColor(sf::Color::Green);
}

IHMView::~IHMView()
{
    //dtor
}

void IHMView::draw() const
{
    const Personnage& joueur = Modeles::m_joueur;

    sf::Sprite variable;
    sf::Sprite barreDeVie;

    m_window.draw(m_fond);
}

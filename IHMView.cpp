#include "IHMView.h"
#include "Modeles.h"

IHMView::IHMView(sf::RenderWindow& window) :
    Vue(window), m_shape(100.f)
{
    m_shape.setFillColor(sf::Color::Green);
}

IHMView::~IHMView()
{
    //dtor
}

void IHMView::draw() const
{
    const Personnage& joueur = Modeles::m_joueur;
    //m_window.draw(m_shape);
}

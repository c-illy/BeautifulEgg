#include "PersonnagesView.h"
#include "Modeles.h"

PersonnagesView::PersonnagesView(sf::RenderWindow& window) :
    Vue(window), m_debug(window, "testAnim")
{

}

PersonnagesView::~PersonnagesView()
{
    //dtor
}

void PersonnagesView::update(sf::Time deltaTemps)
{
    m_debug.update(deltaTemps);
}

void PersonnagesView::draw() const
{
    Personnage& joueur = Modeles::m_joueur;
    std::vector<Personnage*> monstres = Modeles::m_monstres;

    drawPersonnage(joueur);
    for(Personnage* p : monstres)
    {
        drawPersonnage(*p);
    }

    m_debug.draw();///////////////////////////////FIXME
}

void PersonnagesView::drawPersonnage(const Personnage& personnage) const
{

}

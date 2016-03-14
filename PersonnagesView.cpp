#include "PersonnagesView.h"
#include "Modeles.h"

PersonnagesView::PersonnagesView(sf::RenderWindow& window) :
    Vue(window)
{
    //ctor
}

PersonnagesView::~PersonnagesView()
{
    //dtor
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
}

void PersonnagesView::drawPersonnage(const Personnage& personnage) const
{

}

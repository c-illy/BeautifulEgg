#include "PersonnagesView.h"
#include "Modeles.h"
#include "Monstre.h"

PersonnagesView::PersonnagesView(sf::RenderWindow& window) :
    Vue(window)
{

}

PersonnagesView::~PersonnagesView()
{
    for(Animation* anim : m_animations)
    {
        delete anim;
    }
}

void PersonnagesView::init()
{
    m_animations.push_back(new Animation(m_window, Modeles::m_joueur));
}

void PersonnagesView::update(sf::Time deltaTemps)
{
    for(Animation* anim : m_animations)
    {
        anim->update(deltaTemps);
    }
}

void PersonnagesView::draw() const
{
    //Personnage& joueur = Modeles::m_joueur;
    //std::vector<Monstre*>& monstres = Modeles::m_monstres;

    for(Animation* anim : m_animations)
    {
        anim->draw();
    }
}

void PersonnagesView::drawPersonnage(const Personnage& personnage) const
{

}

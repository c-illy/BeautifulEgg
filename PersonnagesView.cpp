#include "PersonnagesView.h"
#include "Modeles.h"
#include "Monstre.h"
#include "Vues.h"
#include "Zone.h"
#include "Animation.h"

Animation* PersonnagesView::m_joueurAnimation = 00;

PersonnagesView::PersonnagesView() :
    Vue(Vues::m_window)
{

}

PersonnagesView::~PersonnagesView()
{
    for(Animation* anim : m_animations)
    {
        if(anim != 00)
        {
            delete anim;
            anim = 00;
        }
    }
}

void PersonnagesView::init(Zone* zone)
{
    if(m_joueurAnimation == 00)
    {
        m_joueurAnimation = new Animation(m_window, Modeles::m_joueur);
    }
    m_animations.push_back(m_joueurAnimation);

    for(Monstre* monstre : zone->m_monstres)
    {
        m_animations.push_back(new Animation(m_window, *monstre));
    }
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

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
    m_yOrderAnims.insert(std::pair<int, Animation*>(
        Modeles::m_joueur.getPosition().getPositionY(),
        m_joueurAnimation));

    for(Monstre* monstre : zone->m_monstres)
    {
        m_animations.push_back(new Animation(m_window, *monstre));
        m_yOrderAnims.insert(std::pair<int, Animation*>(
            monstre->getPosition().getPositionY(),
            m_animations.at(m_animations.size()-1)));
    }
}

void PersonnagesView::update(sf::Time deltaTemps)
{
    bool retirerMorts = (Modeles::m_phase==Modeles::PRET) && Modeles::m_nouvellePhase;
    if(retirerMorts)
    {
        retirerMorts = false;
        for(int i=m_animations.size()-1; i>=0; i--)
        {
            Animation* anim = m_animations.at(i);
            if(!anim->m_personnage.getVivant())
            {
                delete anim;
                m_animations.erase(m_animations.begin()+i);
                retirerMorts = true;
            }
        }
    }

    bool deplacementPerso = Modeles::m_nouvellePhase &&
        ( (Modeles::m_phase==Modeles::ACTION_PJ) || (Modeles::m_phase==Modeles::ACTION_PNJ) );

    if(retirerMorts || deplacementPerso)
    {
        //changement possible des yOrderAnims
        //(on pourrait optimiser mieux, mais pas vraiment la peine)
        //std::cout << "reordonnancement des anims des persos" << std::endl;

        m_yOrderAnims.clear();
        for(Animation* anim : m_animations)
        {
            Position p = anim->m_personnage.getPosition();
            m_yOrderAnims.insert(std::pair<int, Animation*>(
                p.getPositionY(),
                anim));
        }
    }

    for(Animation* anim : m_animations)
    {
        anim->update(deltaTemps);
    }
}

void PersonnagesView::draw() const
{
    //Personnage& joueur = Modeles::m_joueur;
    //std::vector<Monstre*>& monstres = Modeles::m_monstres;

    std::multimap<int, Animation*>::const_iterator it;
    for(it=m_yOrderAnims.begin(); it!=m_yOrderAnims.end(); it++)
    {
        const Animation* anim = it->second;
        anim->draw();
    }
}

void PersonnagesView::drawPersonnage(const Personnage& personnage) const
{

}

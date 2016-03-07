#include <iostream>
#include "Personnage.h"



Case::Case()
{

}

void Case::setPersonnage()
{
    m_perso=new Personnage("a");
}

Personnage Case::getPersonnage()
{
    return *m_perso;
}

Position Case::getPosition()
{
    return m_position;
}



Personnage::Personnage(std::string nom) : m_nom(nom), m_santeMax(100), m_sante(100), m_degats(20), m_directionActuelle(droite)
{

}



void Personnage::perdreSante(int degats)
{
    m_sante -= degats;
    if (m_sante == 0)
    {
        std::cout << "Game over" << std::endl;
    }
}

void Personnage::deplacer(Direction dir)
{
    m_directionActuelle=dir;
}

void Personnage::attaquer(Personnage &autre)
{
    autre.perdreSante(m_degats);


    std::cout<<m_nom<<" inflige "<<m_degats<<" degats a "<<autre.getNom()<<std::endl;
    autre.afficher();

}


void Personnage::sortFeu(Personnage &autre)
{
    autre.perdreSante(10);
}

void Personnage::sortFoudre(Personnage &autre)
{
    autre.perdreSante(10);
}

void Personnage::sortGlace(Personnage &autre)
{
    autre.perdreSante(10);
}













/*
void Personnage::interragir(Objet obj)
{

}
*/

void Personnage::afficher()
{
    std::cout<<m_nom<<" a "<<m_sante<<" points de vie"<<std::endl;
}





std::string Personnage::getNom()
{
    return m_nom;
}


void Personnage::setAction(Action action)
{
    m_actionCourante=action;
}


void Personnage::executerAction()
{
    switch(m_actionCourante)
    {
        case deplacer :  m_position=m_caseCible.getPosition();

            break;

        case actionner :

            break;

        case attaquer :  attaquer(m_caseCible.getPersonnage());

            break;

        case sortFeu :  sortFeu(m_caseCible.getPersonnage());

            break;

        case sortFoudre :  sortFoudre(m_caseCible.getPersonnage());

            break;

        case sortGlace :  sortGlace(m_caseCible.getPersonnage());

            break;




    }
}


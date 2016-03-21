#include <iostream>
#include "Personnage.h"








Personnage::Personnage(std::string nom, int x, int y) :
    m_nom(nom), m_sante(100), m_santeMax(100), m_degats(20), m_position(x,y),
    m_directionActuelle(droite), m_caseCible(NULL), m_vivant(true)
{

}



void Personnage::perdreSante(int degats)
{

    if(m_sante>0)
    {
         m_sante -= degats;


        if (m_sante == 0)
        {

            m_vivant=true;
            std::cout << "Game over" << std::endl;
        }
    }


}



void Personnage::attaquer(Personnage &autre)
{
    autre.perdreSante(m_degats);


    std::cout<<m_nom<<" inflige "<<m_degats<<" degats a "<<autre.getNom()<<std::endl;
    autre.afficher();

}



void Personnage::setCaseCible(Case *caseCible)
{
    m_caseCible=caseCible;
}


/*
void Personnage::interragir(Objet obj)
{

}
*/

void Personnage::setPosition(int x, int y)
{
    m_position.setPositionX(x);
    m_position.setPositionY(y);
}


Position Personnage::getPosition()
{
    return m_position;
}




void Personnage::afficher()
{
    std::cout<<m_nom<<" a "<<m_sante<<" points de vie"<<std::endl;
    std::cout<<m_nom<<" est sur la case ("<<m_position.getPositionX()<<","<<m_position.getPositionY()<<")"<<std::endl;


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
        case DEPLACER :

            std::cout<<m_nom<<" se deplace"<<std::endl;
            setPosition(m_caseCible->getPosition().getPositionX(),m_caseCible->getPosition().getPositionY());

            break;


      case ACTIONNER :

            break;

        case ATTAQUER :

            Personnage *cible;
            cible=m_caseCible->getPersonnage();

            attaquer(*cible);

            break;

    }



}

Personnage::~Personnage()
{
    delete m_caseCible;
}

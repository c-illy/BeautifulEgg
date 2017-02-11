#include "Case.h"
#include "Personnage.h"
#include "Monstre.h"

Case::Case( bool navigable, Personnage* personnage, int x, int y,
           Objet* objet, bool finJeu) :
    m_destination(00),
    m_navigable(navigable), m_personnage(personnage), m_objet(objet),
    m_finJeu(finJeu)
{
    m_position.setPositionX(x);
    m_position.setPositionY(y);
}

Case::~Case()
{
}


bool Case::navigable() const
{
    return m_navigable;
}

bool Case::navigableEtLibre() const
{
    if(!m_navigable) return false;
    if(m_personnage != 00)
    {
        if(m_personnage->getActionCourante() != DEPLACER)
        {
            return false;
        }
    }
    else
    {
        for(Monstre* monstre : Modeles::getMonstres())
        {
            if(
                (monstre->getActionCourante() == DEPLACER) &&
                (monstre->isCaseCible(this))
               )
            {
               return false;
            }
        }
    }
    return true;
}

Personnage* Case::getPersonnage() const
{
    return m_personnage;
}

Objet* Case::getObjet() const
{
    return m_objet;
}


void Case::setPersonnage(Personnage* personnage)
{
    m_personnage = personnage;
}


void Case::setObjet(Objet* objet)
{
    m_objet = objet;
}


Position Case::getPosition() const
{
    return m_position;
}

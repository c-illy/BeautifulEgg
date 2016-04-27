#include "Case.h"
#include "Personnage.h"
#include "Monstre.h"

Case::Case( bool navigable, Personnage* personnage, int x, int y/*, Objet* objet*/) :
    m_destination(00),
    m_navigable(navigable), m_personnage(personnage)
{
    m_position.setPositionX(x);
    m_position.setPositionY(y);
    //ctor
}

Case::~Case()
{
    //dtor
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

/*Objet& Case::getObjet()
{
    return *m_objet;
}
*/

void Case::setPersonnage(Personnage* personnage)
{
    m_personnage = personnage;
}


Position Case::getPosition() const
{
    return m_position;
}

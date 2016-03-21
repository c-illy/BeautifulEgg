#include "Case.h"


Case::Case( bool navigable, Personnage* personnage, int x, int y/*, Objet* objet*/) :
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

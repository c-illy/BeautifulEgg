#include "Case.h"

Case::Case()
{
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

Personnage* Case::getPersonnage()
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

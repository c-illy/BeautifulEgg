#include "Modeles.h"

Royaume Modeles::m_royaume;
Personnage Modeles::m_joueur;
std::vector<Personnage*> Modeles::m_monstres;

void Modeles::init()
{
    m_royaume.chargerFichier();
}

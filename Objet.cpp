#include "Objet.h"
#include "Modeles.h"
#include <iostream>

Objet* Objet::m_bidonLevier2 = 00;

Objet::Objet(ObjetID id, int x, int y, Zone* zoneParente, bool estObstacle) :
    m_id(id), m_position(x,y),
    m_zoneParente(zoneParente),
    m_estObstacle(estObstacle)
{
}

Objet::~Objet()
{
}

void Objet::utiliser()
{
    switch(m_id)
    {
    case SANTE:
        std::cout << "Utilisation Objet id=" << m_id << std::endl;
        Modeles::m_joueur.soignerSante(25);//changer la valeur du soin ici si besoin
        break;
    case BONUS_DEGATS:
        std::cout << "Utilisation Objet id=" << m_id << std::endl;
        Modeles::m_joueur.ameliorerDegats(20);//changer la valeur du soin ici si besoin
        break;
    case BIDON_DEBUG_LEVIER_1:
        std::cout << "Utilisation Objet id=" << m_id << std::endl;
        break;
    default:
        std::cout << "Erreur utilisation objet - ignoré" << std::endl;
    }
}

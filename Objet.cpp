#include "Objet.h"
#include <iostream>

Objet* Objet::m_bidonLevier2 = 00;

Objet::Objet(ObjetID id, int x, int y, Zone* zoneParente) :
    m_id(id), m_position(x,y), m_zoneParente(zoneParente)
{
}

Objet::~Objet()
{
}

void Objet::utiliser()
{
    switch(m_id)
    {
    case BIDON_DEBUG_0:
        std::cout << "Utilisation Objet id=" << m_id << std::endl;
        break;
    case BIDON_DEBUG_1:
        std::cout << "Utilisation Objet id=" << m_id << std::endl;
        break;
    case BIDON_DEBUG_LEVIER_1:
        std::cout << "Utilisation Objet id=" << m_id << std::endl;
        break;
    default:
        std::cout << "Erreur utilisation objet - ignoré" << std::endl;
    }
}

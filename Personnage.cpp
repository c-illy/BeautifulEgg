#include <iostream>
#include "Personnage.h"

void Personnage::perdreSante(int degats)
{
    m_sante -= degats;
    if (m_sante == 0)
    {
        std::cout << "Game over" << std::endl;
    }
}

void Personnage::deplacement(Direction dir)
{
}


#ifndef MODELES_H
#define MODELES_H

#include <vector>

#include "Royaume.h"
#include "Personnage.h"
//#include "Objet.h"

#define TAILLE_CASE_X 100
#define TAILLE_CASE_Y 100

enum Action
{
    DEPLACER,
    ATTAQUER,
    ACTIONNER
};

class Modeles
{
    public:
        static Royaume m_royaume;
        static Personnage m_joueur;
        static std::vector<Personnage*> m_monstres;
        //static std::vector<Objet*> m_objets;
};

#endif // MODELES_H
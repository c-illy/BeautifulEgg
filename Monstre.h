#ifndef MONSTRE_H_INCLUDED
#define MONSTRE_H_INCLUDED

#include "Personnage.h"
#include "Case.h"

//typedef std::vector<int> vecteur;
class Position;


class Monstre: public Personnage
{
    public:
      Monstre();
      void appliquerIA();

    private:
      void choisirDeplacement(const Position* direction);

    private:
      double m_rayonIA;

};

#endif // MONSTRE_H_INCLUDED
#ifndef MONSTRE_H_INCLUDED
#define MONSTRE_H_INCLUDED

#include "Personnage.h"
#include "Case.h"


typedef std::vector<int> vecteur;






class Monstre: public Personnage
{

    public:

    Monstre();
    void choisirDeplacement(vecteur direction);
    void appliquerIA();



    private:

    double m_rayonIA;



};






#endif // MONSTRE_H_INCLUDED

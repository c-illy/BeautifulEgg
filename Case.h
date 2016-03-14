#ifndef CASE_H
#define CASE_H

#include <iostream>
#include "Position.h"
//#include "Personnage.h"
//#include "Objet.h"

//#include "Modeles.h"


class Personnage;

class Modeles;



class Case
{
    public:

        Case(int x, int y, bool navigable, Personnage* personnage/*, Objet* objet*/);

        virtual ~Case();

        bool navigable() const;
        Personnage* getPersonnage();
        Position getPosition();
        //Objet& getObjet();

        void setPersonnage(Personnage* personnage);

    protected:

    private:
        bool m_navigable;
        Personnage* m_personnage;
        Position m_position;

        //Objet* m_objet;
};

#endif // CASE_H

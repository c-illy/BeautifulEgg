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
        Case(bool navigable, Personnage* personnage, int x, int y/*, Objet* objet*/);

        virtual ~Case();

        bool navigable() const;
        Personnage* getPersonnage() const;
        Position getPosition() const;
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

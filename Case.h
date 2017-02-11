#ifndef CASE_H
#define CASE_H

#include <iostream>
#include "Position.h"
class Personnage;
class Objet;


class Destination
{
public:
    int m_numZone;
    int m_x;
    int m_y;
};

class Case
{
    public:
        Case(bool navigable, Personnage* personnage, int x, int y,
             Objet* objet=00, bool finJeu=false);

        virtual ~Case();

        bool navigable() const;
        bool navigableEtLibre() const;
        Personnage* getPersonnage() const;
        Objet* getObjet() const;
        Position getPosition() const;

        void setPersonnage(Personnage* personnage);
        void setObjet(Objet* objet);
        void setNavigable(bool navigable);

    public:
        ///nul par défaut, non nul ssi portail
        Destination* m_destination;
        bool m_finJeu;

    private:
        bool m_navigable;
        Position m_position;
        Personnage* m_personnage;
        Objet* m_objet;
};

#endif // CASE_H

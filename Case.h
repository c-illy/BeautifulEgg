#ifndef CASE_H
#define CASE_H

#include "Personnage.h"
//#include "Objet.h"

class Case
{
    public:
        Case();
        virtual ~Case();

        bool navigable() const;
        Personnage* getPersonnage();
        //Objet& getObjet();

        void setPersonnage(Personnage* personnage);

    protected:

    private:
        bool m_navigable;
        Personnage* m_personnage;
        //Objet* m_objet;
};

#endif // CASE_H

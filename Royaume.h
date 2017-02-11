#ifndef ROYAUME_H
#define ROYAUME_H

#include <vector>
#include "Zone.h"

class Royaume
{
    public:
        Royaume();
        virtual ~Royaume();

        void ajouterZone(Zone* zone);
        void chargerFichier();

        Case& get(int i, int j);
        const Case& get(int i, int j) const;
        int getLargeur() const;
        int getHauteur() const;
        Zone* getZoneCourante();

        void placerPersonnage(int i, int j, Personnage* p);
        void retirerMonstresMorts();
        void placerObjet(int i, int j, Objet* o, Zone* zone);
        void retirerObjet(int x, int y, Objet* o, Zone* zone);//sans delete
        void retirerObjet(int x, int y, Objet* o);//sans delete

    public:
        std::vector<Zone*> m_zones;
        int m_zoneCourante;
};

#endif // ROYAUME_H

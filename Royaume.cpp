#include "Royaume.h"
#include "MapParser.h"
#include "Monstre.h"

Royaume::Royaume()
{

}

Royaume::~Royaume()
{
    for(Zone* zone : m_zones)
    {
        delete zone;
    }
}

void Royaume::chargerFichier()
{
    MapParser::initZonesFromFiles();
}

void Royaume::ajouterZone(Zone* zone)
{
    m_zones.push_back(zone);
}

Case& Royaume::get(int i, int j)
{
    return m_zones.at(m_zoneCourante)->get(i, j);
}

const Case& Royaume::get(int i, int j) const
{
    return m_zones.at(m_zoneCourante)->get(i, j);
}

int Royaume::getLargeur() const
{
    return m_zones.at(m_zoneCourante)->getLargeur();
}

int Royaume::getHauteur() const
{
    return m_zones.at(m_zoneCourante)->getHauteur();
}

Zone* Royaume::getZoneCourante()
{
    return m_zones.at(m_zoneCourante);
}

void Royaume::placerPersonnage(int i, int j, Personnage* p)
{
    get(i, j).setPersonnage(p);
}

void Royaume::placerObjet(int i, int j, Objet* o, Zone* zone)
{
    zone->get(i, j).setObjet(o);
}

void Royaume::retirerMonstresMorts()
{
    Zone* zone = getZoneCourante();

    for(int i=zone->m_monstres.size()-1; i>=0; i--)
    {
        Monstre* monstre = zone->m_monstres.at(i);
        if(!monstre->getVivant())
        {
            Position p = monstre->getPosition();
            placerPersonnage(p.getPositionX(), p.getPositionY(), 00);
            delete monstre;
            zone->m_monstres.erase(zone->m_monstres.begin()+i);
        }
    }
}

//sans delete
void Royaume::retirerObjet(int x, int y, Objet* o, Zone* zone)
{
    std::vector<Objet*>& listeObjs = zone->m_objet;
    std::vector<Objet*>::iterator it;
    bool encore(true);
    for(it=listeObjs.begin(); encore && it!=listeObjs.end(); it++)
    {
        if((*it) == o)
        {
            listeObjs.erase(it);
            encore = false;
        }
    }
    placerObjet(x, y, 00, zone);
}

//sans delete
void Royaume::retirerObjet(int x, int y, Objet* o)
{
    retirerObjet(x, y, o, getZoneCourante());
}




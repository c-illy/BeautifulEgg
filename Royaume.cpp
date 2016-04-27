#include "Royaume.h"
#include "MapParser.h"

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




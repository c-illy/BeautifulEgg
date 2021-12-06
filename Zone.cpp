#include "Zone.h"
#include "Modeles.h"

#include <iostream>

Zone::Zone(int x, int y) : m_cases(x, std::vector<Case*>(y)),
m_secretZone(false), m_bossZone(false)
{

}

Zone::~Zone()
{
	for (int i = 0; i < getLargeur(); i++)
	{
		for (int j = 0; j < getHauteur(); j++)
		{
			Case* cell = (m_cases.at(i).at(j));
			delete cell;
		}
	}
}

/*void Zone::chargerFichier()
{
	m_cases.push_back(std::vector<Case*>());
	m_cases.at(0).push_back(new Case(true,0,0,0));
	m_cases.at(0).push_back(new Case(true, 0,0,0));
	m_cases.at(0).push_back(new Case(true, 0,0,0));
	m_cases.push_back(std::vector<Case*>());
	m_cases.at(1).push_back(new Case(true, 0,0,0));
	m_cases.at(1).push_back(new Case(false, 0,0,0));
	m_cases.at(1).push_back(new Case(true, 0,0,0));
	m_cases.push_back(std::vector<Case*>());
	m_cases.at(2).push_back(new Case(true, 0,0,0));
	m_cases.at(2).push_back(new Case(true, 0,0,0));
	m_cases.at(2).push_back(new Case(true, 0,0,0));
}*/

Case& Zone::get(int i, int j)
{
    return *(m_cases.at(i).at(j));
}

const Case& Zone::get(int i, int j) const
{

//    int minX = 0;
//    int maxX = getLargeur() - 1;
//    int minY = 0;
//    int maxY = getHauteur() - 1;
//    if(!(minX <= i && i <= maxX &&
//    minY <= j && j <= maxY))
//    {
//       std::cout << "plouf\n";
//    }
	return *(m_cases.at(i).at(j));
}

void Zone::set(int i, int j, Case* nouvCase)
{
    m_cases.at(i).at(j) = nouvCase;
}

int Zone::getLargeur() const
{
	return m_cases.size();
}

int Zone::getHauteur() const
{
	if(m_cases.size() > 0)
		return m_cases.at(0).size();
	return 0;
}

const Case* Zone::cheminVersCentre(int x0, int y0) const
{
    Position p0(x0, y0);
    Position dir((getLargeur()/2)-x0, (getHauteur()/2)-y0);
    const Case* res = Modeles::chemin(p0, dir, this);
    if(res == 00)
    {
        res = &get(x0, y0);//pas pu avancer, on reste sur place
    }
    return res;
}

bool Zone::monstrePopable(int x, int y) const
{
    if(!(get(x,y).navigable()))
    {
        return false;
    }
    int minX = 0;
    int maxX = getLargeur() - 1;
    int minY = 0;
    int maxY = getHauteur() - 1;
    for(int i=-2; i<=2; i++)
    {
        for(int j=-2; j<=2; j++)
        {
            if(minX <= x+i && x+i <= maxX &&
               minY <= y+j && y+j <= maxY)
            {
                const Case& c = get(x+i, y+j);
                if(c.m_destination != 00)
                {
                    return false;//trop près d'un portail
                }
                if(c.getPersonnage() == &(Modeles::m_joueur))
                {
                    return false;//trop près du player
                }
            }
        }
    }
    return true;
}

void Zone::debug() const
{
    //const std::vector<Case*>& colonne = m_cases.at(i);
    unsigned int C = m_cases.size();
    std::cout << "colonnes : " << C << std::endl;
    if(m_cases.size() > 0)
    {
        unsigned int L = m_cases.at(0).size();
        std::cout << "lignes : " << L << std::endl;
        for(unsigned int j=0; j<L; j++)
        {
            for(unsigned int i=0; i<C; i++)
            {
                if(m_cases.at(i).at(j)->navigable())
                {
                    std::cout << i%10 << " ";
                }
                else
                {
                    std::cout << "- ";
                }
            }
            std::cout << std::endl;
        }
    }
}


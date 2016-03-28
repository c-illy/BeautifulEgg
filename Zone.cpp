#include "Zone.h"

Zone::Zone(int x, int y) : m_cases(x, std::vector<Case*>(y))
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

void Zone::chargerFichier()
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
}

Case& Zone::get(int i, int j)
{
    return *(m_cases.at(i).at(j));
}

const Case& Zone::get(int i, int j) const
{
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


#include "Royaume.h"

Royaume::Royaume()
{
    m_cases.push_back(std::vector<Case>());
    m_cases.at(0).push_back(Case(true,0,0,0));
    m_cases.at(0).push_back(Case(true, 0,0,0));
    m_cases.at(0).push_back(Case(true, 0,0,0));
    m_cases.push_back(std::vector<Case>());
    m_cases.at(1).push_back(Case(true, 0,0,0));
    m_cases.at(1).push_back(Case(false, 0,0,0));
    m_cases.at(1).push_back(Case(true, 0,0,0));
    m_cases.push_back(std::vector<Case>());
    m_cases.at(2).push_back(Case(true, 0,0,0));
    m_cases.at(2).push_back(Case(true, 0,0,0));
    m_cases.at(2).push_back(Case(true, 0,0,0));
}

Royaume::~Royaume()
{
    //dtor
}

Case& Royaume::get(int i, int j)
{
    return m_cases.at(i).at(j);
}

const Case& Royaume::get(int i, int j) const
{
    return m_cases.at(i).at(j);
}

int Royaume::getLargeur() const
{
    return m_cases.size();
}

int Royaume::getHauteur() const
{
    if(m_cases.size() > 0)
        return m_cases.at(0).size();
    return 0;
}


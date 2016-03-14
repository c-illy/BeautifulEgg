#include "Royaume.h"

Royaume::Royaume()
{
    //ctor
}

Royaume::~Royaume()
{
    //dtor
}

void  set(Case c, int i, int j)
{
    m_cases[i][j] = c;
}

Case& Royaume::get(int i, int j)
{
    return m_cases.at(i).at(j);
}

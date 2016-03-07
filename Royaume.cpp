#include "Royaume.h"

Royaume::Royaume()
{
    //ctor
}

Royaume::~Royaume()
{
    //dtor
}

Case& Royaume::get(int i, int j)
{
    return m_cases.at(i).at(j);
}

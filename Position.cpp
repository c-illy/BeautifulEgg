#include "Position.h"
#include <math.h>


Position::Position(int x, int y): m_x(x), m_y(y)
{

}


int Position::getPositionX() const
{
    return m_x;
}



int Position::getPositionY() const
{
    return m_y;
}

void Position::setPositionX(int x)
{
    m_x=x;
}

void Position::setPositionY(int y)
{
    m_y=y;
}


double Position::distance(const Position &pos) const
{
	double val = pow(m_x - pos.m_x,2) + pow(m_y - pos.m_y,2);
	return sqrt(val);
}


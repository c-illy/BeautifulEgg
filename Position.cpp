#include"Position.h"


Position::Position(int x, int y): m_x(x), m_y(y)
{

}


int Position::getPositionX()
{
    return m_x;
}



int Position::getPositionY()
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

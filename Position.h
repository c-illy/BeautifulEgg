#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED


class Position
{
    public:

    Position(int x=0, int y=0);
    int getPositionX() const;
    int getPositionY() const;
    void setPositionX(int x);
    void setPositionY(int y);
    double distance(const Position &pos) const;


    private:

    int m_x,m_y;

};




#endif // POSITION_H_INCLUDED

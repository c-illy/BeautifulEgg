#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

enum Direction {haut, bas, gauche, droite};

class Personnage
{
    public:
        void perdreSante(int degats);
        void deplacement(Direction dir);
        void attaque(Personnage &autre);
    protected:
        int m_sante;
        int m_santeMax;
        int m_degats;
};


#endif // PERSONNAGE_H_INCLUDED

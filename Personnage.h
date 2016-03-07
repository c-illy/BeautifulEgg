#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <string>
//#include "Case.h"



enum Direction {haut, bas, gauche, droite};
enum Action {deplacer, actionner, attaquer, sortFeu, sortGlace, sortFoudre};
struct Position {int x,y;};



class Personnage;

class Case
{
    public :
     Case();
     ~Case();
     Position getPosition();
     void setPersonnage();
     Personnage getPersonnage();

    private :

    Position m_position;
    Personnage *m_perso;
};



class Personnage
{
    public:


        Personnage(std::string nom);

        void afficher();
        void setAction(Action action);
        void executerAction();
        std::string getNom();



    protected:

        void perdreSante(int degats);
        void deplacer(Direction dir);
        void attaquer(Personnage &autre);
        void sortFeu(Personnage &autre);
        void sortFoudre(Personnage &autre);
        void sortGlace(Personnage &autre);
        //void interragir(Objet obj);


        int m_sante;
        int m_santeMax;
        int m_degats;
        Position m_position;
        std::string m_nom;
        Direction m_directionActuelle;
        Action m_actionCourante;
        Case m_caseCible;
};


#endif // PERSONNAGE_H_INCLUDED

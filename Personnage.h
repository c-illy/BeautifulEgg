#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <string>
#include "Case.h"
#include "Position.h"
#include "Modeles.h"



class Modeles;




enum Direction {haut, bas, gauche, droite};



enum Action
{
    DEPLACER,
    ATTAQUER,
    ACTIONNER
};




class Personnage
{
    public:


        Personnage(std::string nom="joueur", int x=0, int y=0);
        ~Personnage();

        void afficher();
        void setAction(Action action);
        void executerAction();
        std::string getNom();
        void setCaseCible(const Case *caseCible);
        void setPosition(int x, int y);
        Position getPosition() const;





    protected:



        void perdreSante(int degats);
        void attaquer(Personnage &autre);
        //void interragir(Objet obj);


        int m_sante;
        int m_santeMax;
        int m_degats;
        Position m_position;
        std::string m_nom;
        Direction m_directionActuelle;
        Action m_actionCourante;
        const Case *m_caseCible;
        bool m_vivant;

};


#endif // PERSONNAGE_H_INCLUDED

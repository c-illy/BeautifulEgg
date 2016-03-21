#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <string>
#include "Case.h"
#include "Position.h"
#include "Modeles.h"



class Modeles;




enum Direction
{
    HAUT,
    BAS,
    GAUCHE,
    DROITE,
    NOMBRE_DIRECTIONS
};



enum Action
{
    DEPLACER,
    ATTAQUER,
    ACTIONNER,
    NOMBRE_ACTIONS
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


        std::string m_nom;
        int m_sante;
        int m_santeMax;
        int m_degats;
        Position m_position;
        Direction m_directionActuelle;
        const Case *m_caseCible;
        bool m_vivant;
        Action m_actionCourante;

};


#endif // PERSONNAGE_H_INCLUDED

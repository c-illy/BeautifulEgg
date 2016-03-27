#ifndef MODELES_H
#define MODELES_H

#include <vector>

#include "Royaume.h"
#include "Personnage.h"
class Monstre;
//#include "Objet.h"


#define TAILLE_CASE_X 100
#define TAILLE_CASE_Y 50



class Modeles
{

  public:

        enum Phase{PRET, ACTION_PJ, ACTION_PNJ, NB_PHASES_IN_GAME,
            INTRO, FIN, GAME_OVER};
        //struct Position {int x,y;};

        static void init();

        static void updatePhaseIntro();
        static void updatePhasePret();
        static void updatePhasePJ();
        static void updatePhasePNJ();
        static void updatePhaseFin();


        static Royaume m_royaume;
        static Personnage m_joueur;
        static std::vector<Monstre*> m_monstres;

        //gestion phases
        static Phase m_phase;///phase courante
        static bool m_nouvellePhase;///si la phase vient juste de changer
        static int m_phaseDeltaTempsMs;///millisecondes depuis dernier changement de phase
        static const int DUREE_ACTION_PJ_MS;///millisecondes
        static const int DUREE_ACTION_PNJ_MS;///millisecondes

       // static std::vector<Objet*> m_objets;


};

#endif // MODELES_H

#ifndef MODELES_H
#define MODELES_H

#include <vector>

#include "Royaume.h"
#include "Personnage.h"
#include "Cinematique.h"
class Monstre;
class Objet;
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

        static std::vector<Monstre*>& getMonstres();
        static std::vector<Objet*>& getObjets();
        static int getNumZoneCourant();

        static void updatePhasePret();
        static void updatePhasePJ();
        static void updatePhasePNJ();

        /** case à prendre pour suivre un chemin selon direction souhaitée */
        static const Case* chemin(const Position& depart, const Position& direction, const Zone* zone);

        static Royaume m_royaume;
        static Personnage m_joueur;
        //static std::vector<Monstre*> m_monstres;//cf. Zone.h
        static Cinematique m_cinematiqueIntro;
        static Cinematique m_cinematiqueFin;

        //gestion phases
        static Phase m_phase;///phase courante
        static bool m_nouvellePhase;///si la phase vient juste de changer
        static int m_phaseDeltaTempsMs;///millisecondes depuis dernier changement de phase
        static const bool OPTION_FAST;
        static const int DUREE_ACTION_PJ_MS;///millisecondes
        static const int DUREE_ACTION_PNJ_MS;///millisecondes
        static const int IMAGE_PARTIE2_CINEMATIQUE_FIN;

       // static std::vector<Objet*> m_objets;


};

#endif // MODELES_H

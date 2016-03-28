#include "Modeles.h"
#include "Monstre.h"

Royaume Modeles::m_royaume;
Personnage Modeles::m_joueur("joueur");
std::vector<Monstre*> Modeles::m_monstres;


Modeles::Phase Modeles::m_phase(PRET);///TODO = INTRO
bool Modeles::m_nouvellePhase(true);///si la phase vient juste de changer
int Modeles::m_phaseDeltaTempsMs(0);///millisecondes depuis dernier changement de phase
const int Modeles::DUREE_ACTION_PJ_MS(700);///millisecondes
const int Modeles::DUREE_ACTION_PNJ_MS(700);///millisecondes

void Modeles::init()
{
    m_royaume.chargerFichier();
}


void Modeles::updatePhaseIntro()
{
    ///TODO
}

void Modeles::updatePhasePret()
{
    m_phase = ACTION_PJ;
    m_nouvellePhase = true;
    m_phaseDeltaTempsMs = 0;
}

void Modeles::updatePhasePJ()
{
    if (m_phaseDeltaTempsMs >= DUREE_ACTION_PJ_MS)
    {
        m_joueur.executerAction();
        for(unsigned int i=0; i<m_monstres.size(); i++)
        {
            m_monstres.at(i)->appliquerIA();
        }
        m_phase = ACTION_PNJ;
        m_nouvellePhase = true;
        m_phaseDeltaTempsMs = 0;
    }
}

void Modeles::updatePhasePNJ()
{
    if (m_monstres.size() == 0 ||
        m_phaseDeltaTempsMs >= DUREE_ACTION_PNJ_MS)
    {
        for(unsigned int i=0; i<m_monstres.size(); i++)
        {
            m_monstres.at(i)->executerAction();
        }
        m_nouvellePhase = true;
        m_phaseDeltaTempsMs = 0;
        if(m_joueur.getMourant())
        {
            m_phase = GAME_OVER;
        }
        else
        {
            m_phase = PRET;
        }
    }
}

void Modeles::updatePhaseFin()
{
    ///TODO
}

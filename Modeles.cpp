#include "Modeles.h"
#include "Monstre.h"

Royaume Modeles::m_royaume;
Personnage Modeles::m_joueur("joueur");
//std::vector<Monstre*> Modeles::m_monstres;
Cinematique Modeles::m_cinematiqueIntro;
Cinematique Modeles::m_cinematiqueFin;

Modeles::Phase Modeles::m_phase(INTRO);
bool Modeles::m_nouvellePhase(true);///si la phase vient juste de changer
int Modeles::m_phaseDeltaTempsMs(0);///millisecondes depuis dernier changement de phase
const int Modeles::DUREE_ACTION_PJ_MS(400);///millisecondes
const int Modeles::DUREE_ACTION_PNJ_MS(400);///millisecondes

void Modeles::init()
{
    m_royaume.chargerFichier();
}

std::vector<Monstre*>& Modeles::getMonstres()
{
    return m_royaume.getZoneCourante()->m_monstres;
}

std::vector<Objet*>& Modeles::getObjets()
{
    return m_royaume.getZoneCourante()->m_objet;
}

int Modeles::getNumZoneCourant()
{
    return m_royaume.m_zoneCourante;
}

void Modeles::updatePhasePret()
{
    m_phase = ACTION_PJ;
    m_nouvellePhase = true;
    m_phaseDeltaTempsMs = 0;
}

void Modeles::updatePhasePJ()
{
    m_joueur.setPosition(m_joueur.getPosition().getPositionX(), m_joueur.getPosition().getPositionY());
    if (m_phaseDeltaTempsMs >= DUREE_ACTION_PJ_MS)
    {
        m_joueur.executerAction();

        int joueurX = m_joueur.getPosition().getPositionX();
        int joueurY = m_joueur.getPosition().getPositionY();
        Case& caseJoueur = m_royaume.get(joueurX, joueurY);
        Destination* d = caseJoueur.m_destination;
        if(d != 00)
        {
            //changement de zone
            m_royaume.placerPersonnage(joueurX, joueurY, 00);
            m_royaume.m_zoneCourante = d->m_numZone;
            m_joueur.setPosition(d->m_x, d->m_y);
            m_royaume.placerPersonnage(d->m_x, d->m_y, &m_joueur);

            //ne pas laisser les PNJ agir, retourner en phase PRET
            m_phase = PRET;
            m_nouvellePhase = true;
            m_phaseDeltaTempsMs = 0;
            return;
        }
        for(unsigned int i=0; i<getMonstres().size(); i++)
        {
            getMonstres().at(i)->appliquerIA();
        }
        m_phase = ACTION_PNJ;
        m_nouvellePhase = true;
        m_phaseDeltaTempsMs = 0;
    }
}

void Modeles::updatePhasePNJ()
{
    if (getMonstres().size() == 0 ||
        m_phaseDeltaTempsMs >= DUREE_ACTION_PNJ_MS)
    {
        for(unsigned int i=0; i<getMonstres().size(); i++)
        {
            getMonstres().at(i)->executerAction();
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

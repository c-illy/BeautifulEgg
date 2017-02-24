#include "Modeles.h"
#include "Monstre.h"
#include <fstream>
#include <stdlib.h>

Royaume Modeles::m_royaume;
Personnage Modeles::m_joueur("joueur");
//std::vector<Monstre*> Modeles::m_monstres;
Cinematique Modeles::m_cinematiqueIntro;
Cinematique Modeles::m_cinematiqueFin;

Modeles::Phase Modeles::m_phase(INTRO);
bool Modeles::m_nouvellePhase(true);///si la phase vient juste de changer
int Modeles::m_phaseDeltaTempsMs(0);///millisecondes depuis dernier changement de phase
const bool Modeles::OPTION_FAST((std::ifstream("fast")).good());
const int Modeles::DUREE_ACTION_PJ_MS(OPTION_FAST? 200 : 500);///millisecondes
const int Modeles::DUREE_ACTION_PNJ_MS(OPTION_FAST? 200 : 500);///millisecondes
const int Modeles::IMAGE_PARTIE2_CINEMATIQUE_FIN(1);

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
        if(caseJoueur.m_finJeu)
        {
            Modeles::m_phase = Modeles::FIN;
            Modeles::m_nouvellePhase = true;
            Modeles::m_phaseDeltaTempsMs = 0;
        }
        else
        {
            Destination* d = caseJoueur.m_destination;
            if(d != 00)
            {
                //changement de zone
                m_royaume.placerPersonnage(joueurX, joueurY, 00);
                m_royaume.m_zoneCourante = d->m_numZone;

                const Zone* nouvZone = m_royaume.getZoneCourante();
                //avancer une case après destination
                const Case* caseDestination = nouvZone->cheminVersCentre(d->m_x, d->m_y);
                int nouvX = caseDestination->getPosition().getPositionX();
                int nouvY = caseDestination->getPosition().getPositionY();
                m_joueur.setPosition(nouvX, nouvY);
                m_royaume.placerPersonnage(nouvX, nouvY, &m_joueur);

                //ne pas laisser les PNJ agir, retourner en phase PRET
                m_phase = PRET;
                m_nouvellePhase = true;
                m_phaseDeltaTempsMs = 0;
                return;
            }
            if(getMonstres().size() > 0)
            {
                for(unsigned int i=0; i<getMonstres().size(); i++)
                {
                    getMonstres().at(i)->appliquerIA();
                }
                m_phase = ACTION_PNJ;
            }
            else
            {
                m_phase = PRET;
            }
            m_nouvellePhase = true;
            m_phaseDeltaTempsMs = 0;
        }
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

const Case* Modeles::chemin(const Position& depart, const Position& direction, const Zone* zone)
{
    int x0 = depart.getPositionX();
    int y0 = depart.getPositionY();
	int dirX = direction.getPositionX();
	int dirY = direction.getPositionY();
	int resDX = 1;
	int resDY = 1;
	bool plutotX = abs(dirX) >= abs(dirY);

    if(dirX < 0)
    {
        resDX = -1;
    }
    if(dirY < 0)
    {
        resDY = -1;
    }

	if(plutotX)
	{
	    if(zone->get(x0+resDX,y0).navigableEtLibre())
            return &(zone->get(x0+resDX, y0));
	    if(zone->get(x0, y0+resDY).navigableEtLibre())
            return &(zone->get(x0, y0+resDY));
	    if(zone->get(x0, y0-resDY).navigableEtLibre())
            return &(zone->get(x0, y0-resDY));
	}
	else //plutôt y
    {
        if(zone->get(x0, y0+resDY).navigableEtLibre())
            return &(zone->get(x0, y0+resDY));
        if(zone->get(x0+resDX, y0).navigableEtLibre())
            return &(zone->get(x0+resDX, y0));
        if(zone->get(x0-resDX, y0).navigableEtLibre())
            return &(zone->get(x0-resDX, y0));
    }

    return 00;
}


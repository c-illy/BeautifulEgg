#include "Monstre.h"
#include "Modeles.h"
#include "Position.h"
#include "Objet.h"
#include <stdlib.h>

Monstre::Monstre(std::string nom, int x, int y) :
    Personnage(nom, x, y), m_rayonIA(20),
    m_isBoss(false)
{
    m_sante = 40;
    m_santeMax = 40;
    m_degats = 10;
}

Monstre::~Monstre()
{
}

void Monstre::setBoss()
{
    m_isBoss = true;
    m_sante = 200;
    m_santeMax = 200;
    m_degats = 10;
}

void Monstre::setTuto()
{
    m_sante = 20;
    m_santeMax = 20;
    m_degats = 10;
}

Action Monstre::choisirDeplacement(const Position* direction)
{
    if(m_isBoss)
    {
        //arbitraire : le boss ne se déplace pas
        return RIEN;
    }

    const Case* nouvCaseCible = Modeles::chemin(
        m_position, *direction, Modeles::m_royaume.getZoneCourante());
    if(nouvCaseCible != 00)
    {
        setCaseCible(nouvCaseCible);
        return DEPLACER;
    }
    return RIEN;
}

void Monstre::perdreSante(int degats)
{
    Personnage::perdreSante(degats);

    //loot éventuel
    if(m_mourant)
    {
        int x = m_position.getPositionX();
        int y = m_position.getPositionY();
        Case& c = Modeles::m_royaume.get(x, y);
        Zone* zone = Modeles::m_royaume.getZoneCourante();
        int r = rand() % 100;
        if(c.getObjet() == 00 && r<30)
        {
            Objet* objetACreer = new Objet(Objet::SANTE, x, y, zone);
            c.setObjet(objetACreer);
            zone->m_objet.push_back(objetACreer);
        }
    }
}

void Monstre::appliquerIA()
{
    if(m_sante <= 0) //mort
    {
        setAction(RIEN);
        return;
    }

	int joueurX=(Modeles::m_joueur.getPosition().getPositionX());
	int joueurY=(Modeles::m_joueur.getPosition().getPositionY());
	const Case* joueur = &(Modeles::m_royaume.get(joueurX,joueurY));
	Position jp = joueur->getPosition();
	Position p = getPosition();
	double dist = p.distance(jp);

	if (dist == 1)
	{
		setCaseCible(joueur);
		setAction(ATTAQUER);
	}
	else if ((dist < m_rayonIA) && (dist > 1))
	{
		Position direction(joueurX - p.getPositionX(), joueurY - p.getPositionY());
		Action action = choisirDeplacement(&direction);
		setAction(action);//DEPLACER ou RIEN
	}
}


#include "Monstre.h"
#include "Modeles.h"
#include "Position.h"
#include "Objet.h"
#include <stdlib.h>

Monstre::Monstre(std::string nom, int x, int y) :
    Personnage(nom, x, y), m_rayonIA(20),
    m_isBoss(false)
{
    m_sante = 40;//debug!
    m_santeMax = 40;//debug!
    m_degats = 10;//debug!
}

Monstre::~Monstre()
{
}

void Monstre::setBoss()
{
    m_isBoss = true;
    m_sante = 300;//debug!
    m_santeMax = 300;//debug!
    m_degats = 10;//debug!
}

Action Monstre::choisirDeplacement(const Position* direction)
{
    if(m_isBoss)
    {
        //arbitraire : le boss ne se déplace pas
        return RIEN;
    }

	const Royaume& royaume = (Modeles::m_royaume);

	int resX = getPosition().getPositionX();
	int resY = getPosition().getPositionY();
	int dirX = direction->getPositionX();
	int dirY = direction->getPositionY();

	if ((dirX > 0) and (royaume.get(resX+1,resY).navigableEtLibre()))
	{
		setCaseCible(&(royaume.get(resX+1,resY)));
		return DEPLACER;
	}
	if ((dirX < 0) and (royaume.get(resX-1, resY).navigableEtLibre()))
	{
		setCaseCible(&(royaume.get(resX-1,resY)));
		return DEPLACER;
	}
	if ((dirY > 0) and (royaume.get(resX, resY+1).navigableEtLibre()))
	{
		setCaseCible(&(royaume.get(resX,resY+1)));
		return DEPLACER;
	}
	if ((dirY < 0) and (royaume.get(resX, resY-1).navigableEtLibre()))
	{
		setCaseCible(&(royaume.get(resX,resY-1)));
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


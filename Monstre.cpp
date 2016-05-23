#include "Monstre.h"
#include "Modeles.h"
#include "Position.h"

Monstre::Monstre(std::string nom, int x, int y) : Personnage(nom, x, y), m_rayonIA(20)
{
    m_sante = 40;//debug!
    m_degats = 10;//debug!
}

Action Monstre::choisirDeplacement(const Position* direction)
{
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


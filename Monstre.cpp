#include "Monstre.h"
#include "Modeles.h"
#include "Position.h"

Monstre::Monstre(std::string nom, int x, int y) : Personnage(nom, x, y), m_rayonIA(20)
{
}

void Monstre::choisirDeplacement(const Position* direction)
{
	const Royaume& royaume = (Modeles::m_royaume);

	int resX = getPosition().getPositionX();
	int resY = getPosition().getPositionY();
	int dirX = direction->getPositionX();
	int dirY = direction->getPositionY();

	if ((dirX > 0) and (royaume.get(resX+1,resY).navigable()))
	{
		setCaseCible(&(royaume.get(resX+1,resY)));
	}
	if ((dirX < 0) and (royaume.get(resX-1, resY).navigable()))
	{
		setCaseCible(&(royaume.get(resX-1,resY)));
	}
	if ((dirY > 0) and (royaume.get(resX, resY+1).navigable()))
	{
		setCaseCible(&(royaume.get(resX,resY+1)));
	}
	if ((dirY < 0) and (royaume.get(resX, resY+1).navigable()))
	{
		setCaseCible(&(royaume.get(resX,resY-1)));
	}
}

void Monstre::appliquerIA()
{

	int joueurX=(Modeles::m_joueur.getPosition().getPositionX());
	int joueurY=(Modeles::m_joueur.getPosition().getPositionY());
	const Case* joueur = &(Modeles::m_royaume.get(joueurX,joueurY));
	Position jp = joueur->getPosition();
	Position p = getPosition();
	double dist = p.distance(jp);


	std::cout << "x:" << p.getPositionX() << "; y:" << p.getPositionY() << std::endl;
	if (dist == 1)
	{
		setCaseCible(joueur);
		setAction(ATTAQUER);
	}
	else if ((dist < m_rayonIA) && (dist > 1))
	{
		Position direction(joueurX - p.getPositionX(), joueurY - p.getPositionY());
		choisirDeplacement(&direction);
		setAction(DEPLACER);
	}
}


#include "Monstre.h"
#include "Modeles.h"

Monstre::Monstre() : m_rayonIA(20)
{

}



void Monstre::choisirDeplacement(vecteur direction)
{
	//Case* newPos = pos;

	const Royaume& royaume = (Modeles::m_royaume);


	int resX=getPosition().getPositionX();
	int resY=getPosition().getPositionY();




	if ((direction[0] > 0) and (royaume.get(resX+1,resY).navigable()))
	{
		setCaseCible(&(royaume.get(resX+1,resY)));
	}
	if ((direction[0] < 0) and (royaume.get(resX-1, resY).navigable()))
	{
		setCaseCible(&(royaume.get(resX-1,resY)));
	}
	if ((direction[1] > 0) and (royaume.get(resX, resY+1).navigable()))
	{
		setCaseCible(&(royaume.get(resX,resY+1)));
	}
	if ((direction[1] < 0) and (royaume.get(resX, resY+1).navigable()))
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


	if (dist == 1)
	{
		setCaseCible(joueur);
		setAction(ATTAQUER);
	}
	else if ((dist < m_rayonIA) && (dist > 1))
	{
		vecteur direction(joueurX - p.getPositionX(), joueurY - p.getPositionY());
		choisirDeplacement(direction);
		setAction(DEPLACER);
	}
}


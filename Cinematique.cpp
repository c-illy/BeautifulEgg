#include <string>
#include "Cinematique.h"

Cinematique::Cinematique() :
	m_nombreImages(0),
	m_imageCourante(0)//,
	//m_dossierImages(dossier)
{}

void Cinematique::setNbImages(int nb)
{
    m_nombreImages = nb;
}

void Cinematique::allerImageSuivante()
{
	m_imageCourante++;
}

bool Cinematique::estTerminee() const
{
	return m_imageCourante >= m_nombreImages;
}

int Cinematique::getImageCourante() const
{
	return m_imageCourante;
}

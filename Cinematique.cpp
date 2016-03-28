#include <string>
#include "Cinematique.h"

Cinematique::Cinematique(const std::string &dossier, int nbImages) :
	m_nombreImages(nbImages),
	m_imageCourante(0),
	m_dossierImages(dossier)
{}

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

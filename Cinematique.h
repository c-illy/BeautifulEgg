#ifndef CINEMATIQUE_H
#define CINEMATIQUE_H

#include <string>


class Cinematique
{
	private:
		int m_nombreImages;
		int m_imageCourante;
		//std::string m_dossierImages;

	public:
		Cinematique();
		void setNbImages(int nb);
		void allerImageSuivante();
		bool estTerminee() const;
		int getImageCourante() const;
};

#endif

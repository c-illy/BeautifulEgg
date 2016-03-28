#include <string>


class Cinematique
{
	private:
		int m_nombreImages;
		int m_imageCourante;
		std::string m_dossierImages;
	
	public:
		Cinematique(const std::string &dossier, int nbImages);
		void allerImageSuivante();
		bool estTerminee() const;
		int getImageCourante() const;
};

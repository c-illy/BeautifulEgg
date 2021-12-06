#ifndef ZONE_H
#define ZONE_H

#include <vector>
#include "Case.h"
class Monstre;
class Objet;

class Zone
{
	private:

		/// liste des colonnes
		 std::vector<std::vector<Case*> > m_cases;

    public:
		 std::vector<Monstre*> m_monstres;
		 std::vector<Objet*> m_objet;
		 bool m_secretZone;
		 bool m_bossZone;

	public:
		Zone(int x, int y);
		virtual ~Zone();

		//void chargerFichier();

		Case& get(int i, int j);
		const Case& get(int i, int j) const;

		void set(int i, int j, Case* nouvCase);

		int getLargeur() const;
		int getHauteur() const;

		const Case* cheminVersCentre(int x0, int y0) const;
        bool monstrePopable(int x, int y) const;

        void debug() const;

};

#endif // ZONE_H

#include <vector>
#include "Case.h"

class Zone
{
	private:

		/// liste des colonnes
		 std::vector<std::vector<Case*> > m_cases;

	public:
		Zone(int x, int y);
		virtual ~Zone();

		void chargerFichier();

		Case& get(int i, int j);
		const Case& get(int i, int j) const;

		void set(int i, int j, Case* nouvCase);

		int getLargeur() const;
		int getHauteur() const;
};

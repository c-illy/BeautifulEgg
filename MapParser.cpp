#include "MapParser.h"
#include "tinydir.h"
#include "Vues.h"
#include "ZoneView.h"
#include "Monstre.h"

const std::map<sf::Uint32, MapParser::CaseType> MapParser::code =
{ {sf::Color(255, 255, 255).toInteger(), Mur  },
  {sf::Color(0, 0, 0).toInteger(), Vide  },
  {sf::Color(1, 1, 1).toInteger(), Joueur  },
  {sf::Color(255, 0, 0).toInteger(), Monstre1  } };

void MapParser::initZonesFromFiles()
{
    std::string racineZones("./zones");

    std::cout << "ouverture dossier zones" << std::endl;
    tinydir_dir dir;
    tinydir_open(&dir, racineZones.c_str());

    while(dir.has_next)
    {
        tinydir_file file;
        tinydir_readfile(&dir, &file);

        if (file.is_dir && file.name[0]!='.')
        {
            std::string chemin = racineZones + "/" + file.name;
            std::cout << chemin << std::endl;
            parseAndInit(chemin, TAILLE_CASE_X, TAILLE_CASE_Y);
        }

        tinydir_next(&dir);
    }
    tinydir_close(&dir);
}

void MapParser::parseAndInit(const std::string& cheminZone,
                             unsigned int width,
                             unsigned int height)
{
    sf::Image grid;
    grid.loadFromFile(cheminZone + "/" + "grid.png");
	unsigned x = width  / 2;
	unsigned y = height / 2;
	unsigned nLine   = grid.getSize().x / width;
	unsigned nColumn = grid.getSize().y / height;
	Zone* zone = new Zone(nLine, nColumn);

	for(unsigned j=0; j<nColumn; ++j) {
		for(unsigned i=0; i<nLine; ++i) {
			sf::Color color = grid.getPixel(x + i*width,
			                                y + j*height);
            sf::Uint32 colorCode = color.toInteger();

            std::map<sf::Uint32, MapParser::CaseType>::const_iterator it = code.find(colorCode);
            if(it != code.end())
            {
                CaseType caseType = it->second;
                initCase(zone, caseType, i, j);
            }
            else
            {
                std::cerr << "Erreur : Couleur inconnue lors du chargement (" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ")" << std::endl;
            }
		}
	}
	Modeles::m_royaume.ajouterZone(zone);
	Vues::m_zoneViews.push_back(ZoneView());
	Vues::m_zoneViews.at(Vues::m_zoneViews.size()-1).init(cheminZone);
}

void MapParser::initCase(Zone* zone, CaseType type, unsigned x, unsigned y)
{
	Monstre* monstreACreer;
	switch(type)
	{
	case Vide:
		zone->set(x, y, new Case(false,    // no navigable
		                         nullptr, // no personnage
                                 x,
                                 y));
		break;
	case Mur:
		zone->set(x, y, new Case(true,       // navigable
                                 nullptr,   // no personnage
                                 x,
                                 y));
		break;
	case Joueur:
		Modeles::m_joueur.setPosition(x, y);
		zone->set(x, y, new Case(true,
                                 &Modeles::m_joueur,
                                 x,
                                 y));
		break;
	case Monstre1:
		std::cout << "Ajout d'un monstre" << std::endl;
		monstreACreer = new Monstre("monstre1", x, y);
		Modeles::m_monstres.push_back(monstreACreer);
		zone->set(x, y, new Case(true,
                                 monstreACreer,
                                 x,
                                 y));
		break;
	default:
		std::cerr << "Erreur : Type de case inconnue." << std::endl;
		break;
	}
}


#include "MapParser.h"

const std::map<sf::Uint32, MapParser::CaseType> MapParser::code =
{ {sf::Color(255, 255, 255).toInteger(), Empty  },
  {sf::Color(0, 0, 0).toInteger(), Wall  },
  {sf::Color(1, 1, 1).toInteger(), Wall  } };

void MapParser::initZonesFromFiles()
{
    sf::Image img;
    img.loadFromFile("zone_debug.png");
    parseAndInit(img, TAILLE_CASE_X, TAILLE_CASE_Y);
}

void MapParser::parseAndInit(const sf::Image& grid,
                             unsigned int width,
                             unsigned int height)
{
	unsigned x = width  / 2;
	unsigned y = height / 2;
	unsigned nLine   = grid.getSize().x / width;
	unsigned nColumn = grid.getSize().y / height;
	Zone* zone = new Zone(nLine, nColumn);




	for(auto e : code)
    {
        std::cout << e.first << " -> " << e.second << std::endl;
    }




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
                std::cerr << "Erreur : Couleur inconnue lors du chargement (" << color.r << ", " << color.g << ", " << color.b << ")" << std::endl;
            }
		}
	}
	Modeles::m_royaume.ajouterZone(zone);
}

void MapParser::initCase(Zone* zone, CaseType type, unsigned x, unsigned y)
{
	switch(type)
	{
	case Empty:
		zone->set(x, y, new Case(false,    // no navigable
		                         nullptr, // no personnage
                                 x,
                                 y));
		break;
	case Wall:
		zone->set(x, y, new Case(true,       // navigable
                                 nullptr,   // no personnage
                                 x,
                                 y));
		break;
	}
}
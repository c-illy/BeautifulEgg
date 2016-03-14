#include "MapParser.h"

const std::map<sf::Color, MapParser::CaseType> MapParser::code =
{ {sf::Color::Red, Empty  },
  {sf::Color::Blue, Wall  } };

void MapParser::parseAndInit(const sf::Image& grid,
                             unsigned int width,
                             unsigned int height)
{
	unsigned x = width  / 2;
	unsigned y = height / 2;
	unsigned nLine   = grid.getSize().x / width;
	unsigned nColumn = grid.getSize().y / height;

	for(unsigned j=0; j<nColumn; ++j) {
		for(unsigned i=0; i<nLine; ++i) {
			sf::Color color = grid.getPixel(x + i*width,
			                                y + j*height);
			init(code.at(color), x + i*width, y + j*height);

		}
	}
}

void MapParser::init(CaseType type, unsigned x, unsigned y)
{
	switch(type)
	{
	case Empty:
		Modeles::m_royaume.set(Case(false,     // no navigable
		                           nullptr,   // no personnage
		                           nullptr),  // no object
		                      x,
		                      y);
		break;
	case Wall:
		Modeles::m_royaume.set(Case(true,       // navigable
		                           nullptr,    // no personnage
		                           nullptr),   // no object
		                      x,
		                      y);
		break;
	}
}


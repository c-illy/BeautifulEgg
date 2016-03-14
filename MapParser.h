#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <map>
#include <SFML/Graphics.hpp>
#include "Modeles.h"

class MapParser
{
public:
	enum CaseType
	{
		Empty,
		Wall,
	};

	static void parseAndInit(const sf::Image& grid,
	                         unsigned width,
	                         unsigned height);
private:
	static void init(CaseType type, unsigned x, unsigned y);

	static const std::map<sf::Uint32, CaseType> code;

};


#endif // MAPPARSER_H

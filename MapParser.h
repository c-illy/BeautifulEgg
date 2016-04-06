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
		Vide,
		Mur,
		Joueur
	};

	static void initZonesFromFiles();

private:
	static void parseAndInit(const sf::Image& grid,
	                         unsigned width,
	                         unsigned height);
	static void initCase(Zone* zone, CaseType type, unsigned x, unsigned y);

	static const std::map<sf::Uint32, CaseType> code;

};


#endif // MAPPARSER_H

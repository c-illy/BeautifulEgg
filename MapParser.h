#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <map>
#include <SFML/Graphics.hpp>
#include "Modeles.h"
class Cinematique;
class CinematiqueView;

class MapParser
{
public:
	enum CaseType
	{
		Vide,
		Mur,
		Joueur,
		Monstre1,
		ObjetSante,
		BonusDegats,
		Objet2,
		Obstacle0,
		FinJeu
	};

	static void initZonesFromFiles();


    //pour initialisation et stockage
    static std::map<sf::Uint32, std::pair<Destination, Destination> > m_portails;

private:
	static void parseAndInit(
                          const std::string& cheminZone,
                          unsigned width,
                          unsigned height);
	static void initCase(Zone* zone, CaseType type, unsigned x, unsigned y);
	static void initCasePortail(Zone* zone, sf::Uint32 colorCode, unsigned x, unsigned y);
	static void initCinematique(Cinematique* cinematique, CinematiqueView* cinematiqueView, const char* dossier);


	static const std::map<sf::Uint32, CaseType> code;

};


#endif // MAPPARSER_H

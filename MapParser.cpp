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

std::map<sf::Uint32, std::pair<Destination, Destination> > MapParser::m_portails;

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

    //v�rification debug:
    std::cout << "## portails trouv�s : ##" << std::endl;
    std::map<sf::Uint32, std::pair<Destination, Destination> >::iterator it;
    for(it=m_portails.begin(); it!=m_portails.end(); it++)
    {
        std::cout << " " << it->first << "=>[ (zone:" <<
            it->second.first.m_numZone << " \tx:" << it->second.first.m_x << " \ty:" << it->second.first.m_y <<
            ") ~ (zone:" <<
            it->second.second.m_numZone << " \tx:" << it->second.second.m_x << " \ty:" << it->second.second.m_y <<
            ") ]\n";
    }
    std::cout << "## (fin portails) ##" << std::endl;

}

void MapParser::parseAndInit(const std::string& cheminZone,
                             unsigned int width,
                             unsigned int height)
{
    unsigned int nouvNumZone = Modeles::m_royaume.m_zones.size();

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
                //std::cout << "Couleur de portail (" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ")" << std::endl;
                initCasePortail(zone, colorCode, i, j);
            }
		}
	}
	Modeles::m_royaume.ajouterZone(zone);
	Vues::m_zoneViews.push_back(ZoneView());
	Vues::m_zoneViews.at(nouvNumZone).init(cheminZone);
    Vues::m_personnagesViewParZone.push_back(new PersonnagesView());
    Vues::m_personnagesViewParZone.at(nouvNumZone)->init(zone);
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
        //d�signer la zone courante comme la zone de d�part du jeu :
        Modeles::m_royaume.m_zoneCourante = Modeles::m_royaume.m_zones.size();
		break;
	case Monstre1:
		std::cout << "Ajout d'un monstre" << std::endl;
		monstreACreer = new Monstre("monstre1", x, y);
		zone->m_monstres.push_back(monstreACreer);
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

void MapParser::initCasePortail(Zone* zone, sf::Uint32 colorCode, unsigned x, unsigned y)
{
    Case* newCase = new Case(true,    // no navigable
                             nullptr, // no personnage
                             x,
                             y);
    std::map<sf::Uint32, std::pair<Destination, Destination> >::iterator it;
    it = m_portails.find(colorCode);
    Destination here;
    here.m_numZone = Modeles::m_royaume.m_zones.size();
    here.m_x = x;
    here.m_y = y;
    if(it != m_portails.end())
    {
        std::pair<Destination, Destination>& portail = it->second;
        //le portail a �t� trouv�, donc son 1er bout existe d�j� (portail.first)
        //reste � fixer le 2� bout (portail.second):
        portail.second = here;

        //ensuite, remplir le champ m_destination des vraies cases
        newCase->m_destination = &(portail.first);//risque de r�allocation??

        Destination there = portail.first;
        Zone* zoneCible = zone;
        if(there.m_numZone < (int)Modeles::m_royaume.m_zones.size())
        {
            zoneCible = Modeles::m_royaume.m_zones.at(there.m_numZone);
        }
        //else : ok, zone courante pas encore ajout�e � m_royaume.m_zones
        Case& oldCase = zoneCible->get(there.m_x, there.m_y);
        oldCase.m_destination = &(portail.second);
    }
    else
    {
        //nouveau portail pas encore connu
        std::pair<Destination, Destination> newPortail;
        newPortail.first = here;
        m_portails[colorCode] = newPortail;

        //on ne peut pas encore remplir le champ m_destination de newCase, cf. ci-dessus
    }
    zone->set(x, y, newCase);
}


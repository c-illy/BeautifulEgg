#include "MapParser.h"
#include "tinydir.h"
#include "Vues.h"
#include "ZoneView.h"
#include "Monstre.h"
#include "Objet.h"
#include "ObjetsView.h"
#include "Cinematique.h"
#include "CinematiqueView.h"
#include <sstream>

const std::map<sf::Uint32, MapParser::CaseType> MapParser::code =
{ {sf::Color(255, 255, 255).toInteger(), Vide  },
  {sf::Color(0, 0, 0).toInteger(), Mur  },
  {sf::Color(1, 1, 1).toInteger(), Joueur  },
  {sf::Color(255, 0, 0).toInteger(), Monstre1  },
  {sf::Color(100, 0, 0).toInteger(), Objet0  },
  {sf::Color(100, 0, 50).toInteger(), Objet1  },
  {sf::Color(100, 0, 100).toInteger(), Objet2  } };

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

    //vérification debug:
    std::cout << "## portails trouvés : ##" << std::endl;
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

    // CINEMATIQUES
    initCinematique(&Modeles::m_cinematiqueIntro, &Vues::m_cinematiqueViewIntro, "./intro");
    initCinematique(&Modeles::m_cinematiqueFin, &Vues::m_cinematiqueViewFin, "./fin");

    //TEXTURES OBJETS
    std::string texFichiers[] = { "sante.png", "arme.png", "bouton.png" };
    std::string objRacine("./objets/");
    for(int i=0; i<Objet::NB_OBJETS_ID; i++)
    {
        Objet::ObjetID id = (Objet::ObjetID) i;
        Vues::m_objetsView.addTexture(id, objRacine + texFichiers[i]);
    }
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
    Case* caseACreer = 00;
	Monstre* monstreACreer = 00;
	Objet* objetACreer = 00;
	switch(type)
	{
	case Vide:
	    caseACreer = new Case(true,    // no navigable
                             nullptr, // no personnage
                             x,
                             y);
		break;
	case Mur:
	    caseACreer = new Case(false, nullptr, x, y);
		break;
	case Joueur:
		Modeles::m_joueur.setPosition(x, y);
		caseACreer = new Case(true, &Modeles::m_joueur, x, y);
        //désigner la zone courante comme la zone de départ du jeu :
        Modeles::m_royaume.m_zoneCourante = Modeles::m_royaume.m_zones.size();
		break;
	case Monstre1:
		std::cout << "Ajout d'un monstre" << std::endl;
		monstreACreer = new Monstre("monstre1", x, y);
		zone->m_monstres.push_back(monstreACreer);
		caseACreer = new Case(true, monstreACreer, x, y);
		break;
	case Objet0:
		std::cout << "Ajout d'un Objet0" << std::endl;
		objetACreer = new Objet(Objet::BIDON_DEBUG_0, x, y, zone);
		caseACreer = new Case(true, 00, x, y, objetACreer);
		zone->m_objet.push_back(objetACreer);
		break;
	case Objet1:
		std::cout << "Ajout d'un Objet1" << std::endl;
		objetACreer = new Objet(Objet::BIDON_DEBUG_1, x, y, zone);
		caseACreer = new Case(true, 00, x, y, objetACreer);
		zone->m_objet.push_back(objetACreer);
		break;
	case Objet2:
		std::cout << "Ajout d'un Objet2" << std::endl;
		objetACreer = new Objet(Objet::BIDON_DEBUG_LEVIER_1, x, y, zone);
		caseACreer = new Case(false, 00, x, y, objetACreer);
		zone->m_objet.push_back(objetACreer);
		Objet::m_bidonLevier2 = objetACreer;
		break;
	default:
		std::cerr << "Erreur : Type de case inconnue." << std::endl;
		break;
	}

    zone->set(x, y, caseACreer);
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
        //le portail a été trouvé, donc son 1er bout existe déjà (portail.first)
        //reste à fixer le 2è bout (portail.second):
        portail.second = here;

        //ensuite, remplir le champ m_destination des vraies cases
        newCase->m_destination = &(portail.first);//risque de réallocation??

        Destination there = portail.first;
        Zone* zoneCible = zone;
        if(there.m_numZone < (int)Modeles::m_royaume.m_zones.size())
        {
            zoneCible = Modeles::m_royaume.m_zones.at(there.m_numZone);
        }
        //else : ok, zone courante pas encore ajoutée à m_royaume.m_zones
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

void MapParser::initCinematique(Cinematique* cinematique, CinematiqueView* cinematiqueView, const char* dossier)
{
    tinydir_dir dir;
    tinydir_open(&dir, dossier);
    int nbImages = 0;
    while(dir.has_next)
    {
        tinydir_file file;
        tinydir_readfile(&dir, &file);
        if (!file.is_dir && file.name[0]!='T')
        {
            nbImages++;
        }
        tinydir_next(&dir);
    }
    tinydir_close(&dir);
    std::cout << "nb images cinematique " << dossier << " : " << nbImages << std::endl;
    cinematique->setNbImages(nbImages);
    cinematiqueView->m_cinematique = cinematique;
    for(int i=0; i<nbImages; i++)
    {
        std::stringstream s;
        s << dossier << "/" << i << ".png";

        cinematiqueView->m_tex_images.push_back(sf::Texture());
        cinematiqueView->m_tex_images.at(i).loadFromFile(s.str());
    }
}


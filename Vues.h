#ifndef VUES_H
#define VUES_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "RoyaumeView.h"
#include "IHMView.h"
#include "PersonnagesView.h"
#include "ObjetsView.h"
#include "ZoneView.h"
#include "CinematiqueView.h"

enum Musique
{
    PRINCIPALE
};

enum Son
{
    TEST
};

class Vues
{
    public:
        static void init();
        static void update(sf::Time deltaTemps);
        static void draw();

        static sf::Vector2f positionToVect2f(const Position& position);
        static sf::Vector2f getPersonnageSFPosition(const Personnage& personnage);
//        static Position vect2fToPosition(const sf::Vector2f& vect);

        static void jouerMusique(Musique musique);
        static void jouerSon(Son son);

    public:
        static RoyaumeView m_royaumeView;
        static std::vector<ZoneView> m_zoneViews;
        static IHMView m_IHMView;
        static std::vector<PersonnagesView*> m_personnagesViewParZone;//1 instance par zone
        static ObjetsView m_objetsView;
        static CinematiqueView m_cinematiqueViewIntro;
        static CinematiqueView m_cinematiqueViewFin;
        static sf::Music m_musique;
        static const std::map<Musique, std::string> m_nomsMusiques;
        static std::map<Son, sf::Sound>m_sons;

        static sf::RenderWindow m_window;
};

#endif // VUES_H

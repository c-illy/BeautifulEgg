#ifndef VUES_H
#define VUES_H

#include <SFML/Graphics.hpp>

#include "RoyaumeView.h"
#include "IHMView.h"
#include "PersonnagesView.h"
#include "ObjetsView.h"
#include "ZoneView.h"
#include "CinematiqueView.h"

class Vues
{
    public:
        static void init();
        static void update(sf::Time deltaTemps);
        static void draw();

        static sf::Vector2f positionToVect2f(const Position& position);
        static sf::Vector2f getPersonnageSFPosition(const Personnage& personnage);
//        static Position vect2fToPosition(const sf::Vector2f& vect);

        static bool loadFromFile(sf::Image& im, const std::string& chemin);
        static bool loadFromFile(sf::Texture& t, const std::string& chemin);

    public:
        static RoyaumeView m_royaumeView;
        static std::vector<ZoneView> m_zoneViews;
        static IHMView m_IHMView;
        static std::vector<PersonnagesView*> m_personnagesViewParZone;//1 instance par zone
        static ObjetsView m_objetsView;
        static CinematiqueView m_cinematiqueViewIntro;
        static CinematiqueView m_cinematiqueViewFin;

        static sf::RenderStates mulRenderStates;
        static sf::Sprite spriteEffetParchemin;
        static sf::Texture textureParchemin;

        static sf::RenderWindow m_window;
};

#endif // VUES_H

#ifndef VUES_H
#define VUES_H

#include <SFML/Graphics.hpp>

#include "RoyaumeView.h"
#include "IHMView.h"
#include "PersonnagesView.h"
#include "ZoneView.h"

class Vues
{
    public:
        static void init();
        static void update(sf::Time deltaTemps);
        static void draw();

        static sf::Vector2f positionToVect2f(const Position& position);
        static Position vect2fToPosition(const sf::Vector2f& vect);

    public:
        static RoyaumeView m_royaumeView;
        static std::vector<ZoneView> m_zoneViews;
        static IHMView m_IHMView;
        static std::vector<PersonnagesView*> m_personnagesViewParZone;//1 instance par zone

        static sf::RenderWindow m_window;
};

#endif // VUES_H

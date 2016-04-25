#ifndef ZONEVIEW_H
#define ZONEVIEW_H

#include <SFML/Graphics.hpp>

///textures 1er et arriere plan
class ZoneView
{
    public:
        ZoneView();
        virtual ~ZoneView();

        void init(const std::string& nomDossier);

    protected:

    public:
        sf::Texture m_tex_premierPlan;
        sf::Texture m_tex_dernierPlan;
};

#endif // ZONEVIEW_H

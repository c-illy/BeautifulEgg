#ifndef ROYAUMEVIEW_H
#define ROYAUMEVIEW_H

#include "Vue.h"
#include "Royaume.h"

class RoyaumeView : public Vue
{
    public:
        RoyaumeView(sf::RenderWindow& window);
        virtual ~RoyaumeView();

        sf::Vector2u getTailleDecor() const;

        void update(sf::Time deltaTemps);
        void draw() const;
        void drawPremierPlan() const;

    private:
        sf::Texture m_tex_caseNavigable;
        sf::Texture m_tex_caseNonNavigable;

        sf::Texture m_texPremierPlan;
        sf::Texture m_texDernierPlan;
        sf::Sprite m_spritePremierPlan;
        sf::Sprite m_spriteDernierPlan;

        int m_zoneChargee;
};

#endif // ROYAUMEVIEW_H

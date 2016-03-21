#ifndef ROYAUMEVIEW_H
#define ROYAUMEVIEW_H

#include "Vue.h"
#include "Royaume.h"

class RoyaumeView : public Vue
{
    public:
        RoyaumeView(sf::RenderWindow& window);
        virtual ~RoyaumeView();

        void update(sf::Time deltaTemps);
        void draw() const;

    private:
        sf::Texture m_tex_caseNavigable;
        sf::Texture m_tex_caseNonNavigable;
};

#endif // ROYAUMEVIEW_H

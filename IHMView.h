#ifndef IHMVIEW_H
#define IHMVIEW_H

#include "Vue.h"

#define TAILLE_BARRE_X 100
#define TAILLE_BARRE_Y 10

class IHMView : public Vue
{
    public:
        IHMView(sf::RenderWindow& window);
        virtual ~IHMView();

        void update(sf::Time deltaTemps);
        void draw() const;

    private:
        sf::Texture m_tex_barreDeVieVariable;
        sf::Texture m_tex_barreDeVie;

        sf::RectangleShape m_fond;
};

#endif // IHMVIEW_H

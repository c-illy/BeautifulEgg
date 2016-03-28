#ifndef IHMVIEW_H
#define IHMVIEW_H

#include "Vue.h"

#define TAILLE_BARRE_X 100
#define TAILLE_BARRE_Y 10
#define POS_BARRE_X 50
#define POS_BARRE_Y (TAILLE_FENETRE_Y - TAILLE_BARRE_Y - 50)

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

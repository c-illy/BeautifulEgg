#ifndef ANIMATION_H
#define ANIMATION_H

#include "Vue.h"

class Animation : public Vue
{
    public:
        Animation(sf::RenderWindow& window, std::string nom);
        virtual ~Animation();

        void demarrer();
        void update(sf::Time deltaTemps);
        void draw() const;

    protected:
        const int m_spriteLargeur;
        const int m_spriteHauteur;
        const sf::Time m_tempsIntervalle;
        int m_totalFrames;

        sf::Texture m_texture;
        sf::Sprite m_sprite;

        sf::Clock m_clock;
        int m_frameCourante;

    private:
};

#endif // ANIMATION_H

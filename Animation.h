#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation
{
    public:
        Animation(std::string nom);
        virtual ~Animation();

        void animer(sf::Time deltaTemps);

    protected:
        const int m_spriteLargeur;
        const int m_spriteHauteur;
        const float m_tempsIntervalle;

        sf::Texture m_texture;
        sf::Sprite m_sprite;

        sf::Time m_debutAnimation;
        int m_frameCourante;

    private:
};

#endif // ANIMATION_H

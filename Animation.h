#ifndef ANIMATION_H
#define ANIMATION_H

#include "Vue.h"
#include "Personnage.h"

/*

Joueur  haut   marche  10
Joueur  haut   attaque 8
Joueur  bas    marche  10
Joueur  bas    attaque 8
Joueur  droite marche  10
Joueur  droite attaque 8
Joueur  gauche marche  10
Joueur  gauche attaque 8
Monstre haut   marche  20
Monstre haut   attaque 16
Monstre bas    marche  20
...

*/

class Animation : public Vue
{
    public:
        Animation(sf::RenderWindow& window, const Personnage& personnage);
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

    public:
        const Personnage& m_personnage;

    private:
};

#endif // ANIMATION_H

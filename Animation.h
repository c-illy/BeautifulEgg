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

class AnimationRessource
{
public:
    AnimationRessource();
    void load(const std::string& animationCourante);

    public:
        int m_spriteLargeur;
        int m_spriteHauteur;
        sf::Time m_tempsIntervalle;
        int m_totalFrames;
        sf::Texture m_texture;
};

class Animation : public Vue
{
    public:
        Animation(sf::RenderWindow& window, const Personnage& personnage);
        virtual ~Animation();

        static AnimationRessource* getRessource(const Personnage& personnage);

        void loadAnimation();
        void demarrer();
        void update(sf::Time deltaTemps);
        void draw() const;

    private:
        static  std::map<Action, std::string> m_actions;
        static  std::map<Direction, std::string> m_directions;
        static  std::map<std::string, AnimationRessource> m_ressourcesMap;

        static std::string actionToString(Action act);
        static std::string directionToString(Direction dir);

    protected:
        AnimationRessource* m_animationRessource;
        std::string m_animationCourante;
        sf::Sprite m_sprite;
        float m_echelle;
        sf::Clock m_clock;
        int m_frameCourante;

    public:
        const Personnage& m_personnage;

    private:
};

#endif // ANIMATION_H

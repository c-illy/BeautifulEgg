#ifndef PERSONNAGESVIEW_H
#define PERSONNAGESVIEW_H

#include "Vue.h"
#include "Personnage.h"
#include "Animation.h"

class PersonnagesView : public Vue
{
    public:
        PersonnagesView(sf::RenderWindow& window);
        virtual ~PersonnagesView();

        void init();

        void update(sf::Time deltaTemps);
        void draw() const;
        void drawPersonnage(const Personnage& personnage) const;

    private:
        std::vector<Animation*> m_animations;
};

#endif // PERSONNAGESVIEW_H

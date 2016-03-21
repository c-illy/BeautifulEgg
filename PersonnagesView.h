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

        void update(sf::Time deltaTemps);
        void draw() const;
        void drawPersonnage(const Personnage& personnage) const;

    private:
        Animation m_debug;
};

#endif // PERSONNAGESVIEW_H

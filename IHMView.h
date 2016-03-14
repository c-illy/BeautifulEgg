#ifndef IHMVIEW_H
#define IHMVIEW_H

#include "Vue.h"

class IHMView : public Vue
{
    public:
        IHMView(sf::RenderWindow& window);
        virtual ~IHMView();

        void draw() const;

    private:
        sf::CircleShape m_shape;
};

#endif // IHMVIEW_H

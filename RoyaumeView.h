#ifndef ROYAUMEVIEW_H
#define ROYAUMEVIEW_H

#include "Vue.h"
#include "Royaume.h"

class RoyaumeView : public Vue
{
    public:
        RoyaumeView(sf::RenderWindow& window);
        virtual ~RoyaumeView();

        void draw() const;

    private:
};

#endif // ROYAUMEVIEW_H

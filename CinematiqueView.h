#ifndef CINEMATIQUEVIEW_H
#define CINEMATIQUEVIEW_H
#include "Vue.h"

class Cinematique;

class CinematiqueView : public Vue
{
    public:
        CinematiqueView();
        virtual ~CinematiqueView();

        virtual void update(sf::Time deltaTemps);
        virtual void draw() const;

    public:
        Cinematique* m_cinematique;
        std::vector<sf::Texture> m_tex_images;
};

#endif // CINEMATIQUEVIEW_H

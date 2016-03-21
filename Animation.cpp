#include "Animation.h"

Animation::Animation(std::string nom) :
        m_spriteLargeur(100),
        m_spriteHauteur(100),
        m_tempsIntervalle(40.f)
{
    //ctor
}

Animation::~Animation()
{
    //dtor
}

void Animation::animer(sf::Time deltaTemps)
{

}

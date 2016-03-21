#include "Animation.h"

Animation::Animation(sf::RenderWindow& window, std::string nom) :
    Vue(window),
    m_spriteLargeur(100),
    m_spriteHauteur(100),
    m_tempsIntervalle(sf::milliseconds(100)),
    m_totalFrames(3),
    m_frameCourante(0)
{
    if (!m_texture.loadFromFile(RESSOURCES + nom + ".png"))
    {
        // erreur...
    }

    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0, 0, m_spriteLargeur, m_spriteHauteur));
}

Animation::~Animation()
{
    //dtor
}

void Animation::demarrer()
{
    m_clock.restart();
}

void Animation::update(sf::Time deltaTemps)
{
    sf::Time tempsDepuisDebut = m_clock.getElapsedTime();

    int prochaineFrame = ((int)(tempsDepuisDebut / m_tempsIntervalle)) % m_totalFrames;
    if(m_frameCourante != prochaineFrame)
    {
        m_frameCourante = prochaineFrame;
        m_sprite.setTextureRect(sf::IntRect(m_spriteLargeur * m_frameCourante, 0, m_spriteLargeur, m_spriteHauteur));
    }
}

void Animation::draw() const
{
    m_window.draw(m_sprite);
}

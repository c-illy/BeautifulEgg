#include "Animation.h"
#include "Vues.h"

Animation::Animation(sf::RenderWindow& window, const Personnage& personnage) :
    Vue(window),
    m_spriteLargeur(100),
    m_spriteHauteur(100),
    m_tempsIntervalle(sf::milliseconds(100)),
    m_totalFrames(3),
    m_frameCourante(0),
    m_personnage(personnage)
{
    std::string nomFichier = personnage.getNom() + "_marche_bas.png";
    std::cout << "Ouverture du fichier d'animation " << nomFichier << std::endl;
    m_texture.loadFromFile(RESSOURCES + nomFichier);

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
    sf::Vector2f vect = Vues::positionToVect2f(m_personnage.getPosition());
    vect.x += TAILLE_CASE_X - m_spriteLargeur;
    vect.y += TAILLE_CASE_Y - m_spriteHauteur;
    m_sprite.setPosition(vect);

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

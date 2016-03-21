#include "IHMView.h"
#include "Modeles.h"

IHMView::IHMView(sf::RenderWindow& window) :
    Vue(window), m_fond(sf::Vector2f(TAILLE_BARRE_X, TAILLE_BARRE_Y))
{
    if (!m_tex_barreDeVieVariable.loadFromFile(RESSOURCES "barre_variable.png"))
    {
        // erreur...
    }
    if (!m_tex_barreDeVie.loadFromFile(RESSOURCES "barre.png"))
    {
        // erreur...
    }
    m_fond.setFillColor(sf::Color::Green);
}

IHMView::~IHMView()
{
    //dtor
}

void IHMView::update(sf::Time deltaTemps)
{

}

void IHMView::draw() const
{
    const Personnage& joueur = Modeles::m_joueur;

    sf::Sprite barreDeVieVariable(m_tex_barreDeVieVariable, sf::IntRect(0, 0, 100, 10));
    sf::Sprite barreDeVie(m_tex_barreDeVie);

    m_window.draw(m_fond);
    m_window.draw(barreDeVieVariable);
    m_window.draw(barreDeVie);
}

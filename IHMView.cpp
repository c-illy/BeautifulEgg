#include "IHMView.h"
#include "Modeles.h"
#include "Vues.h"

IHMView::IHMView(sf::RenderWindow& window) :
    Vue(window)
{
    Vues::loadFromFile(m_tex_barreDeVieVariable, RESSOURCES "barre_variable.png");
    Vues::loadFromFile(m_tex_barreDeVie, RESSOURCES "barre.png");
    Vues::loadFromFile(m_tex_gameOver, RESSOURCES "game_over.png");
    //m_fond.setSize(sf::Vector2f(m_tex_barreDeVie.getSize().x, m_tex_barreDeVie.getSize().y));
    //m_fond.setFillColor(sf::Color::Green);
    //m_fond.setPosition(POS_BARRE_X, POS_BARRE_Y);
}

IHMView::~IHMView()
{
    //dtor
}

void IHMView::update(sf::Time deltaTemps)
{
    //sf::Vector2f posJoueur = Vues::getPersonnageSFPosition(Modeles::m_joueur);//Vues::positionToVect2f(Modeles::m_joueur.getPosition());
    //m_fond.setPosition(POS_BARRE_X + posJoueur.x, POS_BARRE_Y + posJoueur.y);
}

void IHMView::draw() const
{
    const Personnage& joueur = Modeles::m_joueur;
    int vieJoueur = joueur.getSante();
    int vieMaxJoueur = joueur.getSanteMax();
    int largeurBarreDeVieVariable = m_tex_barreDeVieVariable.getSize().x * vieJoueur/vieMaxJoueur;

    sf::Sprite barreDeVieVariable(m_tex_barreDeVieVariable, sf::IntRect(0, 0, largeurBarreDeVieVariable, m_tex_barreDeVieVariable.getSize().y));
    sf::Sprite barreDeVie(m_tex_barreDeVie);

    sf::Vector2f posJoueur = //Vues::positionToVect2f(Modeles::m_joueur.getPosition());
        Vues::getPersonnageSFPosition(Modeles::m_joueur);

    barreDeVieVariable.setPosition(POS_BARRE_X + posJoueur.x, POS_BARRE_Y + posJoueur.y);
    barreDeVie.setPosition(POS_BARRE_X + posJoueur.x, POS_BARRE_Y + posJoueur.y);

    //m_window.draw(m_fond);
    m_window.draw(barreDeVieVariable);
    m_window.draw(barreDeVie);

    if(Modeles::m_phase == Modeles::GAME_OVER)
    {
        sf::Sprite gameOver(m_tex_gameOver);
        int l = m_tex_gameOver.getSize().x;
        int h = m_tex_gameOver.getSize().y;
        gameOver.setPosition(posJoueur.x - (l/2), posJoueur.y - (h/2));
        m_window.draw(gameOver);
    }
}

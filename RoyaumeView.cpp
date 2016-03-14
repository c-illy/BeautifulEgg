#include "RoyaumeView.h"
#include "Modeles.h"

RoyaumeView::RoyaumeView(sf::RenderWindow& window) :
    Vue(window)
{
    if (!m_tex_caseNavigable.loadFromFile(RESSOURCES "test.png"))
    {
        // erreur...
    }
    if (!m_tex_caseNonNavigable.loadFromFile(RESSOURCES "test2.png"))
    {
        // erreur...
    }
}

RoyaumeView::~RoyaumeView()
{
    //dtor
}

void RoyaumeView::draw() const
{
    const Royaume& royaume = Modeles::m_royaume;

    sf::Sprite sprite_caseNavigable(m_tex_caseNavigable);
    sf::Sprite sprite_caseNonNavigable(m_tex_caseNonNavigable);

    int largeur = royaume.getLargeur();
    int hauteur = royaume.getHauteur();
    for(int i=0; i<largeur; i++)
    {
        for(int j=0; j<hauteur; j++)
        {
            const Case& c = royaume.get(i, j);
            if(c.navigable())
            {
                sprite_caseNavigable.setPosition(i*TAILLE_CASE_X, j*TAILLE_CASE_Y);
                m_window.draw(sprite_caseNavigable);
            }
            else
            {
                sprite_caseNonNavigable.setPosition(i*TAILLE_CASE_X, j*TAILLE_CASE_Y);
                m_window.draw(sprite_caseNonNavigable);
            }
        }
    }
}

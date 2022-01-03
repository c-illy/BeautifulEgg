#include "CinematiqueView.h"
#include "Cinematique.h"
#include "Modeles.h"
#include "Vues.h"

CinematiqueView::CinematiqueView():
    Vue(Vues::m_window), m_cinematique(00)
{
}

CinematiqueView::~CinematiqueView()
{
}


void CinematiqueView::update(sf::Time deltaTemps)
{
}

void CinematiqueView::draw() const
{
    int n = m_cinematique->getImageCourante();
    sf::Sprite sprite(m_tex_images.at(n));
    sf::Vector2f posJoueur = Vues::positionToVect2f(Modeles::m_joueur.getPosition());
    int l = sprite.getTextureRect().width;
    int h = sprite.getTextureRect().height;
    float proportionX = TAILLE_FENETRE_X / ((float)l);
    float proportionY = TAILLE_FENETRE_Y / ((float)h);
    float scale;
    if(proportionX < proportionY)
    {
        scale = (proportionX) * .7;
    }
    else
    {
        scale = (proportionY) * .7;
    }
    sprite.scale(scale, scale);
    sprite.setPosition(posJoueur.x - (l*scale/2), posJoueur.y - (h*scale/2));
    m_window.draw(sprite);
}

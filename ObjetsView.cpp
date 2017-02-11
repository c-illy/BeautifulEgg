
#include "ObjetsView.h"
#include "Objet.h"
#include "Vues.h"
#include "Modeles.h"

std::map<Objet::ObjetID, sf::Texture> ObjetsView::m_texturesObjets;
std::map<Objet::ObjetID, sf::Sprite> ObjetsView::m_spritesObjets;
//const int ObjetsView::m_spriteLargeur(100);
//const int ObjetsView::m_spriteHauteur(50);

ObjetsView::ObjetsView() : Vue(Vues::m_window)
{
}

ObjetsView::~ObjetsView()
{
}

void ObjetsView::addTexture(Objet::ObjetID id, const std::string& fichier)
{
    sf::Texture& tex = m_texturesObjets[id];//ajout implicite de id=>tex dans la map
    Vues::loadFromFile(tex, fichier);
    sf::Sprite& sprite = m_spritesObjets[id];
    sprite.setTexture(tex);
}

void ObjetsView::update(sf::Time deltaTemps)
{
}

void ObjetsView::draw() const
{
    std::vector<Objet*>& objs = Modeles::getObjets();
    for(unsigned int i=0; i<objs.size(); i++)
    {
        Objet* obj = objs.at(i);
        sf::Sprite& sprite = m_spritesObjets.at(obj->m_id);
        sf::Vector2f vect = Vues::positionToVect2f(obj->m_position);
        sf::Vector2u tailleTexture = sprite.getTexture()->getSize();
        vect.x += (TAILLE_CASE_X - tailleTexture.x)/2;//m_spriteLargeur;
        vect.y += (TAILLE_CASE_Y - tailleTexture.y)/2;//m_spriteHauteur;

        sprite.setPosition(vect);
        m_window.draw(sprite);
    }
}

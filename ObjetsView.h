#ifndef OBJETSVIEW_H
#define OBJETSVIEW_H

#include "Vue.h"
#include "Objet.h"

class ObjetsView : public Vue
{
public:

    ObjetsView();
    virtual ~ObjetsView();

    void addTexture(Objet::ObjetID id, const std::string& fichier);

    virtual void update(sf::Time deltaTemps);
    virtual void draw() const;

private:
    static std::map<Objet::ObjetID, sf::Texture> m_texturesObjets;
    static std::map<Objet::ObjetID, sf::Sprite> m_spritesObjets;
    static const int m_spriteLargeur;
    static const int m_spriteHauteur;
};

#endif // OBJETSVIEW_H

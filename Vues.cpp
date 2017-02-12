#include "Vues.h"
#include "VuesAudio.h"

RoyaumeView Vues::m_royaumeView(Vues::m_window);
std::vector<ZoneView> Vues::m_zoneViews;
IHMView Vues::m_IHMView(Vues::m_window);
std::vector<PersonnagesView*> Vues::m_personnagesViewParZone;
ObjetsView Vues::m_objetsView;
CinematiqueView Vues::m_cinematiqueViewIntro;
CinematiqueView Vues::m_cinematiqueViewFin;

sf::RenderStates Vues::mulRenderStates(sf::BlendMultiply);
sf::Sprite Vues::spriteEffetParchemin;
sf::Texture Vues::textureParchemin;

sf::RenderWindow Vues::m_window(sf::VideoMode(TAILLE_FENETRE_X, TAILLE_FENETRE_Y), "EGG");

void Vues::init()
{
    m_window.setFramerateLimit(60);
    VuesAudio::init();
    loadFromFile(textureParchemin, RESSOURCES "textureParchemin.jpg");
    spriteEffetParchemin.setTexture(textureParchemin);
    spriteEffetParchemin.scale(
        (float)m_window.getSize().x / textureParchemin.getSize().x,
        (float)m_window.getSize().y / textureParchemin.getSize().y);
}

void Vues::update(sf::Time deltaTemps)
{
    m_royaumeView.update(deltaTemps);
    int z = Modeles::getNumZoneCourant();
    m_personnagesViewParZone.at(z)->update(deltaTemps);
    m_IHMView.update(deltaTemps);
}

void Vues::draw()
{
    m_window.clear();

    sf::View view = m_window.getDefaultView();
    view.setCenter(getPersonnageSFPosition(Modeles::m_joueur));
    //view.zoom(2.f);
    m_window.setView(view);

    sf::Vector2f posJoueur = getPersonnageSFPosition(Modeles::m_joueur);
    spriteEffetParchemin.setPosition(
        posJoueur.x - (m_window.getSize().x /2),
        posJoueur.y - (m_window.getSize().y /2));

    if(Modeles::m_phase == Modeles::INTRO)
    {
        m_cinematiqueViewIntro.draw();
        m_window.draw(spriteEffetParchemin, mulRenderStates);
    }
    else if(Modeles::m_phase == Modeles::FIN)
    {
        m_cinematiqueViewFin.draw();
        m_window.draw(spriteEffetParchemin, mulRenderStates);
    }
    else
    {
        m_royaumeView.draw();
        m_objetsView.draw();
        int z = Modeles::getNumZoneCourant();
        m_personnagesViewParZone.at(z)->draw();
        m_royaumeView.drawPremierPlan();
        m_window.draw(spriteEffetParchemin, mulRenderStates);
        m_IHMView.draw();

    }

    m_window.display();
    VuesAudio::draw();
}


sf::Vector2f Vues::positionToVect2f(const Position& position)
{
    return sf::Vector2f(position.getPositionX() * TAILLE_CASE_X, position.getPositionY() * TAILLE_CASE_Y);
}

sf::Vector2f Vues::getPersonnageSFPosition(const Personnage& personnage)
{
    sf::Vector2f vect = positionToVect2f(personnage.getPosition());

    if(personnage.getActionCourante() == DEPLACER)
    {
        int direction = personnage.getDirection();
        float deplacement = (float)Modeles::m_phaseDeltaTempsMs / Modeles::DUREE_ACTION_PJ_MS;
        if(direction == HAUT)
            vect.y -= deplacement * TAILLE_CASE_Y;
        if(direction == BAS)
            vect.y += deplacement * TAILLE_CASE_Y;
        if(direction == GAUCHE)
            vect.x -= deplacement * TAILLE_CASE_X;
        if(direction == DROITE)
            vect.x += deplacement * TAILLE_CASE_X;
    }

    return vect;
}

/*Position Vues::vect2fToPosition(const sf::Vector2f& vect)
{
    return Position(vect.x / TAILLE_CASE_X, vect.y / TAILLE_CASE_Y);
}*/

bool Vues::loadFromFile(sf::Image& im, const std::string& chemin)
{
    if(im.loadFromFile(chemin))
    {
        return true;
    }
    else
    {
        std::cout << "erreur chargement image : " << chemin << std::endl;
        return false;
    }
}

bool Vues::loadFromFile(sf::Texture& t, const std::string& chemin)
{
    if(t.loadFromFile(chemin))
    {
        t.setSmooth(true);
        return true;
    }
    else
    {
        std::cout << "erreur chargement texture : " << chemin << std::endl;
        return false;
    }
}

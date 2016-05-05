#include "Vues.h"

RoyaumeView Vues::m_royaumeView(Vues::m_window);
std::vector<ZoneView> Vues::m_zoneViews;
IHMView Vues::m_IHMView(Vues::m_window);
std::vector<PersonnagesView*> Vues::m_personnagesViewParZone;
ObjetsView Vues::m_objetsView;
CinematiqueView Vues::m_cinematiqueViewIntro;
CinematiqueView Vues::m_cinematiqueViewFin;

sf::RenderWindow Vues::m_window(sf::VideoMode(TAILLE_FENETRE_X, TAILLE_FENETRE_Y), "EGG");

void Vues::init()
{
    m_window.setFramerateLimit(60);
    //m_personnagesView.init();//cf. MapParser
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
    const Position& posJoueur = Modeles::m_joueur.getPosition();
    view.setCenter(positionToVect2f(posJoueur));
    //view.zoom(2.f);
    m_window.setView(view);

    if(Modeles::m_phase == Modeles::INTRO)
    {
        m_cinematiqueViewIntro.draw();
    }
    else if(Modeles::m_phase == Modeles::FIN)
    {
        m_cinematiqueViewFin.draw();
    }
    else
    {
        m_royaumeView.draw();
        m_objetsView.draw();
        int z = Modeles::getNumZoneCourant();
        m_personnagesViewParZone.at(z)->draw();
        m_royaumeView.drawPremierPlan();
        m_IHMView.draw();
    }

    m_window.display();
}


sf::Vector2f Vues::positionToVect2f(const Position& position)
{
    return sf::Vector2f(position.getPositionX() * TAILLE_CASE_X, position.getPositionY() * TAILLE_CASE_Y);
}

Position Vues::vect2fToPosition(const sf::Vector2f& vect)
{
    return Position(vect.x / TAILLE_CASE_X, vect.y * TAILLE_CASE_Y);
}

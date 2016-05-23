#include "Vues.h"

RoyaumeView Vues::m_royaumeView(Vues::m_window);
std::vector<ZoneView> Vues::m_zoneViews;
IHMView Vues::m_IHMView(Vues::m_window);
std::vector<PersonnagesView*> Vues::m_personnagesViewParZone;
ObjetsView Vues::m_objetsView;
CinematiqueView Vues::m_cinematiqueViewIntro;
CinematiqueView Vues::m_cinematiqueViewFin;
sf::Music Vues::m_musique;
const std::map<Musique, std::string> Vues::m_nomsMusiques =
{ {PRINCIPALE, "test.ogg"  } };
std::map<Son, sf::Sound> Vues::m_sons;

sf::RenderWindow Vues::m_window(sf::VideoMode(TAILLE_FENETRE_X, TAILLE_FENETRE_Y), "EGG");

void Vues::init()
{
    m_window.setFramerateLimit(60);
    jouerMusique(PRINCIPALE);
    ///TODO initialiser la map des sons
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

void Vues::jouerMusique(Musique musique)
{
    m_musique.stop();
    std::string nom = m_nomsMusiques.at(musique);
    if(!m_musique.openFromFile(nom))
    {
        //Erreur
    }
    m_musique.play();
}

void Vues::jouerSon(Son son)
{
    m_sons.at(son).play();
}

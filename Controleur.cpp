#include "Controleur.h"
#include "Vues.h"

void Controleur::init()
{

}

void Controleur::jouer()
{
    sf::Event event;
    sf::Clock clock;

    while (Vues::m_window.isOpen())
    {
        sf::Time deltaTemps(clock.restart());
        Modeles::m_phaseDeltaTempsMs += deltaTemps.asMilliseconds();


        if(Modeles::m_phase == Modeles::GAME_OVER)
        {
            if((event.type == sf::Event::Closed) ||
                (
                    (Modeles::m_phaseDeltaTempsMs >= Modeles::DUREE_ACTION_PJ_MS) &&
                    Vues::m_window.pollEvent(event) &&
                    (event.type == sf::Event::KeyPressed)
                 ))
            {
                Vues::m_window.close();
            }
        }
        if (Modeles::m_phase == Modeles::INTRO)
        {
            pollIntroEvent(event);
        }
        if (Modeles::m_phase == Modeles::PRET)
        {
            pollEvent(event);
        }
        if (Modeles::m_phase == Modeles::ACTION_PJ)
        {
            Modeles::updatePhasePJ();
        }
        if (Modeles::m_phase == Modeles::ACTION_PNJ)
        {
            Modeles::updatePhasePNJ();
        }
        if (Modeles::m_phase == Modeles::FIN)
        {
            pollFinEvent(event);
        }

        Vues::update(deltaTemps);
        Vues::draw();

        Modeles::m_nouvellePhase = false;
    }
}

void Controleur::pollEvent(sf::Event& event)
{
    if(Vues::m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            Vues::m_window.close();
        }
        if(event.type == sf::Event::KeyPressed)
        {
            bool joueurAgit(false);
            bool deplacementVoulu(false);
            Position posJoueur = Modeles::m_joueur.getPosition();
            Position posCibleTmp = posJoueur;//temporairement
            switch(event.key.code)
            {
            case sf::Keyboard::Z:
                deplacementVoulu = true;
                posCibleTmp.setPositionY(posJoueur.getPositionY()-1);
                break;
            case sf::Keyboard::S:
                deplacementVoulu = true;
                posCibleTmp.setPositionY(posJoueur.getPositionY()+1);
                break;
            case sf::Keyboard::Q:
                deplacementVoulu = true;
                posCibleTmp.setPositionX(posJoueur.getPositionX()-1);
                break;
            case sf::Keyboard::D:
                deplacementVoulu = true;
                posCibleTmp.setPositionX(posJoueur.getPositionX()+1);
                break;
            //////////////<<<debug : test cinematique fin
            case sf::Keyboard::T:
                Modeles::m_phase = Modeles::FIN;
                Modeles::m_nouvellePhase = true;
                Modeles::m_phaseDeltaTempsMs = 0;
                break;
            //////>>>>>>>>>
            default:
                break;
            }
            if(deplacementVoulu)
            {
                Modeles::m_royaume.retirerMonstresMorts();

                const Case& caseCible = Modeles::m_royaume.get(
                    posCibleTmp.getPositionX(), posCibleTmp.getPositionY());
                bool caseOk = caseCible.navigable() &&
                    caseCible.getPersonnage() == 00;
                if(caseOk)
                {
                    Modeles::m_joueur.setAction(DEPLACER);
                }
                else if(caseCible.getPersonnage() != 00)
                {
                    Modeles::m_joueur.setAction(ATTAQUER);
                }
                else if(caseCible.getObjet() != 00)
                {
                    //mur avec objet => actionner
                    Modeles::m_joueur.setAction(ACTIONNER);
                }
                Modeles::m_joueur.setCaseCible(&caseCible);
                ////todo direction
                joueurAgit = true;
            }

            if(joueurAgit)
            {
                Modeles::updatePhasePret();
            }
        }
    }
}

void Controleur::pollIntroEvent(sf::Event& event)
{
    if(Vues::m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            Vues::m_window.close();
        }
        if((event.type == sf::Event::KeyPressed)
           &&
           (Modeles::m_phaseDeltaTempsMs >= Modeles::DUREE_ACTION_PJ_MS))
        {
            Modeles::m_cinematiqueIntro.allerImageSuivante();

            if(Modeles::m_cinematiqueIntro.estTerminee())
            {
                Modeles::m_phase = Modeles::PRET;
                Modeles::m_nouvellePhase = true;
                Modeles::m_phaseDeltaTempsMs = 0;
            }
        }
    }
}

void Controleur::pollFinEvent(sf::Event& event)
{
    if(Vues::m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            Vues::m_window.close();
        }
        if((event.type == sf::Event::KeyPressed)
           &&
           (Modeles::m_phaseDeltaTempsMs >= Modeles::DUREE_ACTION_PJ_MS))
        {
            Modeles::m_cinematiqueFin.allerImageSuivante();

            if(Modeles::m_cinematiqueFin.estTerminee())
            {
                Modeles::m_phase = Modeles::GAME_OVER;
                Vues::m_window.close();
            }
        }
    }
}



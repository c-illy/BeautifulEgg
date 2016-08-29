#include "VuesAudio.h"
#include "Modeles.h"
#include "Monstre.h"
#include "Personnage.h"
#include <iostream>


sf::Music VuesAudio::m_musique;
VuesAudio::Musique VuesAudio::m_morceauEnCours(VuesAudio::GAME_OVER);//valeur par défaut arbitraire
std::list<sf::Sound> VuesAudio::m_sons;

const std::map<VuesAudio::Musique, std::string> VuesAudio::m_nomsMusiques =
{
    {INTRO, "audio/passageSecret_341865.ogg"},
    {EXPLOR, "audio/explor_219017.ogg"},
    {PASSAGE_SECRET, "audio/passageSecret_341865.ogg"},
    {BOSS, "audio/boss_220713.ogg"},
    {FIN_PARTIE1, "audio/passageSecret_341865.ogg"},
    {FIN_PARTIE2, "audio/fin_fin_234343.ogg"},
    {GAME_OVER, "audio/gameOver_218201.ogg"}
};

std::map<VuesAudio::Son, sf::SoundBuffer> VuesAudio::m_buffersSons;

void VuesAudio::init()
{
    m_musique.setLoop(true);
    bool ok(true);
    ok = m_buffersSons[SON_DEPLACER].loadFromFile("audio/deplacement_189640.ogg");
    if(!ok){std::cerr << "erreur fichier son : audio/deplacement_189640.ogg" << std::endl;}
    ok = m_buffersSons[SON_DEPLACER_VERS_OBJET].loadFromFile("audio/deplacement_objet_189640.ogg");
    if(!ok){std::cerr << "erreur fichier son : audio/deplacement_189640.ogg" << std::endl;}
    ok = m_buffersSons[SON_ACTIONNER].loadFromFile("audio/actionner_171233.ogg");
    if(!ok){std::cerr << "erreur fichier son : audio/deplacement_189640.ogg" << std::endl;}
    ok = m_buffersSons[SON_ATTAQUER].loadFromFile("audio/attaque_104183.ogg");
    if(!ok){std::cerr << "erreur fichier son : audio/deplacement_189640.ogg" << std::endl;}
    ok = m_buffersSons[SON_MOURIR].loadFromFile("audio/mourant_157293.ogg");
    if(!ok){std::cerr << "erreur fichier son : audio/deplacement_189640.ogg" << std::endl;}
}

void VuesAudio::draw()
{
    //cas particulier cinematique fin, 2ème partie
    if(Modeles::m_phase == Modeles::FIN)
    {
        if(Modeles::m_cinematiqueFin.getImageCourante() ==
           Modeles::IMAGE_PARTIE2_CINEMATIQUE_FIN)
        {
            m_musique.stop();
        }
        else if(Modeles::m_cinematiqueFin.getImageCourante() >
           Modeles::IMAGE_PARTIE2_CINEMATIQUE_FIN)
       {
            jouerMusique(FIN_PARTIE2);
       }
    }

    if(!Modeles::m_nouvellePhase)
    {
        return;
    }

    std::vector<Monstre*>& monstres = Modeles::getMonstres();
    int nbDepl = 0;
    int nbAtt = 0;
    int nbDying = 0;

    switch(Modeles::m_phase)
    {
    case Modeles::PRET:
            //TODO cas boss => jouerMusique(BOSS);
            //TODO cas passage secret => jouerMusique(PASSAGE_SECRET);
            jouerMusique(EXPLOR);
        break;

    case Modeles::ACTION_PJ:
        if(Modeles::m_joueur.getActionCourante() == ACTIONNER)
            jouerSon(SON_ACTIONNER);
        else if(Modeles::m_joueur.getActionCourante() == ATTAQUER)
            jouerSon(SON_ATTAQUER);
        else if(Modeles::m_joueur.getActionCourante() == DEPLACER)
        {
            if(Modeles::m_joueur.getCaseCible()->getObjet() != 00)
                jouerSon(SON_DEPLACER_VERS_OBJET);
            else
                jouerSon(SON_DEPLACER);
        }
        break;

    case Modeles::ACTION_PNJ:
        for(unsigned int i=0; i<monstres.size(); i++)
        {
            if(monstres.at(i)->getActionCourante() == ATTAQUER)
            {
                nbAtt++;
            }
            if(monstres.at(i)->getActionCourante() == DEPLACER)
            {
                nbDepl++;
            }
            if(monstres.at(i)->getMourant())
            {
                nbDying++;
            }
        }
        if(nbAtt > 0)
        {
            jouerSon(SON_ATTAQUER);
        }
        if(nbDepl > 0)
        {
            jouerSon(SON_DEPLACER);
        }
        if(nbDying > 0)
        {
            jouerSon(SON_MOURIR);
        }
        break;

    case Modeles::INTRO:
            jouerMusique(INTRO);
        break;

    case Modeles::FIN:
            jouerMusique(FIN_PARTIE1);
        break;

    case Modeles::GAME_OVER:
            jouerMusique(GAME_OVER);
        break;

	default:
		std::cerr << "Erreur VuesAudio::draw() : phase inconnue." << std::endl;
		break;
    }
}

void VuesAudio::jouerMusique(Musique musique)
{
    if(musique != m_morceauEnCours)
    {
        m_morceauEnCours = musique;
        m_musique.stop();
        std::string nom = m_nomsMusiques.at(musique);
        if(!m_musique.openFromFile(nom))
        {
            std::cerr << "erreur fichier musique : " << musique <<
                "(" << nom << ")" << std::endl;
        }
        m_musique.play();
    }
}

void VuesAudio::jouerSon(Son son)
{
    bool done(false);
    std::list<sf::Sound>::iterator it;
    for(it = m_sons.begin(); (!done) && it != m_sons.end(); it++)
    {
        sf::Sound& s = *it;
        if(s.getStatus() == sf::Sound::Stopped)
        {
            s.setBuffer(m_buffersSons[son]);
            s.play();
            done = true;
        }
    }
    if(!done)
    {
        m_sons.push_back(sf::Sound(m_buffersSons[son]));
        m_sons.back().play();
        std::cout << "nouveau sf::Sound construit. Total : " << m_sons.size() << std::endl;
    }
}


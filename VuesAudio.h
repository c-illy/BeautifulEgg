#ifndef VUESAUDIO_H
#define VUESAUDIO_H

#include <SFML/Audio.hpp>
#include <map>
#include <list>

/**
Avertissement!
Ceci est une classe-magique-à-tout-faire. Dans un projet plus
complexe, il faudrait faire plusieurs classes XXXVueAudio, une
pour chaque classe pertinente du modèle, et les gérer comme
n'importe quelle autre classe de vue.
*/

class VuesAudio
{

    enum Musique
    {
        INTRO,
        EXPLOR,
        PASSAGE_SECRET,
        BOSS,
        FIN_PARTIE1,
        FIN_PARTIE2,
        GAME_OVER
    };

    enum Son
    {
        SON_DEPLACER,
        SON_DEPLACER_VERS_OBJET,
        SON_ACTIONNER,
        SON_ATTAQUER,
        SON_MOURIR
    };

    public:
        static void init();
        static void draw();

        static void jouerMusique(Musique musique);
        static void jouerSon(Son son);

    public:
        static sf::Music m_musique;
        static const std::map<Musique, std::string> m_nomsMusiques;
        static Musique m_morceauEnCours;

        static std::list<sf::Sound> m_sons;
        static std::map<Son, sf::SoundBuffer>m_buffersSons;

};

#endif // VUESAUDIO_H

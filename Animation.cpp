#include "Animation.h"
#include "Vues.h"

std::map<Action, std::string> Animation::m_actions =
{
    {DEPLACER, "marche"},
    {ATTAQUER, "attaque"},
    {ACTIONNER, "actionne"},
    {RIEN, "rien"}
};
std::map<Direction, std::string> Animation::m_directions =
{
    {HAUT, "haut"},
    {BAS, "bas"},
    {GAUCHE, "gauche"},
    {DROITE, "droite"}
};
std::map<std::string, AnimationRessource> Animation::m_ressourcesMap;

AnimationRessource::AnimationRessource():
    m_spriteLargeur(100),
    m_spriteHauteur(100),
    m_tempsIntervalle(sf::milliseconds(Modeles::DUREE_ACTION_PJ_MS)),
    m_totalFrames(3)
{
}

void AnimationRessource::load(const std::string& animationCourante)
{
    std::string nomFichier = "animations/" + animationCourante;// + ".png";
    sf::Image image;
    //pour avoir largeur de frame, pas optimal mais peu casse-pied pour les graphistes
    if(Vues::loadFromFile(image, RESSOURCES + nomFichier + ".gif"))
    {
        m_spriteLargeur = image.getSize().x;
    }

    if(Vues::loadFromFile(image, RESSOURCES + nomFichier + ".png"))
    {
        m_texture.loadFromImage(image);
        m_texture.setSmooth(true);

        sf::Vector2u textureSize(image.getSize());
        m_spriteHauteur = textureSize.y;
        m_totalFrames = textureSize.x / m_spriteLargeur;
    }
}

Animation::Animation(sf::RenderWindow& window, const Personnage& personnage) :
    Vue(window),
    m_animationRessource(00),
    m_animationCourante(personnage.getNom() + "_marche_bas"),
    m_frameCourante(0),
    m_personnage(personnage)
{
    loadAnimation();
    demarrer();
}

Animation::~Animation()
{
    //dtor
}

AnimationRessource* Animation::getRessource(const Personnage& personnage)
{
    AnimationRessource* res = 00;
    std::string actionName = m_actions[personnage.getActionCourante()];
    std::string directionName = m_directions[personnage.getDirection()];
    std::string animationCourante = personnage.getNom() + "_" +
        actionName + "_" + directionName;
    if(personnage.getMourant() && Modeles::m_phase != Modeles::GAME_OVER)
    {
        if(personnage.getNom() == "boss")
        {
            animationCourante = "boss_dead";
        }
        else
        {
            animationCourante = "dead";
        }
    }

    std::map<std::string, AnimationRessource>::iterator it =
        m_ressourcesMap.find(animationCourante);
    if(it != m_ressourcesMap.end())
    {
        res = &(it->second);
        return res;
    }

    //nouvelle ressource
    res = &(m_ressourcesMap[animationCourante]);//instanciation implicite
    res->load(animationCourante);
    //spécifique (faudrait charger ça selon les ressources)
    if(personnage.getActionCourante() == RIEN)
    {
        if(personnage.getNom() == "boss")
        {
            res->m_tempsIntervalle = sf::milliseconds(4000);
        }
        else
        {
            res->m_tempsIntervalle = sf::milliseconds(900);
        }
    }
    else if(personnage.getMourant() && personnage.getNom() == "boss")
    {
        res->m_tempsIntervalle = sf::milliseconds(8000);
    }
    std::cout << "animations chargées : " << m_ressourcesMap.size() << std::endl;
    return res;
}

void Animation::loadAnimation()
{
    std::string actionName = m_actions[m_personnage.getActionCourante()];
    std::string directionName = m_directions[m_personnage.getDirection()];
    m_animationCourante = m_personnage.getNom() + "_" +
        actionName + "_" + directionName;
    if(m_personnage.getMourant())
    {
        m_animationCourante = "dead";
    }

    m_animationRessource = getRessource(m_personnage);
    m_sprite.setTexture(m_animationRessource->m_texture);
    m_sprite.setTextureRect(sf::IntRect(0, 0,
        m_animationRessource->m_spriteLargeur, m_animationRessource->m_spriteHauteur));
}

void Animation::demarrer()
{
    m_clock.restart();
    m_frameCourante = -1;
}

void Animation::update(sf::Time deltaTemps)
{
    std::string animationSuivante = "";
    animationSuivante += m_personnage.getNom();
    animationSuivante += "_" + actionToString(m_personnage.getActionCourante());
    animationSuivante += "_" + directionToString(m_personnage.getDirection());
    if(m_personnage.getMourant())
    {
        animationSuivante = "dead";
    }
    if(m_animationCourante != animationSuivante)
    {
        loadAnimation();
        demarrer();
    }

    sf::Vector2f vect = Vues::getPersonnageSFPosition(m_personnage);
    vect.x += (TAILLE_CASE_X - m_animationRessource->m_spriteLargeur) / 2;
    vect.y += (TAILLE_CASE_Y - m_animationRessource->m_spriteHauteur) / 2;
    m_sprite.setPosition(vect);

    sf::Int32 tempsDepuisDebut = m_clock.getElapsedTime().asMilliseconds();

    int prochaineFrame = ((int)(tempsDepuisDebut * m_animationRessource->m_totalFrames)
                           / m_animationRessource->m_tempsIntervalle.asMilliseconds());
    prochaineFrame = prochaineFrame % m_animationRessource->m_totalFrames;

    if(m_frameCourante != prochaineFrame)
    {
        m_frameCourante = prochaineFrame;
        m_sprite.setTextureRect(sf::IntRect(
            m_animationRessource->m_spriteLargeur * m_frameCourante,
            0,
            m_animationRessource->m_spriteLargeur,
            m_animationRessource->m_spriteHauteur));
    }
}

void Animation::draw() const
{
    m_window.draw(m_sprite);
}

std::string Animation::actionToString(Action act)
{
    return m_actions[act];
}

std::string Animation::directionToString(Direction dir)
{
    return m_directions[dir];
}

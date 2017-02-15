#include "RoyaumeView.h"
#include "Modeles.h"
#include "Vues.h"
#include "ZoneView.h"

RoyaumeView::RoyaumeView(sf::RenderWindow& window) :
    Vue(window), m_zoneChargee(-1)
{
//    Vues::loadFromFile(m_tex_caseNavigable, RESSOURCES "test.png");
//    Vues::loadFromFile(m_tex_caseNonNavigable, RESSOURCES "test2.png");
}

RoyaumeView::~RoyaumeView()
{
    //dtor
}

void RoyaumeView::update(sf::Time deltaTemps)
{
    int zoneCourante = Modeles::m_royaume.m_zoneCourante;
    if(zoneCourante != m_zoneChargee)
    {
        m_zoneChargee = zoneCourante;
        ZoneView& zview = Vues::m_zoneViews.at(zoneCourante);

        Vues::loadFromFile(m_texPremierPlan, zview.m_dossier + "/premierPlan.png");
        Vues::loadFromFile(m_texDernierPlan, zview.m_dossier + "/dernierPlan.png");
        m_spritePremierPlan.setTexture(m_texPremierPlan);
        m_spriteDernierPlan.setTexture(m_texDernierPlan);
    }
}

void RoyaumeView::draw() const
{
    m_window.draw(m_spriteDernierPlan);
}

void RoyaumeView::drawPremierPlan() const
{
    m_window.draw(m_spritePremierPlan);
}

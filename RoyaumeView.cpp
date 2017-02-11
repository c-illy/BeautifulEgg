#include "RoyaumeView.h"
#include "Modeles.h"
#include "Vues.h"
#include "ZoneView.h"

RoyaumeView::RoyaumeView(sf::RenderWindow& window) :
    Vue(window)
{
    Vues::loadFromFile(m_tex_caseNavigable, RESSOURCES "test.png");
    Vues::loadFromFile(m_tex_caseNonNavigable, RESSOURCES "test2.png");
}

RoyaumeView::~RoyaumeView()
{
    //dtor
}

void RoyaumeView::update(sf::Time deltaTemps)
{

}
void RoyaumeView::draw() const
{
    int zoneCourante = Modeles::m_royaume.m_zoneCourante;
    ZoneView& zview = Vues::m_zoneViews.at(zoneCourante);
    sf::Sprite spriteDernierPlan(zview.m_tex_dernierPlan);
    m_window.draw(spriteDernierPlan);
}

void RoyaumeView::drawPremierPlan() const
{
    int zoneCourante = Modeles::m_royaume.m_zoneCourante;
    ZoneView& zview = Vues::m_zoneViews.at(zoneCourante);
    sf::Sprite spritePremierPlan(zview.m_tex_premierPlan);
    m_window.draw(spritePremierPlan);
}

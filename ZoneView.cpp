#include "ZoneView.h"
#include "Vues.h"
#include <iostream>

ZoneView::ZoneView()
{
}

ZoneView::~ZoneView()
{}

void ZoneView::init(const std::string& nomDossier)
{
    std::string pp = nomDossier + "/premierPlan.png";
    std::string dp = nomDossier + "/dernierPlan.png";
    Vues::loadFromFile(m_tex_premierPlan, pp);
    Vues::loadFromFile(m_tex_dernierPlan, dp);
}


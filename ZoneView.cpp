#include "ZoneView.h"
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
    if (!m_tex_premierPlan.loadFromFile(pp))
    {
        std::cout << "Erreur chargement textures Zone ["
            << pp << "]" << std::endl;
    }
    if (!m_tex_dernierPlan.loadFromFile(dp))
    {
        std::cout << "Erreur chargement textures Zone ["
            << dp << "]" << std::endl;
    }
}


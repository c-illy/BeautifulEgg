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
    m_dossier = nomDossier;
}


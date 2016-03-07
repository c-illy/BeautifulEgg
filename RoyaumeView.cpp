#include "RoyaumeView.h"
#include "Modeles.h"

RoyaumeView::RoyaumeView(sf::RenderWindow& window) :
    Vue(window)
{
    //ctor
}

RoyaumeView::~RoyaumeView()
{
    //dtor
}

void RoyaumeView::draw() const
{
    const Royaume& royaume = Modeles::m_royaume;
}

#ifndef ZONEVIEW_H
#define ZONEVIEW_H

///textures 1er et arriere plan
class ZoneView
{
    public:
        ZoneView();///debug
        ZoneView(const std::string& nomDossier);///pas debug TODO
        virtual ~ZoneView();

    protected:

    private:
        sf::Texture m_tex_premierPlan;
        sf::Texture m_tex_arrierePlan;
};

#endif // ZONEVIEW_H

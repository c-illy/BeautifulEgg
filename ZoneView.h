#ifndef ZONEVIEW_H
#define ZONEVIEW_H

#include <SFML/Graphics.hpp>

///textures 1er et arriere plan
class ZoneView
{
    public:
        ZoneView();
        virtual ~ZoneView();

        void init(const std::string& nomDossier);

    protected:

    public:
        std::string m_dossier;
};

#endif // ZONEVIEW_H

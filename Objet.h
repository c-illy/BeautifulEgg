#ifndef OBJET_H
#define OBJET_H

#include "Position.h"
class Zone;

/** ramassable : sur case navigable (sol)
 *  interactif : sur case non navigable (mur)
 */
class Objet
{
public:
    enum ObjetID{
        SANTE,
        BONUS_DEGATS,
        BIDON_DEBUG_LEVIER_1,
        NB_OBJETS_ID};


    Objet(ObjetID id, int x, int y, Zone* zoneParente);
    virtual ~Objet();

    virtual void utiliser();


public:
    const ObjetID m_id;
    const Position m_position;
    Zone* m_zoneParente;

    static Objet* m_bidonLevier2;
};

#endif // OBJET_H

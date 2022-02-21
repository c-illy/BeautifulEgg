#ifndef MONSTRE_H_INCLUDED
#define MONSTRE_H_INCLUDED

#include "Personnage.h"
#include "Case.h"

//typedef std::vector<int> vecteur;
class Position;


class Monstre: public Personnage
{
public:
    Monstre(std::string nom, int x=0, int y=0);
    virtual ~Monstre();
    void setBoss();
    void setTuto();
    void appliquerIA();
    bool isBoss() const { return m_isBoss; };

private:
    Action choisirDeplacement(const Position* direction);

protected:
    virtual void perdreSante(int degats);

private:
    double m_rayonIA;
    bool m_isBoss;

};

#endif // MONSTRE_H_INCLUDED

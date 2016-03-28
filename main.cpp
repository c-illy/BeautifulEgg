#include "Modeles.h"
#include "Vues.h"
#include "Controleur.h"

int main()
{
    Modeles::init();
    Vues::init();
    Controleur::init();

    Controleur::jouer();

    return 0;
}

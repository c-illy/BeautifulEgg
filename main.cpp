#include "Modeles.h"
#include "Vues.h"
#include "Controleur.h"
#include <stdlib.h>

int main()
{
    srand((unsigned int)time(00));
    Modeles::init();
    Vues::init();
    Controleur::init();

    Controleur::jouer();

    return 0;
}

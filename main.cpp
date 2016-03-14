#include "Modeles.h"
#include "Vues.h"

int main()
{
    /*


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }*/
    for(int i=0; i<4000; i++)
        Vues::draw();

    return 0;
}

#include <iostream>

#include "Modeles.h"
#include "Vues.h"
#include "MapParser.h"

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
    sf::Image image;
    image.create(200, 200);
    image.loadFromFile(RESSOURCES "ParserTest.png");

    MapParser::parseAndInit(image, 100, 100);

    for(int i=0; i<4; ++i) {
        std::cout << Modeles::m_royaume.get(i % 2, i / 2).navigable() << std::endl;
    }

    for(int i=0; i<2000; i++)
        Vues::draw();

    return 0;
}

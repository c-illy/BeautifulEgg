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
    sf::Image image;
    image.create(200, 200);
    image.loadFromFile("ParserTest.png");

    MapParser::parseAndInit(image, 100, 100);


    for(int i=0; i<10000; i++)
        Vues::draw();

    return 0;
}

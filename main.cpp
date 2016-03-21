
#include <SFML/Graphics.hpp>
#include "Personnage.h"
#include "Case.h"

#include "Modeles.h"
#include "Vues.h"


int main()
{



//sf::RenderWindow window(sf::VideoMode(800,600), "BeautifulEgg");

Vues vue;


int a(10);


    Personnage *perso1=new Personnage("p1");
    Personnage *perso2=new Personnage("p2");
    Case case1(true,0,0,0), case2(true,0,3,5);


    while (vue.m_window.isOpen())
    {


        sf::Event event;
        while (vue.m_window.pollEvent(event))
        {

              if (event.type == sf::Event::Closed)
                vue.m_window.close();


        }


            std::cout<<std::endl;
            std::cout<<"appuyer sur un chiffre pour continuer"<<std::endl;
            std::cin>>a;
            std::cout<<std::endl;


            perso1->setCaseCible(&case1);
            case1.setPersonnage(perso2);

            perso1->setAction(ATTAQUER);
            perso1->executerAction();



            perso1->afficher();
            perso1->setCaseCible(&case2);
            perso1->setAction(DEPLACER);
            perso1->executerAction();
            perso1->afficher();



          std::cout<<"============================================="<<std::endl;



        vue.m_window.clear();


          for(int i=0; i<4000; i++)
        Vues::draw();

        vue.m_window.display();


    }








    return 0;
}

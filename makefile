
all:
	export LD_LIBRARY_PATH=/home/alexandre/projets/BeautifulEgg/SFML-2.3.2-l/lib/
	g++ *.cpp -o egg -std=c++11 -ISFML-2.3.2-l/include -LSFML-2.3.2-l/lib -lsfml-graphics -lsfml-window -lsfml-system


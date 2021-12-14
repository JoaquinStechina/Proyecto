#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "Menu_Principal.h"
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	srand(time(NULL));
	Juego Proyecto(new Menu_Principal);
	Proyecto.Jugar();
	return 0;
}


#ifndef JUEGO_H
#define JUEGO_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Juego {
	Escena *esc_actual, *esc_prox = nullptr;
	RenderWindow ventanita;
public:
	Juego(Escena *Pantalla);
	void Cambiar_Escena(Escena *esc_nueva);
	void Jugar();
	~Juego();
};

#endif

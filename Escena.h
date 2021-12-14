#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Juego;

class Escena {
public:
	Escena();
	virtual void Actualizar(RenderWindow &ventana, Juego &j) = 0;
	virtual void Dibujar(RenderWindow &ventana) = 0;
};

#endif


#ifndef FONDO_H
#define FONDO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Sprites.h"
using namespace sf;

class Fondo : public Sprites{
public:
	Fondo(std::string Nombre_textura);
	void Dibujar(RenderWindow &ventana);
};

#endif

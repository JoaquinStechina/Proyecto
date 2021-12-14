#ifndef SPRITE_DE_PERSONAJE_H
#define SPRITE_DE_PERSONAJE_H
#include <SFML/Graphics.hpp>
#include "Sprites.h"
using namespace sf;

class Sprite_de_personaje: public Sprites{
	int cont_sprite=3;
public:
	Sprite_de_personaje(std::string nombre_textura);
	void Actualizar();
	void Dibujar(RenderWindow &ventana);
};

#endif


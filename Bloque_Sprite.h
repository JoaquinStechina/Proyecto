#ifndef BLOQUE_SPRITE_H
#define BLOQUE_SPRITE_H
#include "Sprites.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>

using namespace sf;


class Bloque_Sprite : public Sprites {
	Text texto;
	Font fuente;
	FloatRect rect_texto;
public:
	Bloque_Sprite(std::string nombre_textura, FloatRect bloque);
    Bloque_Sprite(std::string nombre_textura, FloatRect bloque, FloatRect , std::string texto);
	void repetir_bloque(bool &a);
	void Dibujar_bloque(RenderWindow &ventana);
	void Dibujar_texto(RenderWindow &ventana);
	void Dibujar(RenderWindow &ventana);
};

#endif


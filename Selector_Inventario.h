#ifndef SELECTOR_INVENTARIO_H
#define SELECTOR_INVENTARIO_H
#include "Sprites.h"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

class Selector_Inventario : public Sprites {
	SoundBuffer SB_mover;
	Sound S_mover;
	Sprite sprite_selector;
	int cont_pos;
	Clock reloj;
public:
	Selector_Inventario();
	void Cambiar_Pos(const Vector2f v);
	void Cambiar_Pos(const float posx, const float posy);
	int Actualizar(RenderWindow &win);
	void Dibujar(RenderWindow &win);
};

#endif


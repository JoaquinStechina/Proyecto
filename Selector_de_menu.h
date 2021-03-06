#ifndef SELECTOR_DE_MENU_H
#define SELECTOR_DE_MENU_H
#include "Sprites.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Selector_de_menu : public Sprites {
	SoundBuffer SB_mover;
	Sound S_mover;
	Sprite Circulo_sprite_selector;
	int cont_pos;
	int cont_max;
	Clock reloj;
public:
	Selector_de_menu();
	void setCont_Max(int i);
	void Cambiar_Pos(const Vector2f v);
	void Cambiar_Pos(const float posx, const float posy);
	void Rotar(float angulo);
	int Actualizar(RenderWindow &win);
	void Dibujar(RenderWindow &win);
};

#endif


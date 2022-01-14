#include "Selector_Inventario.h"

Selector_Inventario::Selector_Inventario() {
	t_de_sprite.loadFromFile("Imagenes/Sprites/redarrow.png");		//Declaro el sprite del selector y su configuracion;
	sprite_selector.setTexture(t_de_sprite);
	sprite_selector.setOrigin(25,25);
	cont_pos = 0;
	
	SB_mover.loadFromFile("Sonidos/Menu_move.wav");		//Declaro el sonido de cuando el selector se mueve;
	S_mover.setBuffer(SB_mover);
	
	reloj.restart();
}


void Selector_Inventario::Cambiar_Pos (const Vector2f v) {
	sprite_selector.setPosition(v);
}

void Selector_Inventario::Cambiar_Pos (const float posx, const float posy) {
	sprite_selector.setPosition(posx,posy);
}

int Selector_Inventario::Actualizar (RenderWindow & win) {
	if ( reloj.getElapsedTime().asSeconds() > 0.2 ){		//Si pasaron al menos 0.2 segundos del ultimo input;
		if (Keyboard::isKeyPressed(Keyboard::Right)){
			cont_pos++;
			if (cont_pos == 3){
				cont_pos = 0;
			}
			S_mover.play();
			reloj.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)){
			cont_pos--;
			if (cont_pos == -1){
				cont_pos = 2;
			}
			S_mover.play();
			reloj.restart();
		}
	}
	return cont_pos;
}

void Selector_Inventario::Dibujar (RenderWindow & win) {
	win.draw(sprite_selector);
}


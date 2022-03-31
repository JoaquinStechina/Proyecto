#include "Selector_de_menu.h"
#include <SFML/System/Clock.hpp>

Selector_de_menu::Selector_de_menu() {
	t_de_sprite.loadFromFile("Imagenes/Sprites/redarrow.png");		//Declaro el sprite del selector y su configuracion;
	Circulo_sprite_selector.setTexture(t_de_sprite);
	Circulo_sprite_selector.setOrigin(25,25);
	cont_pos = 0;
	
	SB_mover.loadFromFile("Sonidos/Menu_move.wav");		//Declaro el sonido de cuando el selector se mueve;
	S_mover.setBuffer(SB_mover);
	
	reloj.restart();
}

void Selector_de_menu::setCont_Max(int i){
	cont_max = i;
}

int Selector_de_menu::Actualizar(RenderWindow &win) {
	if ( reloj.getElapsedTime().asSeconds() > 0.2 ){		//Si pasaron al menos 0.2 segundos del ultimo input;
		if (Keyboard::isKeyPressed(Keyboard::Down)){
			cont_pos++;
			if (cont_pos == cont_max){
				cont_pos = 0;
			} 
			S_mover.play();
			reloj.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)){
			cont_pos--;
			if (cont_pos == -1){
				cont_pos = cont_max-1;
			}
			S_mover.play();
			reloj.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)){
			cont_pos++;
			if (cont_pos == cont_max){
				cont_pos = 0;
			} 
			S_mover.play();
			reloj.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)){
			cont_pos--;
			if (cont_pos == -1){
				cont_pos = cont_max-1;
			}
			S_mover.play();
			reloj.restart();
		}
	}
	return cont_pos;
}

void Selector_de_menu::Dibujar (RenderWindow & win) {
	win.draw(Circulo_sprite_selector);
}

void Selector_de_menu::Cambiar_Pos (const Vector2f v) {
	Circulo_sprite_selector.setPosition(v);
}

void Selector_de_menu::Cambiar_Pos (const float posx, const float posy) {
	Circulo_sprite_selector.setPosition(posx,posy);
}

void Selector_de_menu::Rotar(float angulo){
	Circulo_sprite_selector.setRotation(angulo);
}

#include "Sprite_de_personaje.h"
#include <SFML/Graphics.hpp>

Sprite_de_personaje::Sprite_de_personaje(std::string nombre_textura) {
	t_de_sprite.loadFromFile(nombre_textura);
	s_sprite.setTexture(t_de_sprite);
}
void Sprite_de_personaje::Actualizar(){
	s_sprite.setTextureRect(IntRect(50*cont_sprite,37*5,50,37));
	cont_sprite++;
	if (cont_sprite == 7){
		cont_sprite = 3;
	}
	s_sprite.setScale(3,3);
}

void Sprite_de_personaje::Dibujar(RenderWindow &ventana){
	ventana.draw(s_sprite);
}


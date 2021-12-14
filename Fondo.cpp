#include "Fondo.h"
#include <SFML/Graphics.hpp>

Fondo::Fondo(std::string Nombre_textura) {
	t_de_sprite.loadFromFile(Nombre_textura);
	s_sprite.setTexture(t_de_sprite);
}

void Fondo::Dibujar (RenderWindow & ventana){
	ventana.draw(s_sprite);
}



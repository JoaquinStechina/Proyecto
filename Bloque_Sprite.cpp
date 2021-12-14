#include "Bloque_Sprite.h"

Bloque_Sprite::Bloque_Sprite(std::string nombre_textura) {
}
Bloque_Sprite::Bloque_Sprite(std::string nombre_textura, FloatRect _texto, std::string texto) {
	
}

void Bloque_Sprite::repetir_bloque (bool &a) {
	t_de_sprite.setRepeated(a);
}

void Bloque_Sprite::Dibujar_bloque(RenderWindow &ventana){
	ventana.draw(s_sprite);
}

void Bloque_Sprite::Dibujar_texto(RenderWindow &ventana){
	ventana.draw(texto);
}


void Bloque_Sprite::Dibujar (RenderWindow & ventana) {
	this->Dibujar_bloque(ventana);
	this->Dibujar_texto(ventana);
}



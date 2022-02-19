#include "Bloque_Sprite.h"

Bloque_Sprite::Bloque_Sprite(std::string nombre_textura) {
	t_de_sprite.loadFromFile(nombre_textura);
	s_sprite.setTexture(t_de_sprite);
	t_de_sprite.setSmooth(true);
}
//Bloque_Sprite(std::string nombre_textura, FloatRect bloque, FloatRect bloque_texto, std::string texto) {
//	
//}

void Bloque_Sprite::cambiar_posicion_bloque (const float & x, const float & y) {
	s_sprite.setPosition(x,y);
}

void Bloque_Sprite::cambiar_escala_bloque (const float & x) {
	s_sprite.setScale(x,x);
}

void Bloque_Sprite::cambiar_escala_bloque (const float & x, const float & y) {
	s_sprite.setScale(x,y);
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



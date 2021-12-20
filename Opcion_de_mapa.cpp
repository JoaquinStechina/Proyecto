#include "Opcion_de_mapa.h"

Opcion_de_mapa::Opcion_de_mapa(std::string t_de_mapa, int Tamanio_texto) {
	fuente.loadFromFile("Fuentes/Triforce.ttf");
	Texto_opcion_mapa.setString(t_de_mapa);
	Texto_opcion_mapa.setFont(fuente);
	Texto_opcion_mapa.setCharacterSize(Tamanio_texto);
	rect_texto_opcion_mapa = Texto_opcion_mapa.getLocalBounds();
	Texto_opcion_mapa.setOrigin(rect_texto_opcion_mapa.width/2, rect_texto_opcion_mapa.height/2);
	t_de_sprite.loadFromFile("Imagenes/Sprites/bloquesito_steel.png");
	s_sprite.setTexture(t_de_sprite);
	r_rect = s_sprite.getLocalBounds();
	s_sprite.setOrigin(r_rect.width/2, r_rect.height/2);
	t_de_sprite.setSmooth(true);
}
void Opcion_de_mapa::Cambiar_Pos_Opcion_mapa ( const Vector2f v ) {
	s_sprite.setPosition(v);
	Texto_opcion_mapa.setPosition(v);
}

void Opcion_de_mapa::Cambiar_Pos_Opcion_mapa (const float posx, const float posy) {
	Texto_opcion_mapa.setPosition(posx, posy);
}

void Opcion_de_mapa::Cambiar_Escala_Opcion_mapa (const float Nueva_Escala) {
	s_sprite.setScale(Nueva_Escala, Nueva_Escala);
}

void Opcion_de_mapa::Actualizar ( ) {
	rect_texto_opcion_mapa = Texto_opcion_mapa.getLocalBounds();
	Texto_opcion_mapa.setOrigin(rect_texto_opcion_mapa.width/2, rect_texto_opcion_mapa.height/2);
	this->Cambiar_Pos_Opcion_mapa(s_sprite.getPosition().x, s_sprite.getPosition().y-10);
}

void Opcion_de_mapa::Dibujar (RenderWindow & win) {
	win.draw(s_sprite);
	win.draw(Texto_opcion_mapa);
}

void Opcion_de_mapa::Cambiar_Pos_Cuadro_mapa (const float posx, const float posy) {
	s_sprite.setPosition(posx, posy);
}


void Opcion_de_mapa::Cambiar_texto (std::string nuevo_texto) {
	Texto_opcion_mapa.setString(nuevo_texto);
}

void Opcion_de_mapa::Cambiar_color_fuente (Color Nuevo_color) {
	Texto_opcion_mapa.setFillColor(Nuevo_color);
}


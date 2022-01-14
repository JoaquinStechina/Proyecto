#include "Opcion_De_Tienda.h"

Opcion_De_Tienda::Opcion_De_Tienda(std::string t_de_menu, int Tamanio_texto) {
	fuente.loadFromFile("Fuentes/Triforce.ttf");
	Texto_opcion_menu.setString(t_de_menu);
	Texto_opcion_menu.setFont(fuente);
	Texto_opcion_menu.setCharacterSize(Tamanio_texto);
	rect_texto_opcion_menu = Texto_opcion_menu.getLocalBounds();
	Texto_opcion_menu.setOrigin(rect_texto_opcion_menu.width/2, rect_texto_opcion_menu.height/2);
	t_de_sprite.loadFromFile("Imagenes/Sprites/opcion_de_tienda.png");
	s_sprite.setTexture(t_de_sprite);
	r_rect = s_sprite.getLocalBounds();
	s_sprite.setOrigin(r_rect.width/2, r_rect.height/2);
	t_de_sprite.setSmooth(true);
}

void Opcion_De_Tienda::Cambiar_Pos_Opcion_Menu (const Vector2f v) {
	s_sprite.setPosition(v);
	Texto_opcion_menu.setPosition(v);
}

void Opcion_De_Tienda::Cambiar_Pos_Opcion_Menu (const float posx, const float posy) {
	Texto_opcion_menu.setPosition(posx, posy);
}

void Opcion_De_Tienda::Cambiar_Escala_Opcion_Menu (const float Nueva_Escala) {
	s_sprite.setScale(Nueva_Escala, Nueva_Escala);
}

void Opcion_De_Tienda::Actualizar ( ) {
	
}

void Opcion_De_Tienda::Dibujar (RenderWindow & win) {
	win.draw(s_sprite);
	win.draw(Texto_opcion_menu);
}

void Opcion_De_Tienda::Cambiar_Pos_Cuadro_Menu (const float posx, const float posy) {
	s_sprite.setPosition(posx, posy);
}


void Opcion_De_Tienda::Cambiar_texto (std::string nuevo_texto) {
	Texto_opcion_menu.setString(nuevo_texto);
	rect_texto_opcion_menu = Texto_opcion_menu.getLocalBounds();
	Texto_opcion_menu.setOrigin(rect_texto_opcion_menu.width/2, rect_texto_opcion_menu.height/2);
}


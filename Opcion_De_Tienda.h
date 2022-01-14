#ifndef OPCION_DE_TIENDA_H
#define OPCION_DE_TIENDA_H
#include "Sprites.h"

class Opcion_De_Tienda : public Sprites {
	Text Texto_opcion_menu;
	Font fuente;
	FloatRect rect_texto_opcion_menu;
public:
	Opcion_De_Tienda(std::string t_de_menu, int Tamanio_texto);
	void Cambiar_Pos_Opcion_Menu(const Vector2f v);
	void Cambiar_Pos_Opcion_Menu(const float posx, const float posy);
	void Cambiar_Pos_Cuadro_Menu(const float posx, const float posy);
	void Cambiar_Escala_Opcion_Menu(const float Nueva_Escala);
	void Cambiar_texto(std::string nuevo_texto);
	void Actualizar();
	void Dibujar(RenderWindow &win);
};

#endif


#ifndef OPCION_DE_MENU_H
#define OPCION_DE_MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Sprites.h"
#include <string>
using namespace std;
using namespace sf;

class Opcion_de_menu : public Sprites {
	Text Texto_opcion_menu;
	Font fuente;
	FloatRect rect_texto_opcion_menu;
public:
	Opcion_de_menu();
	Opcion_de_menu(std::string t_de_menu, int Tamanio_texto);
	void setOpcion(std::string t_de_menu, int Tamanio_texto);
	void Cambiar_Pos_Opcion_Menu(const Vector2f v);
	void Cambiar_Pos_Opcion_Menu(const float posx, const float posy);
	void Cambiar_Pos_Cuadro_Menu(const float posx, const float posy);
	void Cambiar_Escala_Opcion_Menu(const float Nueva_Escala);
	void Actualizar();
	void Dibujar(RenderWindow &win);
};

#endif


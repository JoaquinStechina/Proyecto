#ifndef NODOS_H
#define NODOS_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Nodos {
	int Tipo_de_Nodo;
	Sprite s_nodo;
public:
	Nodos();
	Nodos(int tipo_nuevo_nodo);
	void Definir_tipo_nodo(int t_nodo);
	int Ver_Valor_Nodo();
	void Definir_sprite(Texture &t_textura);
	void Cambiar_pos_nodo(float posx, float posy);
	void Dibujar(RenderWindow &ventana);
};

#endif


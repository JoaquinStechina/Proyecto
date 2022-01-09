#ifndef FILAS_DE_NODOS_H
#define FILAS_DE_NODOS_H
#include "Nodos.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
using namespace std;

class Filas_De_Nodos {
	list<Nodos> v_nodos;
	int Tamanio_fila_nodo;
public:
	Filas_De_Nodos();
	Filas_De_Nodos(bool random);
	Filas_De_Nodos(int valor_nodo);
	int Ver_Cantidad_Nodos();
	void Posicionar_Nodos(float pos_x);
	void Set_Sprite_nodos(Texture &t_mercado, Texture &t_campfire, Texture &t_loot, Texture &t_start, Texture &t_boss, Texture &t_encuentro);
	void Ver_Valor_Nodos();
	void Dibujar(RenderWindow &ventana);
};

#endif


#ifndef SELECTOR_DE_MAPA_H
#define SELECTOR_DE_MAPA_H
#include "Sprites.h"
#include <list>
#include "Filas_De_Nodos.h"
using namespace std;

class Selector_De_Mapa : public Sprites{
	Clock reloj;
	int fila_actual;
public:
	Selector_De_Mapa();
	void Cambiar_Pos(const Vector2f v);
	void Cambiar_Pos(const float posx, const float posy);
	void Actualizar(RenderWindow & ventana, list<Filas_De_Nodos> &lista_filas, int &columna_actual);
	void Dibujar(RenderWindow &ventana);
};

#endif


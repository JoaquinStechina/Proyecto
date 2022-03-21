#ifndef GUARDADO_H
#define GUARDADO_H
#include "Filas_De_Nodos.h"
#include <list>
#include "Player.h"

class guardado {
public:
	guardado();
private:
	guardado(Player &Personaje, list<Filas_De_Nodos> vector_de_filas, int columna_actual);
};

#endif


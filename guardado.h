#ifndef GUARDADO_H
#define GUARDADO_H
#include "Filas_De_Nodos.h"
#include <list>
#include "Player.h"
#include <iostream>
#include <fstream>
#include "Elementos.h"

class guardado {
private:
	Elementos_jugador ab;
	Elementos_mapa mapa;
	
public:
	guardado(Player &Personaje, list<Filas_De_Nodos> v, int columna_actual_flecha);
};

#endif


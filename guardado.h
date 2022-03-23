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
public:
	guardado(Player &Personaje);
};

#endif


#ifndef CARGADO_H
#define CARGADO_H
#include "Menu_mapa.h"

class cargado {
private:
	Elementos_jugador jugador_struct;
	Elementos_mapa mapa_struct;
public:
	cargado();
	Elementos_jugador getStructJugador();
	Elementos_mapa getStructMapa();
};

#endif


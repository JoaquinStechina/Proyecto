#include "cargado.h"

cargado::cargado(){
	ifstream partida("SAVE.zzz",ios::binary|ios::in);
	partida.read(reinterpret_cast<char*>(&cb),sizeof(cb));
	partida.close();
}

Elementos_jugador cargado::getStruct(){
	return cb;
}

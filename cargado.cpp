#include "cargado.h"

cargado::cargado(){
	ifstream jugador_cargar("SAVE.zzz",ios::binary|ios::in);
	jugador_cargar.read(reinterpret_cast<char*>(&jugador_struct),sizeof(jugador_struct));
	jugador_cargar.close();
	
	ifstream mapa_cargar("SAVE2.zzz",ios::binary|ios::in);
	mapa_cargar.read(reinterpret_cast<char*>(&mapa_struct),sizeof(mapa_struct));
	mapa_cargar.close();
}

Elementos_jugador cargado::getStructJugador(){
	return jugador_struct;
}

Elementos_mapa cargado::getStructMapa(){
	return mapa_struct;
}

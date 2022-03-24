#include "cargado.h"

cargado::cargado(){
	ifstream jugador("SAVE.zzz",ios::binary|ios::in);
	jugador.read(reinterpret_cast<char*>(&jugador_struct),sizeof(jugador_struct));
	jugador.close();
	
	ifstream mapa("SAVE2.zzz",ios::binary|ios::in);
	mapa.read(reinterpret_cast<char*>(&mapa_struct),sizeof(mapa_struct));
	mapa.close();
}

Elementos_jugador cargado::getStructJugador(){
	return jugador_struct;
}

Elementos_mapa cargado::getStructMapa(){
	return mapa_struct;
}

#include "guardado.h"
#include <cstring>
using namespace std;


guardado::guardado(Player &Personaje) {
	
	list<Objeto> inv = Personaje.Obtener_Inventario();
	
	int contador = 0;
	for(Objeto &x : inv){
		if(contador == 0){
			ab.item1.Rareza = x.getRareza();
			ab.item1.Stat   = x.getStat();
			ab.item1.Bufo   = x.getBufo();
			ab.item1.Precio = x.getPrecio();
			ab.item1.Tipo   = x.getTipo();
			ab.item1.Bufo   = x.getBufo();
			strcpy(ab.item1.Nombre, x.getNombre().c_str());
		}
		if(contador == 1){
			ab.item2.Rareza = x.getRareza();
			ab.item2.Stat   = x.getStat();
			ab.item2.Bufo   = x.getBufo();
			ab.item2.Precio = x.getPrecio();
			ab.item2.Tipo   = x.getTipo();
			ab.item2.Bufo   = x.getBufo();
			strcpy(ab.item2.Nombre, x.getNombre().c_str());
		}
		if(contador == 2){
			ab.item3.Rareza = x.getRareza();
			ab.item3.Stat   = x.getStat();
			ab.item3.Bufo   = x.getBufo();
			ab.item3.Precio = x.getPrecio();
			ab.item3.Tipo   = x.getTipo();
			ab.item3.Bufo   = x.getBufo();
			strcpy(ab.item3.Nombre, x.getNombre().c_str());
		}
		contador++;
	}
	
	ab.monedas      = Personaje.GetMonedas();
	ab.nivel        = Personaje.getNivel();
	ab.constitucion = Personaje.getConstitucion();
	ab.destreza     = Personaje.getDestreza();
	ab.fuerza       = Personaje.getFuerza();
	ab.inteligencia = Personaje.getInteligencia();
	ab.suerte       = Personaje.getSuerte();
	ab.vida_max     = Personaje.getVidaMax();
	ab.mana_max     = Personaje.getManaMax();
	ab.vida_actual  = Personaje.getVida_Actual();
	ab.mana_actual  = Personaje.getMana_Actual();
	
	ofstream partida("SAVE.zzz",ios::binary);
	partida.write(reinterpret_cast<char*>(&ab),sizeof(ab));
	partida.close();
}

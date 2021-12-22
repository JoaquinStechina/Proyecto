#ifndef OBJETO_H
#define OBJETO_H
#include <string>
#include "Sprites.h"
using namespace std;

class Objeto : public Sprites {
	int rareza, stat, bufo, precio, tipo;			//tipo: armadura o arma o colgante
	string nombre;
public:
	Objeto();
	
	void setRareza(int x);
	void setStat(int x);
	void setBufo(int x);
	void setPrecio(int x);
	void setTipo(int x);
	
	int getRareza();
	int getStat();
	int getBufo();
	int getPrecio();
	int getTipo();
	
	void Pasiva();
	void Actualizar();
};

#endif


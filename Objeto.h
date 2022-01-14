#ifndef OBJETO_H
#define OBJETO_H
#include <string>
#include "Sprites.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;

class Objeto : public Sprites {
	int rareza, stat, bufo, precio, tipo;			//tipo: armadura o arma o colgante
	string nombre;
public:
	Objeto(int tier);
	Objeto();
	
	void setRareza(int x);
	void setStat  (int x);
	void setBufo  (int x);
	void setPrecio(int x);
	void setTipo  (int x);
	void setNombre(string name);
	
	int getRareza   ();
	int getStat     ();
	int getBufo     ();
	int getPrecio   ();
	int getTipo     ();
	string getNombre();
	
	void CambiarPos(float x, float y);
	
	void Pasiva();					//Si debe curar al personaje al atacar, o si debe darle alguna bonificacion extra
	void Actualizar();
	void Dibujar(RenderWindow &ventanita);
};

#endif


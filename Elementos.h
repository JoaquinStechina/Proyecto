#ifndef ELEMENTOS_H
#define ELEMENTOS_H

struct Elementos_inventario{
	int Rareza;
	int Stat;
	int Bufo;
	int Precio;
	int Tipo;
	char Nombre[128];
	
};

struct Elementos_jugador{
	int nivel, monedas;
	int constitucion, fuerza, destreza, inteligencia, suerte;
	int vida_max,mana_max,vida_actual,mana_actual;
	Elementos_inventario item1, item2, item3;
};

#endif

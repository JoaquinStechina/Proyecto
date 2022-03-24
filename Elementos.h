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

struct Elementos_Nodos{
	int tipo_de_nodo;
};

struct Elementos_Filas_De_Nodos{
	int tamanio_fila_nodo;
	Elementos_Nodos aux_nod[3];
};

struct Elementos_mapa{
	Elementos_Filas_De_Nodos aux_filas_nodos[8];
	int c_a_f;
};

#endif

#include "Filas_De_Nodos.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Filas_De_Nodos::Filas_De_Nodos(bool random) {
	Tamanio_fila_nodo = (rand()%3)+1;
	for(int i=0;i<Tamanio_fila_nodo;i++) { 
		Nodos nodo_aux;
		v_nodos.push_back(nodo_aux);
	}
	
}


void Filas_De_Nodos::Ver_Valor_Nodos ( ) {
	cout << v_nodos.size() << endl;
	for(Nodos &x : v_nodos) {
		cout << x.Ver_Valor_Nodo() << endl;
	}
	cout << endl;
}

int Filas_De_Nodos::Ver_Cantidad_Nodos ( ) {
	return v_nodos.size();
}

void Filas_De_Nodos::Posicionar_Nodos (float pos_x) {
	int cont = 0;
	for(Nodos &x : v_nodos) {
		x.Cambiar_pos_nodo(pos_x , (((400/(v_nodos.size()+1))*(cont+1)+100)));
		cont++;
	}
}

void Filas_De_Nodos::Dibujar (RenderWindow & ventana) {
	for(Nodos &x : v_nodos) { 
		x.Dibujar(ventana);
	}
}

Filas_De_Nodos::Filas_De_Nodos (int valor_nodo) {
	Nodos aux_nodo;
	aux_nodo.Definir_tipo_nodo(valor_nodo);
	v_nodos.push_back(aux_nodo);
}

void Filas_De_Nodos::Set_Sprite_nodos (Texture &t_mercado, Texture &t_campfire, Texture &t_loot, Texture &t_start, Texture &t_boss, Texture &t_encuentro) {
	for(Nodos &x: v_nodos){
		if( x.Ver_Valor_Nodo()==1){
			x.Definir_sprite(t_campfire);
		}
		if( x.Ver_Valor_Nodo()==2){
			x.Definir_sprite(t_encuentro);
		}
		if( x.Ver_Valor_Nodo()==3){
			x.Definir_sprite(t_mercado);
		}
		if( x.Ver_Valor_Nodo()==4){
			x.Definir_sprite(t_loot);
		}
		if( x.Ver_Valor_Nodo()==5){
			x.Definir_sprite(t_boss);
		}
		if( x.Ver_Valor_Nodo()==6){
			x.Definir_sprite(t_start);
		}
		
	}
}

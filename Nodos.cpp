#include "Nodos.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Nodos::Nodos(){
	int valor_Aux_nodo = (rand()%100)+1;
	if( valor_Aux_nodo > 0 and valor_Aux_nodo < 26 ){
		Tipo_de_Nodo = 1;
	}
	if( valor_Aux_nodo > 25 and valor_Aux_nodo < 81 ){
		Tipo_de_Nodo = 2;
	}
	if( valor_Aux_nodo > 80 and valor_Aux_nodo < 91 ){
		Tipo_de_Nodo = 3;
	}
	if( valor_Aux_nodo > 90 and valor_Aux_nodo < 101 ){
		Tipo_de_Nodo = 4;
	}
	s_nodo.setOrigin(25,25);
}

Nodos::Nodos(int tipo_nuevo_nodo){
	Tipo_de_Nodo = tipo_nuevo_nodo;
	s_nodo.setOrigin(25,25);
}

int Nodos::Ver_Valor_Nodo ( ) {
	return Tipo_de_Nodo;
}

void Nodos::Definir_tipo_nodo ( int t_nodo) {
	Tipo_de_Nodo = t_nodo;
}

void Nodos::Dibujar (RenderWindow &ventana) {
	ventana.draw(s_nodo);
}

void Nodos::Cambiar_pos_nodo (float posx, float posy) {
	s_nodo.setPosition(posx, posy);
}

void Nodos::Definir_sprite (Texture &t_textura) {
	s_nodo.setTexture(t_textura);
}


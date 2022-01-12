#include "Menu_Inventario.h"
#include "Player.h"
#include <iostream>
using namespace std;

Menu_Inventario::Menu_Inventario(Player &Jugador, list<Filas_De_Nodos> vector_filas, int pos_selector) : fondito("Imagenes/Fondos/fondo.jpg"), Titulo("Inventario", 40){
	Titulo.Cambiar_Pos_Cuadro_Menu(600,100);
	Titulo.Cambiar_Pos_Opcion_Menu(600,90);
	
	//Copio los datos del mapa para ejecutarlo nuevamente mas tarde;
	v_de_filas = vector_filas;
	p_del_selector = pos_selector;
	personaje_aux = Jugador;
	
	inv_aux = Jugador.Obtener_Inventario();
	int rareza_aux, tipo_aux;
	int contador = 0;
	for(Objeto &x : inv_aux){
		if (contador == 0){ x.CambiarPos(300,300); x.setTipo(1); }
		if (contador == 1){ x.CambiarPos(600,300); x.setTipo(2); }
		if (contador == 2){ x.CambiarPos(900,300); x.setTipo(3); }
		contador++;
	}
}


void Menu_Inventario::Actualizar (RenderWindow & ventana, Juego & j) {
	if (Keyboard::isKeyPressed(Keyboard::Escape)){
		j.Cambiar_Escena(new Menu_mapa(personaje_aux, v_de_filas, p_del_selector));
	}
}

void Menu_Inventario::Dibujar (RenderWindow & ventana) {
	fondito.Dibujar(ventana);
	Titulo.Dibujar(ventana);
	for(Objeto &x : inv_aux){
		x.Dibujar(ventana);
	}
}


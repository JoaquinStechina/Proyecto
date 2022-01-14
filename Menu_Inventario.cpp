#include "Menu_Inventario.h"
#include "Player.h"
#include <iostream>
using namespace std;

Menu_Inventario::Menu_Inventario(Player &Jugador, list<Filas_De_Nodos> vector_filas, int pos_selector) : fondito("Imagenes/Fondos/fondo2_1.png"), Titulo("Inventario", 40){
	Titulo.Cambiar_Pos_Cuadro_Menu(600,100);
	Titulo.Cambiar_Pos_Opcion_Menu(600,90);
	
	//Hago un fondo gris para el texto;
	Fondo_Base.setSize(Vector2f(1000.f,200.f));
	Fondo_Base.setOrigin(Vector2f(500.f, 100.f));
	Fondo_Base.setFillColor(Color(255,255,255,128));
	Fondo_Base.setPosition(600.f,450.f);
	
	//Copio los datos del mapa para ejecutarlo nuevamente mas tarde;
	v_de_filas = vector_filas;
	p_del_selector = pos_selector;
	personaje_aux = Jugador;
	inv_aux = Jugador.Obtener_Inventario();
	
	//Pongo los objetos en su lugar
	int contador = 0;
	for(Objeto &x : inv_aux){
		if (contador == 0){ x.CambiarPos(300,250); x.setTipo(1); }
		if (contador == 1){ x.CambiarPos(600,250); x.setTipo(2); }
		if (contador == 2){ x.CambiarPos(900,250); x.setTipo(3); }
		contador++;
	}
	
	//Configuro Descripcion
	Fuente.loadFromFile("Fuentes/Triforce.ttf");
	Nombre.setFont(Fuente);
	Nombre.setFillColor(Color(0,0,0));
	Nombre.setCharacterSize(35);
	Nombre.setPosition(120,430);
	Nombre.setString("vacio");
}


void Menu_Inventario::Actualizar (RenderWindow & ventana, Juego & j) {
	int cont_inv;
	cont_pos = Selector1.Actualizar(ventana);
	if (reloj.getElapsedTime().asSeconds() > 0.2){
		if (Keyboard::isKeyPressed(Keyboard::Escape)){
			j.Cambiar_Escena(new Menu_mapa(personaje_aux, v_de_filas, p_del_selector));
			reloj.restart();
		}
		if ( cont_pos == 0){
			cont_inv = 0;
			Selector1.Cambiar_Pos(250,250);
			reloj.restart();
			for ( Objeto &x : inv_aux ){
				cont_inv++;
				if( cont_inv == 1 ){ Nombre.setString(x.getNombre()); }
			}
		}
		if ( cont_pos == 1){
			cont_inv = 0;
			Selector1.Cambiar_Pos(550,250);
			reloj.restart();
			for ( Objeto &x : inv_aux ){
				cont_inv++;
				if( cont_inv == 2 ){ Nombre.setString(x.getNombre()); }
			}
		}
		if ( cont_pos == 2){
			cont_inv = 0;
			Selector1.Cambiar_Pos(850,250);
			reloj.restart();
			for ( Objeto &x : inv_aux ){
				cont_inv++;
				if( cont_inv == 3 ){ Nombre.setString(x.getNombre()); }
			}
		}
	}
}

void Menu_Inventario::Dibujar (RenderWindow & ventana) {
	fondito.Dibujar(ventana);
	Titulo.Dibujar(ventana);
	for(Objeto &x : inv_aux){
		x.Dibujar(ventana);
	}
	Selector1.Dibujar(ventana);
	ventana.draw(Fondo_Base);
	ventana.draw(Nombre);
}


#include "Menu_mapa.h"
#include <SFML/System.hpp>
#include "Menu_Principal.h"
#include <vector>
#include <iostream>
using namespace std;

Menu_mapa::Menu_mapa() : Fondo_juego("Imagenes/Fondos/fondo.jpg"), titulo("Piso 1", 40){
	
	//Hago un fondo gris para el mapa;
	Fondo_Base.setSize(Vector2f(1000.f,400.f));
	Fondo_Base.setOrigin(Vector2f(500.f, 200.f));
	Fondo_Base.setFillColor(Color(255,255,255,128));
	Fondo_Base.setPosition(600.f,300.f);
	
	//Declaro las texturas
	t_campfire.loadFromFile("Imagenes/Sprites/campfire.png");
	t_mercado.loadFromFile("Imagenes/Sprites/Mercado.png");
	t_loot.loadFromFile("Imagenes/Sprites/loot.png");
	t_encuentro.loadFromFile("Imagenes/Sprites/Encuentro.png");
	t_start.loadFromFile("Imagenes/Sprites/Start.png");
	t_boss.loadFromFile("Imagenes/Sprites/Boss.png");
	
	//Creo la fila inicial, final, y las aleatorias del medio y las meto en un vector de filas;
	int cant_nodos_totales = 0;
	Filas_De_Nodos fila_inicial(6);
	Filas_De_Nodos fila_final(5);
	
	while(cant_nodos_totales<13){	//Que no aparezcan menos de 7 nodos;
		cant_nodos_totales=0;
		if(!V_Filas.empty()){  //Si no esta vacio se vacia;
			V_Filas.erase(V_Filas.begin(), V_Filas.end());
		}
		V_Filas.push_back(fila_inicial);
		for(int i=1;i<7;i++) { //Cantidad de columnas a aparecer;
			Filas_De_Nodos fila_aux(true);
			V_Filas.push_back(fila_aux);
		}
		V_Filas.push_back(fila_final);
		for(Filas_De_Nodos &x: V_Filas){
			cant_nodos_totales = cant_nodos_totales + x.Ver_Cantidad_Nodos();
		}
	}
	
	//Posiciono los nodos;
	int cont = 0;
	for(Filas_De_Nodos &x : V_Filas) {
		float posx = ((1000.f/(V_Filas.size()+1))*(cont+1))+100;
		x.Posicionar_Nodos(posx);
		cont++;
	}
	
	//Les asigno sus sprites;
	for( Filas_De_Nodos &x : V_Filas ){
		x.Set_Sprite_nodos(t_mercado, t_campfire, t_loot, t_start, t_boss, t_encuentro);
	}
	
	//Posiciono mi selector;
	columna_actual_flecha = 2;
	selec_mapa.Cambiar_Pos((((1000.f/(V_Filas.size()+1))*(columna_actual_flecha))+50), 300.f);
	
	//Sonidos;
	sb_buffer_enter.loadFromFile( "Sonidos/Menu_select.wav" );
	s_sonido_enter.setBuffer(sb_buffer_enter);
	
	//Titulo
	titulo.Cambiar_Escala_Opcion_Menu(1.2);
	titulo.Cambiar_Pos_Opcion_Menu(600,40);
	titulo.Cambiar_Pos_Cuadro_Menu(600,50);
}

void Menu_mapa::Actualizar (RenderWindow & ventana, Juego & j) {
	if (Keyboard::isKeyPressed(Keyboard::Escape)){
		j.Cambiar_Escena(new Menu_Principal);
		s_sonido_enter.play();
	}
	selec_mapa.Actualizar(ventana, V_Filas,columna_actual_flecha);
}

void Menu_mapa::Dibujar (RenderWindow & ventana) {
	Fondo_juego.Dibujar(ventana);
	ventana.draw(Fondo_Base);
	for(Filas_De_Nodos x : V_Filas) { 
		x.Dibujar(ventana);
	}
	selec_mapa.Dibujar(ventana);
	titulo.Dibujar(ventana);
}


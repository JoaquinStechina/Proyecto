#include "Menu_Tienda.h"
#include "Menu_mapa.h"
#include "Menu_Principal.h"
#include <iostream>
using namespace std;

Menu_Tienda::Menu_Tienda(Player &Jugador, list<Filas_De_Nodos> vector_filas, int pos_selector, Lista_de_objetos listita) : fondo_menu_principal("Imagenes/Fondos/fondo2_1.png"), Opcion1("Opcion Uno",25), Opcion2("Opcion Dos",25), Opcion3("Opcion Tres",25), precio1("0",30), precio2("0",30), precio3("0",30), monedas("0",30) {	
	//Configuracion de sonido y reloj
	sb_buffer.loadFromFile("Sonidos/Menu_select.wav");
	s_sonido_enter.setBuffer(sb_buffer);
	reloj.restart();
	
	//Copio los datos del mapa para ejecutarlo nuevamente mas tarde;
	v_de_filas = vector_filas;
	p_del_selector = pos_selector;
	personaje_aux = Jugador;
	inv_aux = Jugador.Obtener_Inventario();
	
	//Creo la lista de objetos que estan a la venta
	int objeto1, objeto2, objeto3, contadorcito;
	objeto1 = rand()%12+4;
	objeto2 = rand()%12+4;
	objeto3 = rand()%12+4;
	while ( objeto2 == objeto1 ){objeto2 = rand()%12+3;}
	while ( objeto3 == objeto1 or objeto3 == objeto2 ){objeto3 = rand()%12+3;}
	for (Objeto &x : listita.objetos_del_juego){
		contadorcito++;
		if (contadorcito == objeto1){stock.push_back(x);}
		if (contadorcito == objeto2){stock.push_back(x);}
		if (contadorcito == objeto3){stock.push_back(x);}
	}
	
	//Coloco datos de los objetos en el menu;
	contadorcito = 0;
	for(Objeto &x : stock){
		contadorcito++;
		if (contadorcito == 1){Opcion1.Cambiar_texto(x.getNombre()); Op1 = x;}
		if (contadorcito == 2){Opcion2.Cambiar_texto(x.getNombre()); Op2 = x;}
		if (contadorcito == 3){Opcion3.Cambiar_texto(x.getNombre()); Op3 = x;}
	}
	//Posiciono las opciones y el selector
	Opcion1.Cambiar_Pos_Opcion_Menu(300,145);
	Opcion1.Cambiar_Pos_Cuadro_Menu(300,150);
	Opcion2.Cambiar_Pos_Opcion_Menu(300,295);
	Opcion2.Cambiar_Pos_Cuadro_Menu(300,300);
	Opcion3.Cambiar_Pos_Opcion_Menu(300,445);
	Opcion3.Cambiar_Pos_Cuadro_Menu(300,450);
	Selector1.Cambiar_Pos(50, 150);
	
	//Pongo los precios;
	precio1.Cambiar_Pos_Cuadro_mapa(900,145);
	precio1.Cambiar_Pos_Opcion_mapa(900,150);
	precio2.Cambiar_Pos_Cuadro_mapa(900,295);
	precio2.Cambiar_Pos_Opcion_mapa(900,300);
	precio3.Cambiar_Pos_Cuadro_mapa(900,445);
	precio3.Cambiar_Pos_Opcion_mapa(900,450);
	contadorcito = 0;
	for(Objeto &x : stock){
		contadorcito++;
		if(contadorcito == 1){ precio1.Cambiar_texto(to_string(x.getPrecio())); p1 = x.getPrecio(); t1 = x.getTipo();}
		if(contadorcito == 2){ precio2.Cambiar_texto(to_string(x.getPrecio())); p2 = x.getPrecio(); t2 = x.getTipo();}
		if(contadorcito == 3){ precio3.Cambiar_texto(to_string(x.getPrecio())); p3 = x.getPrecio(); t3 = x.getTipo();}
	}
	precio1.Cambiar_color_fuente(Color(255,200,60));
	precio2.Cambiar_color_fuente(Color(255,200,60));
	precio3.Cambiar_color_fuente(Color(255,200,60));
	
	monedas.Cambiar_Pos_Cuadro_mapa(1125,550);
	monedas.Cambiar_Pos_Opcion_mapa(1125,540);
	monedas.Cambiar_texto(to_string(Jugador.GetMonedas()));
	monedas.Cambiar_color_fuente(Color(255,200,60));
	
	if(!stock.empty()){cout<<"Stock lleno!!"<<endl;}
	else{cout<<"Stock vacio!!"<<endl;}
}


void Menu_Tienda::Actualizar (RenderWindow & ventana, Juego & j) {
	precio1.Actualizar();
	precio2.Actualizar();
	precio3.Actualizar();
	monedas.Actualizar();
	cont_pos = Selector1.Actualizar(ventana);
	if (reloj.getElapsedTime().asSeconds() > 0.2){
		if (Keyboard::isKeyPressed(Keyboard::Escape)){
			j.Cambiar_Escena(new Menu_mapa(personaje_aux, v_de_filas, p_del_selector));
			reloj.restart();
		}
		if ( cont_pos == 0){
			Selector1.Cambiar_Pos(50,150);
			if(Keyboard::isKeyPressed(Keyboard::Space)){
				if ( personaje_aux.GetMonedas() >= p1 ){
					int contadorcito = 0;
					for(Objeto &x : inv_aux){
						contadorcito++;
						if( contadorcito == t1 ){
							x = Op1;
						}
					}
					personaje_aux.SetMonedas(personaje_aux.GetMonedas()-p1);
					personaje_aux.Set_Inventario(inv_aux);
					monedas.Cambiar_texto(to_string(personaje_aux.GetMonedas()));
				}
				s_sonido_enter.play();
				reloj.restart();
			}
		}
		if ( cont_pos == 1){
			Selector1.Cambiar_Pos(50,300);
			if(Keyboard::isKeyPressed(Keyboard::Space)){
				if ( personaje_aux.GetMonedas() >= p2 ){
					int contadorcito = 0;
					for(Objeto &x : inv_aux){
						contadorcito++;
						if( contadorcito == t2 ){
							x = Op2;
						}
					}
					personaje_aux.SetMonedas(personaje_aux.GetMonedas()-p2);
					personaje_aux.Set_Inventario(inv_aux);
					monedas.Cambiar_texto(to_string(personaje_aux.GetMonedas()));
				}
				s_sonido_enter.play();
				reloj.restart();
			}
			
		}
		if ( cont_pos == 2){
			Selector1.Cambiar_Pos(50,450);
			if (Keyboard::isKeyPressed(Keyboard::Space)){
				if ( personaje_aux.GetMonedas() >= p3 ){
					int contadorcito = 0;
					for(Objeto &x : inv_aux){
						contadorcito++;
						if( contadorcito == t3 ){
							x = Op3;
						}
					}
					personaje_aux.SetMonedas(personaje_aux.GetMonedas()-p3);
					personaje_aux.Set_Inventario(inv_aux);
					monedas.Cambiar_texto(to_string(personaje_aux.GetMonedas()));
				}
				s_sonido_enter.play();
				reloj.restart();
			}
		}
	}
}

void Menu_Tienda::Dibujar (RenderWindow & ventana) {
	fondo_menu_principal.Dibujar(ventana);
	Opcion1.Dibujar(ventana);
	Opcion2.Dibujar(ventana);
	Opcion3.Dibujar(ventana);
	Selector1.Dibujar(ventana);
	precio1.Dibujar(ventana);
	precio2.Dibujar(ventana);
	precio3.Dibujar(ventana);
	monedas.Dibujar(ventana);
}


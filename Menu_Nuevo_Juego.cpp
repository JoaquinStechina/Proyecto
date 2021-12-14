#include "Menu_Nuevo_Juego.h"
#include "Menu_Principal.h"
#include "Menu_Nueva_Partida.h"

Menu_Nuevo_Juego::Menu_Nuevo_Juego() : fondo("Imagenes/Fondos/fondo2_1.png"), Opcion1("Nueva partida",35),Opcion2("Cargar partida",35){
	Opcion1.Cambiar_Escala_Opcion_Menu(1.2);
	Opcion1.Cambiar_Pos_Opcion_Menu(600,140);
	Opcion1.Cambiar_Pos_Cuadro_Menu(600,150);
	Opcion2.Cambiar_Escala_Opcion_Menu(1.2);
	Opcion2.Cambiar_Pos_Opcion_Menu(600,255);
	Opcion2.Cambiar_Pos_Cuadro_Menu(600,260);
	Selector1.Cambiar_Pos(400, 150);
	
	sb_buffer.loadFromFile("Sonidos/Menu_select.wav");
	s_sonido_enter.setBuffer(sb_buffer);
	
	reloj.restart();
}

void Menu_Nuevo_Juego::Actualizar (RenderWindow & ventana, Juego & j) {
	cont_pos = Selector1.Actualizar(ventana);
	if (reloj.getElapsedTime().asSeconds() > 0.2){
		if (Keyboard::isKeyPressed(Keyboard::Escape)){
			j.Cambiar_Escena(new Menu_Principal);
			reloj.restart();
		}
		if ( cont_pos == 0){
			Selector1.Cambiar_Pos(400,150);
			if(Keyboard::isKeyPressed(Keyboard::Space)){
				j.Cambiar_Escena(new Menu_Nueva_Partida);
				s_sonido_enter.play();
				reloj.restart();
			}
		}
		if ( cont_pos == 1){
			Selector1.Cambiar_Pos(400,260);
		}
	}	
}

void Menu_Nuevo_Juego::Dibujar (RenderWindow & ventana) {
	fondo.Dibujar(ventana);
	Opcion1.Dibujar(ventana);
	Opcion2.Dibujar(ventana);
	Selector1.Dibujar(ventana);
}


#include "Menu_Principal.h"
#include "Juego.h"
#include "Menu_Sobre_este_juego.h"
#include "Menu_mapa.h"
#include "Menu_Nuevo_Juego.h"
#include "Player.h"

Menu_Principal::Menu_Principal() : fondo_menu_principal("Imagenes/Fondos/fondo2_1.png"), Opcion1("Jugar", 38), Opcion2("Sobre el Proyecto", 25), Opcion3("Salir", 25){
	Opcion1.Cambiar_Escala_Opcion_Menu(1.2);
	Opcion1.Cambiar_Pos_Opcion_Menu(600,140);
	Opcion1.Cambiar_Pos_Cuadro_Menu(600,150);
	Opcion2.Cambiar_Escala_Opcion_Menu(1);
	Opcion2.Cambiar_Pos_Opcion_Menu(600,255);
	Opcion2.Cambiar_Pos_Cuadro_Menu(600,260);
	Opcion3.Cambiar_Escala_Opcion_Menu(1);
	Opcion3.Cambiar_Pos_Opcion_Menu(600,355);
	Opcion3.Cambiar_Pos_Cuadro_Menu(600,360);
	Selector1.Cambiar_Pos(400, 150);
	Selector1.setCont_Max(3);
	
	sb_buffer.loadFromFile("Sonidos/Menu_select.wav");
	s_sonido_enter.setBuffer(sb_buffer);
	
	reloj.restart();
}


void Menu_Principal::Actualizar (RenderWindow &ventana, Juego &j) {
	cont_pos = Selector1.Actualizar(ventana);
	if (reloj.getElapsedTime().asSeconds() > 0.2){
		if (Keyboard::isKeyPressed(Keyboard::Escape)){
			ventana.close();
			reloj.restart();
		}
		if ( cont_pos == 0){
			Selector1.Cambiar_Pos(400,150);
			if(Keyboard::isKeyPressed(Keyboard::Space)){
				j.Cambiar_Escena(new Menu_Nuevo_Juego);
				s_sonido_enter.play();
				reloj.restart();
			}
		}
		if ( cont_pos == 1){
			Selector1.Cambiar_Pos(400,260);
			if(Keyboard::isKeyPressed(Keyboard::Space)){
				j.Cambiar_Escena(new Menu_Sobre_este_juego);
				s_sonido_enter.play();
				reloj.restart();
			}
			
		}
		if ( cont_pos == 2){
			Selector1.Cambiar_Pos(400,360);
			if (Keyboard::isKeyPressed(Keyboard::Space)){
				j.Cambiar_Escena(new Menu_mapa(rockermen));
				s_sonido_enter.play();
				reloj.restart();
			}
		}
	}
}

void Menu_Principal::Dibujar (RenderWindow & ventana) {
	fondo_menu_principal.Dibujar(ventana);
	Opcion1.Dibujar(ventana);
	Opcion2.Dibujar(ventana);
	Opcion3.Dibujar(ventana);
	Selector1.Dibujar(ventana);
}


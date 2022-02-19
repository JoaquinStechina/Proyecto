#include "Menu_Nueva_Partida.h"
#include "Menu_Nuevo_Juego.h"

Menu_Nueva_Partida::Menu_Nueva_Partida() : fondo("Imagenes/Fondos/fondo2_1.png"), opc1("Creador de Personaje",50), Menu("Imagenes/Sprites/letrero_emerald.png") {
	opc1.Cambiar_Escala_Opcion_Menu(2);
	opc1.Cambiar_Pos_Cuadro_Menu(600,100);
	opc1.Cambiar_Pos_Opcion_Menu(600,90); 
	Menu.cambiar_posicion_bloque(200,200);
	Menu.cambiar_escala_bloque(0.35,0.1);
	sb_buffer.loadFromFile("Sonidos/Menu_select.wav");
	s_sonido_enter.setBuffer(sb_buffer);
}

void Menu_Nueva_Partida::Actualizar (RenderWindow & ventana, Juego & j) {
	//cont_pos = Selector1.Actualizar(ventana);
	if (reloj.getElapsedTime().asSeconds() > 0.2){
		if (Keyboard::isKeyPressed(Keyboard::Escape)){
			j.Cambiar_Escena(new Menu_Nuevo_Juego);
			s_sonido_enter.play();
			reloj.restart();
		}
	}
}

void Menu_Nueva_Partida::Dibujar (RenderWindow & ventana) {
	fondo.Dibujar(ventana);
	opc1.Dibujar(ventana);
	Menu.Dibujar_bloque(ventana);
}


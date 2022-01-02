#include "Menu_Inventario.h"
#include "Player.h"

Menu_Inventario::Menu_Inventario(Player &Jugador, Menu_mapa Mapa) : mapa_aux(Jugador), fondito("Imagenes/Fondos/fondo.jpg"), Titulo("Inventario", 40){
	mapa_aux = Mapa;
	Titulo.Cambiar_Pos_Cuadro_Menu(600,300);
	Titulo.Cambiar_Pos_Opcion_Menu(600,300);
}


void Menu_Inventario::Actualizar (RenderWindow & ventana, Juego & j) {
	if (Keyboard::isKeyPressed(Keyboard::Escape)){
		j.Cambiar_Escena(&mapa_aux);
		/*s_sonido_enter.play();*/
	}
}

void Menu_Inventario::Dibujar (RenderWindow & ventana) {
	fondito.Dibujar(ventana);
	Titulo.Dibujar(ventana);
}


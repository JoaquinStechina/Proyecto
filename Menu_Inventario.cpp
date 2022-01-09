#include "Menu_Inventario.h"
#include "Player.h"

Menu_Inventario::Menu_Inventario(Player &Jugador, list<Filas_De_Nodos> vector_filas, int pos_selector) : fondito("Imagenes/Fondos/fondo.jpg"), Titulo("Inventario", 40){
	Titulo.Cambiar_Pos_Cuadro_Menu(600,300);
	Titulo.Cambiar_Pos_Opcion_Menu(600,300);
	//Copio el vector y la posicion del selector;
	v_de_filas = vector_filas;
	p_del_selector = pos_selector;
	personaje_aux = Jugador;
}


void Menu_Inventario::Actualizar (RenderWindow & ventana, Juego & j) {
	if (Keyboard::isKeyPressed(Keyboard::Escape)){
		j.Cambiar_Escena(new Menu_mapa(personaje_aux, v_de_filas, p_del_selector));
		/*s_sonido_enter.play();*/
	}
}

void Menu_Inventario::Dibujar (RenderWindow & ventana) {
	fondito.Dibujar(ventana);
	Titulo.Dibujar(ventana);
}


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
	Selector1.setCont_Max(2);
	
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
			if(Keyboard::isKeyPressed(Keyboard::Space)){
				az = save.getStructJugador();
				ay = save.getStructMapa();
				Player* aux_player = new Player(az);
				if(!aux_v.empty()){  //Si no esta vacio se vacia;
					aux_v.erase(aux_v.begin(), aux_v.end());
				}
				for(int i=0;i<8;i++) { 
					cout<<i<<" ";
					if(!aux_n.empty()){  //Si no esta vacio se vacia;
						aux_n.erase(aux_n.begin(), aux_n.end());
					}
					for(int j=0;j<ay.aux_filas_nodos[i].tamanio_fila_nodo;j++) {
						Nodos otro_aux(ay.aux_filas_nodos[i].aux_nod[j].tipo_de_nodo);
						aux_n.push_back(otro_aux);
						cout<<j<<" ";
					}
					
					Filas_De_Nodos otro_aux2(aux_n,ay.aux_filas_nodos[i].tamanio_fila_nodo);
					aux_v.push_back(otro_aux2);
					cout<<endl;
				}
				j.Cambiar_Escena(new Menu_mapa(*aux_player,aux_v,ay.c_a_f));
				s_sonido_enter.play();
				reloj.restart();
			}
		}
	}	
}

void Menu_Nuevo_Juego::Dibujar (RenderWindow & ventana) {
	fondo.Dibujar(ventana);
	Opcion1.Dibujar(ventana);
	Opcion2.Dibujar(ventana);
	Selector1.Dibujar(ventana);
}


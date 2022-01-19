#ifndef MENU_TIENDA_H
#define MENU_TIENDA_H
#include "Escena.h"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/System/Clock.hpp>
#include "Fondo.h"
#include "Selector_de_menu.h"
#include "Player.h"
#include <list>
#include "Filas_De_Nodos.h"
#include "Lista_de_objetos.h"
#include "Objeto.h"
#include "Opcion_De_Tienda.h"
#include "Opcion_de_mapa.h"
using namespace std;

class Menu_Tienda : public Escena, public Lista_de_objetos {
	//Menu;
	SoundBuffer sb_buffer;
	Sound s_sonido_enter;
	int cont_pos;
	Clock reloj;
	Fondo fondo_menu_principal;
	Opcion_De_Tienda Opcion1, Opcion2, Opcion3;
	Selector_de_menu Selector1;
	Opcion_de_mapa precio1, precio2, precio3, monedas;
	int p1,p2,p3,t1,t2,t3;
	Objeto Op1,Op2,Op3;
	
	//Personaje;
	Player personaje_aux;
	list<Objeto> inv_aux;
	
	//Datos del mapa;
	list<Filas_De_Nodos> v_de_filas;
	int p_del_selector;
	
	//Tienda;
	list<Objeto> stock;
public:
	Menu_Tienda(Player &Jugador, list<Filas_De_Nodos> vector_filas, int pos_selector);
	void Actualizar(RenderWindow &ventana, Juego &j) override;
	void Dibujar(RenderWindow &ventana) override;
};

#endif


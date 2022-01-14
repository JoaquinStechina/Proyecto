#ifndef MENU_INVENTARIO_H
#define MENU_INVENTARIO_H
#include "Escena.h"
#include "Player.h"
#include "Opcion_de_menu.h"
#include "Fondo.h"
#include "Menu_mapa.h"
#include "Juego.h"
#include <list>
#include "Objeto.h"
#include <SFML/System/Clock.hpp>
#include "Selector_Inventario.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
using namespace std;

class Menu_Inventario : public Escena {
	//Menu;
	Fondo fondito;
	Opcion_de_menu Titulo;
	Clock reloj;
	int cont_pos;
	Selector_Inventario Selector1;
	RectangleShape Fondo_Base;
	Text Nombre;
	Font Fuente;
	
	//Personaje;
	Player personaje_aux;
	list<Objeto> inv_aux;
	
	//Datos del mapa;
	list<Filas_De_Nodos> v_de_filas;
	int p_del_selector;
public:
	Menu_Inventario(Player &Jugador, list<Filas_De_Nodos> vector_filas, int pos_selector);
	void Actualizar(RenderWindow &ventana, Juego &j) override;
	void Dibujar(RenderWindow &ventana) override;
};

#endif


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
using namespace std;

class Menu_Inventario : public Escena {
	//Menu;
	Fondo fondito;
	Opcion_de_menu Titulo;
	
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
private:
};

#endif


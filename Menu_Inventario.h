#ifndef MENU_INVENTARIO_H
#define MENU_INVENTARIO_H
#include "Escena.h"
#include "Player.h"
#include "Opcion_de_menu.h"
#include "Fondo.h"
#include "Menu_mapa.h"
#include "Juego.h"

class Menu_Inventario : public Escena {
	Fondo fondito;
	Opcion_de_menu Titulo;
	Menu_mapa mapa_aux;
public:
	Menu_Inventario(Player &Jugador, Menu_mapa Mapa);
	void Actualizar(RenderWindow &ventana, Juego &j) override;
	void Dibujar(RenderWindow &ventana) override;
private:
};

#endif


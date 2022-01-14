#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include "Sprite_de_personaje.h"
#include "Fondo.h"
#include "Opcion_de_menu.h"
#include "Selector_de_menu.h"
#include "Juego.h"
#include <SFML/Audio.hpp>
#include "Player.h"
using namespace std;

class Menu_Principal : public Escena{
	//temporal, solo para ver que funcionen ciertas cosas, eliminar mas tarde;
	Player rockermen;
	
	//Menu
	SoundBuffer sb_buffer;
	Sound s_sonido_enter;
	int cont_pos;
	Clock reloj;
	Fondo fondo_menu_principal;
	Opcion_de_menu Opcion1;
	Opcion_de_menu Opcion2;
	Opcion_de_menu Opcion3;
	Selector_de_menu Selector1;
public:
	Menu_Principal();
	void Actualizar(RenderWindow &ventana, Juego &j) override;
	void Dibujar(RenderWindow &ventana) override;
};

#endif


#ifndef MENU_NUEVO_JUEGO_H
#define MENU_NUEVO_JUEGO_H
#include "Escena.h"
#include "Opcion_de_menu.h"
#include <SFML/System/Clock.hpp>
#include "Selector_de_menu.h"
#include "Fondo.h"
#include "Juego.h"
#include <SFML/Audio.hpp>

class Menu_Nuevo_Juego : public Escena {
	SoundBuffer sb_buffer;
	Sound s_sonido_enter;
	int cont_pos;
	Fondo fondo;
	Clock reloj;
	Opcion_de_menu Opcion1,Opcion2;
	Selector_de_menu Selector1;
public:
	Menu_Nuevo_Juego();
	void Actualizar (RenderWindow & ventana, Juego & j);
	void Dibujar (RenderWindow & ventana);
};

#endif

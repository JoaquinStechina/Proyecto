#ifndef MENU_NUEVA_PARTIDA_H
#define MENU_NUEVA_PARTIDA_H
#include "Escena.h"
#include "Opcion_de_menu.h"
#include <SFML/System/Clock.hpp>
#include "Selector_de_menu.h"
#include "Fondo.h"
#include "Juego.h"
#include <SFML/Audio.hpp>
#include "Sprites.h"

class Menu_Nueva_Partida : public Escena {
	SoundBuffer sb_buffer;
	Sound s_sonido_enter;
	int cont_pos;
	Fondo fondo;
	Clock reloj;
	Opcion_de_menu opc1;
public:
	Menu_Nueva_Partida();
	void Actualizar (RenderWindow & ventana, Juego & j);
	void Dibujar (RenderWindow & ventana);
};

#endif

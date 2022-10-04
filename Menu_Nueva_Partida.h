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
#include "Selector_de_menu.h"
#include "Bloque_Sprite.h"
#include <SFML/Graphics/Rect.hpp>
#include "Menu_mapa.h"
#include "Player.h"

using namespace sf;

class Menu_Nueva_Partida : public Escena {
	Player *player = new Player;
	Bloque_Sprite arreglo_cuadros[5];
	Bloque_Sprite Cuadro1, Cuadro2, Cuadro3;
	Clock reloj;
	Fondo fondo;
	int cont_pos;
	int puntos_disponibles = 10;
	Opcion_de_menu arreglo[5];
	Selector_de_menu Selector1;
	SoundBuffer sb_buffer;
	Sound s_sonido_enter;
<<<<<<< HEAD
	Bloque_Sprite Menu;
	int cont_pos;
	Fondo fondo;
	Clock reloj;
	Opcion_de_menu arreglo[6];
=======
>>>>>>> 28ece76b321902082f09f974b70b20f07fab9ab4
public:
	Menu_Nueva_Partida ();
	void Actualizar    (RenderWindow & ventana, Juego & j);
	void Dibujar       (RenderWindow & ventana);
	~Menu_Nueva_Partida();
};

#endif

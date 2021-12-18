#ifndef MENU_MAPA_H
#define MENU_MAPA_H
#include "Escena.h"
#include <SFML/Graphics.hpp>
#include "Fondo.h"
#include "Filas_De_Nodos.h"
#include <list>
#include "Selector_De_Mapa.h"
#include <SFML/Audio.hpp>
#include "Opcion_de_menu.h"
using namespace std;

class Menu_mapa : public Escena {
	//Barra de vida;
	Texture bar_vacia;
	Texture hpbar;
	Texture manabar;
	Texture bar_level;
	
	//Sonidos
	SoundBuffer sb_buffer_enter;
	Sound s_sonido_enter;
	
	//Fondo
	RectangleShape Fondo_Base;
	Fondo Fondo_juego;
	Opcion_de_menu titulo;
	
	//Selector y filas
	list<Filas_De_Nodos> V_Filas;
	Selector_De_Mapa selec_mapa;
	int columna_actual_flecha;
	
	//Iconos del mapa
	Texture t_campfire;
	Texture t_mercado;
	Texture t_start;
	Texture t_boss;
	Texture t_encuentro;
	Texture t_loot;
public:
	Menu_mapa();
	void Actualizar(RenderWindow &ventana, Juego &j) override;
	void Dibujar(RenderWindow &ventana) override;
};

#endif


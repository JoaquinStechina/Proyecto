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
#include "Player.h"
#include "Opcion_de_mapa.h"
using namespace std;

class Menu_mapa : public Escena {
	//UI;
	Texture bar_vacia, hpbar, manabar, bar_level, t_moneda_icon;
	Sprite s_empty_bar, s_hp_bar, s_mana_bar, s_bar_lvl, s_moneda_icon;
	Opcion_de_mapa monedas;
	Opcion_de_menu titulo, inventario;
	
	//Sonidos
	SoundBuffer sb_buffer_enter;
	Sound s_sonido_enter;
	
	//Fondo
	RectangleShape Fondo_Base;
	Fondo Fondo_juego;
	
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
	
	//Personaje;
	Player personaje;
public:
	Menu_mapa(Player &Personaje);
	Menu_mapa(Player &Personaje, list<Filas_De_Nodos> vector_de_filas, int columna_actual);
	void Actualizar(RenderWindow &ventana, Juego &j) override;
	void Dibujar(RenderWindow &ventana) override;
};

#endif


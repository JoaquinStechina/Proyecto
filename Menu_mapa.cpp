#include "Menu_mapa.h"
#include <SFML/System.hpp>
#include "Menu_Principal.h"
#include <vector>
#include <iostream>
#include "Player.h"
#include "Menu_Inventario.h"
#include "Menu_Tienda.h"
using namespace std;

Menu_mapa::Menu_mapa(Player &m_Personaje) : Fondo_juego("Imagenes/Fondos/fondo.jpg"), titulo("Piso 1", 40), monedas("0",30), inventario("inventario", 30),guardar_partida("Guardar Partida",30){
	
	personaje = m_Personaje;
	
	//Hago un fondo gris para el mapa;
	Fondo_Base.setSize(Vector2f(1000.f,400.f));
	Fondo_Base.setOrigin(Vector2f(500.f, 200.f));
	Fondo_Base.setFillColor(Color(255,255,255,128));
	Fondo_Base.setPosition(600.f,300.f);
	
	//Declaro las texturas
	t_campfire.loadFromFile("Imagenes/Sprites/campfire.png");
	t_mercado.loadFromFile("Imagenes/Sprites/Mercado.png");
	t_loot.loadFromFile("Imagenes/Sprites/loot.png");
	t_encuentro.loadFromFile("Imagenes/Sprites/Encuentro.png");
	t_start.loadFromFile("Imagenes/Sprites/Start.png");
	t_boss.loadFromFile("Imagenes/Sprites/Boss.png");
	bar_vacia.loadFromFile("Imagenes/HP_Bar/backplate.png");
	bar_vacia.setSmooth(true);
	hpbar.loadFromFile("Imagenes/HP_Bar/left_bar.png");
	hpbar.setSmooth(true);
	manabar.loadFromFile("Imagenes/HP_Bar/right_bar.png");
	manabar.setSmooth(true);
	bar_level.loadFromFile("Imagenes/HP_Bar/mid_top.png");
	bar_level.setSmooth(true);
	
	//Creo la fila inicial, final, y las aleatorias del medio y las meto en un vector de filas;
	int cant_nodos_totales = 0;
	Filas_De_Nodos fila_inicial(6);
	Filas_De_Nodos fila_final(5);
	
	while(cant_nodos_totales<13){	//Que no aparezcan menos de 7 nodos;
		cant_nodos_totales=0;
		if(!V_Filas.empty()){  //Si no esta vacio se vacia;
			V_Filas.erase(V_Filas.begin(), V_Filas.end());
		}
		V_Filas.push_back(fila_inicial);
		for(int i=1;i<7;i++) { //Cantidad de columnas a aparecer;
			Filas_De_Nodos fila_aux(true);
			V_Filas.push_back(fila_aux);
		}
		V_Filas.push_back(fila_final);
		for(Filas_De_Nodos &x: V_Filas){
			cant_nodos_totales = cant_nodos_totales + x.Ver_Cantidad_Nodos();
		}
	}
	
	//Posiciono los nodos;
	int cont = 0;
	for(Filas_De_Nodos &x : V_Filas) {
		float posx = ((1000.f/(V_Filas.size()+1))*(cont+1))+100;
		x.Posicionar_Nodos(posx);
		cont++;
	}
	
	//Les asigno sus sprites;
	for( Filas_De_Nodos &x : V_Filas ){
		x.Set_Sprite_nodos(t_mercado, t_campfire, t_loot, t_start, t_boss, t_encuentro);
	}
	
	//Posiciono mi selector;
	columna_actual_flecha = 2;
	selec_mapa.Cambiar_Pos((((1000.f/(V_Filas.size()+1))*(columna_actual_flecha))+50), 300.f);
	
	//Sonidos;
	sb_buffer_enter.loadFromFile( "Sonidos/Menu_select.wav" );
	s_sonido_enter.setBuffer(sb_buffer_enter);
	
	//Titulo
	titulo.Cambiar_Escala_Opcion_Menu(1.2);
	titulo.Cambiar_Pos_Opcion_Menu(600,40);
	titulo.Cambiar_Pos_Cuadro_Menu(600,50);
	
	//Barra de vida
	s_empty_bar.setTexture(bar_vacia);
	s_empty_bar.setPosition(387.75,493.5);
	s_empty_bar.setScale(0.5,0.5);
	s_hp_bar.setTexture(hpbar);
	s_hp_bar.setTextureRect(IntRect(0, 0, 424*(personaje.getVida_Actual()/personaje.getVidaMax()), 227));
	s_hp_bar.setPosition(387.75,492.5);
	s_hp_bar.setScale(0.5,0.5);
	s_mana_bar.setTexture(manabar);
	s_mana_bar.setScale(0.5,0.5);
	s_mana_bar.setOrigin(424.5,0);
	s_mana_bar.setTextureRect(IntRect(424+((1-(personaje.getMana_Actual()/personaje.getManaMax()))*424), 0, 424, 227));
	s_mana_bar.setPosition(811.75+((1-(personaje.getMana_Actual()/personaje.getManaMax()))*212),492.5);
	s_bar_lvl.setTexture(bar_level);
	s_bar_lvl.setPosition(387.75,493);
	s_bar_lvl.setScale(0.5,0.5);
	
	//Moneda
	t_moneda_icon.loadFromFile("Imagenes/Sprites/Monedas.png");
	s_moneda_icon.setTexture(t_moneda_icon);
	s_moneda_icon.setPosition(825,526);
	monedas.Cambiar_Pos_Cuadro_mapa(920,550);
	monedas.Cambiar_Pos_Opcion_mapa(920,540);
	string nueva_cant_monedas = to_string(personaje.GetMonedas());
	monedas.Cambiar_texto(nueva_cant_monedas);
	monedas.Cambiar_color_fuente(Color(255,200,60));
	
	//Inventario;
	inventario.Cambiar_Pos_Opcion_Menu(1000,40);
	inventario.Cambiar_Pos_Cuadro_Menu(1000,50);
	
	//Boton guardar partida;
	guardar_partida.Cambiar_Pos_Opcion_Menu(200,540);
	guardar_partida.Cambiar_Pos_Cuadro_Menu(200,550);
}

void Menu_mapa::Actualizar (RenderWindow & ventana, Juego & j) {
	if (Keyboard::isKeyPressed(Keyboard::Escape)){
		j.Cambiar_Escena(new Menu_Principal);
		s_sonido_enter.play();
	}
	if (Keyboard::isKeyPressed(Keyboard::I)){
		j.Cambiar_Escena(new Menu_Inventario(personaje, V_Filas, columna_actual_flecha));
		s_sonido_enter.play();
	}
	if (Keyboard::isKeyPressed(Keyboard::T)){
		j.Cambiar_Escena(new Menu_Tienda(personaje, V_Filas, columna_actual_flecha));
		s_sonido_enter.play();
	}
	if(Keyboard::isKeyPressed(Keyboard::G)){
		guardado a(personaje);
		s_sonido_enter.play();
	}
	selec_mapa.Actualizar(ventana, V_Filas,columna_actual_flecha);
	monedas.Actualizar();
}

void Menu_mapa::Dibujar (RenderWindow & ventana) {
	Fondo_juego.Dibujar(ventana);
	ventana.draw(Fondo_Base);
	for(Filas_De_Nodos x : V_Filas) { 
		x.Dibujar(ventana);
	}
	selec_mapa.Dibujar(ventana);
	titulo.Dibujar(ventana);
	ventana.draw(s_empty_bar);
	ventana.draw(s_hp_bar);
	ventana.draw(s_mana_bar);
	ventana.draw(s_bar_lvl);
	ventana.draw(s_moneda_icon);
	monedas.Dibujar(ventana);
	inventario.Dibujar(ventana);
	guardar_partida.Dibujar(ventana);
}


Menu_mapa::Menu_mapa (Player & Personaje, list<Filas_De_Nodos> vector_de_filas, int columna_actual) : Fondo_juego("Imagenes/Fondos/fondo.jpg"), titulo("Piso 1", 40), monedas("0",30), inventario("inventario", 30),guardar_partida("Guardar Partida",30) {
	personaje = Personaje;
	
	//Hago un fondo gris para el mapa;
	Fondo_Base.setSize(Vector2f(1000.f,400.f));
	Fondo_Base.setOrigin(Vector2f(500.f, 200.f));
	Fondo_Base.setFillColor(Color(255,255,255,128));
	Fondo_Base.setPosition(600.f,300.f);
	
	//Declaro las texturas
	t_campfire.loadFromFile("Imagenes/Sprites/campfire.png");
	t_mercado.loadFromFile("Imagenes/Sprites/Mercado.png");
	t_loot.loadFromFile("Imagenes/Sprites/loot.png");
	t_encuentro.loadFromFile("Imagenes/Sprites/Encuentro.png");
	t_start.loadFromFile("Imagenes/Sprites/Start.png");
	t_boss.loadFromFile("Imagenes/Sprites/Boss.png");
	bar_vacia.loadFromFile("Imagenes/HP_Bar/backplate.png");
	bar_vacia.setSmooth(true);
	hpbar.loadFromFile("Imagenes/HP_Bar/left_bar.png");
	hpbar.setSmooth(true);
	manabar.loadFromFile("Imagenes/HP_Bar/right_bar.png");
	manabar.setSmooth(true);
	bar_level.loadFromFile("Imagenes/HP_Bar/mid_top.png");
	bar_level.setSmooth(true);
	
	//Copio el vector y la posicion del selector;
	if(!V_Filas.empty()){  //Si no esta vacio se vacia;
		V_Filas.erase(V_Filas.begin(), V_Filas.end());
	}
	V_Filas = vector_de_filas;
	columna_actual_flecha = columna_actual;
	
	//Posiciono los nodos;
	int cont = 0;
	for(Filas_De_Nodos &x : V_Filas) {
		float posx = ((1000.f/(V_Filas.size()+1))*(cont+1))+100;
		x.Posicionar_Nodos(posx);
		cont++;
	}
	
	//Les asigno sus sprites;
	for( Filas_De_Nodos &x : V_Filas ){
		x.Set_Sprite_nodos(t_mercado, t_campfire, t_loot, t_start, t_boss, t_encuentro);
	}
	
	//Posiciono mi selector;
	selec_mapa.Cambiar_Pos((((1000.f/(V_Filas.size()+1))*(columna_actual_flecha))+50), 300.f);
	
	//Sonidos;
	sb_buffer_enter.loadFromFile( "Sonidos/Menu_select.wav" );
	s_sonido_enter.setBuffer(sb_buffer_enter);
	
	//Titulo
	titulo.Cambiar_Escala_Opcion_Menu(1.2);
	titulo.Cambiar_Pos_Opcion_Menu(600,40);
	titulo.Cambiar_Pos_Cuadro_Menu(600,50);
	
	//Barra de vida
	s_empty_bar.setTexture(bar_vacia);
	s_empty_bar.setPosition(387.75,493.5);
	s_empty_bar.setScale(0.5,0.5);
	s_hp_bar.setTexture(hpbar);
	s_hp_bar.setTextureRect(IntRect(0, 0, 424*(personaje.getVida_Actual()/personaje.getVidaMax()), 227));
	s_hp_bar.setPosition(387.75,492.5);
	s_hp_bar.setScale(0.5,0.5);
	s_mana_bar.setTexture(manabar);
	s_mana_bar.setScale(0.5,0.5);
	s_mana_bar.setOrigin(424.5,0);
	s_mana_bar.setTextureRect(IntRect(424+((1-(personaje.getMana_Actual()/personaje.getManaMax()))*424), 0, 424, 227));
	s_mana_bar.setPosition(811.75+((1-(personaje.getMana_Actual()/personaje.getManaMax()))*212),492.5);
	s_bar_lvl.setTexture(bar_level);
	s_bar_lvl.setPosition(387.75,493);
	s_bar_lvl.setScale(0.5,0.5);
	
	//Moneda
	t_moneda_icon.loadFromFile("Imagenes/Sprites/Monedas.png");
	s_moneda_icon.setTexture(t_moneda_icon);
	s_moneda_icon.setPosition(825,526);
	monedas.Cambiar_Pos_Cuadro_mapa(920,550);
	monedas.Cambiar_Pos_Opcion_mapa(920,540);
	string nueva_cant_monedas = to_string(personaje.GetMonedas());
	monedas.Cambiar_texto(nueva_cant_monedas);
	monedas.Cambiar_color_fuente(Color(255,200,60));
	
	//Inventario;
	inventario.Cambiar_Pos_Opcion_Menu(1000,40);
	inventario.Cambiar_Pos_Cuadro_Menu(1000,50);
	
	//Boton guardar partida;
	guardar_partida.Cambiar_Pos_Opcion_Menu(200,540);
	guardar_partida.Cambiar_Pos_Cuadro_Menu(200,550);
}


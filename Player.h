#ifndef PLAYER_H
#define PLAYER_H
#include "Stats.h"
#include "NPC.h"
#include <list>
#include "Objeto.h"
#include "Lista_de_objetos.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include "Elementos.h"
#include "Juego.h"
#include "Sprites.h"
using namespace std;

enum ESTADOS_ANIMACION_JUGADOR{QUIETO = 0, ATACANDO};

class Player : public Stats, public Lista_de_objetos, public Sprites{
	//Inicializacion
	void inicVariables();
	void inicTextura();
	void inicSprite();
	void inicAnimacion();
	
	//Animacion
	unsigned short animEstado;
	IntRect cuadroActual;
	Clock relojAnimacion;
	
	//Variables
	int nivel, exp, umbral_exp, monedas;
	list<Objeto> Inventario_Jugador;
public:
	Player();
	Player(Elementos_jugador &aux);
	virtual ~Player();
	
	//Getters
	int getNivel();
	int GetMonedas();
	list<Objeto> getInventario();
	
	//Setters
	void setNivel(int x);
	void SetMonedas(int cantMonedas);
	void Set_Inventario( list<Objeto> nuevo_inventario );
	
	//Funciones
	void SumarMonedas(int cantMonedas);
	void actualizarMovimiento();
	void Actualizar();
	void Dibujar (RenderWindow & ventana);
};

#endif

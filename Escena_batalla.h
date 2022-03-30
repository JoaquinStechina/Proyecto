#ifndef ESCENA_BATALLA_H
#define ESCENA_BATALLA_H
#include "Escena.h"
#include "Fondo.h"
#include "Juego.h"
#include "Player.h"
#include <vector>
#include "Opcion_de_menu.h"
using namespace std;

class Escena_batalla : public Escena{
private:
	Fondo fondo;
	Opcion_de_menu opciones[4];
	
	//Inicializacion
	void inicOpciones();
	
	Player jugador;
public:
	Escena_batalla(Player& jugador);
	~Escena_batalla();
	
	//Funciones
	void Actualizar (RenderWindow & ventana, Juego & j);
	void Dibujar (RenderWindow & ventana);
};

#endif


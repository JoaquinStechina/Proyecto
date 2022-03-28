#include "Escena_batalla.h"

Escena_batalla::Escena_batalla(Player& jugador):fondo("Imagenes/Fondos/FE-BG2.png") {
	this->jugador = jugador;
}

Escena_batalla::~Escena_batalla() {
	
}

void Escena_batalla::Actualizar(RenderWindow & ventana, Juego & j){
	this->jugador.Actualizar();
}

void Escena_batalla::Dibujar(RenderWindow & ventana){
	this->fondo.Dibujar(ventana);
	this->jugador.Dibujar(ventana);
}

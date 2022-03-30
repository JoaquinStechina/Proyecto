#include "Escena_batalla.h"

void Escena_batalla::inicOpciones(){
	for(int i=0;i<4;i++) { 
		switch(i){
		case 0:
			this->opciones[i].setOpcion("Atacar",30);
			break;
		case 1:
			this->opciones[i].setOpcion("Bloquear",30);
			break;
		case 2:
			this->opciones[i].setOpcion("Desviar",30);
			break;
		case 3:
			this->opciones[i].setOpcion("Magia",30);
			break;
		}
	}
}

Escena_batalla::Escena_batalla(Player& jugador): fondo("Imagenes/Fondos/FE-BG2.png"){
	this->inicOpciones();
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

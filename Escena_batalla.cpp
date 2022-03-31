#include "Escena_batalla.h"

void Escena_batalla::inicOpciones(){
	this->x = 180;
	this->y = 550;
	
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
		
		this->opciones[i].Cambiar_Pos_Cuadro_Menu(this->x, this->y);
		this->opciones[i].Cambiar_Pos_Opcion_Menu(this->x, this->y-10);
		this->x += 280;
	}
}

void Escena_batalla::inicSelector(){
	this->x = 180;
	this->y = 490;
	this->selector.Cambiar_Pos(this->x, this->y);
	this->selector.Rotar(90);
	this->selector.setCont_Max(4);
}

Escena_batalla::Escena_batalla(Player& jugador): fondo("Imagenes/Fondos/FE-BG2.png"){
	this->inicOpciones();
	this->inicSelector();
	this->jugador = jugador;
}

Escena_batalla::~Escena_batalla() {
	
}

void Escena_batalla::Actualizar(RenderWindow & ventana, Juego & j){
	char cont_pos = selector.Actualizar(ventana);
	this->jugador.Actualizar(cont_pos);
	if (reloj.getElapsedTime().asSeconds() > 0.2){
		if(cont_pos == 0){
			selector.Cambiar_Pos(this->x,this->y);
			reloj.restart();
		}
		if(cont_pos == 1){
			selector.Cambiar_Pos(this->x+280,this->y);
			reloj.restart();
		}
		if(cont_pos == 2){
			selector.Cambiar_Pos(this->x+(280*2),this->y);
			reloj.restart();
		}
		if(cont_pos == 3){
			selector.Cambiar_Pos(this->x+(280*3),this->y);
			reloj.restart();
		}
	}
}

void Escena_batalla::Dibujar(RenderWindow & ventana){
	this->fondo.Dibujar(ventana);
	this->jugador.Dibujar(ventana);
	for(int i=0;i<4;i++) { 
		this->opciones[i].Dibujar(ventana);
	}
	this->selector.Dibujar(ventana);
}

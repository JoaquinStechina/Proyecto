#include "Juego.h"
#include "Escena.h"

Juego::Juego(Escena *Pantalla) : ventanita(VideoMode(1200,600),"Proyecto", Style::Titlebar|Style::Close){
	ventanita.setFramerateLimit(60);
	esc_actual = Pantalla;
}

void Juego::Jugar ( ) {
	while(ventanita.isOpen()) {
		Event e;
		while(ventanita.pollEvent(e)) {
			if(e.type == Event::Closed){
				ventanita.close();
			}
		}
		
		ventanita.clear(Color(255,255,255,255));
		
		esc_actual->Actualizar(ventanita, *this);
		esc_actual->Dibujar(ventanita);
		
		if(esc_prox){
			delete esc_actual;
			esc_actual = esc_prox;
			esc_prox = nullptr;
		}
		
		ventanita.display();
	}
}

Juego::~Juego ( ) {
	delete esc_actual;
}

void Juego::Cambiar_Escena (Escena * esc_nueva) {
	esc_prox = esc_nueva;
}

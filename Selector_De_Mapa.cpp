#include "Selector_De_Mapa.h"
#include "Filas_De_Nodos.h"
#include <list>
using namespace std;

Selector_De_Mapa::Selector_De_Mapa() {
	t_de_sprite.loadFromFile("Imagenes/Sprites/redarrow.png");
	s_sprite.setTexture(t_de_sprite);
	s_sprite.setOrigin(25,25);
	reloj.restart();
	fila_actual=1;
	
	//sonido;
	sb_buffer_move.loadFromFile( "Sonidos/Menu_move.wav" );
	s_sonido_move.setBuffer(sb_buffer_move);
}


void Selector_De_Mapa::Cambiar_Pos (const Vector2f v) {
	s_sprite.setPosition(v);
}

void Selector_De_Mapa::Cambiar_Pos (const float posx, const float posy) {
	s_sprite.setPosition(posx, posy);
}

void Selector_De_Mapa::Actualizar (RenderWindow & ventana, list<Filas_De_Nodos> &lista_filas, int &columna_actual) {
	int cant_columnas = lista_filas.size()-1;
	int contador = 0;
	int cantidad_nodos_enColumnaActual;
	for(Filas_De_Nodos &x : lista_filas){
		contador++;
		if (contador == columna_actual){
			cantidad_nodos_enColumnaActual=x.Ver_Cantidad_Nodos();
		}
	}
	s_sprite.setPosition( ((1000.f/(lista_filas.size()+1))*(columna_actual))+50, (((400/(cantidad_nodos_enColumnaActual+1))*(fila_actual)+100)) );
	if( reloj.getElapsedTime().asSeconds() > 0.2 ){
		if (Keyboard::isKeyPressed(Keyboard::Down)){
			fila_actual++;
			if(fila_actual > cantidad_nodos_enColumnaActual){
				fila_actual=1;
			}
			s_sonido_move.play();
			reloj.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)){
			fila_actual--;
			if (fila_actual<1){
				fila_actual=cantidad_nodos_enColumnaActual;
			}
			s_sonido_move.play();
			reloj.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)){
			columna_actual++;
			fila_actual=1;
			if( columna_actual > lista_filas.size() ){
				columna_actual=2;
			}
			s_sonido_move.play();
			reloj.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)){
			columna_actual--;
			fila_actual=1;
			if( columna_actual < 2 ){
				columna_actual=lista_filas.size();
			}
			s_sonido_move.play();
			reloj.restart();
		}
	}
	
	
}

void Selector_De_Mapa::Dibujar (RenderWindow & ventana) {
	ventana.draw(s_sprite);
}


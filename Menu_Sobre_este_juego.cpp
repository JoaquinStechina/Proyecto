#include "Menu_Sobre_este_juego.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Juego.h"
#include "Menu_Principal.h"
using namespace std;

Menu_Sobre_este_juego::Menu_Sobre_este_juego() : fondo_sobre_este_juego("Imagenes/Fondos/fondo2_1.png"){
	fuente.loadFromFile("Fuentes/Triforce.ttf");
	texto_sobre_este_juego.setFont(fuente);
	texto_sobre_este_juego.setFillColor(Color(0,0,0));
	texto_sobre_este_juego.setCharacterSize(24);
	rect_fondo.setSize(Vector2f(1000.f,500.f));
	rect_fondo.setOrigin(Vector2f(500.f,250.f));
	rect_fondo.setFillColor(Color(255,255,255,128));
	rect_fondo.setPosition(600.f,300.f);
}


void Menu_Sobre_este_juego::Actualizar (RenderWindow & ventana, Juego &j) {
	if (Keyboard::isKeyPressed(Keyboard::Escape)){
		j.Cambiar_Escena(new Menu_Principal);
	}
	
}

void Menu_Sobre_este_juego::Dibujar (RenderWindow &ventana) {
	fondo_sobre_este_juego.Dibujar(ventana);
	ventana.draw(rect_fondo);
	ifstream Archi("Texto/Sobre_este_juego.txt");
	string aux;
	int cont = 1;
	while (getline(Archi, aux)){
		texto_sobre_este_juego.setString(aux);
		rect_text_sej = texto_sobre_este_juego.getLocalBounds();
		texto_sobre_este_juego.setOrigin( rect_text_sej.width/2, rect_text_sej.height/2 );
		texto_sobre_este_juego.setPosition(ventana.getSize().x/2, 75*cont);
		ventana.draw(texto_sobre_este_juego);
		cont++;
	}
}


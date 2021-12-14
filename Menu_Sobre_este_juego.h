#ifndef MENU_SOBRE_ESTE_JUEGO_H
#define MENU_SOBRE_ESTE_JUEGO_H
#include "Escena.h"
#include "Fondo.h"
#include <SFML/Graphics.hpp>
#include "Juego.h"

class Menu_Sobre_este_juego : public Escena {
	Fondo fondo_sobre_este_juego;
	Font fuente;
	Text texto_sobre_este_juego;
	FloatRect rect_text_sej;
	RectangleShape rect_fondo;
public:
	Menu_Sobre_este_juego();
	void Actualizar(RenderWindow &ventana, Juego &j) override;
	void Dibujar(RenderWindow &ventana) override;
};

#endif

#ifndef BLOQUE_SPRITE_H
#define BLOQUE_SPRITE_H
#include "Sprites.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>

using namespace sf;

class Bloque_Sprite : public Sprites { 
	Text texto;
	Font fuente;
public:
	Bloque_Sprite                ();
	Bloque_Sprite                (std::string nombre_textura);
<<<<<<< HEAD
    Bloque_Sprite                (std::string nombre_textura, std::string texto);
=======
	Bloque_Sprite                (std::string nombre_textura, std::string texto);
	Bloque_Sprite                (std::string nombre_textura, int i);
	void setBloque_Sprite        (std::string nombre_textura, int i);
	void cambiar_texto           (int i);
	void cambiar_texto           (std::string nuevo_texto);
>>>>>>> 28ece76b321902082f09f974b70b20f07fab9ab4
	void cambiar_posicion_texto  (const float &x, const float &y);
	void cambiar_posicion_bloque (const float &x, const float &y);
	void cambiar_escala_texto    (const float &x, const float &y);
	void cambiar_escala_bloque   (const float &x, const float &y);
	void cambiar_escala_bloque   (const float &x);
	void repetir_bloque          (bool &a);
	void Dibujar_bloque          (RenderWindow &ventana);
	void Dibujar_texto           (RenderWindow &ventana);
	void Dibujar                 (RenderWindow &ventana);
};

#endif


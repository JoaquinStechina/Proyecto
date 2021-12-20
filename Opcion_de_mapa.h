#ifndef OPCION_DE_MAPA_H
#define OPCION_DE_MAPA_H
#include <SFML/Graphics.hpp>
#include "Sprites.h"
using namespace sf;

class Opcion_de_mapa : public Sprites {
	Text Texto_opcion_mapa;
	Font fuente;
	FloatRect rect_texto_opcion_mapa;
public:
	Opcion_de_mapa(std::string t_de_mapa, int Tamanio_texto);
	void Cambiar_color_fuente(Color nuevo_Color);
	void Cambiar_Pos_Opcion_mapa(const Vector2f v);
	void Cambiar_Pos_Opcion_mapa(const float posx, const float posy);
	void Cambiar_Pos_Cuadro_mapa(const float posx, const float posy);
	void Cambiar_Escala_Opcion_mapa(const float Nueva_Escala);
	void Cambiar_texto(std::string nuevo_texto);
	void Actualizar();
	void Dibujar(RenderWindow &win);
};

#endif


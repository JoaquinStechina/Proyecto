#ifndef NPC_H
#define NPC_H
#include "Stats.h"
#include "Sprites.h"
#include <SFML/Graphics/RenderWindow.hpp>

class NPC : public Stats, public Sprites {
public:
	NPC();
	void Actualizar();
	void Dibujar(RenderWindow &ventana);
};

#endif


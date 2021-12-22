#include "NPC.h"

NPC::NPC() {
	//Estadisticas;
	this->setConstitucion(5);
	this->setFuerza(5);
	this->setDestreza(5);
	this->setInteligencia(5);
	this->setSuerte(5);
	this->setVidaMax(this->getConstitucion() * 10);
	this->setManaMax(this->getInteligencia() * 5);
	this->setVida_Actual(this->getVidaMax());
	this->setMana_Actual(this->getManaMax());
	
	//Sprite;
	t_de_sprite.loadFromFile("Imagenes/Sprites/Esqueleto_walk.png");
	s_sprite.setTexture(t_de_sprite);
	s_sprite.setTextureRect(IntRect(0,0,160,160));
}

void NPC::Actualizar ( ) {
	
}

void NPC::Dibujar (RenderWindow & ventana) {
	
}


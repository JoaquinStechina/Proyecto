#include "Player.h"

Player::Player() {
	this->setConstitucion(5);
	this->setFuerza(5);
	this->setDestreza(5);
	this->setInteligencia(5);
	this->setSuerte(5);
	this->setVidaMax(this->getConstitucion() * 10);
	this->setManaMax(this->getInteligencia() * 5);
	this->setVida_Actual(this->getVidaMax());
	this->setMana_Actual(this->getManaMax());
}


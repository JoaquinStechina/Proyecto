#include "Player.h"

Player::Player() {
	this->setConstitucion(5);
	this->setFuerza(5);
	this->setDestreza(5);
	this->setInteligencia(5);
	this->setSuerte(5);
	this->setVida(this->getConstitucion() * 10);
	this->setMana(this->getInteligencia() * 5);
}


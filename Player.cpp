#include "Player.h"

Player::Player() {
	monedas = 0;
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


void Player::SetMonedas (int cantMonedas) {
	monedas = cantMonedas;
}

int Player::GetMonedas ( ) {
	return monedas;
}

void Player::SumarMonedas (int cantMonedas) {
	monedas = monedas + cantMonedas;
}


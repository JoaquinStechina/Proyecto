#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	//Set Unidades por defecto;
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
	

//	Inventario ficticio;
	int contadorcito = 0;
	for (Objeto &x : objetos_del_juego){
		contadorcito++;	
		if (contadorcito == 12){Inventario.push_back(x); }
		if (contadorcito == 13){Inventario.push_back(x); }
		if (contadorcito == 15){Inventario.push_back(x); }
	}
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

void Player::setNivel (int x) {
	nivel = x;
}

int Player::getNivel ( ) {
	return nivel;
}


list<Objeto> Player::Obtener_Inventario ( ) {
	return Inventario;
}


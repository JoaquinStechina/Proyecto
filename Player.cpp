#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {
	//Set Unidades por defecto;
	monedas = 50;
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
		if (contadorcito == 1){Inventario.push_back(x); }
		if (contadorcito == 2){Inventario.push_back(x); }
		if (contadorcito == 3){Inventario.push_back(x); }
	}
}

Player::Player(Elementos_jugador &aux){
	
	list<Objeto> aux_i;
	Objeto a1,a2,a3;
	
	a1.setBufo(aux.item1.Bufo);
	a1.setNombre(aux.item1.Nombre);
	a1.setPrecio(aux.item1.Precio);
	a1.setRareza(aux.item1.Rareza);
	a1.setStat(aux.item1.Stat);
	a1.setTipo(aux.item1.Tipo);
	aux_i.push_back(a1);
	
	a2.setBufo(aux.item2.Bufo);
	a2.setNombre(aux.item2.Nombre);
	a2.setPrecio(aux.item2.Precio);
	a2.setRareza(aux.item2.Rareza);
	a2.setStat(aux.item2.Stat);
	a2.setTipo(aux.item2.Tipo);
	aux_i.push_back(a2);
	
	a3.setBufo(aux.item3.Bufo);
	a3.setNombre(aux.item3.Nombre);
	a3.setPrecio(aux.item3.Precio);
	a3.setRareza(aux.item3.Rareza);
	a3.setStat(aux.item3.Stat);
	a3.setTipo(aux.item3.Tipo);
	aux_i.push_back(a3);
	
	this->setConstitucion(aux.constitucion);
	this->setFuerza(aux.fuerza);
	this->setDestreza(aux.destreza);
	this->setInteligencia(aux.inteligencia);
	this->setSuerte(aux.suerte);
	this->setVidaMax(aux.vida_max);
	this->setManaMax(aux.mana_max);
	this->setVida_Actual(aux.vida_actual);
	this->setMana_Actual(aux.mana_actual);
	this->SetMonedas(aux.monedas);
	this->setNivel(aux.nivel);
	
	Inventario = aux_i;
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


void Player::Set_Inventario (list<Objeto> nuevo_inventario) {
	Inventario = nuevo_inventario;
}


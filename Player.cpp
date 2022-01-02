#include "Player.h"

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
	
		//Set objetos base;
	//tier1
	Objeto armadura_con(1);
	armadura_con.setStat(1);
	armadura_con.setTipo(1);
	lista_objetos.push_back(armadura_con);
	Objeto espada_dex(1);
	espada_dex.setStat(3);
	espada_dex.setTipo(2);
	lista_objetos.push_back(espada_dex);
	Objeto espada_stg(1);
	espada_stg.setStat(2);
	espada_stg.setTipo(2);
	lista_objetos.push_back(espada_stg);
	Objeto amuleto_int(1);
	amuleto_int.setStat(4);
	amuleto_int.setTipo(3);
	lista_objetos.push_back(amuleto_int);
	//tier2
	Objeto armadura_con2(2);
	armadura_con.setStat(1);
	armadura_con.setTipo(1);
	lista_objetos.push_back(armadura_con);
	Objeto espada_dex2(2);
	espada_dex.setStat(3);
	espada_dex.setTipo(2);
	lista_objetos.push_back(espada_dex);
	Objeto espada_stg2(2);
	espada_stg.setStat(2);
	espada_stg.setTipo(2);
	lista_objetos.push_back(espada_stg);
	Objeto amuleto_int2(2);
	amuleto_int.setStat(4);
	amuleto_int.setTipo(3);
	lista_objetos.push_back(amuleto_int);
	//tier3
	Objeto armadura_con3(3);
	armadura_con.setStat(1);
	armadura_con.setTipo(1);
	lista_objetos.push_back(armadura_con);
	Objeto espada_dex3(3);
	espada_dex.setStat(3);
	espada_dex.setTipo(2);
	lista_objetos.push_back(espada_dex);
	Objeto espada_stg3(3);
	espada_stg.setStat(2);
	espada_stg.setTipo(2);
	lista_objetos.push_back(espada_stg);
	Objeto amuleto_int3(3);
	amuleto_int.setStat(4);
	amuleto_int.setTipo(3);
	lista_objetos.push_back(amuleto_int);
	
	//Inventario ficticio;
	int contadorcito = 0;
	for (Objeto &x : lista_objetos){
		contadorcito++;
		if (contadorcito = 1){ Inventario.push_back(x); }
		if (contadorcito = 2){ Inventario.push_back(x); }
		if (contadorcito = 3){ Inventario.push_back(x); }
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


#include "Player.h"
#include <iostream>
using namespace std;

void Player::inicVariables(){
	//Animacion
	this->animEstado = QUIETO;
	
	//Variables privadas
	this->nivel = 0;
	this->exp = 0;
	this->umbral_exp = 100;
	this->monedas = 50;
	
	//Inventario
	int contadorcito = 0;
	for (Objeto &x : objetos_del_juego){
		contadorcito++;	
		if (contadorcito == 1){Inventario_Jugador.push_back(x); }
		if (contadorcito == 2){Inventario_Jugador.push_back(x); }
		if (contadorcito == 3){Inventario_Jugador.push_back(x); }
	}
}

void Player::inicTextura(){
	if(!this->t_de_sprite.loadFromFile("Imagenes/Sprites/jugador.png"))
		cout<<"No se pudo cargar la textura del jugador"<<endl;
	else
		cout<<"Se cargo la textura del jugador"<<endl;
}

void Player::inicSprite(){
	
	this->s_sprite.setTexture(this->t_de_sprite);
	this->cuadroActual = IntRect(0,0,55,37);
	
	this->s_sprite.setTextureRect(this->cuadroActual);
	this->s_sprite.setScale(3.f,3.f);
}

void Player::inicAnimacion(){
	this->relojAnimacion.restart();
}

Player::Player() {
	//Inicializacion
	this->inicVariables();
	this->inicTextura();
	this->inicSprite();
	this->inicAnimacion();
	
	//Set Unidades por defecto;
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

Player::Player(Elementos_jugador &aux){
	//Inicializacion
	this->inicTextura();
	this->inicSprite();
	this->inicAnimacion();
	
	//Inicializado de variables auxiliares
	list<Objeto> aux_i;
	Objeto a1,a2,a3;
	
	//Cargado de los objetos
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
	
	//Cargado de las estadisticas
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
	
	//Cargado del inventario
	this->Inventario_Jugador = aux_i;
}

Player::~Player(){}

void Player::SetMonedas (int cantMonedas) {
	this->monedas = cantMonedas;
}

int Player::GetMonedas ( ) {
	return this->monedas;
}

void Player::SumarMonedas (int cantMonedas) {
	this->monedas += cantMonedas;
}

void Player::setNivel (int x) {
	this->nivel = x;
}

int Player::getNivel ( ) {
	return this->nivel;
}


list<Objeto> Player::getInventario ( ) {
	return this->Inventario_Jugador;
}


void Player::Set_Inventario (list<Objeto> nuevo_inventario) {
	this->Inventario_Jugador = nuevo_inventario;
}

void Player::actualizarMovimiento(){
	if(this->animEstado == QUIETO){
		if(this->relojAnimacion.getElapsedTime().asSeconds() >= 0.15f){
			
			this->cuadroActual.left += 50;
			
			if(this->cuadroActual.left >= 165)
				this->cuadroActual.left = 0;
			
			this->relojAnimacion.restart();
			this->s_sprite.setTextureRect(this->cuadroActual);
		}
	}
	else if(this->animEstado == ATACANDO){
		
	}
	else
	   this->relojAnimacion.restart();
}

void Player::Actualizar(){
	this->actualizarMovimiento();
}

void Player::Dibujar (RenderWindow & ventana){
	ventana.draw(this->s_sprite);
}

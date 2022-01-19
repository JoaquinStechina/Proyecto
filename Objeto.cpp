#include "Objeto.h"
#include <iostream>
using namespace std;

Objeto::Objeto(int tier) {
	rareza = tier;			//si es comun, poco comun, o raro;
	stat = 0;				//0 seria constitucion, 1 seria la estadistica que sigue, y asi
	bufo = 3*rareza;			//Es el bonificador que da en esa estadistica, aumenta segun la rareza
	precio = 10*tier;		//Lo que costaria comprarlo en el juego
	tipo = 1;				//Si es un arma, armadura, o baratija
}


void Objeto::setRareza (int x)       {rareza=x;}
void Objeto::setStat   (int x)       {stat=x;}
void Objeto::setBufo   (int x)       {bufo=x;}
void Objeto::setPrecio (int x)       {precio=x;}
void Objeto::setTipo   (int x)       {tipo=x; this->Actualizar();}
void Objeto::setNombre (string name) {nombre = name;}


int Objeto::getRareza()    {return rareza;}
int Objeto::getStat()      {return stat;}
int Objeto::getBufo()      {return bufo;}
int Objeto::getPrecio()    {return precio;}
int Objeto::getTipo()      {return tipo;}
string Objeto::getNombre() {return nombre;}

void Objeto::Pasiva ( ) {}

void Objeto::Actualizar(){
	if(tipo == 1){												//Armaduras
		if( rareza == 0 ){
			t_de_sprite.loadFromFile("Imagenes/Sprites/arm0.png");
			s_sprite.setTexture(t_de_sprite);
		}
		if( rareza == 1 ){
			t_de_sprite.loadFromFile("Imagenes/Sprites/arm1.png");
			s_sprite.setTexture(t_de_sprite);
		}
		if( rareza == 2 ){
			t_de_sprite.loadFromFile("Imagenes/Sprites/arm2.png");
			s_sprite.setTexture(t_de_sprite);
		}
		if( rareza == 3 ){
			t_de_sprite.loadFromFile("Imagenes/Sprites/arm3.png");
			s_sprite.setTexture(t_de_sprite);
		}
	}
	if(tipo == 2){												//Armas
		if( rareza == 0 ){
			t_de_sprite.loadFromFile("Imagenes/Sprites/wpn0.png");
			s_sprite.setTexture(t_de_sprite);
		}
		if( rareza == 1 ){
			t_de_sprite.loadFromFile("Imagenes/Sprites/wpn1.png");
			s_sprite.setTexture(t_de_sprite);
		}
		if( rareza == 2 ){
			t_de_sprite.loadFromFile("Imagenes/Sprites/wpn2.png");
			s_sprite.setTexture(t_de_sprite);
		}
		if( rareza == 3 ){
			t_de_sprite.loadFromFile("Imagenes/Sprites/wpn3.png");
			s_sprite.setTexture(t_de_sprite);
		}
	}
	if(tipo == 3){												//Baratijas
		if( rareza == 0 ){
			t_de_sprite.loadFromFile("Imagenes/Sprites/ani0.png");
			s_sprite.setTexture(t_de_sprite);
		}
		if( rareza == 1 ){
			t_de_sprite.loadFromFile("Imagenes/Sprites/ani1.png");
			s_sprite.setTexture(t_de_sprite);
		}
		if( rareza == 2 ){
			t_de_sprite.loadFromFile("Imagenes/Sprites/ani2.png");
			s_sprite.setTexture(t_de_sprite);
		}
		if( rareza == 3 ){
			t_de_sprite.loadFromFile("Imagenes/Sprites/ani3.png");
			s_sprite.setTexture(t_de_sprite);
		}
	}
	s_sprite.setOrigin(24,24);
}

void Objeto::CambiarPos (float x, float y) {
	s_sprite.setPosition(x,y);
}

void Objeto::Dibujar (RenderWindow & ventanita) {
	ventanita.draw(s_sprite);
}


Objeto::Objeto ( ) {
	
}


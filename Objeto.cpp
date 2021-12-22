#include "Objeto.h"

Objeto::Objeto() {
	rareza = 0;
	stat = 0;
	bufo = 0;
	precio = 0;
	tipo = 0;
	t_de_sprite.loadFromFile("Imagenes/Sprites/spritesheet_48x48.png");
	s_sprite.setTexture(t_de_sprite);
}


void Objeto::setRareza (int x) {rareza=x; this->Actualizar();}
void Objeto::setStat   (int x) {stat=x;}
void Objeto::setBufo   (int x) {bufo=x;}
void Objeto::setPrecio (int x) {precio=x;}
void Objeto::setTipo   (int x) {tipo=x; this->Actualizar();}

int Objeto::getRareza()   {return rareza;}
int Objeto::getStat()     {return stat;}
int Objeto::getBufo()     {return bufo;}
int Objeto::getPrecio()   {return precio;}
int Objeto::getTipo()     {return tipo;}

void Objeto::Pasiva ( ) {}

void Objeto::Actualizar(){
	if(tipo == 0){
		if( rareza == 0 ){
			s_sprite.setTextureRect(IntRect(48*1,0,48,48));
		}
		if( rareza == 1 ){
			s_sprite.setTextureRect(IntRect(48*3,0,48,48));
		}
		if( rareza == 2 ){
			s_sprite.setTextureRect(IntRect(48*4,0,48,48));
		}
	}
	if(tipo == 1){
		if( rareza == 0 ){
			s_sprite.setTextureRect(IntRect(48*0,48*21,48,48));
		}
		if( rareza == 1 ){
			s_sprite.setTextureRect(IntRect(48*1,48*21,48,48));
		}
		if( rareza == 2 ){
			s_sprite.setTextureRect(IntRect(48*2,48*21,48,48));
		}
	}
	if(tipo == 2){
		if( rareza == 0 ){
			s_sprite.setTextureRect(IntRect(48*6,48*13,48,48));
		}
		if( rareza == 1 ){
			s_sprite.setTextureRect(IntRect(48*7,48*13,48,48));
		}
		if( rareza == 2 ){
			s_sprite.setTextureRect(IntRect(48*8,48*13,48,48));
		}
	}
}


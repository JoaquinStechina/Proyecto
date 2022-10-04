#include "Bloque_Sprite.h"

Bloque_Sprite::Bloque_Sprite(){}

Bloque_Sprite::Bloque_Sprite(std::string nombre_textura) {
	//Carga de la textura para posteriormente utilizarla en el sprite
	t_de_sprite.loadFromFile(nombre_textura);
	s_sprite.setTexture(t_de_sprite);
	
	//Inicializo variable "a" y le asigno las dimensiones de s_sprite
	//Se podria usar ".getSize()" pero este devuelve unsigned int
	//y habria que pasarlo a float
	FloatRect a = s_sprite.getLocalBounds();
	
	//Para settear el origen es necesario pasarle float
<<<<<<< HEAD
	s_sprite.setOrigin(a.height/2,a.width/2);
=======
	s_sprite.setOrigin(a.width/2,a.height/2);
>>>>>>> 28ece76b321902082f09f974b70b20f07fab9ab4
	
	//Suavizado del sprite
	t_de_sprite.setSmooth(true);
}

Bloque_Sprite::Bloque_Sprite(std::string nombre_textura, std::string texto) {
	//Cargado
	fuente.loadFromFile("Fuentes/Triforce.ttf");
	t_de_sprite.loadFromFile(nombre_textura);
	s_sprite.setTexture(t_de_sprite);
	
	//Se settea el texto y la fuente del mismo para luego obtener
	//las dimensiones de su bloque y definir su origen en el centro del mismo
	this->texto.setString(texto);
	this->texto.setFont(fuente);
	FloatRect a = this->texto.getLocalBounds();
<<<<<<< HEAD
	this->texto.setOrigin(a.height/2,a.width/2);
	
	//Centrado del origen del sprite
	FloatRect b = s_sprite.getLocalBounds();
	s_sprite.setOrigin(b.height/2,b.width/2);
=======
	this->texto.setOrigin(a.width/2,a.height/2);
	
	//Centrado del origen del sprite
	FloatRect b = s_sprite.getLocalBounds();
	s_sprite.setOrigin(b.width/2,b.height/2);
>>>>>>> 28ece76b321902082f09f974b70b20f07fab9ab4
	
	//Suavizado del sprite
	t_de_sprite.setSmooth(true);
}

<<<<<<< HEAD
=======
Bloque_Sprite::Bloque_Sprite(std::string nombre_textura, int i) {
	
	fuente.loadFromFile("Fuentes/Triforce.ttf");
	t_de_sprite.loadFromFile(nombre_textura);
	s_sprite.setTexture(t_de_sprite);
	
	this->texto.setString(std::to_string(i));
	this->texto.setFont(fuente);
	FloatRect a = this->texto.getLocalBounds();
	this->texto.setOrigin(a.width/2,a.height/2);
	
	FloatRect b = s_sprite.getLocalBounds();
	s_sprite.setOrigin(b.width/2,b.height/2);
	
	t_de_sprite.setSmooth(true);
}

void Bloque_Sprite::setBloque_Sprite(std::string nombre_textura, int i){
	
	fuente.loadFromFile("Fuentes/Triforce.ttf");
	t_de_sprite.loadFromFile(nombre_textura);
	s_sprite.setTexture(t_de_sprite);
	
	this->texto.setString(std::to_string(i));
	this->texto.setFont(fuente);
	FloatRect a = this->texto.getLocalBounds();
	this->texto.setOrigin(a.width/2,a.height/2);
	
	FloatRect b = s_sprite.getLocalBounds();
	s_sprite.setOrigin(b.width/2,b.height/2);
	
	t_de_sprite.setSmooth(true);
}

void Bloque_Sprite::cambiar_texto(int i){
	this->texto.setString(std::to_string(i));
	FloatRect a = this->texto.getLocalBounds();
	this->texto.setOrigin(a.width/2,a.height/2);
}

void Bloque_Sprite::cambiar_texto(std::string nuevo_texto){
	this->texto.setString(nuevo_texto);
	FloatRect a = this->texto.getLocalBounds();
	this->texto.setOrigin(a.width/2,a.height/2);
}

>>>>>>> 28ece76b321902082f09f974b70b20f07fab9ab4
void Bloque_Sprite::cambiar_posicion_texto (const float & x, const float & y){
	texto.setPosition(x,y);
}

void Bloque_Sprite::cambiar_posicion_bloque (const float & x, const float & y) {
	s_sprite.setPosition(x,y);
}

void Bloque_Sprite::cambiar_escala_texto (const float & x, const float & y){
	texto.setScale(x,y);
}

void Bloque_Sprite::cambiar_escala_bloque (const float & x) {
	s_sprite.setScale(x,x);
}

void Bloque_Sprite::cambiar_escala_bloque (const float & x, const float & y) {
	s_sprite.setScale(x,y);
}

void Bloque_Sprite::repetir_bloque (bool &a) {
	t_de_sprite.setRepeated(a);
}

void Bloque_Sprite::Dibujar_bloque(RenderWindow &ventana){
	ventana.draw(s_sprite);
}

void Bloque_Sprite::Dibujar_texto(RenderWindow &ventana){
	ventana.draw(texto);
}


void Bloque_Sprite::Dibujar (RenderWindow & ventana) {
	this->Dibujar_bloque(ventana);
	this->Dibujar_texto(ventana);
}




#ifndef SPRITES_H
#define SPRITES_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Sprites {
public:
	Sprites();
	
	//Variables
	Texture t_de_sprite;
	Sprite s_sprite;
	FloatRect r_rect;
	IntRect cuadroActual;
};

#endif


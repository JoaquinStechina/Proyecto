#ifndef SPRITES_H
#define SPRITES_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Sprites {
public:
	Texture t_de_sprite;
	Sprite s_sprite;
	FloatRect r_rect;
	Sprites();
};

#endif


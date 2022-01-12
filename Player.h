#ifndef PLAYER_H
#define PLAYER_H
#include "Stats.h"
#include "NPC.h"
#include <list>
#include "Objeto.h"
#include "Lista_de_objetos.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;

class Player : public Stats, public Lista_de_objetos{
	int nivel, exp, umbral_exp, monedas;
	list<Objeto> Inventario;
public:
	Player();
	void SetMonedas(int cantMonedas);
	void SumarMonedas(int cantMonedas);
	void setNivel(int x);
	int getNivel();
	int GetMonedas();
	list<Objeto> Obtener_Inventario();
};

#endif

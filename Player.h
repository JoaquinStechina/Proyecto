#ifndef PLAYER_H
#define PLAYER_H
#include "Stats.h"
#include "NPC.h"
#include <list>
#include "Objeto.h"
using namespace std;

class Player : public Stats{
	int nivel, exp, umbral_exp, monedas;
//	list<Objeto> lista_objetos;
//	list<Objeto> Inventario;
public:
	Player();
	void SetMonedas(int cantMonedas);
	void SumarMonedas(int cantMonedas);
	void setNivel(int x);
	int getNivel();
	int GetMonedas();
};

#endif

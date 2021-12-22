#ifndef PLAYER_H
#define PLAYER_H
#include "Stats.h"
#include "NPC.h"

class Player : public Stats{
	int nivel, exp, umbral_exp, monedas;
public:
	Player();
	void SetMonedas(int cantMonedas);
	void SumarMonedas(int cantMonedas);
	void setNivel(int x);
	int getNivel();
	int GetMonedas();
};

#endif


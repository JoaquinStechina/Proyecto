#ifndef PLAYER_H
#define PLAYER_H
#include "PJs.h"

class Player : public PJs{
	int exp, umbral_exp, monedas;
public:
	void SetMonedas(int cantMonedas);
	void SumarMonedas(int cantMonedas);
	int GetMonedas();
	Player();
};

#endif


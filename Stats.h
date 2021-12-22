#ifndef STATS_H
#define STATS_H
#include <fstream>
using namespace std;

struct Stats_Storage{
	float Constitucion;
	float Fuerza;
	float Destreza;
	float Inteligencia;
	float Suerte;
	float Vida;
	float Mana;
	float Vida_actual;
	float Mana_actual;
};

class Stats {
	Stats_Storage a;
public:
	Stats();
	
	//Getters
	float getConstitucion();
	float getFuerza      ();
	float getDestreza    ();
	float getInteligencia();
	float getSuerte      ();
	float getVidaMax     ();
	float getManaMax     ();
	float getVida_Actual ();
	float getMana_Actual ();
	
	//Setters
	void setConstitucion (float x);
	void setFuerza       (float x);
	void setDestreza     (float x);
	void setInteligencia (float x);
	void setSuerte       (float x);
	void setVidaMax      (float x);
	void setManaMax      (float x);
	void setVida_Actual	 (float x);
	void setMana_Actual  (float x);
};

#endif


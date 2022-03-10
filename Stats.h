#ifndef STATS_H
#define STATS_H
#include <fstream>
using namespace std;

struct Stats_Storage{
	int Constitucion;
	int Fuerza;
	int Destreza;
	int Inteligencia;
	int Suerte;
	int Vida;
	int Mana;
	int Vida_actual;
	int Mana_actual;
};

class Stats {
	Stats_Storage a;
public:
	Stats();
	
	//Getters
	int getConstitucion();
	int getFuerza      ();
	int getDestreza    ();
	int getInteligencia();
	int getSuerte      ();
	int getVidaMax     ();
	int getManaMax     ();
	int getVida_Actual ();
	int getMana_Actual ();
	
	//Setters
	void setConstitucion (int x);
	void setFuerza       (int x);
	void setDestreza     (int x);
	void setInteligencia (int x);
	void setSuerte       (int x);
	void setVidaMax      (int x);
	void setManaMax      (int x);
	void setVida_Actual	 (int x);
	void setMana_Actual  (int x);
};

#endif


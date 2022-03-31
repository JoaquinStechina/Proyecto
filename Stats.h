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
	const int getConstitucion();
	const int getFuerza      ();
	const int getDestreza    ();
	const int getInteligencia();
	const int getSuerte      ();
	const int getVidaMax     ();
	const int getManaMax     ();
	const int getVida_Actual ();
	const int getMana_Actual ();
	
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


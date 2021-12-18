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
};

class Stats {
	Stats_Storage a;
public:
	Stats();
	
	//Getters
	int getConstitucion();
	int getFuerza();
	int getDestreza();
	int getInteligencia();
	int getSuerte();
	int getVida();
	int getMana();
	
	//Setters
	void setConstitucion (int &x);
	void setFuerza       (int &x);
	void setDestreza     (int &x);
	void setInteligencia (int &x);
	void setSuerte       (int &x);
	void setVida         (int &x);
	void setMana         (int &x);
};

#endif


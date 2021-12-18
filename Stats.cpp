#include "Stats.h"

Stats::Stats() {
	
}

//Getters
int Stats::getConstitucion() {return a.Constitucion;}
int Stats::getFuerza()       {return a.Fuerza;}
int Stats::getDestreza()     {return a.Destreza;}
int Stats::getInteligencia() {return a.Inteligencia;}
int Stats::getSuerte()       {return a.Suerte;}
int Stats::getVidaMax()      {return a.Vida;}
int Stats::getManaMax()      {return a.Mana;}
int Stats::getVida_Actual()  {return a.Vida_actual;}
int Stats::getMana_Actual()  {return a.Mana_actual;}

//Setters
void Stats::setConstitucion (int x){a.Constitucion = x;}
void Stats::setFuerza       (int x){a.Fuerza = x;}
void Stats::setDestreza     (int x){a.Destreza = x;}
void Stats::setInteligencia (int x){a.Inteligencia = x;}
void Stats::setSuerte       (int x){a.Suerte = x;}
void Stats::setVidaMax		(int x){a.Vida = x;}
void Stats::setManaMax		(int x){a.Mana = x;}
void Stats::setVida_Actual  (int x){a.Vida_actual = x;}
void Stats::setMana_Actual  (int x){a.Mana_actual = x;}


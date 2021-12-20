#include "Stats.h"

Stats::Stats() {
	
}

//Getters
float Stats::getConstitucion() {return a.Constitucion;}
float Stats::getFuerza()       {return a.Fuerza;}
float Stats::getDestreza()     {return a.Destreza;}
float Stats::getInteligencia() {return a.Inteligencia;}
float Stats::getSuerte()       {return a.Suerte;}
float Stats::getVidaMax()      {return a.Vida;}
float Stats::getManaMax()      {return a.Mana;}
float Stats::getVida_Actual()  {return a.Vida_actual;}
float Stats::getMana_Actual()  {return a.Mana_actual;}
int   Stats::getNivel()        {return a.Nivel;};
//Setters
void Stats::setConstitucion (float x){a.Constitucion = x;}
void Stats::setFuerza       (float x){a.Fuerza = x;}
void Stats::setDestreza     (float x){a.Destreza = x;}
void Stats::setInteligencia (float x){a.Inteligencia = x;}
void Stats::setSuerte       (float x){a.Suerte = x;}
void Stats::setVidaMax		(float x){a.Vida = x;}
void Stats::setManaMax		(float x){a.Mana = x;}
void Stats::setVida_Actual  (float x){a.Vida_actual = x;}
void Stats::setMana_Actual  (float x){a.Mana_actual = x;}
void Stats::setNivel        (int x)  {a.Nivel = x;}



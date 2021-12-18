#include "Stats.h"

Stats::Stats() {
	
}

//Getters
int Stats::getConstitucion() {return a.Constitucion;}
int Stats::getFuerza()       {return a.Fuerza;}
int Stats::getDestreza()     {return a.Destreza;}
int Stats::getInteligencia() {return a.Inteligencia;}
int Stats::getSuerte()       {return a.Suerte;}
int Stats::getVida()         {return a.Vida;}
int Stats::getMana()         {return a.Mana;}
//Setters
void Stats::setConstitucion (int &x){a.Constitucion = x;}
void Stats::setFuerza       (int &x){a.Fuerza = x;}
void Stats::setDestreza     (int &x){a.Destreza = x;}
void Stats::setInteligencia (int &x){a.Inteligencia = x;}
void Stats::setSuerte       (int &x){a.Suerte = x;}
void Stats::setVida         (int &x){a.Vida = x;}
void Stats::setMana         (int &x){a.Mana = x;}

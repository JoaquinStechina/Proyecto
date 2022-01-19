#include "Lista_de_objetos.h"
#include <string>
#include <iostream>
using namespace std;

Lista_de_objetos::Lista_de_objetos() {
	string nombrecito;
		//Set objetos base;
	//Tier Inicial
	Objeto armadura_con0(0);
	armadura_con0.setStat(1);
	armadura_con0.setTipo(1);
	nombrecito = "Armadura Rota.";
	armadura_con0.setNombre(nombrecito);
	objetos_del_juego.push_back(armadura_con0);
	Objeto espada_dex0(0);
	espada_dex0.setStat(3);
	espada_dex0.setTipo(2);
	nombrecito = "Espada Rota.";
	espada_dex0.setNombre(nombrecito);
	objetos_del_juego.push_back(espada_dex0);
	Objeto amuleto_int0(0);
	amuleto_int0.setStat(4);
	amuleto_int0.setTipo(3);
	nombrecito = "Baratija Rota.";
	amuleto_int0.setNombre(nombrecito);
	objetos_del_juego.push_back(amuleto_int0);
	//tier1
	Objeto armadura_con(1);
	armadura_con.setStat(1);
	armadura_con.setTipo(1);
	nombrecito = "Armadura Antigua +3 a Constitucion.";
	armadura_con.setNombre(nombrecito);
	objetos_del_juego.push_back(armadura_con);
	Objeto espada_dex(1);
	espada_dex.setStat(3);
	espada_dex.setTipo(2);
	nombrecito = "Espada Ligera Antigua +3 a Destreza.";
	espada_dex.setNombre(nombrecito);
	objetos_del_juego.push_back(espada_dex);
	Objeto espada_stg(1);
	espada_stg.setStat(2);
	espada_stg.setTipo(2);
	nombrecito = "Espada Pesada Antigua +3 a Fuerza.";
	espada_stg.setNombre(nombrecito);
	objetos_del_juego.push_back(espada_stg);
	Objeto amuleto_int(1);
	amuleto_int.setStat(4);
	amuleto_int.setTipo(3);
	nombrecito = "Baratija Antigua +3 a Inteligencia.";
	amuleto_int.setNombre(nombrecito);
	objetos_del_juego.push_back(amuleto_int);
	//tier2
	Objeto armadura_con2(2);
	armadura_con2.setStat(1);
	armadura_con2.setTipo(1);
	nombrecito = "Armadura Media +6 a Constitucion.";
	armadura_con2.setNombre(nombrecito);
	objetos_del_juego.push_back(armadura_con2);
	Objeto espada_dex2(2);
	espada_dex2.setStat(3);
	espada_dex2.setTipo(2);
	nombrecito = "Espada Ligera Media +6 a Destreza.";
	espada_dex2.setNombre(nombrecito);
	objetos_del_juego.push_back(espada_dex2);
	Objeto espada_stg2(2);
	espada_stg2.setStat(2);
	espada_stg2.setTipo(2);
	nombrecito = "Espada Pesada Media +6 a Fuerza.";
	espada_stg2.setNombre(nombrecito);
	objetos_del_juego.push_back(espada_stg2);
	Objeto amuleto_int2(2);
	amuleto_int2.setStat(4);
	amuleto_int2.setTipo(3);
	nombrecito = "Baratija Media +6 a Inteligencia.";
	amuleto_int2.setNombre(nombrecito);
	objetos_del_juego.push_back(amuleto_int2);
	//tier3
	Objeto armadura_con3(3);
	armadura_con3.setStat(1);
	armadura_con3.setTipo(1);
	nombrecito = "Armadura Superior +9 a Constitucion.";
	armadura_con3.setNombre(nombrecito);
	objetos_del_juego.push_back(armadura_con3);
	Objeto espada_dex3(3);
	espada_dex3.setStat(3);
	espada_dex3.setTipo(2);
	nombrecito = "Espada Ligera Superior +9 a Destreza.";
	espada_dex3.setNombre(nombrecito);
	objetos_del_juego.push_back(espada_dex3);
	Objeto espada_stg3(3);
	espada_stg3.setStat(2);
	espada_stg3.setTipo(2);
	nombrecito = "Espada Pesada Superior +9 a Fuerza.";
	espada_stg3.setNombre(nombrecito);
	objetos_del_juego.push_back(espada_stg3);
	Objeto amuleto_int3(3);
	amuleto_int3.setStat(4);
	amuleto_int3.setTipo(3);
	nombrecito = "Baratija Superior +9 a Inteligencia.";
	amuleto_int3.setNombre(nombrecito);
	objetos_del_juego.push_back(amuleto_int3);
}


#include "Lista_de_objetos.h"

Lista_de_objetos::Lista_de_objetos() {
		//Set objetos base;
	//tier1
	Objeto armadura_con(1);
	armadura_con.setStat(1);
	armadura_con.setTipo(1);
	objetos_del_juego.push_back(armadura_con);
	Objeto espada_dex(1);
	espada_dex.setStat(3);
	espada_dex.setTipo(2);
	objetos_del_juego.push_back(espada_dex);
	Objeto espada_stg(1);
	espada_stg.setStat(2);
	espada_stg.setTipo(2);
	objetos_del_juego.push_back(espada_stg);
	Objeto amuleto_int(1);
	amuleto_int.setStat(4);
	amuleto_int.setTipo(3);
	objetos_del_juego.push_back(amuleto_int);
	//tier2
	Objeto armadura_con2(2);
	armadura_con.setStat(1);
	armadura_con.setTipo(1);
	objetos_del_juego.push_back(armadura_con);
	Objeto espada_dex2(2);
	espada_dex.setStat(3);
	espada_dex.setTipo(2);
	objetos_del_juego.push_back(espada_dex);
	Objeto espada_stg2(2);
	espada_stg.setStat(2);
	espada_stg.setTipo(2);
	objetos_del_juego.push_back(espada_stg);
	Objeto amuleto_int2(2);
	amuleto_int.setStat(4);
	amuleto_int.setTipo(3);
	objetos_del_juego.push_back(amuleto_int);
	//tier3
	Objeto armadura_con3(3);
	armadura_con.setStat(1);
	armadura_con.setTipo(1);
	objetos_del_juego.push_back(armadura_con);
	Objeto espada_dex3(3);
	espada_dex.setStat(3);
	espada_dex.setTipo(2);
	objetos_del_juego.push_back(espada_dex);
	Objeto espada_stg3(3);
	espada_stg.setStat(2);
	espada_stg.setTipo(2);
	objetos_del_juego.push_back(espada_stg);
	Objeto amuleto_int3(3);
	amuleto_int.setStat(4);
	amuleto_int.setTipo(3);
	objetos_del_juego.push_back(amuleto_int);
}


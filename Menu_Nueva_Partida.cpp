#include "Menu_Nueva_Partida.h"
#include "Menu_Nuevo_Juego.h"
#include "Menu_mapa.h"

<<<<<<< HEAD
Menu_Nueva_Partida::Menu_Nueva_Partida() : fondo("Imagenes/Fondos/fondo2_1.png"), Menu("Imagenes/Sprites/bloquesito_steel.png","Creador de personaje") {
//	opc1.Cambiar_Escala_Opcion_Menu(2);
//	opc1.Cambiar_Pos_Cuadro_Menu(600,100);
//	opc1.Cambiar_Pos_Opcion_Menu(600,90);
	Menu.cambiar_posicion_bloque(600,100);
	Menu.cambiar_posicion_texto(600,100);
//	Menu.cambiar_escala_bloque(5,1);
=======
Menu_Nueva_Partida::Menu_Nueva_Partida() : fondo("Imagenes/Fondos/fondo2_1.png"), Cuadro1("Imagenes/Sprites/Letrero_metal.png","Creador de personaje"), Cuadro2("Imagenes/Sprites/bloquesito_steel.png",10), Cuadro3("Imagenes/Sprites/Letrero_metal.png","Continuar") {
	
	Cuadro1.cambiar_escala_bloque(1.1);
	Cuadro1.cambiar_posicion_texto(600,50);
	Cuadro1.cambiar_posicion_bloque(600,55);
	
	Cuadro2.cambiar_posicion_texto(600,130);
	Cuadro2.cambiar_posicion_bloque(600,135.5);
	Cuadro2.cambiar_escala_bloque(1.1);
	
	Cuadro3.cambiar_escala_bloque(1.1);
	Cuadro3.cambiar_posicion_texto(600,555);
	Cuadro3.cambiar_posicion_bloque(600,560);
	
	Selector1.Cambiar_Pos(340, 210);
	Selector1.setCont_Max(6);
	
	float x = 500;
	float y = 210;
	
	for(int i=0;i<5;i++) { 
		string texto;
		switch(i){
		case 0:
			texto = "Constitucion";
			break;
		case 1:
			texto = "Fuerza";
			break;
		case 2:
			texto = "Destreza";
			break;
		case 3:
			texto = "Inteligencia";
			break;
		case 4:
			texto = "Suerte";
			break;
		default:
			break;
		}
		
		arreglo[i].setOpcion(texto,30);
		arreglo[i].Cambiar_Pos_Cuadro_Menu(x,y);
		arreglo[i].Cambiar_Pos_Opcion_Menu(x,y-5.5);
		
		y += 70;
	}
	
	float cuadro_x = 700;
	float cuadro_y = 210;
	
	for(int i=0;i<5;i++) { 
		switch(i){
		case 0:
			arreglo_cuadros[i].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getConstitucion());
			break;
		case 1:
			arreglo_cuadros[i].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getFuerza());
			break;
		case 2:
			arreglo_cuadros[i].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getDestreza());
			break;
		case 3:
			arreglo_cuadros[i].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getInteligencia());
			break;
		case 4:
			arreglo_cuadros[i].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getSuerte());
			break;
		default:
			break;
		}
		
		arreglo_cuadros[i].cambiar_posicion_texto(cuadro_x,cuadro_y-10);
		arreglo_cuadros[i].cambiar_posicion_bloque(cuadro_x,cuadro_y+0.5);
		cuadro_y += 70;
	}
	
>>>>>>> 28ece76b321902082f09f974b70b20f07fab9ab4
	sb_buffer.loadFromFile("Sonidos/Menu_select.wav");
	s_sonido_enter.setBuffer(sb_buffer);
}

void Menu_Nueva_Partida::Actualizar (RenderWindow & ventana, Juego & j) {
	cont_pos = Selector1.Actualizar(ventana);
	if (reloj.getElapsedTime().asSeconds() > 0.2){
		if (Keyboard::isKeyPressed(Keyboard::Escape)){
			j.Cambiar_Escena(new Menu_Nuevo_Juego);
			s_sonido_enter.play();
			reloj.restart();
		}
		if(cont_pos == 0){
			Selector1.Cambiar_Pos(340,210);
			if(Keyboard::isKeyPressed(Keyboard::Left)){
				if(player->getConstitucion() > 1){
					player->setConstitucion(player->getConstitucion()-1);
					puntos_disponibles += 1;
					Cuadro2.setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",puntos_disponibles);
					arreglo_cuadros[cont_pos].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getConstitucion());
					reloj.restart();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::Right)){
				if(puntos_disponibles > 0){
					player->setConstitucion(player->getConstitucion()+1);
					puntos_disponibles -= 1;
					Cuadro2.setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",puntos_disponibles);
					arreglo_cuadros[cont_pos].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getConstitucion());
					reloj.restart();
				}
			}
		}
		if(cont_pos == 1){
			Selector1.Cambiar_Pos(340,280);
			if(Keyboard::isKeyPressed(Keyboard::Left)){
				if(player->getFuerza() > 1){
					player->setFuerza(player->getFuerza()-1);
					puntos_disponibles += 1;
					Cuadro2.setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",puntos_disponibles);
					arreglo_cuadros[cont_pos].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getFuerza());
					reloj.restart();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::Right)){
				if(puntos_disponibles > 0){
					player->setFuerza(player->getFuerza()+1);
					puntos_disponibles -= 1;
					Cuadro2.setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",puntos_disponibles);
					arreglo_cuadros[cont_pos].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getFuerza());
					reloj.restart();
				}
			}
		}
		if(cont_pos == 2){
			Selector1.Cambiar_Pos(340,350);
			if(Keyboard::isKeyPressed(Keyboard::Left)){
				if(player->getDestreza() > 1){
					player->setDestreza(player->getDestreza()-1);
					puntos_disponibles += 1;
					Cuadro2.setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",puntos_disponibles);
					arreglo_cuadros[cont_pos].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getDestreza());
					reloj.restart();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::Right)){
				if(puntos_disponibles > 0){
					player->setDestreza(player->getDestreza()+1);
					puntos_disponibles -= 1;
					Cuadro2.setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",puntos_disponibles);
					arreglo_cuadros[cont_pos].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getDestreza());
					reloj.restart();
				}
			}
		}
		if(cont_pos == 3){
			Selector1.Cambiar_Pos(340,420);
			if(Keyboard::isKeyPressed(Keyboard::Left)){
				if(player->getInteligencia() > 1){
					player->setInteligencia(player->getInteligencia()-1);
					puntos_disponibles += 1;
					Cuadro2.setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",puntos_disponibles);
					arreglo_cuadros[cont_pos].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getInteligencia());
					reloj.restart();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::Right)){
				if(puntos_disponibles > 0){
					player->setInteligencia(player->getInteligencia()+1);
					puntos_disponibles -= 1;
					Cuadro2.setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",puntos_disponibles);
					arreglo_cuadros[cont_pos].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getInteligencia());
					reloj.restart();
				}
			}
		}
		if(cont_pos == 4){
			Selector1.Cambiar_Pos(340,490);
			if(Keyboard::isKeyPressed(Keyboard::Left)){
				if(player->getSuerte() > 1){
					player->setSuerte(player->getSuerte()-1);
					puntos_disponibles += 1;
					Cuadro2.setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",puntos_disponibles);
					arreglo_cuadros[cont_pos].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getSuerte());
					reloj.restart();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::Right)){
				if(puntos_disponibles > 0){
					player->setSuerte(player->getSuerte()+1);
					puntos_disponibles -= 1;
					Cuadro2.setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",puntos_disponibles);
					arreglo_cuadros[cont_pos].setBloque_Sprite("Imagenes/Sprites/bloquesito_steel.png",player->getSuerte());
					reloj.restart();
				}
			}
		}
		if(cont_pos == 5){
			Selector1.Cambiar_Pos(435,560);
			if(Keyboard::isKeyPressed(Keyboard::Space)){
				j.Cambiar_Escena(new Menu_mapa(*player));
				s_sonido_enter.play();
				reloj.restart();
			}
		}
	}
}

void Menu_Nueva_Partida::Dibujar (RenderWindow & ventana) {
	fondo.Dibujar(ventana);
<<<<<<< HEAD
//	opc1.Dibujar(ventana);
	Menu.Dibujar(ventana);
=======
	Cuadro1.Dibujar(ventana);
	Cuadro2.Dibujar(ventana);
	for(int i=0;i<5;i++) { 
		arreglo[i].Dibujar(ventana);
	}
	for(int i=0;i<5;i++) { 
		arreglo_cuadros[i].Dibujar(ventana);
	}
	Selector1.Dibujar(ventana);
	Cuadro3.Dibujar(ventana);
>>>>>>> 28ece76b321902082f09f974b70b20f07fab9ab4
}

Menu_Nueva_Partida::~Menu_Nueva_Partida(){
	delete player;
}

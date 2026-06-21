#pragma once
#include <string>
#include <vector>
#include "Objeto.h"
struct Jugador
{
	std::string nombre;
	int mapaActual;
	int posicion=0;
	int monedas;
	int estrellas;
	Objeto inventario[3];
	int cantidadObjetos;
	int minijuegosGanados=0;
	char avatar;
	bool esperando;
	std::string dibujo[7];
};
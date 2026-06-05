#pragma once
#include <string>
#include <vector>
#include "Objeto.h"
struct Jugador
{
	std::string nombre;
	int posicion;
	int monedas;
	int estrellas;
	Objeto inventario[3];
	int cantidadObjetos;
};
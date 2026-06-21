#pragma once
#include <string>

struct Pokemon {
	std::string Nombre;
	double vida=10.0;
	double ataque =1.0;
	double defensa =1.0;
	bool protegido = false;
};
#include <iostream>
#include <conio.h>
#include "Game.h"
#include "pokemon.h"
#include "jugador.h"
#define ANCHO_PANTALLA 120
#define ALTO_PANTALLA 30

using namespace std;
using namespace System;

void tituloInicio(int x, int y) {
	string math[] =
	{
		".-.   .-.  .--.  .---. .-. .-.   ",
		"|  `.'  | / {} \\{_   _}| {_} |   ",
		"| |\\ /| |/  /\\  \\ | |  | { } |   ",
		"`-' ` `-'`-'  `-' `-'  `-' `-'  "
	};
	string mon[] = {
		".-.   .-. .----. .-. .-.",
		"|  `.'  |/  {}  \\|  `| |",
		"| |\\ /| |\\      /| |\\  |",
		"`-' ` `-' `----' `-' `-'"
	};
	for (int i = 0;i < 4;i++) {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y+i);
		cout << math[i];
		Console::ForegroundColor = ConsoleColor::Blue;
		Console::SetCursorPosition(x + 32, y+i);
		cout << mon[i];
		Console::ResetColor();
	}
	_sleep(1500);
	Console::Clear();

}

void intefazPokeMath() {
	Console::Clear();

	Console::ForegroundColor = ConsoleColor::White;
	for (int i = 1; i <= ANCHO_PANTALLA - 1; i++) {
		Console::SetCursorPosition(i, 0);
		cout << '-';
	}
	for (int i = 1; i <= ANCHO_PANTALLA - 1;i++) {
		Console::SetCursorPosition(i, ALTO_PANTALLA - 1);
		cout << '-';
	}
	for (int j = 1; j <= ALTO_PANTALLA; j++) {
		if (j == 1 || j == ALTO_PANTALLA) {
			Console::SetCursorPosition(1, j - 1);
			cout << '+';
			Console::SetCursorPosition(ANCHO_PANTALLA - 1, j - 1);
			cout << '+';
		}
		else {
			Console::SetCursorPosition(1, j - 1);
			cout << '|';
			Console::SetCursorPosition(ANCHO_PANTALLA - 1, j - 1);
			cout << '|';
		}
	}
	for (int b = 1; b <= ANCHO_PANTALLA - 1; b++) {
		if (b == 1 || b == ANCHO_PANTALLA - 1) {
			Console::SetCursorPosition(b, (ALTO_PANTALLA / 2) + 4);
			cout << '+';
		}
		else {
			Console::SetCursorPosition(b, (ALTO_PANTALLA / 2) + 4);
			cout << '-';
		}
	}

}
int probabilidad() {
	return (rand() % 10) + 1;
}
void interfazVida(Pokemon& p,bool enemigo,Jugador& j) {
	int x = enemigo ? 5 : 90;
	int y = enemigo ? 4 : 15;

	Console::SetCursorPosition(x, y );
	cout << string(25, ' ');
	Console::SetCursorPosition(x, y);
	cout << j.nombre<<"  Nv 100";
	Console::SetCursorPosition(x, y + 1);
	cout << string(25, ' ');
	Console::SetCursorPosition(x, y + 1);
		if (enemigo == false) {
			Console::BackgroundColor = ConsoleColor::Green;
		}else{
			Console::BackgroundColor = ConsoleColor::Red;
		}
		cout << string(p.vida*2,' ');
	Console::ResetColor();
	Console::SetCursorPosition(x, y + 2);
	cout << string(20, ' ');
	Console::SetCursorPosition(x, y + 2);
	cout<<"              10/" << p.vida;

}
void mensajeBatalla(string msg, int x = 4, int y = 22) {
	Console::SetCursorPosition(x, y);
	cout << string(ANCHO_PANTALLA - 10, ' ');
	Console::SetCursorPosition(x, y);
	cout << msg;
	_getch();
}
void limpiarZonaMenu(int x, int y, int alto = 4, int ancho = 15) {
	for (int i = 0; i < alto; i++) {
		Console::SetCursorPosition(x, y + i);
		cout << string(ancho, ' ');
	}
}
bool minijuegoFiguras(int x, int y) {
	string pistas[4] = {
		"No tiene lados, es redonda",
		"Tiene 4 lados iguales y angulos rectos",
		"Tiene 4 lados iguales pero angulos no rectos",
		"Tiene 3 lados y 3 angulos"
	};
	string opciones[] = { "Circulo", "Rectangulo", "Rombo", "Triangulo" };
	int correcta = rand() % 4;
	int seleccion = 0;
	int tecla;

	limpiarZonaMenu(x, y, 6, 70);

	Console::ForegroundColor = ConsoleColor::Cyan;
	Console::SetCursorPosition(x, y);
	cout << "Que figura es? " << pistas[correcta];
	Console::ResetColor();

	do {
		for (int i = 0; i < 4; i++) {
			Console::SetCursorPosition(x, y + 2 + i);
			if (i == seleccion) {
				Console::BackgroundColor = ConsoleColor::White;
				Console::ForegroundColor = ConsoleColor::Black;
			}
			cout << opciones[i] << "      ";
			Console::ResetColor();
		}

		tecla = _getch();
		if (tecla == 224) {
			tecla = _getch();
			if (tecla == 72 && seleccion > 0) seleccion--; // flecha arriba
			if (tecla == 80 && seleccion < 3) seleccion++; // flecha abajo
		}
	} while (tecla != 13); // Enter

	limpiarZonaMenu(x, y, 6, 70); 

	return seleccion == correcta;
}
int interfazAtaques(int x,int y) {
	string opciones[] = { "LUCHA","MOCHILA" };
	int seleccion = 0;
	int tecla;
	limpiarZonaMenu(x, y);
	do{
		for (int i = 0; i < 2;i++) {
			Console::SetCursorPosition(x, y + i);
			if (i == seleccion) {
				Console::BackgroundColor = ConsoleColor::White;
				Console::ForegroundColor = ConsoleColor::Black;
			}
			cout << opciones[i] << "      ";
			Console::ResetColor();
		}
		tecla = _getch();
		if (tecla == 224) {
			tecla = _getch();
			if (tecla == 72 && seleccion > 0) seleccion--;
			if (tecla == 80 && seleccion < 1) seleccion++;
		}
	} while (tecla != 13);
	return seleccion;
}
int menuAtaque(int x, int y) {
	string ataques[] = { "Tacleada","Grunido","Latigo","Proteccion" };
	int seleccion = 0;
	int tecla;
	limpiarZonaMenu(x, y);
	do {
		for (int i = 0;i < 4;i++) {
			Console::SetCursorPosition(x, y + i);
			if (i == seleccion) {
				Console::BackgroundColor = ConsoleColor::White;
				Console::ForegroundColor = ConsoleColor::Black;
			}
			cout << ataques[i] << "      ";
			Console::ResetColor();
		}
		tecla = _getch();
		if (tecla == 224) {
			tecla = _getch();
			if (tecla == 72 && seleccion > 0)seleccion--;
			if (tecla == 80 && seleccion < 3)seleccion++;
		}
	} while (tecla != 13);
	return seleccion;
}
void turno(Jugador& personaje1, Jugador& personaje2,Pokemon& p1, Pokemon& p2) {
	bool turnoJugador = true;

		interfazVida(p1, false, personaje1);
		interfazVida(p2, true, personaje2);
		dibujarAvatar(personaje1, 90, 4);
		dibujarAvatar(personaje2, 5, 10);
	while (p1.vida >0 && p2.vida >0)
	{

		int menuElegido = interfazAtaques(95, 21);

		if (menuElegido == 1) {
			continue;
		}

		int opcion = menuAtaque(95, 21) + 1; // 1=Tacleada, 2=Gruñido, 3=Latigo, 4=Proteccion


		if (turnoJugador)
		{
			//	int x = enemigo ? 5 : 90;
			// int y = enemigo ? 4 : 15;
			dibujarAvatar(personaje1, 90, 4);
			dibujarAvatar(personaje2, 5, 10);
			interfazVida(p1, false, personaje1);
			interfazVida(p2, true, personaje2);
			switch (opcion) {
			case 1:
				//tacleada
				if (!p2.protegido) {
					double mult = minijuegoFiguras(40, 20) ? 1.5 : 0.5;
					p2.vida -= (p1.ataque+(1-p2.defensa))*mult;
					mensajeBatalla(personaje1.nombre + (mult == 1.0 ? " acerto! Tacleada completa" : " fallo, Tacleada debil"));
					mensajeBatalla(personaje1.nombre + " uso Tacleada");
				}
				else {
					p2.protegido = false;
					mensajeBatalla(personaje2.nombre + " se protegio del ataque");

				}
				break;
			case 2:
				//gruñido
				if (probabilidad() > 4) {
					p2.ataque -= 0.10;
					if (p2.ataque < 0.10) {
						p2.ataque = 0.10;
					}
					mensajeBatalla(personaje1.nombre + " uso gruñido");

				}
				else {
					cout << "Fallaste el ataque";
				}
				break;
			case 3:
				//latigo
				if (probabilidad() > 4) {
						p2.defensa -= 0.10;
					if (p2.defensa < 0.10) {
						p2.defensa = 0.10;
					}
					mensajeBatalla(personaje1.nombre + " uso Grunido, bajo el ataque del rival");

				}
				else {
					mensajeBatalla("Fallaste el ataque");
				}
				break;

			case 4:
				//proteccion
				p1.protegido = true;
				break;

			}

		}
		else {
			dibujarAvatar(personaje2, 90, 4);
			dibujarAvatar(personaje1, 5, 10);
			interfazVida(p2, false, personaje2);
			interfazVida(p1, true, personaje1);
			switch (opcion) {
			case 1:
				//tacleada
				if (!p1.protegido) {
					double mult = minijuegoFiguras(40, 20) ? 1.5 : 0.5;
					p1.vida -= (p2.ataque + (1 - p1.defensa))*mult;
					mensajeBatalla(personaje1.nombre + (mult == 1.0 ? " acerto! Tacleada completa" : " fallo, Tacleada debil"));
				}
				else {
					p1.protegido = false;
				}
				break;
			case 2:
				//gruñido
				if (probabilidad() > 4) {
					p1.ataque -= 0.10;
					if (p1.ataque < 0.10) {
						p1.ataque = 0.10;
					}
				}
				else {
					cout << "Fallaste el ataque";
				}
				break;
			case 3:
				//latigo
				if (probabilidad() > 4) {
					p1.defensa -= 0.10;
					if (p1.defensa < 0.10) {
						p1.defensa = 0.10;
					}
				}
				else {
					cout << "Fallaste el ataque";
				}
				break;

			case 4:
				//proteccion
				p2.protegido = true;
				break;

			}
		}
		turnoJugador = !turnoJugador;

	}
	if (p1.vida <= 0) {
		personaje2.estrellas += 1;
		personaje2.minijuegosGanados += 1;
		personaje2.monedas += 10;
		mensajeBatalla(personaje2.nombre + " gano la batalla y obtuvo 1 estrella, 10 monedas");
	}
	else {
		personaje1.estrellas += 1;
		personaje1.minijuegosGanados += 1;
		personaje1.monedas += 10;
		mensajeBatalla(personaje1.nombre + " gano la batalla y obtuvo 1 estrella, 10 monedas");
	}
}
void reglasPokeMath(int x,int y) {
	string reglas[] = {
		"Es un duelo en el que tenga mejores conocimientos en ",
		"geometria, sus ataques tendran mayor impacto, ",
		"pero tambien puedes llegar a ganar con tu ingenio, ",
		"usando los ataquesm objetos y defensa en el momento indicado",
		", cada personaje tendra un turno, donde solo podra realizar ",
		"una accionm, ya sea predecir el ataque de tu rival defendiendote, ",
		"atacar a tu rival o suando un objeto."
	};
	for (int i = 0; i < 7;i++) {
		Console::SetCursorPosition(x, y + i);
		cout << reglas[i]<<endl;
	}

	_getch();
	Console::Clear();
}

void juegoPokeMath(Jugador& j1,Jugador& j2) {
	Pokemon p1;
	Pokemon p2;
	Console::Clear();
	tituloInicio(30, 10);
	reglasPokeMath(20,6);
	intefazPokeMath();
	turno(j1, j2, p1, p2);
	_getch();
	Console::Clear();
}
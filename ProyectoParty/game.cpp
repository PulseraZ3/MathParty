#include "Jugador.h"
#include "Game.h"
#include <iostream>
#include <conio.h>
#define ANCHO_PANTALLA 120
#define ALTO_PANTALLA 30
using namespace std;
using namespace System;
#define MAPAS 5
#define CASILLAS 15
char mapas[MAPAS][CASILLAS] =
{
	{'C','C','C','R','C','C','O','C','C','R','C','C','R','C','R'},
	{'C','C','C','C','R','C','C','O','C','C','R','C','C','R','C'},
	{'C','C','C','R','C','O','C','C','C','R','C','C','R','C','C'},
	{'C','R','C','C','R','C','C','R','C','C','O','C','C','R','C'},
	{'R','C','C','C','C','R','C','C','R','C','C','R','C','C','O'}
};

int turnoPersonaje() {
	return rand() % 6 + 1;
}
void creacionDadito(int d)
{
	char a = char(218); // ┌
	char b = char(191); // ┐
	char c = char(192); // └
	char h = char(217); // ┘
	char e = char(196); // ─
	char f = char(179); // │
	char g = char(254); // ■

	if (d == 1)
	{
		cout << a << e << e << e << e << b << endl;
		cout << f << "    " << f << endl;
		cout << f << " " << g << "  " << f << endl;
		cout << f << "    " << f << endl;
		cout << c << e << e << e << e << h << endl;
	}
	else if (d == 2)
	{
		cout << a << e << e << e << e << b << endl;
		cout << f << g << "   " << f << endl;
		cout << f << "    " << f << endl;
		cout << f << "   " << g << f << endl;
		cout << c << e << e << e << e << h << endl;
	}
	else if (d == 3)
	{
		cout << a << e << e << e << e << b << endl;
		cout << f << g << "   " << f << endl;
		cout << f << " " << g << "  " << f << endl;
		cout << f << "   " << g << f << endl;
		cout << c << e << e << e << e << h << endl;
	}
	else if (d == 4)
	{
		cout << a << e << e << e << e << b << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << f << "    " << f << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << c << e << e << e << e << h << endl;
	}
	else if (d == 5)
	{
		cout << a << e << e << e << e << b << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << f << " " << g << "  " << f << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << c << e << e << e << e << h << endl;
	}
	else if (d == 6)
	{
		cout << a << e << e << e << e << b << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << c << e << e << e << e << h << endl;
	}

	else if (d == 8)
	{
		cout << a << e << e << e << e << b << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << f << "    " << f << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << c << e << e << e << e << h << endl;

		cout << endl;

		cout << a << e << e << e << e << b << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << f << "    " << f << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << c << e << e << e << e << h << endl;
	}
	else if (d == 10)
	{
		cout << a << e << e << e << e << b << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << f << " " << g << "  " << f << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << c << e << e << e << e << h << endl;

		cout << endl;

		cout << a << e << e << e << e << b << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << f << " " << g << "  " << f << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << c << e << e << e << e << h << endl;
	}

	else if (d == 12)
	{
		cout << a << e << e << e << e << b << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << c << e << e << e << e << h << endl;

		cout << endl;

		cout << a << e << e << e << e << b << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << f << g << " " << g << " " << f << endl;
		cout << c << e << e << e << e << h << endl;

	}
}
int lanzarDado(int cantidadDado) {
	int suma = 0;
	for (int i = 1; i <= cantidadDado; i++) {
		int dado = turnoPersonaje();
		//creacionDadito(dado);
		suma += dado;
	}
	return suma;
}

void interfazAvatar() {
	system("cls");
	for (int i = 1; i <= ANCHO_PANTALLA - 20;i++) {
		for (int j = 1; j <= 10;j++) {
			if (i == 1 || j == 1 || i == ANCHO_PANTALLA - 20 || j == 10) {
				Console::ForegroundColor = ConsoleColor::White;
				Console::SetCursorPosition(i + 10, j);
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
	}
	Console::ForegroundColor = ConsoleColor::White;

	Console::SetCursorPosition(30, 2);
	cout << "    1      ";
	Console::ForegroundColor = ConsoleColor::Blue;
	Console::SetCursorPosition(30, 3);
	cout << "   _O_      ";
	Console::SetCursorPosition(30, 4);
	cout << " /     \\   ";
	Console::SetCursorPosition(30, 5);
	cout << "|==/=\\==|  ";
	Console::SetCursorPosition(30, 6);
	cout << "|  O O  |  ";
	Console::SetCursorPosition(30, 7);
	cout << " \\  V  /   ";
	Console::SetCursorPosition(30, 8);
	cout << " /`---'\\   ";
	Console::SetCursorPosition(30, 9);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "    @       ";
	
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(44, 2);
	cout << "    2      ";
	Console::ForegroundColor = ConsoleColor::Cyan;
	Console::SetCursorPosition(44, 3);
	cout << "  _____    ";
	Console::SetCursorPosition(44, 4);
	cout << " |     |   ";
	Console::SetCursorPosition(44, 5);
	cout << " |[/_\\]|   ";
	Console::SetCursorPosition(44, 6);
	cout << " / O O \\   ";
	Console::SetCursorPosition(44, 7);
	cout << "/\\  -  /\\ ";
	Console::SetCursorPosition(44, 8);
	cout << " /`---'\\   ";
	Console::SetCursorPosition(44, 9);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "    $       ";
	Console::SetCursorPosition(58, 2);
	cout << "      3      ";
	Console::ForegroundColor = ConsoleColor::Red;
	Console::SetCursorPosition(58, 3);
	cout << "     _<>_      ";
	Console::SetCursorPosition(58, 4);
	cout << "   /      \\   ";
	Console::SetCursorPosition(58, 5);
	cout << "  |==\\==/==|  ";
	Console::SetCursorPosition(58, 6);
	cout << "  |   ><   |  ";
	Console::SetCursorPosition(58, 7);
	cout << ",-\\   ()   /-.";
	Console::SetCursorPosition(58, 8);
	cout << "V( `-====-' )V";
	Console::SetCursorPosition(58, 9);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "      O       ";
	Console::SetCursorPosition(74, 2);
	cout << "    4      ";
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(74, 3);
	cout << "   ___      ";
	Console::SetCursorPosition(74, 4);
	cout << " /  _  \\   ";
	Console::SetCursorPosition(74, 5);
	cout << "|  / \\  |  ";
	Console::SetCursorPosition(74, 6);
	cout << "|  |\"|  |  ";
	Console::SetCursorPosition(74, 7);
	cout << " \\  X  /   ";
	Console::SetCursorPosition(74, 8);
	cout << " /`---'\\   ";
	Console::SetCursorPosition(74, 9);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "    &      ";

	Console::SetCursorPosition(88, 2);
	cout << "   5      ";
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(88, 3);
	cout << "|\\/\\/\\/|  ";
	Console::SetCursorPosition(88, 4);
	cout << "|      |   ";
	Console::SetCursorPosition(88, 5);
	cout << "| (o)(o)   ";
	Console::SetCursorPosition(88, 6);
	cout << "C      _)  ";
	Console::SetCursorPosition(88, 7);
	cout << "| ,___|    ";
	Console::SetCursorPosition(88, 8);
	cout << "|    /     ";
	Console::SetCursorPosition(88, 9);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "   W      ";
}
void interfazNombre(int numPersonaje) {
	system("cls");
	interfazAvatar();
	Console::ForegroundColor = ConsoleColor::DarkYellow;
	Console::SetCursorPosition((ANCHO_PANTALLA / 2) - 10, ALTO_PANTALLA/2);
	cout << "Ingrese su nombre "<<numPersonaje<<endl;
}

char ingresoAvatar(int numAvatar) {
	switch (numAvatar) {
	case 1:
		return '@';
		break;
	case 2:
		return '$';
		break;
	case 3:
		return 'O';
		break;
	case 4:
		return '&';
		break;
	case 5:
		return 'W';
		break;
	default: return '@';
	}
	
}

void ingresoDatos(Jugador jugadores[]) {
	int avatar;
	for (int i =0; i < 2;i++) {
		interfazNombre(i);
		Console::SetCursorPosition((ANCHO_PANTALLA / 2)-10, (ALTO_PANTALLA / 2) + 1);
		cin >> jugadores[i].nombre;
		Console::SetCursorPosition((ANCHO_PANTALLA / 3) + 10, (ALTO_PANTALLA / 2) + 2);
		cout << "Ingrese el numero del avatar: ";
		cin >> avatar;
		jugadores[i].avatar = ingresoAvatar(avatar);
		_getch();
	}
}
void dibujarCasilla(int x, int y, char tipo)
{
	if (tipo == 'C')
	{
		Console::ForegroundColor = ConsoleColor::Blue;

		Console::SetCursorPosition(x, y);
		cout << "+----+";

		Console::SetCursorPosition(x, y + 1);
		cout << "|    |";

		Console::SetCursorPosition(x, y + 2);
		cout << "+----+";
	}

	if (tipo == 'O')
	{
		Console::ForegroundColor = ConsoleColor::Red;

		Console::SetCursorPosition(x, y);
		cout << " /--\\ ";

		Console::SetCursorPosition(x, y + 1);
		cout << "(    )";

		Console::SetCursorPosition(x, y + 2);
		cout << " \\--/ ";
	}

	if (tipo == 'R')
	{
		Console::ForegroundColor = ConsoleColor::Magenta;

		Console::SetCursorPosition(x, y);
		cout << "  /\\  ";

		Console::SetCursorPosition(x, y + 1);
		cout << "<    >";

		Console::SetCursorPosition(x, y + 2);
		cout << "  \\/  ";
	}
}
void moverJugador(Jugador& j, int pasos)
{
	j.posicion += pasos;

	while (j.posicion >= CASILLAS)
	{
		j.posicion -= CASILLAS;
		j.mapaActual++;

		if (j.mapaActual >= MAPAS)
		{
			j.mapaActual = MAPAS - 1;
			j.posicion = CASILLAS - 1;
			break;
		}
	}
}
void fondoMapa() {
	Console::Clear();
}
void eventosCasillas(Jugador& j, Jugador& j2) {
	char casillas = mapas[j.mapaActual][j.posicion];
	switch (j.mapaActual) {
	case 'O':
		if (casillas == 'O')fondoMapa();
		break;
	}
}
int turnoJugador(Jugador& j)
{
	int pasos = lanzarDado(2);
	moverJugador(j, pasos);
	return pasos;
}
void dibujarMapa(Jugador& j1, Jugador& j2)
{
	int baseX = 25;
	int baseY = 8;
	int anchoCasilla = 6;

	for (int i = 0; i < CASILLAS; i++)
	{
		int x = baseX + i * anchoCasilla;
		char tipo = mapas[j1.mapaActual][i];

		bool j1Aqui = (i == j1.posicion && j1.mapaActual == j1.mapaActual); 
		bool j2Aqui = (i == j2.posicion && j2.mapaActual == j1.mapaActual);

		string centro = "    "; 
		if (j1Aqui && j2Aqui)      centro = string(" ") + j1.avatar + j2.avatar + " ";
		else if (j1Aqui)           centro = string("  ") + j1.avatar + " ";
		else if (j2Aqui)           centro = string("  ") + j2.avatar + " ";
		if (tipo == 'C')
		{
			Console::ForegroundColor = (j1Aqui || j2Aqui) ? ConsoleColor::Yellow : ConsoleColor::Blue;
			Console::SetCursorPosition(x, baseY);     cout << "+----+";
			Console::SetCursorPosition(x, baseY + 1); cout << "|" << centro << "|";
			Console::SetCursorPosition(x, baseY + 2); cout << "+----+";
		}
		else if (tipo == 'O')
		{
			Console::ForegroundColor = (j1Aqui || j2Aqui) ? ConsoleColor::Yellow : ConsoleColor::Red;
			Console::SetCursorPosition(x, baseY);     cout << " /--\\ ";
			Console::SetCursorPosition(x, baseY + 1); cout << "(" << centro << ")";
			Console::SetCursorPosition(x, baseY + 2); cout << " \\--/ ";
		}
		else if (tipo == 'R')
		{
			Console::ForegroundColor = (j1Aqui || j2Aqui) ? ConsoleColor::Yellow : ConsoleColor::Magenta;
			Console::SetCursorPosition(x, baseY);     cout << "  /\\  ";
			Console::SetCursorPosition(x, baseY + 1); cout << "<" << centro << ">";
			Console::SetCursorPosition(x, baseY + 2); cout << "  \\/  ";
		}

		// Número de casilla
		Console::ForegroundColor = ConsoleColor::DarkGray;
		Console::SetCursorPosition(x + 1, baseY + 3);
		if (i < 10) cout << " " << i;
		else        cout << i;
	}

	Console::ForegroundColor = ConsoleColor::White;
}
void dibujarMarco() {
	Console::ForegroundColor = ConsoleColor::White;
	for (int i = 1; i <= ANCHO_PANTALLA-1; i++) {
		Console::SetCursorPosition(i,0);
		cout << '-';
	}
	for (int i = 1; i <= ANCHO_PANTALLA-1;i++) {
		Console::SetCursorPosition(i, ALTO_PANTALLA - 1);
		cout << '-';
	}
	for (int j = 1; j <= ALTO_PANTALLA; j++) {
		if (j == 1 || j == ALTO_PANTALLA) {
			Console::SetCursorPosition(1, j-1);
			cout << '+';
			Console::SetCursorPosition(ANCHO_PANTALLA-1, j - 1);
			cout << '+';
		}
		else {
			Console::SetCursorPosition(1, j-1);
			cout << '|';
			Console::SetCursorPosition(ANCHO_PANTALLA-1, j-1);
			cout << '|';
		}
	}
	for (int b = 1; b <= ANCHO_PANTALLA-1; b++) {
		if (b == 1 || b == ANCHO_PANTALLA-1) {
			Console::SetCursorPosition(b, (ALTO_PANTALLA / 2) + 4);
			cout << '+';
		}
		else {
			Console::SetCursorPosition(b,(ALTO_PANTALLA/2)+4);
			cout << '-';
		}
	}
	for (int b = 1; b <= (ALTO_PANTALLA/2)+5; b++) {
		if (b == 1 || b == (ALTO_PANTALLA / 2) + 5) {
			Console::SetCursorPosition((ALTO_PANTALLA / 2) + 6, b - 1);
			cout << '+';
		}
		else {
			Console::SetCursorPosition((ALTO_PANTALLA/2)+6,b-1);
			cout << '|';
		}
	}
}
void limpiarZonaMapa()
{
	for (int y = 5; y < 10; y++)
	{
		Console::SetCursorPosition(50, y);
		cout << "                                        ";
	}
}
void mostrarEstadoJugadores(Jugador& j1, Jugador& j2,string jugadorTurno,int ultimoDado)
{
	for (int y = 20; y <= 26; y++)
	{
		Console::SetCursorPosition(2, y);
		cout << string(115, ' ');
	}
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 1);
	cout << "Informacion General"<<endl;
	Console::ForegroundColor = ConsoleColor::White;

	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 2);
	cout << "Jugador 1: "<<endl;
	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 3);
	cout << j1.nombre<< " (" << j1.avatar << ")";
	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 4);
	cout << "Mapa: " << j1.mapaActual;
	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 5);
	cout << "Pos: " << j1.posicion;
	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 6);
	cout << "Monedas: " << j1.monedas;
	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 7);
	cout << "Estrellas: " << j1.estrellas;


	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 8);
	cout << "Jugador 2: " << endl;
	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 9);
	cout<<j2.nombre<< " (" << j2.avatar << ")";

	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 10);
	cout << "Mapa: " << j2.mapaActual;

	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 11);
	cout << "Pos: " << j2.posicion;

	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 12);
	cout << "Monedas: " << j2.monedas;

	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 13);
	cout << "Estrellas: " << j2.estrellas;


	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 14);
	cout << "Turno actual: " << jugadorTurno;

	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 15);
	cout << "                    "; // limpiar

	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 15);
	cout << "Ultimo dado: " << ultimoDado;
}
void iniciarJuego()
{
	Jugador j;
	Jugador j2;

	bool turno = true;

	j.nombre = "Leonardo";
	j.mapaActual = 0;
	j.posicion = 0;
	j.monedas = 0;
	j.estrellas = 0;
	j.avatar = '@';

	j2.nombre = "Carlos";
	j2.mapaActual = 0;
	j2.posicion = 0;
	j2.monedas = 0;
	j2.estrellas = 0;
	j2.avatar = '&';

	srand(time(NULL));

	system("cls");
	dibujarMarco();

	while (true)
	{
		Console::SetCursorPosition(5, 27);
		cout << "Presione ESPACIO para lanzar el dado (ESC para salir) ";

		char tecla = _getch();

		if (tecla == 27) 
			break;

		if (tecla != ' ')
			continue;

		limpiarZonaMapa();

		int dado = 0;

		if (turno)
		{
			dado = turnoJugador(j);
			eventosCasillas(j, j2);
			dibujarMapa(j, j2);

			mostrarEstadoJugadores(
				j,
				j2,
				j.nombre,
				dado
			);
		}
		else
		{
			dado = turnoJugador(j2);

			dibujarMapa(j, j2);

			mostrarEstadoJugadores(
				j,
				j2,
				j2.nombre,
				dado
			);
		}

		turno = !turno;
	}
}
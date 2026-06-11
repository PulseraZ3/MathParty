#include "Jugador.h"
#include "Game.h"
#include <iostream>
#include <conio.h>
#define ANCHO_PANTALLA 120
#define ALTO_PANTALLA 30
using namespace std;
using namespace System;
const int NUM_CASILLAS = 20;

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
	for (int i = 1; i <= 2;i++) {
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
void dibujarTablero(char tipo)
{

}
void dibujarMarco() {
	system("cls");
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
void iniciarJuego() {
	dibujarMarco();
	dibujarTablero();
	_getch();
}
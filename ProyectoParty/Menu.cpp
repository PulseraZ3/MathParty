#include "Menus.h"
#include <iostream>
#include <conio.h>
#define ANCHO_PANTALLA 120
#define ALTO_PANTALLA 30
using namespace std;
using namespace System;
void pantalla() {
	Console::SetWindowSize(ANCHO_PANTALLA, ALTO_PANTALLA);
	Console::CursorVisible = false;
}
void menuPrincipal() {
	pantalla();
	//Math
	Console::ForegroundColor = ConsoleColor::Blue;
	Console::SetCursorPosition(ANCHO_PANTALLA/10, (ALTO_PANTALLA/6));
	cout << "$$\\      $$\\  $$$$$$\\ $$$$$$$$\\ $$\\   $$\\";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA/6)+1);
	cout << "$$$\\    $$$ |$$  __$$\\\\__$$  __|$$ |  $$ |";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA/6)+2);
	cout << "$$$$\\  $$$$ |$$ /  $$ |  $$ |   $$ |  $$ |";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA/6)+3);
	cout << "$$\\$$\\$$ $$ |$$$$$$$$ |  $$ |   $$$$$$$$ |";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA/6)+4);
	cout << "$$ \\$$$  $$ |$$  __$$ |  $$ |   $$  __$$ |";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA/6)+5);
	cout << "$$ |\\$  /$$ |$$ |  $$ |  $$ |   $$ |  $$ |";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA/6)+6);
	cout << "$$ | \\_/ $$ |$$ |  $$ |  $$ |   $$ |  $$ |";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA/6)+7);
	cout << "\\__|     \\__|\\__|  \\__|  \\__|   \\__|  \\__|";
	// Party
	Console::ForegroundColor = ConsoleColor::Magenta;
	Console::SetCursorPosition(ANCHO_PANTALLA / 2, (ALTO_PANTALLA / 6));
	cout << " /$$$$$$$   /$$$$$$  /$$$$$$$  /$$$$$$$$ /$$     /$$";
	Console::SetCursorPosition(ANCHO_PANTALLA / 2, (ALTO_PANTALLA / 6) + 1);
	cout << "| $$__  $$ /$$__  $$| $$__  $$|__  $$__/|  $$   /$$/";
	Console::SetCursorPosition(ANCHO_PANTALLA / 2, (ALTO_PANTALLA / 6) + 2);
	cout << "| $$  \\ $$| $$  \\ $$| $$  \\ $$   | $$    \\  $$ /$$/ ";
	Console::SetCursorPosition(ANCHO_PANTALLA / 2, (ALTO_PANTALLA / 6) + 3);
	cout << "| $$$$$$$/| $$$$$$$$| $$$$$$$/   | $$     \\  $$$$/  ";
	Console::SetCursorPosition(ANCHO_PANTALLA / 2, (ALTO_PANTALLA / 6) + 4);
	cout << "| $$____/ | $$__  $$| $$__  $$   | $$      \\  $$/   ";
	Console::SetCursorPosition(ANCHO_PANTALLA / 2, (ALTO_PANTALLA / 6) + 5);
	cout << "| $$      | $$  | $$| $$  \\ $$   | $$       | $$    ";
	Console::SetCursorPosition(ANCHO_PANTALLA / 2, (ALTO_PANTALLA / 6) + 6);
	cout << "| $$      | $$  | $$| $$  | $$   | $$       | $$    ";
	Console::SetCursorPosition(ANCHO_PANTALLA / 2, (ALTO_PANTALLA / 6) + 7);
	cout << "|__/      |__/  |__/|__/  |__/   |__/       |__/    ";
	_getch();
}
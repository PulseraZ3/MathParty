#include "Menus.h"
#include "Game.h"
#include <iostream>
#include <conio.h>
#define ANCHO_PANTALLA 120
#define ALTO_PANTALLA 30
using namespace std;
using namespace System;
//aca es para setear el ancho de la pantalla  con valores define 
void pantalla() {
	Console::SetWindowSize(ANCHO_PANTALLA, ALTO_PANTALLA);
	Console::CursorVisible = false;
}

void menuJuego() {

}
//aca menu de configuracion
void menuConfiguracion() {
	system("cls");
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA / 10));
	cout << "  ___  __   __ _  ____  __  ___ ";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA / 10) + 1);
	cout << " / __)/  \\ (  ( \\(  __)(  )/ __)";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA / 10) + 2);
	cout << "( (__(  O )/    / ) _)  )(( (_ \\";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA / 10) + 3);
	cout << " \\___)\\__/ \\_)__)(__)  (__)\\___/";
	_getch();
}
//aca es mathParty, esto fue lo primero que se programo por eso esta asui 
void tituloPrincipal() {
	Console::ForegroundColor = ConsoleColor::Blue;
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA / 6));
	cout << "$$\\      $$\\  $$$$$$\\ $$$$$$$$\\ $$\\   $$\\";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA / 6) + 1);
	cout << "$$$\\    $$$ |$$  __$$\\\\__$$  __|$$ |  $$ |";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA / 6) + 2);
	cout << "$$$$\\  $$$$ |$$ /  $$ |  $$ |   $$ |  $$ |";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA / 6) + 3);
	cout << "$$\\$$\\$$ $$ |$$$$$$$$ |  $$ |   $$$$$$$$ |";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA / 6) + 4);
	cout << "$$ \\$$$  $$ |$$  __$$ |  $$ |   $$  __$$ |";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA / 6) + 5);
	cout << "$$ |\\$  /$$ |$$ |  $$ |  $$ |   $$ |  $$ |";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA / 6) + 6);
	cout << "$$ | \\_/ $$ |$$ |  $$ |  $$ |   $$ |  $$ |";
	Console::SetCursorPosition(ANCHO_PANTALLA / 10, (ALTO_PANTALLA / 6) + 7);
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

	//play
	Console::ForegroundColor = ConsoleColor::DarkYellow;
	Console::SetCursorPosition((ANCHO_PANTALLA / 3) + 5, (ANCHO_PANTALLA / 7));
	cout << " _____ __    _____ __ __ ";
	Console::SetCursorPosition((ANCHO_PANTALLA / 3) + 5, (ANCHO_PANTALLA / 7) + 1);
	cout << "|  _  |  |  |  _  |  |  |";
	Console::SetCursorPosition((ANCHO_PANTALLA / 3) + 5, (ANCHO_PANTALLA / 7) + 2);
	cout << "|   __|  |__|     |_   _|";
	Console::SetCursorPosition((ANCHO_PANTALLA / 3) + 5, (ANCHO_PANTALLA / 7) + 3);
	cout << "|__|  |_____|__|__| |_|  ";
	Console::SetCursorPosition((ANCHO_PANTALLA / 3) + 10, (ANCHO_PANTALLA / 7) + 4);
	cout << "Press 1 to Play";

}

//aca esta lo mas importante
void menuPrincipal() {
	pantalla(); // declaramos la pantalla
	//Math
	char tecla;
	Jugador jugadores[2]; // inicializamos los dos jugadores 

	while (true){ // el while importante 
		system("cls");
		tituloPrincipal();//inicializamos el titulo
		//Falta el config
			tecla = _getch();
			switch (tecla) {
			case '1': // si presiona 1 entonces jugamos 
				ingresoDatos(jugadores);
				iniciarJuego(jugadores[0],jugadores[1]);
				break;
			case '2': 
				menuConfiguracion(); //configuracion la cual aun no se puede configurar
				break;
			case '3':
				return;
				break;
			}

	}
	
}

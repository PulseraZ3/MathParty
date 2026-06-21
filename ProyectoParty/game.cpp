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
//definicion del mapa C = "Casilla comun" O = "casilla rara" y R = "juegos" solo un juego por mapa
char mapas[MAPAS][CASILLAS] =
{
	{'C','C','C','O','C','C','O','C','C','C','C','C','O','C','R'},
	{'C','C','C','O','C','C','O','C','C','C','C','C','O','C','R'},
	{'C','C','C','O','C','C','O','C','C','C','C','C','O','C','R'},
	{'C','C','C','O','C','C','O','C','C','C','C','C','O','C','R'},
	{'C','C','C','O','C','C','O','C','C','C','C','C','O','C','R'}
};

//avatars de los juegadores, solo disponibles 5
string avatar1[] = {
		"    1      ",
		"   _O_      ",
		" /     \\   ",
		"|==/=\\==|  ",
		"|  O O  |  ",
		" \\  V  /   ",
		" /`---'\\   "
};
string avatar2[] = {
		"    2      ",
		"  _____    ",
		" |     |   ",
		" |[/_\\]|   ",
		" / O O \\   ",
		"/\\  -  /\\ ",
		" /`---'\\   ",
};
string avatar3[] = {
		"      3      ",
		"     _<>_      ",
		"   /      \\   ",
		"  |==\\==/==|  ",
		"  |   ><   |  ",
		",-\\   ()   /-.",
		"V( `-====-' )V"
};
string avatar4[] = {
	"    4      ",
	"   ___      ",
	" /  _  \\   ",
	"|  / \\  |  ",
	"|  |\"|  |  ",
	" \\  X  /   ",
	" /`---'\\   "
};
string avatar5[] = {
		"   5      ",
		"|\\/\\/\\/|  ",
		"|      |   ",
		"| (o)(o)   ",
		"C      _)  ",
		"| ,___|    ",
		"|    /     "
};
//fondo, en este caso Nivel 1 : Viejo Oeste
string casa[] = {
	"         _",
	"      _-'_'-_",
	"   _-' _____ '-_",
	"_-' ___________ '-_",
	" |___|||||||||___|",
	" |___|||||||o|___|",
	" |___|||||||||___|"
};
string cactus[] = {
	"    ,-.",
	" ,. | |",
	" ||_| | ,.",
	" `--. |_||",
	"    | .--`",
	"    | |",
};
string vaquerosDer[] = {
	" O .-+",
	"/|-/",
	"/ \\"
};
string vaquerosIz[] = {
	"+-. O ",
	"  \\-|\\",
	"   / \\"
};

//fondo, en este caso Nivel 2 : PokeMath

string arbol[] = {
	"    .-^-.",
	"   /     \\",
	"  / .---. \\",
	"  \\_______/",
	"      |",
	"      |"
};
string hierba[] = {
	" \\|/ \\|/",
	"  |   |  ",
};
//fondo, en este caso Nivel 3: Mundo marino
string tiburon[] = {
	"       .   )\\ ",
	"       \\`.-' `-oo",
	"        ) _  __,0)",
	"       /.' )/       ",
	"       '"
};
string alga[] = {
	" )",
	" (",
	" )",
	"/"
};
string pez[] = {
	"><>"
};
string castilloAcuatico[] = {
	"      ____________              ",
	"     /____________\\            ",
	"   _  |_   _  :_:|   _   _   _  ",
	"  | |_| |_| |   _|  | |_| |_| |",
	"   \\_:_:_:_:/|_|_|_|\\:_:_:_:_/ ",
	"    |:|_|:_:_:,---,:_:_:|_|:| ",
	"    |_:_:_:_,'     `,_:_:_:_|",
	"    |:_:_:_/         \\_:_:_:|",
	"____|_:_:_|           |_:_:_|",
	".  `|_:_:_|           |_:_:_|"
};
//fondo, en este caso Nivel 4 : Medieval
string castilloRojo[] = {
	"         o___.-' /",
	"         |      _\\_",
	"         |___.-'   ",
	"         |",
	"[_]_[_]_[_]_[_]_[_]",
	"[__j__j__j__j__j__]",
	"  [_j__j/V\\_j__j]",
	"  [__j_// \\\\__j_]",
	"  [__j_|___|__j_]",
	"  [_j__j__j__j__]",
	"  [__j__j__j__j_]",
};
string castilloAzul[] = {
	"\\ '-.___o",
	" /_      |",
	"   '-.___|",
	"         |",
	"[_]_[_]_[_]_[_]_[_]",
	"[__j__j__j__j__j__]",
	"  [_j__j/V\\_j__j]",
	"  [__j_// \\\\__j_]",
	"  [__j_|___|__j_]",
	"  [_j__j__j__j__]",
	"  [__j__j__j__j_]",
};
string canonDer[] = {
	"             , .",
	"      _-|---= *:--",
	"   ._(O)/     ' `",
};
string canonIz[] = {
	"        . ,",
	"      --:* =---|-_",
	"       ` '     \\(O)_.",
};

//creacion del turno de personaje
int turnoPersonaje() {
	return rand() % 6 + 1;
}

//utilizacion del dado de Mayumi
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
//lanzar dado, en este caso son dos veces, reciber la cantidad de veces que se lanzara dado
int lanzarDado(int cantidadDado) {
	int suma = 0;
	for (int i = 1; i <= cantidadDado; i++) {
		int dado = turnoPersonaje();
		//creacionDadito(dado);
		suma += dado;
	}
	return suma;
}
//interfaz de menu avatar, donde se usan for para el borde ******
//se dibuja los avatars.
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
	
	for (int i = 0; i < 7; i++) {
		Console::ForegroundColor = ConsoleColor::Cyan;
		Console::SetCursorPosition(30, i + 2);
		cout<<avatar1[i];
	}
	Console::SetCursorPosition(30, 9);
	Console::ForegroundColor = ConsoleColor::White;

	cout << "    @       ";
	
	for (int i = 0;i < 7; i++) {
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(44, i + 2);
		cout << avatar2[i];
	}
	Console::SetCursorPosition(44, 9);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "    $       ";
	
	for (int i = 0;i < 7; i++) {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(58, i + 2);
		cout << avatar3[i];
	}
	Console::SetCursorPosition(58, 9);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "      O       ";
	
	for (int i = 0;i < 7; i++) {
		Console::ForegroundColor = ConsoleColor::Blue;
		Console::SetCursorPosition(74, i+2);
		cout << avatar4[i];
	}
	Console::SetCursorPosition(74, 9);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "    &      ";
	
	for (int i = 0;i < 7; i++) {
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(88, i + 2);
		cout << avatar5[i];
	}
	Console::SetCursorPosition(88, 9);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "   W      ";
}
//ingreso de nombre, integaz de ingresos 
void interfazNombre(int numPersonaje) {
	system("cls");
	interfazAvatar();
	Console::ForegroundColor = ConsoleColor::DarkYellow;
	Console::SetCursorPosition((ANCHO_PANTALLA / 2) - 10, ALTO_PANTALLA/2);
	cout << "Ingrese su nombre "<<numPersonaje<<endl;
}
// evaluamos el numAvatar y dependiendo del numero tendra un avatar de char deiferentes
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

//primeor agarramos al jugador j y su opcion lo cual debe ingresar
// evaluamos la opcion, si elegio = avatar 1 en este caso, case 1 se pondra elegido = avatar1,
//ahora dibujamos en j.dibujo[] le pojnemos que sea igual al elegido[] 
//basicamente para escribir lo que tenemos en j.dibujo y ya xd
void asiganarAvatar(Jugador& j, int opcion) {
	string* elegido;
	switch (opcion) {
	case 1: elegido = avatar1; break;
	case 2: elegido = avatar2;break;
	case 3: elegido = avatar3;break;
	case 4: elegido = avatar4;break;
	case 5: elegido = avatar5;break;
	}
	for (int i = 0; i < 7;i++) {
		j.dibujo[i] = elegido[i];
	}
}
//aca se ingresan datos basicmos como nombre y avatar que arriba se esta agarrando.
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
		asiganarAvatar(jugadores[i], avatar);
		_getch();
	}
}
//aca primero agarramos los datos del jugador y x y es para mero posicionamiento
void dibujarAvatar(Jugador& j, int x, int y) {
	for (int i = 1; i < 7; i++) {//el avatar tiene de ancho 7 y de alto 7 le puse 20 para que sea mas grande y se borre, sobretodo en la parte de pokemath, fue lo que mejor se me ocurrio
		Console::SetCursorPosition(x, y + i);
		cout << string(20, ' ');
	}
	for (int i = 1;i < 7;i++) {
		Console::SetCursorPosition(x, y + i);
		cout << j.dibujo[i];
	}
}
//aca primero dependiendo del tipo de se dibuja lo siguiente
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

//aca tenemos la cantidad de posiciones, en este caso agarrramos jugador ejemplo j1, ahora la cantidad de posiociones en este caso es lo que salga del dado
void moverJugador(Jugador& j, int pasos)
{
	if (j.esperando) return;//si el jugador esta esperando entonces ejecutamos return para que se acabe la funcion

	j.posicion += pasos; // de lo contrario hacemos que avance las posiciones que es igual a tu posicion actual ya sea = 0 j1.posicion = j1.posicion+pasos en este caso ponte que sacas 12 en el dado

	if (j.posicion >= CASILLAS) // si posiciones es mayor a casillas en este caso 
	{
		j.posicion = CASILLAS - 1; //tu posicion cambia a la casilla actual -1
		if (j.mapaActual < MAPAS - 1) // si el mapaactual es menor a mapas-1 en este caso 
			j.esperando = true; // si llegas al final vaya
	}
}
//en este caso validamos si llegan al final de un mapa, lo que hacemos que los enviamos al siguiente mapa y reiniciamos sus posiciones a 0.
void revisarAvanceMapa(Jugador& j1, Jugador& j2)
{
	if (j1.esperando && j2.esperando)
	{
		j1.mapaActual++;
		j2.mapaActual++;
		j1.posicion = 0;
		j2.posicion = 0;
		j1.esperando = false;
		j2.esperando = false;

		if (j1.mapaActual >= MAPAS) j1.mapaActual = MAPAS - 1;
		if (j2.mapaActual >= MAPAS) j2.mapaActual = MAPAS - 1;
	}
}

//dependiendo del mapa tiene un diferente fondo y ya xd
void fondoMapa(int mapa) {

	switch (mapa) {
	case 1:
		for (int i = 0; i < 7; i++) {
			Console::ForegroundColor = ConsoleColor::DarkYellow;
			Console::SetCursorPosition(25, 1 + i);
			cout << casa[i];
			Console::ForegroundColor = ConsoleColor::DarkYellow;
			Console::SetCursorPosition(95, 1 + i);
			cout << casa[i];
			if (i < 6) {
				Console::ForegroundColor = ConsoleColor::Green;
				Console::SetCursorPosition(45, 2 + i);
				cout << cactus[i];


				Console::ForegroundColor = ConsoleColor::Green;
				Console::SetCursorPosition(84, 2 + i);
				cout << cactus[i];

			}
			if (i < 3) {
				Console::ForegroundColor = ConsoleColor::White;
				Console::SetCursorPosition(60, 5 + i);
				cout << vaquerosDer[i];
				Console::ForegroundColor = ConsoleColor::White;
				Console::SetCursorPosition(75, 5 + i);
				cout << vaquerosIz[i];
			}
		}
		break;

	case 2: 
		for (int i = 0; i < 6; i++) {
			Console::ForegroundColor = ConsoleColor::DarkGreen;
			Console::SetCursorPosition(21, 1 + i);
			cout << arbol[i];

			Console::SetCursorPosition(60, 1 + i);
			cout << arbol[i];

			Console::SetCursorPosition(95, 1 + i);
			cout << arbol[i];
		}
		for (int i = 0; i < 2; i++) {
			Console::ForegroundColor = ConsoleColor::Green;
			Console::SetCursorPosition(35, 8 + i);
			cout << hierba[i];

			Console::SetCursorPosition(75, 8 + i);
			cout << hierba[i];

			Console::SetCursorPosition(105, 8 + i);
			cout << hierba[i];
		}
		break;

	case 3: // Mapa inspirado en un mundo acuatico
		for (int i = 0; i < 10;i++) {
			Console::SetCursorPosition(25, 1 + i);
			cout << castilloAcuatico[i];
		}
		for (int i = 0; i < 5; i++) {
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(60, 1 + i);
			cout << tiburon[i];
			if (i < 4) {

				Console::ForegroundColor = ConsoleColor::Green;
				Console::SetCursorPosition(70, 6 + i);
				cout << alga[i];

				Console::SetCursorPosition(105, 6 + i);
				cout << alga[i];

			}
			if (i < 1) {
				Console::ForegroundColor = ConsoleColor::Blue;
				Console::SetCursorPosition(100, 4 + i);
				cout << pez[i];
			}
		}
		break;
	case 4:
		for (int i = 0; i < 11; i++) {
			Console::ForegroundColor = ConsoleColor::Red;
			Console::SetCursorPosition(24, 1 + i);
			cout << castilloRojo[i];
			Console::ForegroundColor = ConsoleColor::Blue;
			Console::SetCursorPosition(99, 1 + i);
			cout << castilloAzul[i];
			if (i < 3) {
				Console::ForegroundColor = ConsoleColor::Red;
				Console::SetCursorPosition(40, 9 + i);
				cout << canonDer[i];
				Console::ForegroundColor = ConsoleColor::Blue;
				Console::SetCursorPosition(78, 9 + i);
				cout << canonIz[i];
			}
		}
		break;
	}
}

//dependiendo de la casilla en la que caigas ocurre algo, podria agregar mas n ose xd

void eventosCasillas(Jugador& j,Jugador& j2, bool& pokeMathJugado, bool& artiJugado, bool& reflejosJugado) {
	char casillas = mapas[j.mapaActual][j.posicion];
		if (casillas == 'O') {
			j.monedas += 5;
		}
		if (casillas == 'R' && j.mapaActual == 2 && !pokeMathJugado) {
			juegoPokeMath(j,j2);
			pokeMathJugado = true;
			Console::Clear();
			fondoMapa(j.mapaActual);
			dibujarMarco();
		}
		if (casillas == 'R' && j.mapaActual == 4 && !artiJugado) {
			juego_artilleria(j, j2);
			artiJugado = true;
			Console::Clear();
			fondoMapa(j.mapaActual);
			dibujarMarco();
		}
		if (casillas == 'R' && j.mapaActual == 1 && !reflejosJugado) {
			juegoreflejos(j, j2);
			reflejosJugado = true;
			Console::Clear();
			fondoMapa(j.mapaActual);
			dibujarMarco();
		}

	
}
//en este caso uso mi lanzar dado(2) 2 significa la cantidad de dados que vamos a lanzar y bueno retorna los pasos que a avanzara
int turnoJugador(Jugador& j)
{
	int pasos = lanzarDado(2);
	moverJugador(j, pasos);
	return pasos;
}

//ya aca es el mapa recibimos los dos jugadores, solo necitamos la posiicon avatar y mapaactual
void dibujarMapa(Jugador& j1, Jugador& j2)
{
	//primero definimos la posicion inicial del mapa 
	int baseX = 25;
	int baseY = 13;
	int anchoCasilla = 6; 

	for (int i = 0; i < CASILLAS; i++) //aca hacemos un for con la cantidad de casillas
	{
		int x = baseX + i * anchoCasilla; //calculamos la posiicon horizontal 
		char tipo = mapas[j1.mapaActual][i]; //obtemeos el tipo de casilla

		bool j1Aqui = (i == j1.posicion && j1.mapaActual == j1.mapaActual);  
		bool j2Aqui = (i == j2.posicion && j2.mapaActual == j1.mapaActual);

		string centro = "    "; 
		if (j1Aqui && j2Aqui)      centro = string(" ") + j1.avatar + j2.avatar + " "; // si estan ambos
		else if (j1Aqui)           centro = string("  ") + j1.avatar + " "; // si solo esta jugador 1 
		else if (j2Aqui)           centro = string("  ") + j2.avatar + " "; // si solo esta jugador 2
		if (tipo == 'C') //aca estamos dibujando la casilla con el avatar adentro 
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

		Console::ForegroundColor = ConsoleColor::DarkGray;
		Console::SetCursorPosition(x + 1, baseY + 3);
		if (i < 10) cout << " " << i;
		else        cout << i;
	}

	Console::ForegroundColor = ConsoleColor::White;
}

//fors para dibujar los marcos
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

//limpiamos el mapa para que se actualice
void limpiarZonaMapa()
{
	int borde = (ALTO_PANTALLA / 2) + 10;
	for (int y = 13; y < 16; y++)
	{
		Console::SetCursorPosition(borde, y);
		cout << string(ANCHO_PANTALLA-borde-4, ' ');
	}
}
//mostramos ifnromacion general de ambos jugadores 
void mostrarEstadoJugadores(Jugador& j1, Jugador& j2,string jugadorTurno,int ultimoDado)
{
	for (int y = 1; y <= 12; y++)
	{
		Console::SetCursorPosition(2, y);
		cout << string(18, ' ');
	}
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
	cout << "Mapa: " << j1.mapaActual;
	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 4);
	cout << "Pos: " << j1.posicion;

	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 6);
	cout << "Jugador 2: " << endl;

	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 7);
	cout << "Mapa: " << j2.mapaActual;

	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 8);
	cout << "Pos: " << j2.posicion;

	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 9);
	cout << "Turno: " << jugadorTurno;
}
bool juegoTerminado(Jugador& j1, Jugador& j2)
{
	bool j1Final = (j1.mapaActual == MAPAS - 1 &&
		j1.posicion == CASILLAS - 1);

	bool j2Final = (j2.mapaActual == MAPAS - 1 &&
		j2.posicion == CASILLAS - 1);

	return j1Final || j2Final;
}
//aca es la interfaz de objetos donde estan infromacion mas especifica del juego
void intefazObjetos(Jugador& j, int x, int y) {

	Console::SetCursorPosition(x + 10, y);
	cout <<"Tablero Avatar: " << j.avatar;

	dibujarAvatar(j, x, y);

	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(x + 12, y + 1);
	cout << "Monedas: " << j.monedas << "   ";

	Console::SetCursorPosition(x + 23, y + 1);
	cout << "Estrellas: " << j.estrellas << "   ";

	Console::ForegroundColor = ConsoleColor::DarkMagenta;
	Console::SetCursorPosition(x + 12, y + 2);
	cout << "Minijuegos Ganados: " << j.minijuegosGanados<< "   ";
	Console::ResetColor();
}
// decide quien gana
int determinarGanador(Jugador& j1, Jugador& j2) {
	if (j1.estrellas != j2.estrellas) {
		if (j1.estrellas > j2.estrellas) {
			return 1;
		}
		else {
			return 2;
		}
	}

	if (j1.monedas != j2.monedas) {
		if (j1.monedas > j2.monedas) {
			return 1;
		}
		else {
			return 2;
		}
	}

	if (j1.minijuegosGanados != j2.minijuegosGanados) {
		if (j1.minijuegosGanados > j2.minijuegosGanados) {
			return 1;
		}
		else {
			return 2;
		}
	}

	return 0; // empataron
}
//una interfaz (esto lo hizo la ia) xd 
void interfazFinJuego(Jugador& j1, Jugador& j2) {
	system("cls");

	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition((ANCHO_PANTALLA / 2) - 9, 3);
	cout << "JUEGO TERMINADO";

	int ganador = determinarGanador(j1, j2);

	Jugador* primero;
	Jugador* segundo;

	if (ganador == 2) {
		primero = &j2;
		segundo = &j1;
	}
	else {
		primero = &j1;
		segundo = &j2;
	}

	int baseX = (ANCHO_PANTALLA / 2) - 12;
	int baseY = 8;

	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(baseX, baseY - 1);
	cout << primero->nombre;
	Console::SetCursorPosition(baseX, baseY);
	cout << " _______ ";
	Console::SetCursorPosition(baseX, baseY + 1);
	cout << "|       |";
	Console::SetCursorPosition(baseX, baseY + 2);
	cout << "|   1   |";
	Console::SetCursorPosition(baseX, baseY + 3);
	cout << "|_______|";

	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(baseX + 11, baseY + 1);
	cout << segundo->nombre;
	Console::SetCursorPosition(baseX + 11, baseY + 2);
	cout << " _______ ";
	Console::SetCursorPosition(baseX + 11, baseY + 3);
	cout << "|       |";
	Console::SetCursorPosition(baseX + 11, baseY + 4);
	cout << "|   2   |";
	Console::SetCursorPosition(baseX + 11, baseY + 5);
	cout << "|_______|";

	if (ganador == 0) {
		Console::ForegroundColor = ConsoleColor::Cyan;
		Console::SetCursorPosition((ANCHO_PANTALLA / 2) - 4, baseY - 3);
		cout << "EMPATE";
	}

	Console::ForegroundColor = ConsoleColor::White;
	int statsY = baseY + 8;
	Console::SetCursorPosition(baseX - 5, statsY);
	cout << j1.nombre << ": " << j1.estrellas << " estrellas, " << j1.monedas << " monedas, " << j1.minijuegosGanados << " minijuegos ganados";
	Console::SetCursorPosition(baseX - 5, statsY + 1);
	cout << j2.nombre << ": " << j2.estrellas << " estrellas, " << j2.monedas << " monedas, " << j2.minijuegosGanados << " minijuegos ganados";

	Console::SetCursorPosition(baseX - 5, statsY + 3);
	cout << "Presione cualquier tecla para salir...";
	Console::ResetColor();
	_getch();
}
//aca lo importante, el nucleo del juego
void iniciarJuego(Jugador& j, Jugador& j2)
{


	bool turno = true; 
	bool pokeMathJugado = false;
	bool artiJugado = false;
	bool reflejosJugado = false;
	j.mapaActual = 0;
	j.posicion = 0;
	j.monedas = 0;
	j.estrellas = 0;

	j2.mapaActual = 0;
	j2.posicion = 0;
	j2.monedas = 0;
	j2.estrellas = 0;
	//Inicializacion de los datos del struct jugador, en este caso tenemos dos jugadores los cuales estan inicialiados en el main 
	srand(time(NULL));

	system("cls");
	fondoMapa(j.mapaActual); //ponemos el fondo del mapa
	dibujarMarco(); //dibujamos los marcos

	while (true) // comenzamos el while
	{
		//esto es para detectar si un juego fue terminado el cual solo se ejecutaria una vez
		if (juegoTerminado(j, j2))
		{
			interfazFinJuego(j, j2);
			break;
		}
		//interfaz de ambos objetos
		intefazObjetos(j, 3, 20);
		intefazObjetos(j2, 55, 20);

		Console::SetCursorPosition(5, 28);
		cout << "Presione ESPACIO para lanzar el dado (ESC para salir) "; //feedback sobre cuando lanzar un dado

		char tecla = _getch();
		
		if (tecla == 27)  //aca metemos espacio
			break;

		if (tecla != ' ')
			continue;

		limpiarZonaMapa(); //limpiamos el mapa o sea actualizamos

		int dado = 0;
		//comienza el turno del jugador 1
		if (turno)
		{
			int mapaAnterior = j.mapaActual;
			dado = turnoJugador(j);
			revisarAvanceMapa(j, j2);
			if (j.mapaActual != mapaAnterior) {
				system("cls");
				fondoMapa(j.mapaActual);
				dibujarMarco();
			}
			eventosCasillas(j,j2,pokeMathJugado, artiJugado, reflejosJugado);
			dibujarMapa(j, j2);

			mostrarEstadoJugadores(
				j,
				j2,
				j.nombre,
				dado
			);
		}
		else //turno del jugador 2
		{
			int mapaAnterior = j2.mapaActual;
			dado = turnoJugador(j2);
			revisarAvanceMapa(j, j2);

			if (j2.mapaActual != mapaAnterior) {
				system("cls");
				fondoMapa(j2.mapaActual);
				dibujarMarco();
			}
			eventosCasillas(j2,j, pokeMathJugado, artiJugado, reflejosJugado);
			dibujarMapa(j2, j);

			mostrarEstadoJugadores(
				j,
				j2,
				j2.nombre,
				dado
			);
		}

		turno = !turno; //se acaba un turno, esto es porque turno = true = al jugador 1 y el !turno = jugador 2
	}
	
}
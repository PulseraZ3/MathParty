#include <iostream>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <cstdlib> 
#include <windows.h>
#include <string>
#include "Jugador.h"
#include "pokemon.h"
#define ANCHO_PANTALLA 120
#define ALTO_PANTALLA 30
using namespace std;
using namespace System;
//aca es para setear el ancho de la pantalla  con valores define 
#define MAPAS 4
#define CASILLAS 15
//120x30
//definicion del mapa C = "Casilla comun" O = "casilla rara" y R = "juegos" solo un juego por mapa
char mapas[MAPAS][CASILLAS] =
{
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
string cactusC[] = {
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

string arbolA[] = {
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
//pokemath
//titulo
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
		Console::SetCursorPosition(x, y + i);
		cout << math[i];
		Console::ForegroundColor = ConsoleColor::Blue;
		Console::SetCursorPosition(x + 32, y + i);
		cout << mon[i];
		Console::ResetColor();
	}
	_sleep(1500);
	Console::Clear();

}
//interfaz copia y pega de la que use en partyMath
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
//aca usamos probabilidades esto sera util para la eficacia de los ataques unicamente latigo y gruñido
int probabilidad() {
	return (rand() % 10) + 1;
}

//la vida fundamental use lo que enseño de un laberinto y simplemente era quitar
void interfazVida(Pokemon& p, bool enemigo, Jugador& j) {
	int x = enemigo ? 5 : 90;
	int y = enemigo ? 4 : 15;

	Console::SetCursorPosition(x, y);
	cout << string(25, ' ');
	Console::SetCursorPosition(x, y);
	cout << j.nombre << "  Nv 100";
	Console::SetCursorPosition(x, y + 1);
	cout << string(25, ' ');
	Console::SetCursorPosition(x, y + 1);
	if (enemigo == false) {
		Console::BackgroundColor = ConsoleColor::Green;
	}
	else {
		Console::BackgroundColor = ConsoleColor::Red;
	}
	cout << string(p.vida * 2, ' ');
	Console::ResetColor();
	Console::SetCursorPosition(x, y + 2);
	cout << string(20, ' ');
	Console::SetCursorPosition(x, y + 2);
	cout << "              10/" << p.vida;

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
int interfazAtaques(int x, int y) {
	string opciones[] = { "LUCHA","MOCHILA" };
	int seleccion = 0;
	int tecla;
	limpiarZonaMenu(x, y);
	do {
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
void turno(Jugador& personaje1, Jugador& personaje2, Pokemon& p1, Pokemon& p2) {
	bool turnoJugador = true;

	interfazVida(p1, false, personaje1);
	interfazVida(p2, true, personaje2);
	dibujarAvatar(personaje1, 90, 4);
	dibujarAvatar(personaje2, 5, 10);
	while (p1.vida > 0 && p2.vida > 0)
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
					p2.vida -= (p1.ataque + (1 - p2.defensa)) * mult;
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
					p1.vida -= (p2.ataque + (1 - p1.defensa)) * mult;
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
void reglasPokeMath(int x, int y) {
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
		cout << reglas[i] << endl;
	}

	_getch();
	Console::Clear();
}

void juegoPokeMath(Jugador& j1, Jugador& j2) {
	Pokemon* p1 = new Pokemon();
	Pokemon* p2 = new Pokemon();
	Console::Clear();
	tituloInicio(30, 10);
	reglasPokeMath(20, 6);
	intefazPokeMath();
	turno(j1, j2, *p1, *p2);
	delete p1;
	delete p2;
	_getch();
	Console::Clear();
}

//Artilleria


void titulo(int ancho, int alto) {
	int y_inicio = (alto / 2) - 6;
	int x_titulo = (ancho - 105) / 2;
	if (x_titulo < 0) x_titulo = 0;

	string lineas1[] = {
		"  __   ____  ____  __  __    __    ____  ____  __   __     _  _  _  _  __   ____  __  ____  __    ____ ",
		" / _\\ (  _ \\(_  _)(  )(  )  (  )  (  __)(  _ \\(  ) / _\\   ( \\/ )/ )( \\(  ) (_  _)(  )(  _ \\(  )  (  __)",
		"/    \\ )   /  )(   )( / (_/\\/ (_/\\ ) _)  )   / )( /    \\  / \\/ \\) \\/ (/ (_/\\ )(   )(  ) __// (_/\\ ) _) ",
		"\\_/\\_/(__\\_) (__) (__)\\____/\\____/(____)(__\\_)(__)\\_/\\_/  \\_)(_/\\____/\\____/(__) (__)(__)  \\____/(____)"
	};
	for (int i = 0; i < 4; i++) {
		Console::SetCursorPosition(x_titulo, y_inicio + i);
		cout << lineas1[i];
	}

	int ydeltitulo = y_inicio + 6;

	Console::SetCursorPosition((ancho - 46) / 2, ydeltitulo);
	cout << "Rivales, tendreis que enfrentarse entre si con";
	Console::SetCursorPosition((ancho - 50) / 2, ydeltitulo + 1);
	cout << "sus canones disparando al castillo del adversario.";
	Console::SetCursorPosition((ancho - 46) / 2, ydeltitulo + 2);
	cout << "Su dano dependera de cuando crean que sea buen";
	Console::SetCursorPosition((ancho - 51) / 2, ydeltitulo + 3);
	cout << "momento detener su dado de tiro... tendran dos y el";
	Console::SetCursorPosition((ancho - 36) / 2, ydeltitulo + 4);
	cout << "resultado sera el dano a infligir...";
	Console::SetCursorPosition((ancho - 20) / 2, ydeltitulo + 7);
	cout << "Generales, Suerte :)";

	Console::SetCursorPosition((ancho - 32) / 2, ydeltitulo + 9);
	cout << "[ PRESIONA CUALQUIER TECLA PARA EMPEZAR ]";
}

void canon_peq_der(int x, int y) {
	string lineas[] = {
		"   __       ",
		"  /  \\====* ",
		" /____\\     "
	};
	for (int i = 0; i < 3; i++) {
		Console::SetCursorPosition(x, y + i);
		cout << lineas[i];
	}
}

void canon_peq_izq(int x, int y) {
	string lineas[] = {
		"       __   ",
		" *====/  \\  ",
		"     /____\\ "
	};
	for (int i = 0; i < 3; i++) {
		Console::SetCursorPosition(x, y + i);
		cout << lineas[i];
	}
}

void castillo_peq(int x, int y) {
	string lineas[] = {
		"   |>        |>   ",
		"   |         |    ",
		" _|_|_     _|_|_  ",
		"|     |___|     | ",
		"| [ ]       [ ] | ",
		"|_______________| "
	};
	for (int i = 0; i < 6; i++) {
		Console::SetCursorPosition(x, y + i);
		cout << lineas[i];
	}
}

void explosion(int x, int y) {
	string lineas[] = {
		"                  ",
		"    \\||/   \\||/   ",
		"   -BOOM- -BOOM-  ",
		"    /||\\   /||\\   ",
		"                  ",
		"                  "
	};
	for (int i = 0; i < 6; i++) {
		Console::SetCursorPosition(x, y + i);
		cout << lineas[i];
	}
}

void arbol(int x, int y) {
	string lineas[] = {
		"  /\\  ",
		" /  \\ ",
		"  ||  ",
	};
	for (int i = 0; i < 3; i++) {
		Console::SetCursorPosition(x, y + i);
		cout << lineas[i];
	}
}

//recicle la funcion del game jam, funciona muy similar
int dibujarSuelo(int ancho, int alto) {
	int alturaSuelo = 5;
	int inicioSueloY = alto - alturaSuelo;

	for (int y = inicioSueloY; y < alto; y++) {
		for (int x = 0; x < ancho; x++) {
			Console::SetCursorPosition(x, y);
			if (rand() % 100 < 10) {
				int tipoFlor = rand() % 3;
				if (tipoFlor == 0) Console::ForegroundColor = ConsoleColor::Yellow;
				else if (tipoFlor == 1) Console::ForegroundColor = ConsoleColor::White;
				else Console::ForegroundColor = ConsoleColor::Magenta;

				Console::BackgroundColor = ConsoleColor::DarkGreen;
				cout << "*";
			}
			else {
				Console::BackgroundColor = ConsoleColor::Green;
				cout << " ";
			}
		}
	}
	Console::ResetColor();
	return inicioSueloY;
}

void pantallaMultiplicacion(int ancho, int alto, int dado1, int dado2) {
	system("cls");
	int total = dado1 * dado2;

	int digitosTotal = (total < 10) ? 1 : 2;
	int anchoM1 = 36 + digitosTotal;
	int anchoM2 = 15 + digitosTotal;


	//no hay Ñ :(
	Console::SetCursorPosition((ancho - anchoM1) / 2, alto / 2);
	cout << "El dano que se va a infligir sera '" << total << "'";

	Console::SetCursorPosition((ancho - anchoM2) / 2, (alto / 2) + 1);
	cout << "porque " << dado1 << " * " << dado2 << " = " << total;

	Console::SetCursorPosition((ancho - 36) / 2, (alto / 2) + 3);
	cout << "Presiona una tecla para el ataque...";
	_getch();
}
//cubo

void dibujarCuboRotando(int x, int y, int numeroCentro) {
	// tipo tragamonedas
	// condicion, entonces , sino
	int n1 = (numeroCentro - 3 <= 0) ? (numeroCentro - 2 + 6) : (numeroCentro - 2);
	int n2 = (numeroCentro - 2 <= 0) ? (numeroCentro - 2 + 6) : (numeroCentro - 2);
	int n3 = (numeroCentro - 1 <= 0) ? (numeroCentro - 1 + 6) : (numeroCentro - 1);
	int n5 = (numeroCentro + 1 > 6) ? (numeroCentro + 1 - 6) : (numeroCentro + 1);
	int n6 = (numeroCentro + 2 > 6) ? (numeroCentro + 2 - 6) : (numeroCentro + 2);
	int n7 = (numeroCentro + 3 > 6) ? (numeroCentro + 3 - 6) : (numeroCentro + 3);

	Console::SetCursorPosition(x, y);     cout << "   +---------------+";
	Console::SetCursorPosition(x, y + 1); cout << "   |       " << n1 << "       |";
	Console::SetCursorPosition(x, y + 2); cout << "   |       " << n2 << "       |";
	Console::SetCursorPosition(x, y + 3); cout << "   |       " << n3 << "       |";
	Console::ForegroundColor = ConsoleColor::Cyan;
	Console::SetCursorPosition(x, y + 4); cout << "   |  <<<  " << numeroCentro << "  >>>  |";
	Console::ResetColor();
	Console::SetCursorPosition(x, y + 5); cout << "   |       " << n5 << "       |";
	Console::SetCursorPosition(x, y + 6); cout << "   |       " << n6 << "       |";
	Console::SetCursorPosition(x, y + 7); cout << "   |       " << n7 << "       |";
	Console::SetCursorPosition(x, y + 8); cout << "   +---------------+";
}

//se dibuja pero creo que deberia crear una funcion donde se borre el trazo del stickman para q deje de aparecer un 
//bug visual cuando este saltando
void dibujarStickmanFrame(int x, int y_suelo, int frame) {
	if (frame == 1) {
		Console::SetCursorPosition(x, y_suelo - 3); cout << "  O  ";
		Console::SetCursorPosition(x, y_suelo - 2); cout << " /|\\ ";
		Console::SetCursorPosition(x, y_suelo - 1); cout << " / \\ ";
	}
	else if (frame == 2) {
		Console::SetCursorPosition(x, y_suelo - 5); cout << "  O  ";
		Console::SetCursorPosition(x, y_suelo - 4); cout << " \\|/ ";
		Console::SetCursorPosition(x, y_suelo - 3); cout << " / \\ ";
		Console::SetCursorPosition(x, y_suelo - 2); cout << "     ";
		Console::SetCursorPosition(x, y_suelo - 1); cout << "     ";
	}
	else if (frame == 3) {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y_suelo - 5); cout << "  O  ";
		//le pega
		Console::ResetColor();
		Console::SetCursorPosition(x, y_suelo - 4); cout << " /|\\ ";
		Console::SetCursorPosition(x, y_suelo - 3); cout << " / \\ ";
		Console::SetCursorPosition(x, y_suelo - 2); cout << "     ";
		Console::SetCursorPosition(x, y_suelo - 1); cout << "     ";
	}
	else if (frame == 4) {
		Console::SetCursorPosition(x, y_suelo - 4); cout << "  O  ";
		Console::SetCursorPosition(x, y_suelo - 3); cout << " /|\\ ";
		Console::SetCursorPosition(x, y_suelo - 2); cout << " / \\ ";
		Console::SetCursorPosition(x, y_suelo - 1); cout << "     ";
	}
	Console::SetCursorPosition(x - 1, y_suelo); cout << "=======";
}

int ejecutarTurnoMaximizado(int ancho, int alto, int jugador) {
	//si '-' , condicion, sino '|'
	char teclaObjetivo = (jugador == 1) ? 'a' : 'l';
	char teclaObjetivoMayus = (jugador == 1) ? 'A' : 'L';
	int dado1 = 0;
	int dado2 = 0;

	for (int tiro = 1; tiro <= 2; tiro++) {
		system("cls");

		// guia
		Console::SetCursorPosition((ancho - 44) / 2, 2);
		cout << "=== RONDA DE TIRO: Jugador " << jugador << " ===";
		Console::SetCursorPosition((ancho - 22) / 2, 3);
		cout << "TIRO DE DADO " << tiro << " DE 2";
		Console::SetCursorPosition((ancho - 52) / 2, 4);
		cout << "Presiona [" << teclaObjetivoMayus << "] en el momento justo para saltar!";

		if (tiro == 2) {
			//NO HAY Ñ
			Console::SetCursorPosition((ancho - 24) / 2, 5);
			cout << "Dano Acumulado: " << dado1;
		}



		int y_suelo = alto - 6;
		int y_cubo = y_suelo - 13;
		int x_centro = (ancho - 20) / 2;

		//1
		int numCentro = 1;

		// Vel, aun no defino cual es la mejor
		//opc 1, 25 + rand 40
		//opc 1, 40 + rand 200
		//opc 1, 15 + rand 400
		int velocidadGiro = 40 + (rand() % 200);

		//sale
		while (_kbhit()) _getch();

		bool haSaltado = false;
		// ciclo 1 - recoge el valor q "elige" el jugadore
		while (!haSaltado) {
			dibujarCuboRotando(x_centro, y_cubo, numCentro);
			dibujarStickmanFrame(x_centro + 7, y_suelo, 1);

			_sleep(velocidadGiro);
			numCentro = (numCentro % 6) + 1;

			if (_kbhit()) {
				char presionada = _getch();
				if (presionada == teclaObjetivo || presionada == teclaObjetivoMayus) {
					haSaltado = true;
				}
			}
		}

		// ciclo 2 - animacion
		// frame 2
		numCentro = (numCentro % 6) + 1;
		dibujarCuboRotando(x_centro, y_cubo, numCentro);
		dibujarStickmanFrame(x_centro + 7, y_suelo, 2);
		_sleep(70);

		// frame 3, "golpe"
		int valorFinaldado = numCentro;
		dibujarCuboRotando(x_centro, y_cubo, valorFinaldado);
		dibujarStickmanFrame(x_centro + 7, y_suelo, 3);
		Console::SetCursorPosition(x_centro + 6, y_cubo + 9);
		cout << " *!BOOM!* ";
		_sleep(350);

		// frame 4, cae
		dibujarStickmanFrame(x_centro + 7, y_suelo, 4);
		_sleep(70);

		// frame 5 (1) - llega
		dibujarStickmanFrame(x_centro + 7, y_suelo, 1);
		_sleep(70);

		if (tiro == 1) dado1 = valorFinaldado;
		else dado2 = valorFinaldado;


		Console::SetCursorPosition((ancho - 24) / 2, y_suelo + 2);
		cout << "Puntaje obtenido: " << valorFinaldado << "!";
		Console::SetCursorPosition((ancho - 36) / 2, y_suelo + 3);
		cout << "Presiona una tecla para continuar...";
		_getch();
	}
	pantallaMultiplicacion(ancho, alto, dado1, dado2);
	return dado1 * dado2;
}

//campo / pantalla

void dibujarBarraVida(int x, int y, string etiqueta, int vida) {
	Console::SetCursorPosition(x, y);
	cout << etiqueta << ": [";
	int barras = vida / 10;

	// cambia el colo depndiendo de cuanta vida haya
	if (vida > 50) Console::ForegroundColor = ConsoleColor::Green;
	else if (vida > 25) Console::ForegroundColor = ConsoleColor::Yellow;
	else Console::ForegroundColor = ConsoleColor::Red;

	for (int i = 0; i < 10; i++) {
		if (i < barras) cout << "I";
		else cout << ".";
	}
	Console::ResetColor();
	cout << "] " << vida << " HP";
}

void dibujarCampoBatalla(int ancho, int alto, int vida1, int vida2) {
	system("cls");

	// barras de vida
	dibujarBarraVida(4, 2, "CASTILLO J1", vida1);
	dibujarBarraVida(ancho - 32, 2, "CASTILLO J2", vida2);

	int y_suelo = dibujarSuelo(ancho, alto);

	//castillos
	int x_castillo_izq = 2;
	int x_castillo_der = ancho - 20;

	int x_arbol_izq = 24;
	int x_canon_izq = 40;

	int x_canon_der = ancho - 52;
	int x_arbol_der = ancho - 30;

	//cañones
	canon_peq_der(x_canon_izq, y_suelo - 3);
	canon_peq_izq(x_canon_der, y_suelo - 3);

	arbol(x_arbol_izq, y_suelo - 3);
	arbol(x_arbol_izq + 8, y_suelo - 3);
	arbol(x_arbol_der - 8, y_suelo - 3);
	arbol(x_arbol_der, y_suelo - 3);

	int y_castillo = y_suelo - 6;
	castillo_peq(x_castillo_izq, y_castillo);
	castillo_peq(x_castillo_der, y_castillo);
}

//--------------------------------------------------------------------------------------------------------------------------------------------

void animarProyectilYExplosion(int ancho, int alto, int atacante, int v1, int v2) {
	int y_suelo = alto - 5;
	int y_castillo = y_suelo - 6;
	int x_origen, x_destino;

	if (atacante == 1) {
		x_origen = 40 + 11; // punta del cañón izquierdo
		x_destino = ancho - 14; // blanco en el castillo derecho
	}
	else {
		x_origen = (ancho - 52) + 1; // Punta del cañón derecho
		x_destino = 10; // Blanco en el castillo izquierdo
	}

	int y_origen = y_suelo - 2;
	int y_destino = y_castillo + 3;

	// Ecuación balística parabólica en base al tiempo
	double framesMax = 25.0;
	for (int f = 0; f <= framesMax; f++) {
		double t = f / framesMax;
		int px = x_origen + (x_destino - x_origen) * t;
		// Curva parabólica simulada con una altura máxima de arco de 9 líneas
		double arcoAltura = 9.0 * 4.0 * t * (1.0 - t);
		int py = y_origen + (y_destino - y_origen) * t - arcoAltura;

		if (px >= 0 && px < ancho && py >= 0 && py < alto) {
			Console::SetCursorPosition(px, py); cout << "O";
		}
		_sleep(35);
		if (px >= 0 && px < ancho && py >= 0 && py < alto) {
			Console::SetCursorPosition(px, py); cout << " ";
		}
	}

	// Impacto y reconstrucción automática limpia
	int x_impacto = (atacante == 1) ? (ancho - 20) : 2;
	explosion(x_impacto, y_castillo);
	_sleep(800);

	dibujarCampoBatalla(ancho, alto, v1, v2);
}

//
//--------------------------------------------------------------------------------------------------------------------------------------------
//menu + animacion

void menu(int ancho, int alto) {
	system("cls");
	titulo(ancho, alto);

	int y_suelo = dibujarSuelo(ancho, alto);
	int x_castillo_izq = 2, x_castillo_der = ancho - 20;
	int x_arbol_izq = 24, x_canon_izq = 40;
	int x_canon_der = ancho - 52, x_arbol_der = ancho - 30;

	canon_peq_izq(x_canon_izq, y_suelo - 3);
	canon_peq_der(x_canon_der, y_suelo - 3);
	arbol(x_arbol_izq, y_suelo - 3); arbol(x_arbol_izq + 8, y_suelo - 3);
	arbol(x_arbol_der - 8, y_suelo - 3); arbol(x_arbol_der, y_suelo - 3);

	int y_castillo = y_suelo - 6;
	castillo_peq(x_castillo_izq, y_castillo);
	castillo_peq(x_castillo_der, y_castillo);

	int proy_y_inicio = 12;
	int p_izq1 = x_castillo_izq + 4, p_izq2 = x_castillo_izq + 13;
	int p_der1 = x_castillo_der + 4, p_der2 = x_castillo_der + 13;
	int anim_y = proy_y_inicio;

	while (!_kbhit()) {
		//cm uso string aqui?
		if (anim_y > proy_y_inicio) {
			Console::SetCursorPosition(p_izq1, anim_y - 1); cout << " ";
			Console::SetCursorPosition(p_izq2, anim_y - 1); cout << " ";
			Console::SetCursorPosition(p_der1, anim_y - 1); cout << " ";
			Console::SetCursorPosition(p_der2, anim_y - 1); cout << " ";
		}
		Console::SetCursorPosition(p_izq1, anim_y); cout << "O";
		Console::SetCursorPosition(p_izq2, anim_y); cout << "O";
		Console::SetCursorPosition(p_der1, anim_y); cout << "O";
		Console::SetCursorPosition(p_der2, anim_y); cout << "O";

		_sleep(70);
		anim_y++;

		if (anim_y >= y_castillo + 2) {
			//ya fue ya
			Console::SetCursorPosition(p_izq1, anim_y - 1); cout << " ";
			Console::SetCursorPosition(p_izq2, anim_y - 1); cout << " ";
			Console::SetCursorPosition(p_der1, anim_y - 1); cout << " ";
			Console::SetCursorPosition(p_der2, anim_y - 1); cout << " ";
			explosion(x_castillo_izq, y_castillo);
			explosion(x_castillo_der, y_castillo);
			_sleep(800);
			castillo_peq(x_castillo_izq, y_castillo);
			castillo_peq(x_castillo_der, y_castillo);
			_sleep(300);
			anim_y = proy_y_inicio;
		}
	}
	_getch();
}

void juego_artilleria(Jugador& personaje1, Jugador& personaje2) {
	srand(time(NULL));
	Console::CursorVisible = false;

	int alto = Console::WindowHeight;
	int ancho = Console::WindowWidth;


	menu(ancho, alto);

	//VIDA DE LOS BICHOS
	int saludJ1 = 100;
	int saludJ2 = 100;
	int turno = 1; // 1 = Jugador Izquierda, 2 = Jugador Derecha

	//juego principal
	while (saludJ1 > 0 && saludJ2 > 0) {
		dibujarCampoBatalla(ancho, alto, saludJ1, saludJ2);

		Console::SetCursorPosition((ancho - 32) / 2, 5);
		cout << ">>> TURNO ACTUAL: JUGADOR " << turno << " <<<";
		Console::SetCursorPosition((ancho - 40) / 2, 6);
		cout << "Presiona cualquier tecla para ir a tu cubo...";
		_getch();

		//"maximiza" la perspectiva del palitos
		int danoTotalTurno = ejecutarTurnoMaximizado(ancho, alto, turno);

		//regresa al mapa principal
		if (turno == 1) {
			saludJ2 -= danoTotalTurno;
			if (saludJ2 < 0) saludJ2 = 0;
			dibujarCampoBatalla(ancho, alto, saludJ1, saludJ2);

			Console::SetCursorPosition((ancho - 42) / 2, 5);
			cout << "Fuego! Proyectil de J1 causa " << danoTotalTurno << " de dano.";
			animarProyectilYExplosion(ancho, alto, 1, saludJ1, saludJ2);
			turno = 2; // cede el turno
		}
		else {
			saludJ1 -= danoTotalTurno;
			if (saludJ1 < 0) saludJ1 = 0;
			dibujarCampoBatalla(ancho, alto, saludJ1, saludJ2);

			Console::SetCursorPosition((ancho - 42) / 2, 5);
			cout << "Fuego! Proyectil de J2 causa " << danoTotalTurno << " de dano.";
			animarProyectilYExplosion(ancho, alto, 2, saludJ1, saludJ2);
			turno = 1; // cede el turno
		}
	}

	//"pantalla de ganador", puede mejorar... :(
	system("cls");
	Console::SetCursorPosition((ancho - 30) / 2, alto / 2 - 1);
	cout << "==============================";
	Console::SetCursorPosition((ancho - 22) / 2, alto / 2);

	//no deberian haber empates vaya
	if (saludJ1 <= 0 && saludJ2 <= 0) {
		cout << "EMPATE CATACLISMICO (Como paso eso?)!";
		personaje1.monedas += 10;
		personaje2.monedas += 10;

	}
	//PERO ME DA IGUAL 🤑
	else if (saludJ1 <= 0) {
		cout << "VICTORIA DEL JUGADOR 2!";
		personaje2.estrellas += 1;
		personaje2.monedas += 20;
		personaje2.minijuegosGanados += 1;

	}
	else {
		cout << "VICTORIA DEL JUGADOR 1!";
		personaje1.estrellas += 1;
		personaje1.monedas += 20;
		personaje1.minijuegosGanados += 1;

	}
	Console::SetCursorPosition((ancho - 30) / 2, alto / 2 + 1);
	cout << "==============================";

	Console::SetCursorPosition((ancho - 38) / 2, alto / 2 + 3);
	cout << "Presiona cualquier tecla para finalizar...";
	_getch();
}

//Reflejos

void explosione(int x, int y) {
	//explosion 1 y 2 respectivamente
	if (x < 2) x = 2;
	if (x > 117) x = 117;

	Console::SetCursorPosition(x - 2, y - 1); cout << "\\ | /";
	Console::SetCursorPosition(x - 2, y);     cout << "- O -";
	Console::SetCursorPosition(x - 2, y + 1); cout << "/ | \\";
	_sleep(600);
}

void animacion_disparo(int x_inicio, int x_fin, int y, bool acierto) {
	if (acierto) {
		int paso;
		if (x_inicio < x_fin) {
			paso = 1;
		}
		else {
			paso = -1;
		}

		for (int i = x_inicio; i != x_fin; i += paso) {
			Console::SetCursorPosition(i, y);
			cout << "*";
			_sleep(7);
			Console::SetCursorPosition(i, y);
			cout << " ";
		}
		explosione(x_fin, y);
	}
	else {
		explosione(x_inicio, y);
	}
}

void recuadro(int alto, int ancho, int x, int y) {
	int salto = 40;

	Console::SetCursorPosition((ancho / 2) - salto, y);
	cout << " ________________________________________________________________________";
	Console::SetCursorPosition((ancho / 2) - salto, y + 1);
	cout << "/                                                                        \\";
	Console::SetCursorPosition((ancho / 2) - salto, y + 2);
	cout << "|                                                                        |";
	Console::SetCursorPosition((ancho / 2) - salto, y + 3);
	cout << "|                                                                        |";
	Console::SetCursorPosition((ancho / 2) - salto, y + 4);
	cout << "|                                                                        |";
	Console::SetCursorPosition((ancho / 2) - salto, y + 5);
	cout << "|                                                                        |";
	Console::SetCursorPosition((ancho / 2) - salto, y + 6);
	cout << "|                                                                        |";
	Console::SetCursorPosition((ancho / 2) - salto, y + 7);
	cout << "|                                                                        |";
	Console::SetCursorPosition((ancho / 2) - salto, y + 8);
	cout << "\\________________________________________________________________________/";
}

void limpiar_interior_recuadro(int ancho, int y) {
	for (int i = 2; i <= 7; i++) {
		//-39
		Console::SetCursorPosition((ancho / 2) - 39, y + i);
		cout << "                                                                        ";
	}
}

void preparado_texto(int alto, int ancho, int x, int y) {
	int mitad_largo = 37;
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 2);
	cout << "  ____  ____  _____ ____  ____  ____  ____  ____  ____  ____  ____ ";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 3);
	cout << " |  __\\/  __\\/  __//  __\\/  _ \\/  __\\/  _ \\/  _ \\/  _ \\/ ___\\/ _  \\";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 4);
	cout << " |  \\/||  \\/||  \\  |  \\/|| / \\||  \\/|| / \\|| | \\|| / \\||    \\\\/ \\ |";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 5);
	cout << " |  __/|    /|  /_ |  __/| |-|||    /| |-||| |_/|| \\_/|\\___ |   / /";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 6);
	cout << " \\_/   \\_/\\_\\\\____\\\\_/   \\_/ \\|\\_/\\_\\\\_/ \\|\\____/\\____/\\____/   \\/ ";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 7);
	cout << "                                                               \\/ ";
}

void esperen_texto(int alto, int ancho, int x, int y) {
	//ns pq la n parece una d
	int mitad_largo = 34;

	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 2);
	cout << " ______ _____  ____   ______ ____   ______ ____ ";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 3);
	cout << "/ ____// ___/ / __ \\ / ____// __ \\ / ____// __ \\";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 4);
	cout << "| __/   \\__ \\ / /_/ // __/  / /_/ // __/  / / / /";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 5);
	cout << "| /___  ___/ // ____// /___ / _, _// /___ / /_/ / ";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 6);
	cout << "/_____/ /____//_/    /_____//_/ |_|/_____//_____/ ";
}

void dibujar_suelo(int alto, int ancho) {
	for (int j = 1; j <= 3; j++) {
		Console::SetCursorPosition(0, alto - j);
		Console::BackgroundColor = ConsoleColor::DarkYellow;
		for (int i = 0; i < ancho; i++) {
			int prob = rand() % 10;
			if (prob == 0) cout << ".";
			else if (prob == 1) cout << "~";
			else if (prob == 2) cout << "*";
			else cout << " ";
		}
	}
	Console::ResetColor();
}

void cactus(int x, int y) {
	string lineas[]{
		"              _   _",
		"             / '-' \\",
		"            ;       ;",
		"         /'-|       |-'\\",
		"        \\   '-------'   /",
		"         '.___.....___.'",
		"           _|;__;__.|_",
		"          |     Y     |    .--.",
		" .--.      \\__.'^'.__/    /;   \\",
		"|   ;\\      |_  ;  _|     |  ' |",
		"| ;  |      { ````` }     |;   |",
		"| ;  \\      |;  ;   |_____/ ;  |",
		"|   '.'-----'      ' -_   .'   /",
		" '.   -     - ;  ;   .------`",
		"   `--------.      ;|",
		"            |;  ,   |",
		"            |;   ;  |",
		"            `-------`"
	};
	for (int i = 0; i < 18; i++) {
		int targetY = y + i;
		Console::SetCursorPosition(x, targetY);
		cout << lineas[i];
	}
}

void dibujarescenario_estatico(int alto, int ancho, int& vidasJ1, int& vidasJ2, int altura_base) {
	int xcactus0 = ancho / 8;
	int xcactus1 = ancho - (ancho / 4);

	dibujar_suelo(alto, ancho);
	cactus(xcactus0, altura_base);
	cactus(xcactus1, altura_base);

	Console::SetCursorPosition(2, 2);
	cout << "Vidas J1 (A): ";
	for (int i = 0; i < vidasJ1; i++) cout << "()";

	Console::SetCursorPosition(ancho - 30, 2);
	cout << "Vidas J2 (L): ";
	for (int i = 0; i < vidasJ2; i++) cout << "()";
}

int generaroperacion(int ancho, int y_recuadro) {
	//numeros aleatorios
	int num1 = (rand() % 15) + 1;
	int num2 = (rand() % 15) + 1;

	//Operacion aleatoria
	int tipo = rand() % 10;
	int respuesta = 0;
	string operador = "";

	if (tipo == 0 || tipo == 1 || tipo == 2 || tipo == 3) {
		operador = "+";
		respuesta = num1 + num2;
	}
	else if (tipo == 4 || tipo == 5 || tipo == 6 || tipo == 7) {
		operador = "-";
		respuesta = num1 - num2;
	}
	else if (tipo == 8 || tipo == 9) {
		operador = "x";
		respuesta = num1 * num2;
	}

	Console::SetCursorPosition((ancho / 2) - 15, y_recuadro + 4);
	cout << "Rapido! Cuanto es: " << num1 << " " << operador << " " << num2 << "?: ";

	return respuesta;
}

void jugarronda(int alto, int ancho, int& vidasJ1, int& vidasJ2) {
	system("cls");

	int altura_base = alto - 33;
	if (altura_base < 10) altura_base = 10;

	dibujarescenario_estatico(alto, ancho, vidasJ1, vidasJ2, altura_base);

	int y_recuadro = 1;

	//1
	recuadro(alto, ancho, 0, y_recuadro);
	preparado_texto(alto, ancho, 0, y_recuadro);
	_sleep(1500);

	//2
	limpiar_interior_recuadro(ancho, y_recuadro);
	esperen_texto(alto, ancho, 0, y_recuadro);

	// rand de max 15 seg y min 3 seg
	int tiempo_tension = (rand() % 13) + 3;

	for (int i = 0; i < tiempo_tension; i++) {
		Console::SetCursorPosition((ancho / 2) + 16 + i, y_recuadro + 6);
		_sleep(1000);
		cout << "O";
	}

	//3
	limpiar_interior_recuadro(ancho, y_recuadro);
	Console::SetCursorPosition((ancho / 2) - 15, y_recuadro + 4);
	cout << "!!! DISPAREN (J1:A / J2:L) !!!";

	bool disparo_realizado = false;
	char tecla_presionada = ' ';

	while (!disparo_realizado) {
		if (_kbhit()) {
			tecla_presionada = _getch();
			if (tecla_presionada == 'a' || tecla_presionada == 'A' ||
				tecla_presionada == 'l' || tecla_presionada == 'L') {
				disparo_realizado = true;
			}
		}
	}

	Console::SetCursorPosition((ancho / 2) - 15, y_recuadro + 5);
	if (tecla_presionada == 'a' || tecla_presionada == 'A') {
		cout << "Jugador 1 apunto primero!";
	}
	else {
		cout << "Jugador 2 apunto primero!";
	}
	_sleep(1000);

	//4
	limpiar_interior_recuadro(ancho, y_recuadro);
	int respuesta_correcta = generaroperacion(ancho, y_recuadro);
	int respuesta_jugador;
	cin >> respuesta_jugador;

	int y_brazo = altura_base + 4;
	int x_J1 = (ancho / 8) + 28;
	int x_J2 = ancho - (ancho / 4);

	// evaluo si el tiro salio bien o le salió por la culata
	Console::SetCursorPosition((ancho / 2) - 20, y_recuadro + 6);
	if (respuesta_jugador == respuesta_correcta) {
		cout << "¡RESPUESTA CORRECTA! Tiro acertado.       ";
		if (tecla_presionada == 'a' || tecla_presionada == 'A') {
			animacion_disparo(x_J1, x_J2, y_brazo, true);
			vidasJ2--;
		}
		else {
			animacion_disparo(x_J2, x_J1, y_brazo, true);
			vidasJ1--;
		}
	}
	else {
		cout << "¡ERROR! El arma te exploto en la cara.     ";
		if (tecla_presionada == 'a' || tecla_presionada == 'A') {
			animacion_disparo((ancho / 8) + 14, 0, y_brazo, false);
			vidasJ1--;
		}
		else {
			animacion_disparo((ancho - (ancho / 4)) + 14, 0, y_brazo, false);
			vidasJ2--;
		}
	}

	_sleep(1000);
}

void menu_inicio(int alto, int ancho, int x, int y) {
	//110 - 55
	system("color 06");
	system("cls");

	Console::SetCursorPosition((ancho / 2) - 55, y + 4);
	cout << " ____  ____  ____  __    ____    __   __   ____     __   ____  __  ____  _  _  ____  ____  __  ___  __   ____";
	Console::SetCursorPosition((ancho / 2) - 55, y + 5);
	cout << "(  _ \\(  __)(  __)(  )  (  __) _(  ) /  \\ / ___)   / _\\ (  _ \\(  )(_  _)( \\/ )(  __)(_  _)(  )/ __)/  \\ / ___)";
	Console::SetCursorPosition((ancho / 2) - 55, y + 6);
	cout << ") | / ) _)  ) _)  / (_/\\ ) _) / \\) \\(  O )\\___ \\  /    \\ )   / )(   )(  / \\/ \\ ) _)   )(   )(( (__(  O )\\___ \\";
	Console::SetCursorPosition((ancho / 2) - 55, y + 7);
	cout << "(__\\_)(____)(__)  \\____/(____)\\____/ \\__/ (____/  \\_/\\_/(__\\_)(__) (__) \\_)(_/(____) (__) (__)\\___)\\__/ (____/";

	Console::SetCursorPosition((ancho / 2) - 20, y + 10);
	cout << "Es un duelo revolver frente a tu rival,";
	Console::SetCursorPosition((ancho / 2) - 22, y + 11);
	cout << "el primero en apuntar tendra que responder";
	Console::SetCursorPosition((ancho / 2) - 22, y + 12);
	cout << "una operacion, si lo resuelves correctamente";
	Console::SetCursorPosition((ancho / 2) - 20, y + 13);
	cout << "tu tiro es efectivo; caso opuesto el tiro";
	Console::SetCursorPosition((ancho / 2) - 22, y + 14);
	cout << "te da a ti mismo y vuelve a iniciar la ronda";
	Console::SetCursorPosition((ancho / 2) - 15, y + 16);
	cout << "Cada uno tiene 3 vidas...";
	Console::SetCursorPosition((ancho / 2) - 10, y + 18);
	cout << "Suerte Vaquero";

	Console::SetCursorPosition((ancho / 2) - 10, y + 21);
	cout << "   O_         _O   ";
	Console::SetCursorPosition((ancho / 2) - 10, y + 22);
	cout << "  /|>-       -<|\\  ";
	Console::SetCursorPosition((ancho / 2) - 10, y + 23);
	cout << "  / \\         / \\  ";

	dibujar_suelo(alto, ancho);

	Console::SetCursorPosition((ancho / 2) - 15, alto - 5);
	cout << "Presione ENTER para continuar";
	_getch();
	system("cls");
}

void juegoreflejos(Jugador& j1, Jugador& j2) {
	srand(time(NULL));
	Console::CursorVisible = false;

	int alto = Console::WindowHeight;
	int ancho = Console::WindowWidth;


	//creo que voy a necesitar el nombre de los jugadores // es verdad, nah ya fue, para q?

	int vidasJ1 = 3;
	int vidasJ2 = 3;

	menu_inicio(alto, ancho, 0, 0);

	while (vidasJ1 > 0 && vidasJ2 > 0) {
		jugarronda(alto, ancho, vidasJ1, vidasJ2);
	}

	system("cls");
	Console::SetCursorPosition((ancho / 2) - 10, alto / 2);
	//ahora que lo pienso... jamas pasara un empate
	//if (vidasJ1 == 0 && vidasJ2 == 0) {
	//	cout << "¡EMPATE! Ambos cayeron.";
	//}
	if (vidasJ1 > 0) {
		cout << "¡GANA EL JUGADOR 1!";
		j1.minijuegosGanados += 1;
		j1.estrellas += 1;
		j1.monedas += 10;
	}
	else {
		cout << "¡GANA EL JUGADOR 2!";
		j2.minijuegosGanados += 1;
		j2.estrellas += 1;
		j2.monedas += 10;
	}

	Console::SetCursorPosition((ancho / 2) - 16, (alto / 2) - 2);
	cout << "Presione ENTER para salir...";

	char tecla;
	while (tecla != 13) { // el char de enter...
		tecla = _getch();
	}


}

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
		cout << avatar1[i];
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
		Console::SetCursorPosition(74, i + 2);
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
	Console::SetCursorPosition((ANCHO_PANTALLA / 2) - 10, ALTO_PANTALLA / 2);
	cout << "Ingrese su nombre " << numPersonaje << endl;
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
	for (int i = 0; i < 2;i++) {
		interfazNombre(i);
		Console::SetCursorPosition((ANCHO_PANTALLA / 2) - 10, (ALTO_PANTALLA / 2) + 1);
		cin >> jugadores[i].nombre;
		Console::SetCursorPosition((ANCHO_PANTALLA / 3) + 10, (ALTO_PANTALLA / 2) + 2);
		cout << "Ingrese el numero del avatar: ";
		cin >> avatar;
		jugadores[i].avatar = ingresoAvatar(avatar);
		asiganarAvatar(jugadores[i], avatar);
		_getch();
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
	case 0:
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
				cout << cactusC[i];


				Console::ForegroundColor = ConsoleColor::Green;
				Console::SetCursorPosition(84, 2 + i);
				cout << cactusC[i];

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

	case 1:
		for (int i = 0; i < 6; i++) {
			Console::ForegroundColor = ConsoleColor::DarkGreen;
			Console::SetCursorPosition(21, 1 + i);
			cout << arbolA[i];

			Console::SetCursorPosition(60, 1 + i);
			cout << arbolA[i];

			Console::SetCursorPosition(95, 1 + i);
			cout << arbolA[i];
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

	case 2: // Mapa inspirado en un mundo acuatico
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
	case 3:
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
//fors para dibujar los marcos
void dibujarMarco() {
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
	for (int b = 1; b <= (ALTO_PANTALLA / 2) + 5; b++) {
		if (b == 1 || b == (ALTO_PANTALLA / 2) + 5) {
			Console::SetCursorPosition((ALTO_PANTALLA / 2) + 6, b - 1);
			cout << '+';
		}
		else {
			Console::SetCursorPosition((ALTO_PANTALLA / 2) + 6, b - 1);
			cout << '|';
		}
	}
}

//dependiendo de la casilla en la que caigas ocurre algo, podria agregar mas n ose xd

void eventosCasillas(Jugador& j, Jugador& j2, bool& pokeMathJugado, bool& artiJugado, bool& reflejosJugado) {
	char casillas = mapas[j.mapaActual][j.posicion];
	if (casillas == 'O') {
		j.monedas += 5;
	}
	if (casillas == 'R' && j.mapaActual == 1 && !pokeMathJugado) {
		juegoPokeMath(j, j2);
		pokeMathJugado = true;
		Console::Clear();
		fondoMapa(j.mapaActual);
		dibujarMarco();
	}
	if (casillas == 'R' && j.mapaActual == 3 && !artiJugado) {
		//juego_artilleria(j, j2);
		artiJugado = true;
		Console::Clear();
		fondoMapa(j.mapaActual);
		dibujarMarco();
	}
	if (casillas == 'R' && j.mapaActual == 0 && !reflejosJugado) {
		//juegoreflejos(j, j2);
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


//limpiamos el mapa para que se actualice
void limpiarZonaMapa()
{
	int borde = (ALTO_PANTALLA / 2) + 10;
	for (int y = 13; y < 16; y++)
	{
		Console::SetCursorPosition(borde, y);
		cout << string(ANCHO_PANTALLA - borde - 4, ' ');
	}
}
//mostramos ifnromacion general de ambos jugadores 
void mostrarEstadoJugadores(Jugador& j1, Jugador& j2, string jugadorTurno, int ultimoDado)
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
	cout << "Informacion General" << endl;
	Console::ForegroundColor = ConsoleColor::White;

	Console::SetCursorPosition((ANCHO_PANTALLA / 5) - 22, 2);
	cout << "Jugador 1: " << endl;
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
	cout << "Tablero Avatar: " << j.avatar;

	dibujarAvatar(j, x, y);

	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(x + 12, y + 1);
	cout << "Monedas: " << j.monedas << "   ";

	Console::SetCursorPosition(x + 23, y + 1);
	cout << "Estrellas: " << j.estrellas << "   ";

	Console::ForegroundColor = ConsoleColor::DarkMagenta;
	Console::SetCursorPosition(x + 12, y + 2);
	cout << "Minijuegos Ganados: " << j.minijuegosGanados << "   ";
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
			eventosCasillas(j, j2, pokeMathJugado, artiJugado, reflejosJugado);
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
			eventosCasillas(j2, j, pokeMathJugado, artiJugado, reflejosJugado);
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
void pantalla() {
	Console::SetWindowSize(ANCHO_PANTALLA, ALTO_PANTALLA);
	Console::CursorVisible = false;
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

	while (true) { // el while importante 
		system("cls");
		tituloPrincipal();//inicializamos el titulo
		//Falta el config
		tecla = _getch();
		switch (tecla) {
		case '1': // si presiona 1 entonces jugamos 
			ingresoDatos(jugadores);
			iniciarJuego(jugadores[0], jugadores[1]);
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
int main() {
	menuPrincipal();
	_getch();
}
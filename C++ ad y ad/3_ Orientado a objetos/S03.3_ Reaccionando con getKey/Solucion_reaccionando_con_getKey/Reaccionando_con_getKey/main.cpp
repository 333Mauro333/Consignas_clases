#include <iostream>

#include "mgtv_library.h"

#include "opcion_del_menu.h"

using namespace std;
using namespace mgtv_library::console;


void resaltarOpcion(string opcion, int posicionY);

void avanzarOpcion(int& opcion, int opcionMaxima);
void retrocederOpcion(int& opcion, int opcionMaxima);
void entrarALaOpcion(OPCION_DEL_MENU opcionAIngresar);

int main()
{
	const int opcionMaxima = 5;

	int anchoVentana = ConsoleExt::getScreenWidth();
	int altoVentana = ConsoleExt::getScreenHeight();

	bool inProgram = true;
	int opcionSeleccionada = 1;
	int teclaPresionada = 0;

	const string opcion1 = "JUGAR";
	const string opcion2 = "OPCIONES";
	const string opcion3 = "AYUDA";
	const string opcion4 = "CREDITOS";
	const string opcion5 = "SALIR";

	const string mensajeFinal = "Presione cualquier tecla para cerrar la ventana... ";

	const char teclaArriba1 = 'W';
	const char teclaArriba2 = 'w';
	const char teclaAbajo1 = 'S';
	const char teclaAbajo2 = 's';


	ConsoleExt::hideCursor();

	while (inProgram)
	{
		system("cls"); // Limpia la pantalla.

		#pragma region MUESTRA DE OPCIONES

		ConsoleExt::goToCoordinates(anchoVentana / 2 - opcion1.size() / 2, altoVentana / 2 - 2);
		cout << opcion1;

		ConsoleExt::goToCoordinates(anchoVentana / 2 - opcion2.size() / 2 + 1, altoVentana / 2 - 1);
		cout << opcion2;

		ConsoleExt::goToCoordinates(anchoVentana / 2 - opcion3.size() / 2, altoVentana / 2);
		cout << opcion3;

		ConsoleExt::goToCoordinates(anchoVentana / 2 - opcion4.size() / 2 + 1, altoVentana / 2 + 1);
		cout << opcion4;

		ConsoleExt::goToCoordinates(anchoVentana / 2 - opcion5.size() / 2, altoVentana / 2 + 2);
		cout << opcion5;

		#pragma endregion

		#pragma region RESALTADO DE OPCION ACTUAL

		switch (opcionSeleccionada)
		{
		case 1:
			resaltarOpcion(opcion1, altoVentana / 2 - 2);
			break;

		case 2:
			resaltarOpcion(opcion2, altoVentana / 2 - 1);
			break;

		case 3:
			resaltarOpcion(opcion3, altoVentana / 2);
			break;

		case 4:
			resaltarOpcion(opcion4, altoVentana / 2 + 1);
			break;

		case 5:
			resaltarOpcion(opcion5, altoVentana / 2 + 2);
			break;
		}

		#pragma endregion

		// Se obtiene la tecla presionada.
		teclaPresionada = ConsoleExt::getKey(true);

		// Se reacciona ante la tecla presionada.
		switch (teclaPresionada)
		{
		case teclaArriba1:
		case teclaArriba2:
			retrocederOpcion(opcionSeleccionada, opcionMaxima);
			break;

		case teclaAbajo1:
		case teclaAbajo2:
			avanzarOpcion(opcionSeleccionada, opcionMaxima);
			break;

		case KEY_ENTER:
			entrarALaOpcion((OPCION_DEL_MENU)opcionSeleccionada);

			if (opcionSeleccionada == opcionMaxima)
			{
				inProgram = false;
			}

			break;
		}
	}

	ConsoleExt::goToCoordinates(anchoVentana / 2 - mensajeFinal.size() / 2, altoVentana / 2 + 7);
	ConsoleExt::writeWithColor(mensajeFinal, COLOR::C_GREEN);

	ConsoleExt::getKey(true);


	return 0;
}

void resaltarOpcion(string opcion, int posicionY)
{
	const char flechaIzquierda = (char)17;  // ◄
	const char flechaDerecha = (char)16;    // ►


	ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - opcion.size() / 2 - 2, posicionY);
	cout << flechaDerecha;

	ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 + opcion.size() / 2 + 2, posicionY);
	cout << flechaIzquierda;
}

void avanzarOpcion(int& opcion, int opcionMaxima)
{
	if (opcion != opcionMaxima)
	{
		opcion++;
	}
	else
	{
		opcion = 1;
	}
}
void retrocederOpcion(int& opcion, int opcionMaxima)
{
	if (opcion != 1)
	{
		opcion--;
	}
	else
	{
		opcion = opcionMaxima;
	}
}
void entrarALaOpcion(OPCION_DEL_MENU opcionAIngresar)
{
	const string respuesta1 = "Este es un menu de prueba. No hay un juego para cargar. ";
	const string respuesta2 = "Aca se mostrarian las opciones. Al ser un programa de prueba, no hay opciones.";
	const string respuesta3_1 = "Podes navegar a traves del menu principal con \"Flecha arriba\" y \"Flecha abajo\".";
	const string respuesta3_2 = "Para ingresar a la opcion, presionar \"Enter\".";
	const string respuesta4 = "Nada que reconocer. Simplemente es un programa de ejemplo para que mis alumnos aprendan :)";
	const string respuesta5 = "Programa finalizado. Gracias por utilizar!";

	int posicionY = ConsoleExt::getScreenHeight() / 2 + 5;


	switch (opcionAIngresar)
	{
	case OPCION_DEL_MENU::JUGAR:
		ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - respuesta1.size() / 2, posicionY);
		cout << respuesta1;
		break;

	case OPCION_DEL_MENU::OPCIONES:
		ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - respuesta2.size() / 2, posicionY);
		cout << respuesta2;
		break;

	case OPCION_DEL_MENU::AYUDA:
		ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - respuesta3_1.size() / 2, posicionY);
		cout << respuesta3_1;
		ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - respuesta3_2.size() / 2, posicionY + 1);
		cout << respuesta3_2;
		break;

	case OPCION_DEL_MENU::CREDITOS:
		ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - respuesta4.size() / 2, posicionY);
		cout << respuesta4;
		break;

	case OPCION_DEL_MENU::SALIR:
		ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - respuesta5.size() / 2, posicionY);
		cout << respuesta5;
		break;
	}

	ConsoleExt::getKey(true);
}

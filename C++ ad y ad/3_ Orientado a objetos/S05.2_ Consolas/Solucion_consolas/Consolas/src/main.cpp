#include <iostream>

#include "mgtv_library.h"

#include "consola/consola.h"
#include "mando/mando.h"
#include "enums/pantalla/pantalla.h"

using namespace std;
using namespace mgtv_library::console;


void dibujarTele(int x, int y, bool conMando, Consola* consola);

int main()
{
	bool enPrograma = true;

	int anchoConsola = ConsoleExt::getScreenWidth();
	int altoConsola = ConsoleExt::getScreenHeight();

	PANTALLA pantallaActual = PANTALLA::MENU_PRINCIPAL;

	// Menu principal.
	const string tituloPrograma = "----- CONSOLAS -----";
	int posicionTituloProgramaX = anchoConsola / 2 - tituloPrograma.size() / 2;
	int posicionTituloProgramaY = 2;

	const string opcion1 = "1. CONECTAR A UNA CONSOLA";
	const string opcion2 = "2. DESCONECTAR";
	const string opcion3 = "3. CAMBIAR VOLUMEN";
	const string opcion4 = "4. CAMBIAR BRILLO";
	const string opcion5 = "5. SALIR DEL PROGRAMA";

	// Conexion a una consola.
	const string tituloConectar = "----- CONECTAR A UNA CONSOLA -----";
	int posicionTituloConectarX = anchoConsola / 2 - tituloConectar.size() / 2;
	int posicionTituloConectarY = 2;

	// Cambio de volumen.
	const string tituloVolumen = "----- CAMBIAR VOLUMEN -----";
	int posicionTituloVolumenX = anchoConsola / 2 - tituloVolumen.size() / 2;
	int posicionTituloVolumenY = 2;

	// Cambio de brillo.
	const string tituloBrillo = "----- CAMBIAR BRILLO -----";
	int posicionTituloBrilloX = anchoConsola / 2 - tituloBrillo.size() / 2;
	int posicionTituloBrilloY = 2;

	// Objetos.
	const int cantidadDeConsolas = 3;
	Consola* consolas[cantidadDeConsolas] = {};

	Mando* mando = new Mando();

	// Otras variables.
	bool seConectan = false;

	const int distanciaEntreTeles = 32;
	int margenParaEscribir = anchoConsola / 2 - 15;
	int volumenTemporal = 0;
	int brilloTemporal = 0;
	int auxiliar = 0;

	int opcionIngresada = 0;
	int teclaPresionada = 0;



	for (int i = 0; i < cantidadDeConsolas; i++)
	{
		consolas[i] = new Consola();
	}

	while (enPrograma)
	{
		system("cls");

		switch (pantallaActual)
		{
		case PANTALLA::MENU_PRINCIPAL:

			#pragma region MUESTRA DEL MENU

			auxiliar = -distanciaEntreTeles - 10;

			ConsoleExt::goToCoordinates(posicionTituloProgramaX, posicionTituloProgramaY);
			cout << tituloPrograma;

			for (int i = 0; i < cantidadDeConsolas; i++)
			{
				// "mando->getConsola() == consolas[i]", al final de la comparacion, se convierte en un
				// "true" o en un "false". Es por eso que ese valor se puede guardar en una variable bool.
				seConectan = mando->getConsola() == consolas[i];

				dibujarTele(anchoConsola / 2 + auxiliar, posicionTituloProgramaY + 3, seConectan, consolas[i]);

				auxiliar += distanciaEntreTeles; // Se aplica la distancia sobre X.
			}

			auxiliar = 0;

			ConsoleExt::goToCoordinates(anchoConsola / 2 - opcion1.size() / 2, posicionTituloProgramaY + 17);
			cout << opcion1;
			ConsoleExt::goToCoordinates(anchoConsola / 2 - opcion2.size() / 2, posicionTituloProgramaY + 18);
			cout << opcion2;
			ConsoleExt::goToCoordinates(anchoConsola / 2 - opcion3.size() / 2, posicionTituloProgramaY + 19);
			cout << opcion3;
			ConsoleExt::goToCoordinates(anchoConsola / 2 - opcion4.size() / 2, posicionTituloProgramaY + 20);
			cout << opcion4;
			ConsoleExt::goToCoordinates(anchoConsola / 2 - opcion5.size() / 2, posicionTituloProgramaY + 21);
			cout << opcion5;

			#pragma endregion

			#pragma region PETICION DEL NUMERO

			ConsoleExt::goToCoordinates(margenParaEscribir, posicionTituloProgramaY + 23);
			cout << "Opcion ingresada: ";
			cin >> opcionIngresada;

			#pragma endregion

			#pragma region REACCION AL NUMERO INGRESADO

			switch (opcionIngresada)
			{
			case 1: // Conectar a una consola.

				if (!mando->estaConectado())
				{
					pantallaActual = PANTALLA::CONECTAR_A_CONSOLA;
				}
				else
				{
					ConsoleExt::goToCoordinates(anchoConsola / 2 - 41, posicionTituloProgramaY + 25);
					ConsoleExt::writeWithColor("El mando ya esta conectado a una consola. Presione cualquier tecla para continuar... ", COLOR::C_LRED);
					ConsoleExt::getKey(true);
				}

				break;

			case 2: // Desconectar.

				if (mando->estaConectado())
				{
					mando->desconectar();

					ConsoleExt::goToCoordinates(anchoConsola / 2 - 40, posicionTituloProgramaY + 25);
					ConsoleExt::writeWithColor("El mando fue desconectado de la consola. ", COLOR::C_GREEN);
					ConsoleExt::writeWithColor("Presione cualquier tecla para continuar... ", COLOR::C_GREEN);
				}
				else
				{
					ConsoleExt::goToCoordinates(anchoConsola / 2 - 43, posicionTituloProgramaY + 25);
					ConsoleExt::writeWithColor("El mando no estaba conectado a ninguna consola. ", COLOR::C_LRED);
					ConsoleExt::writeWithColor("Presione cualquier tecla para continuar... ", COLOR::C_LRED);
				}

				ConsoleExt::getKey(true);

				break;

			case 3: // Cambiar volumen.

				if (mando->estaConectado())
				{
					pantallaActual = PANTALLA::CAMBIAR_VOLUMEN;
				}
				else
				{
					ConsoleExt::goToCoordinates(anchoConsola / 2 - 56, posicionTituloProgramaY + 25);
					ConsoleExt::writeWithColor("Para cambiar el volumen, el mando debe estar conectado a una consola. ", COLOR::C_LRED);
					ConsoleExt::writeWithColor("Presione cualquier tecla para continuar... ", COLOR::C_LRED);
					ConsoleExt::getKey(true);
				}

				break;

			case 4: // Cambiar volumen.

				if (mando->estaConectado())
				{
					pantallaActual = PANTALLA::CAMBIAR_BRILLO;
				}
				else
				{
					ConsoleExt::goToCoordinates(anchoConsola / 2 - 55, posicionTituloProgramaY + 25);
					ConsoleExt::writeWithColor("Para cambiar el brillo, el mando debe estar conectado a una consola. ", COLOR::C_LRED);
					ConsoleExt::writeWithColor("Presione cualquier tecla para continuar... ", COLOR::C_LRED);
					ConsoleExt::getKey(true);
				}

				break;

			case 5:

				enPrograma = false;
				ConsoleExt::goToCoordinates(anchoConsola / 2 - 30, posicionTituloProgramaY + 25);
				ConsoleExt::writeWithColor("El programa se ha finalizado. Muchas gracias por utilizar!", COLOR::C_GREEN);

				break;
			}

			#pragma endregion

			break;

		case PANTALLA::CONECTAR_A_CONSOLA:

			#pragma region MUESTRA DEL MENU

			auxiliar = -1;

			ConsoleExt::goToCoordinates(posicionTituloConectarX, posicionTituloConectarY);
			cout << tituloConectar;

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 47, altoConsola / 2 - 3);
			cout << "Ingrese el numero de consola a la que desea conectarse (ingrese " << cantidadDeConsolas + 1 << " para volver al menu principal):";

			for (int i = 0; i < cantidadDeConsolas; i++)
			{
				ConsoleExt::goToCoordinates(anchoConsola / 2 - 25, altoConsola / 2 + auxiliar);
				cout << "Consola " << i + 1 << ". Volumen: " << consolas[i]->getVolumen() << "%. Brillo: " << consolas[i]->getBrillo() << "%.";

				auxiliar++;
			}

			#pragma endregion

			#pragma region PETICION DEL NUMERO

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 25, altoConsola / 2 + 3);
			cout << "Opcion ingresada: ";
			cin >> opcionIngresada;

			#pragma endregion

			#pragma region REACCION AL NUMERO INGRESADO

			if (opcionIngresada >= 1 && opcionIngresada <= cantidadDeConsolas)
			{
				mando->conectarALaConsola(consolas[opcionIngresada - 1]);

				ConsoleExt::goToCoordinates(anchoConsola / 2 - 25, altoConsola / 2 + 5);
				ConsoleExt::writeWithColor("El mando fue conectado a la consola elegida correctamente!", COLOR::C_GREEN);
				ConsoleExt::goToCoordinates(anchoConsola / 2 - 25, altoConsola / 2 + 6);
				ConsoleExt::writeWithColor("Presione cualquier tecla para volver al menu principal... ", COLOR::C_GREEN);
				ConsoleExt::getKey(true);

				pantallaActual = PANTALLA::MENU_PRINCIPAL;
			}
			else if (opcionIngresada == cantidadDeConsolas + 1)
			{
				pantallaActual = PANTALLA::MENU_PRINCIPAL;
			}

			#pragma endregion

			break;

		case PANTALLA::CAMBIAR_VOLUMEN:

			#pragma region CAMBIO DE VOLUMEN

			volumenTemporal = mando->getConsola()->getVolumen();

			ConsoleExt::goToCoordinates(posicionTituloVolumenX, posicionTituloVolumenY);
			cout << tituloVolumen;

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 - 3);
			cout << "Modifique el volumen actual con \"Flecha arriba\" y \"Flecha abajo\".";
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 - 2);
			cout << "Presione ENTER para aplicar el nuevo volumen.";
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 - 1);
			cout << "Presione ESC para volver al menu sin aplicar el nuevo volumen.";

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 13, altoConsola / 2 + 1);
			cout << (char)30; // ▲
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 + 2);
			cout << "Volumen actual: ";
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 13, altoConsola / 2 + 3);
			cout << (char)31; // ▼

			while (teclaPresionada != KEY_ESC && teclaPresionada != KEY_ENTER)
			{
				ConsoleExt::goToCoordinates(anchoConsola / 2 - 14, altoConsola / 2 + 2);
				cout << volumenTemporal << "%. ";

				teclaPresionada = ConsoleExt::getKey(true);

				switch (teclaPresionada)
				{
				case KEY_UP:

					if (volumenTemporal < 100)
					{
						volumenTemporal++;
					}

					break;

				case KEY_DOWN:

					if (volumenTemporal > 0)
					{
						volumenTemporal--;
					}

					break;

				case KEY_ENTER:

					mando->getConsola()->setVolumen(volumenTemporal);

					ConsoleExt::goToCoordinates(anchoConsola / 2 - 43, altoConsola / 2 + 5);
					ConsoleExt::writeWithColor("Se ha aplicado el nuevo volumen! ", COLOR::C_GREEN);
					ConsoleExt::writeWithColor("Presione cualquier tecla para volver al menu principal... ", COLOR::C_GREEN);
					ConsoleExt::getKey(true);

					break;
				}
			}

			teclaPresionada = 0;
			pantallaActual = PANTALLA::MENU_PRINCIPAL;

			#pragma endregion

			break;

		case PANTALLA::CAMBIAR_BRILLO:

			#pragma region CAMBIO DE BRILLO

			brilloTemporal = mando->getConsola()->getBrillo();

			ConsoleExt::goToCoordinates(posicionTituloBrilloX, posicionTituloBrilloY);
			cout << tituloBrillo;

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 - 3);
			cout << "Modifique el brillo actual con \"Flecha arriba\" y \"Flecha abajo\".";
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 - 2);
			cout << "Presione ENTER para aplicar el nuevo brillo.";
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 - 1);
			cout << "Presione ESC para volver al menu sin aplicar el nuevo brillo.";

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 14, altoConsola / 2 + 1);
			cout << (char)30; // ▲
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 + 2);
			cout << "Brillo actual: ";
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 14, altoConsola / 2 + 3);
			cout << (char)31; // ▼

			while (teclaPresionada != KEY_ESC && teclaPresionada != KEY_ENTER)
			{
				ConsoleExt::goToCoordinates(anchoConsola / 2 - 15, altoConsola / 2 + 2);
				cout << brilloTemporal << "%. ";

				teclaPresionada = ConsoleExt::getKey(true);

				switch (teclaPresionada)
				{
				case KEY_UP:

					if (brilloTemporal < 100)
					{
						brilloTemporal++;
					}

					break;

				case KEY_DOWN:

					if (brilloTemporal > 0)
					{
						brilloTemporal--;
					}

					break;

				case KEY_ENTER:

					mando->getConsola()->setBrillo(brilloTemporal);

					ConsoleExt::goToCoordinates(anchoConsola / 2 - 42, altoConsola / 2 + 5);
					ConsoleExt::writeWithColor("Se ha aplicado el nuevo brillo! ", COLOR::C_GREEN);
					ConsoleExt::writeWithColor("Presione cualquier tecla para volver al menu principal... ", COLOR::C_GREEN);
					ConsoleExt::getKey(true);

					break;
				}
			}

			teclaPresionada = 0;
			pantallaActual = PANTALLA::MENU_PRINCIPAL;

			#pragma endregion

			break;
		}
	}

	ConsoleExt::goToCoordinates(anchoConsola / 2 - 26, posicionTituloProgramaY + 26);
	ConsoleExt::writeWithColor("Presione cualquier tecla para cerrar la ventana... ", COLOR::C_GREEN);

	ConsoleExt::getKey(true);

	for (int i = 0; i < cantidadDeConsolas; i++)
	{
		delete consolas[i];
	}

	delete mando;



	return 0;
}

void dibujarTele(int x, int y, bool conMando, Consola* consola)
{
	const char horizontalDown = (char)203; // ╦
	const char verticalPipe = (char)186;   // ║
	COLOR colorAnterior = ConsoleExt::getForegroundColor();
	COLOR colorDeTele = COLOR::C_GRAY;


	ConsoleExt::setForegroundColor(colorDeTele);

	ConsoleExt::drawFrame(x, y, x + 20, y + 5); // Monitor.
	ConsoleExt::goToCoordinates(x + 10, y + 5);
	cout << horizontalDown;

	// Tronco que sostiene el monitor.
	for (int i = 0; i < 3; i++)
	{
		ConsoleExt::goToCoordinates(x + 10, y + 6 + i);
		cout << verticalPipe;
	}

	ConsoleExt::drawFrame(x + 5, y + 8, x + 15, y + 9); // Consola.

	ConsoleExt::goToCoordinates(x + 1, y + 2);

	// Texto que indica si el mando esta conectado o no.
	if (conMando)
	{
		ConsoleExt::writeWithColor("  Mando conectado!", COLOR::C_LGREEN);
		ConsoleExt::setForegroundColor(COLOR::C_LGREEN);
	}
	else
	{
		ConsoleExt::writeWithColor("   Ningun mando", COLOR::C_RED);
		ConsoleExt::goToCoordinates(x + 5, y + 3);
		ConsoleExt::writeWithColor("detectado.", COLOR::C_RED);
		ConsoleExt::setForegroundColor(COLOR::C_RED);
	}

	ConsoleExt::goToCoordinates(x + 4, y + 11);
	cout << "Volumen: " << consola->getVolumen() << "%.";
	ConsoleExt::goToCoordinates(x + 4, y + 12);
	cout << "Brillo: " << consola->getBrillo() << "%.";

	ConsoleExt::setForegroundColor(colorAnterior);
}

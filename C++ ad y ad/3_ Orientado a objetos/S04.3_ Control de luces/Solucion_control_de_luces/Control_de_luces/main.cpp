#include <iostream>

#include "mgtv_library.h"

#include "luz.h"

using namespace std;
using namespace mgtv_library::console;


void borrarLinea(int linea);
void borrarPantalla(int lineaDesdeDondeBorrar);

int main()
{
	bool enPrograma = true;

	int anchoConsola = ConsoleExt::getScreenWidth();
	int altoConsola = ConsoleExt::getScreenHeight();

	const int cantidadLuces = 5;
	Luz* luces[cantidadLuces];

	string titulo = "CONTROL DE LUCES";
	int posicionTituloX = anchoConsola / 2 - titulo.size() / 2;
	int posicionTituloY = 2;

	int opcionIngresada = 0;


	for (int i = 0; i < cantidadLuces; i++)
	{
		luces[i] = new Luz();
	}

	for (int i = 0; i < cantidadLuces; i++)
	{
		luces[i]->setPosicion(anchoConsola / cantidadLuces * i + 1, posicionTituloY + 3);
	}

	while (enPrograma)
	{
		system("cls");

		#pragma region MUESTRA DE MENU

		ConsoleExt::goToCoordinates(posicionTituloX, posicionTituloY);
		ConsoleExt::writeWithColor(titulo, COLOR::C_BWHITE);

		for (int i = 0; i < cantidadLuces; i++)
		{
			luces[i]->draw();
		}

		ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, posicionTituloY + 14);
		cout << "Cantidad de luces encendidas: " << Luz::getLucesEncendidas() << ".";

		ConsoleExt::goToCoordinates(anchoConsola / 2 - 15, posicionTituloY + 17);
		cout << "1. ENCENDER TODAS LAS LUCES";

		ConsoleExt::goToCoordinates(anchoConsola / 2 - 15, posicionTituloY + 18);
		cout << "2. APAGAR TODAS LAS LUCES";

		ConsoleExt::goToCoordinates(anchoConsola / 2 - 15, posicionTituloY + 19);
		cout << "3. ENCENDER UNA LUZ";

		ConsoleExt::goToCoordinates(anchoConsola / 2 - 15, posicionTituloY + 20);
		cout << "4. APAGAR UNA LUZ";

		ConsoleExt::goToCoordinates(anchoConsola / 2 - 15, posicionTituloY + 21);
		cout << "5. SALIR";

		#pragma endregion

		ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, posicionTituloY + 23);
		cout << "Opcion ingresada: ";
		cin >> opcionIngresada;

		switch (opcionIngresada)
		{
		case 1:

			#pragma region ENCENDIDO DE TODAS LAS LUCES

			if (Luz::getLucesEncendidas() < cantidadLuces)
			{
				for (int i = 0; i < cantidadLuces; i++)
				{
					if (!luces[i]->getEstaEncendida())
					{
						luces[i]->encender();
					}
				}

				ConsoleExt::goToCoordinates(anchoConsola / 2 - 37, posicionTituloY + 25);

				ConsoleExt::writeWithColor("Todas las luces fueron prendidas. ", COLOR::C_GREEN);
			}
			else
			{
				ConsoleExt::goToCoordinates(anchoConsola / 2 - 38, posicionTituloY + 25);
				ConsoleExt::writeWithColor("Todas las luces ya estan prendidas. ", COLOR::C_GREEN);
			}

			ConsoleExt::writeWithColor("Presione cualquier tecla para continuar... ", COLOR::C_GREEN);
			ConsoleExt::getKey(true);

			#pragma endregion

			break;

		case 2:

			#pragma region APAGADO DE TODAS LAS LUCES

			if (Luz::getLucesEncendidas() > 0)
			{
				for (int i = 0; i < cantidadLuces; i++)
				{
					if (luces[i]->getEstaEncendida())
					{
						luces[i]->apagar();
					}
				}

				ConsoleExt::goToCoordinates(anchoConsola / 2 - 36, posicionTituloY + 25);

				ConsoleExt::writeWithColor("Todas las luces fueron apagadas. ", COLOR::C_GREEN);
			}
			else
			{
				ConsoleExt::goToCoordinates(anchoConsola / 2 - 34, posicionTituloY + 25);
				ConsoleExt::writeWithColor("Las luces ya estan apagadas. ", COLOR::C_GREEN);
			}

			ConsoleExt::writeWithColor("Presione cualquier tecla para continuar... ", COLOR::C_GREEN);
			ConsoleExt::getKey(true);

			#pragma endregion

			break;

		case 3:

			#pragma region ENCENDIDO DE UNA LUZ

			if (Luz::getLucesEncendidas() != cantidadLuces)
			{
				do
				{
					borrarPantalla(posicionTituloY + 17);

					ConsoleExt::goToCoordinates(anchoConsola / 2 - 25, posicionTituloY + 17);
					cout << "Ingrese el numero de luz que desea encender (entre 1 y " << cantidadLuces << "): ";
					cin >> opcionIngresada;

				} while (opcionIngresada < 1 || opcionIngresada > cantidadLuces);

				if (!luces[opcionIngresada - 1]->getEstaEncendida())
				{
					luces[opcionIngresada - 1]->encender();

					ConsoleExt::goToCoordinates(anchoConsola / 2 - 29, posicionTituloY + 19);
					ConsoleExt::writeWithColor("La luz fue encendida. ", COLOR::C_GREEN);
				}
				else
				{
					ConsoleExt::goToCoordinates(anchoConsola / 2 - 31, posicionTituloY + 19);
					ConsoleExt::writeWithColor("La luz ya esta encendida. ", COLOR::C_GREEN);
				}
			}
			else
			{
				ConsoleExt::goToCoordinates(anchoConsola / 2 - 38, posicionTituloY + 25);
				ConsoleExt::writeWithColor("Todas las luces ya estan prendidas.", COLOR::C_GREEN);
			}

			ConsoleExt::writeWithColor("Presione cualquier tecla para continuar... ", COLOR::C_GREEN);
			ConsoleExt::getKey(true);

			#pragma endregion

			break;

		case 4:

			#pragma region APAGADO DE UNA LUZ

			if (Luz::getLucesEncendidas() != 0)
			{
				do
				{
					borrarPantalla(posicionTituloY + 17);

					ConsoleExt::goToCoordinates(anchoConsola / 2 - 25, posicionTituloY + 17);
					cout << "Ingrese el numero de luz que desea apagar (entre 1 y " << cantidadLuces << "): ";
					cin >> opcionIngresada;

				} while (opcionIngresada < 1 || opcionIngresada > cantidadLuces);

				if (luces[opcionIngresada - 1]->getEstaEncendida())
				{
					luces[opcionIngresada - 1]->apagar();

					ConsoleExt::goToCoordinates(anchoConsola / 2 - 28, posicionTituloY + 19);
					ConsoleExt::writeWithColor("La luz fue apagada. ", COLOR::C_GREEN);
				}
				else
				{
					ConsoleExt::goToCoordinates(anchoConsola / 2 - 30, posicionTituloY + 19);
					ConsoleExt::writeWithColor("La luz ya esta apagada. ", COLOR::C_GREEN);
				}
			}
			else
			{
				ConsoleExt::goToCoordinates(anchoConsola / 2 - 34, posicionTituloY + 25);
				ConsoleExt::writeWithColor("Las luces ya estan apagadas. ", COLOR::C_GREEN);
			}

			ConsoleExt::writeWithColor("Presione cualquier tecla para continuar... ", COLOR::C_GREEN);
			ConsoleExt::getKey(true);

			#pragma endregion

			break;

		case 5:

			#pragma region FINALIZACION DEL PROGRAMA

			enPrograma = false;

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 37, posicionTituloY + 25);
			ConsoleExt::writeWithColor("Gracias por utilizar. Presione cualquier tecla para cerrar la ventana... ", COLOR::C_GREEN);

			#pragma endregion

			break;
		}
	}


	ConsoleExt::getKey(true);

	return 0;
}

void borrarLinea(int linea)
{
	for (int i = 0; i < ConsoleExt::getScreenWidth(); i++)
	{
		ConsoleExt::goToCoordinates(i + 1, linea);
		cout << " ";
	}
}
void borrarPantalla(int lineaDesdeDondeBorrar)
{
	for (int i = lineaDesdeDondeBorrar; i <= ConsoleExt::getScreenHeight(); i++)
	{
		borrarLinea(i);
	}
}

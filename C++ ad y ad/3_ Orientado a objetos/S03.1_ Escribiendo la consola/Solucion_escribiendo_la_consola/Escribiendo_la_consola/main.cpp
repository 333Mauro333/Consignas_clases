#include <iostream>

#include "mgtv_library.h"

using namespace std;
using namespace mgtv_library::console;


void borrarLinea();
bool estaDentroDeLosLimites(int num, int limMin, int limMax);

int main()
{
	string titulo = "ESCRIBIENDO LA CONSOLA";
	int anchoVentana = ConsoleExt::getScreenWidth();
	int altoVentana = ConsoleExt::getScreenHeight();

	int distanciaDelTitulo = 4;
	int columnaDelTitulo = anchoVentana / 2 - titulo.size() / 2; // Posicion para que el título quede centrado.
	int lineaDelTitulo = altoVentana - distanciaDelTitulo;

	int x = 0;
	int y = 0;

	bool inProgram = true;


	ConsoleExt::setConsoleTitle(titulo.c_str());

	ConsoleExt::goToCoordinates(columnaDelTitulo, altoVentana - distanciaDelTitulo);
	ConsoleExt::writeWithColor(titulo, COLOR::C_YELLOW);

	while (inProgram)
	{
		if (x >= columnaDelTitulo && x <= columnaDelTitulo + titulo.size() && y == altoVentana - distanciaDelTitulo)
		{
			ConsoleExt::goToCoordinates(columnaDelTitulo, altoVentana - distanciaDelTitulo);
			ConsoleExt::writeWithColor(titulo, COLOR::C_YELLOW);
		}

		do
		{
			ConsoleExt::goToCoordinates(1, altoVentana - 2);
			borrarLinea();

			ConsoleExt::goToCoordinates(1, altoVentana - 2);

			cout << "Ingrese la posicion X (entre 1 y " << anchoVentana << "): ";
			cin >> x;

		} while (!estaDentroDeLosLimites(x, 1, anchoVentana));

		do
		{
			ConsoleExt::goToCoordinates(1, altoVentana - 1);
			borrarLinea();

			ConsoleExt::goToCoordinates(1, altoVentana - 1);

			cout << "Ingrese la posicion Y (entre 1 y " << altoVentana << "): ";
			cin >> y;

		} while (!estaDentroDeLosLimites(y, 0, altoVentana));

		if (y != 0)
		{
			ConsoleExt::goToCoordinates(1, altoVentana - 1);
			borrarLinea();

			ConsoleExt::goToCoordinates(x, y);
			cout << "#";
		}
		else
		{
			inProgram = false;
		}
	}

	ConsoleExt::setForegroundColor(COLOR::C_GREEN);

	cout << "Programa finalizado correctamente. ";
	system("pause");

	ConsoleExt::setForegroundColor(COLOR::C_WHITE);


	return 0;
}

void borrarLinea()
{
	for (int i = 0; i < ConsoleExt::getScreenWidth(); i++)
	{
		cout << " ";
	}
}
bool estaDentroDeLosLimites(int num, int limMin, int limMax)
{
	return num >= limMin && num <= limMax;
}

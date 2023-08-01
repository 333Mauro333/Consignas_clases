#include <iostream>

#include "mgtv_library.h"

using namespace std;
using namespace mgtv_library::console;


void borrarLinea(int linea);
bool estaDentroDeLosLimites(int num, int limMin, int limMax);

int main()
{
	bool inProgram = true;

	int anchoVentana = ConsoleExt::getScreenWidth() - 1;
	int altoVentana = ConsoleExt::getScreenHeight() - 1;

	const string titulo = "ESCRIBIENDO LA CONSOLA";
	const int distanciaDelTitulo = 4;
	int columnaDelTitulo = anchoVentana / 2 - titulo.size() / 2; // Posicion para que el título quede centrado.
	int lineaDelTitulo = altoVentana - distanciaDelTitulo;

	int x = 0;
	int y = 0;

	const char numeral = '#';



	ConsoleExt::setConsoleTitle(titulo); // Se cambia el titulo de la consola.

	// Se escribe el titulo en la consola.
	ConsoleExt::goToCoordinates(columnaDelTitulo, altoVentana - distanciaDelTitulo);
	ConsoleExt::writeWithColor(titulo, COLOR::C_YELLOW);

	// Comienza el loop del programa.
	while (inProgram)
	{
		// Si el ultimo # se ingreso sobre el titulo, el mismo se vuelve a escribir.
		if (x >= columnaDelTitulo && x <= columnaDelTitulo + titulo.size() && y == altoVentana - distanciaDelTitulo)
		{
			ConsoleExt::goToCoordinates(columnaDelTitulo, altoVentana - distanciaDelTitulo);
			ConsoleExt::writeWithColor(titulo, COLOR::C_YELLOW);
		}

		// Se pide la coordenada "x".
		do
		{
			borrarLinea(altoVentana - 2);

			ConsoleExt::goToCoordinates(0, altoVentana - 2);

			cout << "Ingrese la posicion X (entre 0 y " << anchoVentana << "): ";
			cin >> x;

		} while (!estaDentroDeLosLimites(x, 0, anchoVentana));

		// Se pide la coordenada "y".
		do
		{
			borrarLinea(altoVentana - 1);

			ConsoleExt::goToCoordinates(0, altoVentana - 1);

			cout << "Ingrese la posicion Y (entre 0 y " << altoVentana << "): ";
			cin >> y;

		} while (!estaDentroDeLosLimites(y, -1, altoVentana));

		// Se verifica si la coordenada "y" no es -1 (en el caso de que lo sea, se finaliza el programa).
		if (y != -1)
		{
			// Se borra la linea donde se pidio la coordenada "y".
			borrarLinea(altoVentana - 1);

			// Se va a las coordenadas ingresadas y se escribe el "#".
			ConsoleExt::goToCoordinates(x, y);
			cout << numeral;
		}
		else
		{
			// Se finaliza el programa.
			inProgram = false;
		}
	}

	ConsoleExt::writeWithColor("Programa finalizado correctamente. Presione cualquier tecla para cerrar la ventana... ", COLOR::C_GREEN);
	ConsoleExt::getKey(true);


	return 0;
}

void borrarLinea(int linea)
{
	ConsoleExt::goToCoordinates(0, linea);

	for (int i = 0; i < ConsoleExt::getScreenWidth(); i++)
	{
		cout << " ";
	}
}
bool estaDentroDeLosLimites(int num, int limMin, int limMax)
{
	return num >= limMin && num <= limMax;
}

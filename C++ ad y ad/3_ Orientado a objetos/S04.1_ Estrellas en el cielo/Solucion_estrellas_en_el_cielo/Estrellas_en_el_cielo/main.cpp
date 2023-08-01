#include <iostream>

#include "mgtv_library.h"

#include "estrella.h"

using namespace std;
using namespace mgtv_library::console;


int pedirNumero(int limMin, int limMax, int x, int y, string mensaje, bool muestraLimites = false);

void escribirPosicionEstrella(Estrella* estrella, int numeroEstrella = 1);
int obtenerNumeroRandom(int min, int max);

void borrarLinea(int linea);
void borrarMenu(int inicioDeBorrado);

int main()
{
	Estrella* estrella1 = new Estrella();
	Estrella* estrella2 = new Estrella();

	bool enPrograma = true;

	const string titulo = "ESTRELLAS EN EL CIELO";

	int anchoConsola = ConsoleExt::getScreenWidth() - 1;
	int altoConsola = ConsoleExt::getScreenHeight() - 1;

	const int distanciaBordeX = 20;
	const int distanciaBordeYSup = 4;
	const int distanciaBordeYInf = 15;

	int marcoBordeIzquierdo = distanciaBordeX;
	int marcoBordeDerecho = anchoConsola - distanciaBordeX;
	int marcoBordeSuperior = distanciaBordeYSup;
	int marcoBordeInferior = altoConsola - distanciaBordeYInf;

	int opcionIngresada = 0;

	int x = 0;
	int y = 0;



	srand(time(NULL));

	ConsoleExt::setConsoleTitle(titulo);

	x = obtenerNumeroRandom(marcoBordeIzquierdo + 1, marcoBordeDerecho - 1);
	y = obtenerNumeroRandom(marcoBordeSuperior + 1, marcoBordeInferior - 1);

	estrella1->setPosicion(x, y);

	x = obtenerNumeroRandom(marcoBordeIzquierdo + 1, marcoBordeDerecho - 1);
	y = obtenerNumeroRandom(marcoBordeSuperior + 1, marcoBordeInferior - 1);

	estrella2->setPosicion(x, y);

	ConsoleExt::setBackgroundColor(COLOR::C_BLUE);
	ConsoleExt::setForegroundColor(COLOR::C_WHITE);

	while (enPrograma)
	{
		system("cls");

		// Se escribe el titulo.
		ConsoleExt::goToCoordinates(anchoConsola / 2 - titulo.size() / 2, marcoBordeSuperior - 1);
		ConsoleExt::writeWithColor(titulo, COLOR::C_BWHITE);

		// Se dibuja el marco que va a contener las estrellas.
		ConsoleExt::drawFrame(marcoBordeIzquierdo, marcoBordeSuperior, marcoBordeDerecho, marcoBordeInferior);

		estrella1->draw();
		estrella2->draw();

		ConsoleExt::goToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 1);
		cout << "Cambios de posicion totales: " << Estrella::getCantCambiosPosicion() << ".";

		// Se escriben las posiciones de las estrellas.
		ConsoleExt::goToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 3);
		escribirPosicionEstrella(estrella1);
		ConsoleExt::goToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 4);
		escribirPosicionEstrella(estrella2, 2);

		// Se muestra el menu de opciones.
		ConsoleExt::goToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 7);
		cout << "1. Establecer posiciones aleatorias";
		ConsoleExt::goToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 8);
		cout << "2. Definir una nueva posicion";
		ConsoleExt::goToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 9);
		cout << "3. Salir del programa";

		// Se pide el numero de opcion.
		opcionIngresada = pedirNumero(1, 3, marcoBordeIzquierdo, marcoBordeInferior + 11, "Opcion ingresada: ");

		// Se reacciona en cuanto al numero de opcion.
		switch (opcionIngresada)
		{
		case 1:

			#pragma region POSICIONAMIENTO ALEATORIO DE LAS ESTRELLAS

			x = obtenerNumeroRandom(marcoBordeIzquierdo + 1, marcoBordeDerecho - 1);
			y = obtenerNumeroRandom(marcoBordeSuperior + 1, marcoBordeInferior - 1);

			estrella1->setPosicion(x, y);

			x = obtenerNumeroRandom(marcoBordeIzquierdo + 1, marcoBordeDerecho - 1);
			y = obtenerNumeroRandom(marcoBordeSuperior + 1, marcoBordeInferior - 1);

			estrella2->setPosicion(x, y);

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 37, marcoBordeInferior + 12);
			cout << "Posiciones cambiadas correctamente. ";
			system("pause");

			#pragma endregion

			break;

		case 2:

			#pragma region PEDIDO DE COORDENADAS Y ESTRELLA

			borrarMenu(marcoBordeInferior + 6); // Se borra desde la seccion del menu para abajo.

			// Se muestra el nuevo menu.
			ConsoleExt::goToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 7);
			cout << "1. Cambiar posicion de la primera estrella";
			ConsoleExt::goToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 8);
			cout << "2. Cambiar posicion de la segunda estrella";
			ConsoleExt::goToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 9);
			cout << "3. Volver al menu principal";

			// Se pide el numero de opcion.
			opcionIngresada = pedirNumero(1, 3, marcoBordeIzquierdo, marcoBordeInferior + 11, "Opcion ingresada: ");

			// Se reacciona si la opcion ingresada corresponde al cambio de posicion de una estrella.
			if (opcionIngresada != 3)
			{
				borrarMenu(marcoBordeInferior + 6);

				x = pedirNumero(marcoBordeIzquierdo + 1, marcoBordeDerecho - 1, marcoBordeIzquierdo, marcoBordeInferior + 7, "Ingrese la posicion X", true);
				y = pedirNumero(marcoBordeSuperior + 1, marcoBordeInferior - 1, marcoBordeIzquierdo, marcoBordeInferior + 8, "Ingrese la posicion Y", true);

				// Se establece la posicion a la estrella correspondiente.
				switch (opcionIngresada)
				{
				case 1:
					estrella1->setPosicion(x, y);
					break;

				case 2:
					estrella2->setPosicion(x, y);
					break;
				}

				ConsoleExt::goToCoordinates(anchoConsola / 2 - 37, marcoBordeInferior + 10);
				ConsoleExt::writeWithColor("Estrella posicionada correctamente. Presione cualquier tecla para continuar... ", COLOR::C_GREEN);
				ConsoleExt::getKey(true);
			}

			#pragma endregion

			break;

		case 3:

			#pragma region SALIDA DEL PROGRAMA

			enPrograma = false;

			ConsoleExt::goToCoordinates(marcoBordeIzquierdo - 10, marcoBordeInferior + 13);
			ConsoleExt::writeWithColor("Programa finalizado. Muchas gracias por utilizar! Presione cualquier tecla para cerrar la ventana... ", COLOR::C_GREEN);
			ConsoleExt::getKey(true);
			cout << endl;

			#pragma endregion

			break;
		}
	}

	delete estrella1;
	delete estrella2;



	return 0;
}

int pedirNumero(int limMin, int limMax, int x, int y, string mensaje, bool muestraLimites)
{
	int num = 0;
	bool esValido = false;


	do
	{
		borrarMenu(y);
		ConsoleExt::goToCoordinates(x, y);

		cout << mensaje;

		if (muestraLimites)
		{
			cout << " (entre " << limMin << " y " << limMax << "): ";
		}

		cin >> num;

		if (!cin.good())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			esValido = num >= limMin && num <= limMax;
		}

	} while (!esValido);

	return num;
}

void escribirPosicionEstrella(Estrella* estrella, int numeroEstrella)
{
	cout << "Posicion de la estrella " << numeroEstrella << ": (" << estrella->getPosicion().x << "; " << estrella->getPosicion().y << ").";
}
int obtenerNumeroRandom(int min, int max)
{
	int numRandom = rand() % (max - min + 1) + min;

	return numRandom;
}

void borrarLinea(int linea)
{
	ConsoleExt::goToCoordinates(0, linea);

	for (int i = 0; i < ConsoleExt::getScreenWidth(); i++)
	{
		cout << " ";
	}
}
void borrarMenu(int inicioDeBorrado)
{
	for (int i = inicioDeBorrado; i < ConsoleExt::getScreenHeight(); i++)
	{
		borrarLinea(i);
	}
}

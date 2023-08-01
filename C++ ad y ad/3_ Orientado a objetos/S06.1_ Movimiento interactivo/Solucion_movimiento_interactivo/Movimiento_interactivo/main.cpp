#include <iostream>

#include "mgtv_library.h"

#include "jugador.h"

using namespace std;
using namespace mgtv_library::console;


int main()
{
	bool enPrograma = true;
	int fps = 10;

	int anchoConsola = ConsoleExt::getScreenWidth();
	int altoConsola = ConsoleExt::getScreenHeight();

	const int distanciaBordesX = 15;
	const int distanciaBordesY = 5;

	int marcoBordeSuperior = distanciaBordesY;
	int marcoBordeInferior = altoConsola - distanciaBordesY;
	int marcoBordeIzquierdo = distanciaBordesX;
	int marcoBordeDerecho = anchoConsola - distanciaBordesX;

	const string mensajeVictoria1 = "Enhorabuena! Has llegado a la cantidad necesaria de movimientos!";
	const string mensajeVictoria2 = "Presione cualquier tecla para finalizar el juego... ";

	Jugador* jugador = new Jugador(anchoConsola / 2, altoConsola / 2);

	const int movimientosNecesarios = 50;



	ConsoleExt::hideCursor();

	jugador->setControles((int)'w', (int)'s', (int)'a', (int)'d');
	jugador->setControlesAlternativos((int)'W', (int)'S', (int)'A', (int)'D');
	jugador->setLimites(marcoBordeSuperior, marcoBordeInferior, marcoBordeIzquierdo, marcoBordeDerecho);

	while (enPrograma)
	{
		ConsoleExt::sleep(1.0f / fps); // Se ocupa de controlar la cantidad de fotogramas por segundo.

		#pragma region UPDATE

		jugador->update();

		if (jugador->getCantidadDeMovimientosHechos() >= movimientosNecesarios)
		{
			enPrograma = false;
		}

		#pragma endregion

		#pragma region DRAW

		system("cls");

		ConsoleExt::drawFrame(marcoBordeIzquierdo, marcoBordeSuperior, marcoBordeDerecho, marcoBordeInferior);

		ConsoleExt::goToCoordinates(marcoBordeIzquierdo + 5, marcoBordeSuperior - 1);
		cout << "Movimientos hechos: " << jugador->getCantidadDeMovimientosHechos();
		ConsoleExt::goToCoordinates(marcoBordeDerecho - 31, marcoBordeSuperior - 1);
		cout << "Movimientos necesarios: " << movimientosNecesarios;

		jugador->draw();

		if (jugador->getCantidadDeMovimientosHechos() >= movimientosNecesarios)
		{
			ConsoleExt::showCursor();

			ConsoleExt::goToCoordinates(anchoConsola / 2 - mensajeVictoria1.size() / 2, altoConsola / 2 - 1);
			ConsoleExt::writeWithColor(mensajeVictoria1, COLOR::C_GREEN);
			ConsoleExt::goToCoordinates(anchoConsola / 2 - mensajeVictoria2.size() / 2, altoConsola / 2);
			ConsoleExt::writeWithColor(mensajeVictoria2, COLOR::C_GREEN);

			enPrograma = false;
		}

		#pragma endregion
	}


	ConsoleExt::getKey(true);
	ConsoleExt::goToCoordinates(1, marcoBordeInferior + 1);

	delete jugador;


	return 0;
}

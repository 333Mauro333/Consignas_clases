#include "estrella.h"

#include <iostream>

#include "mgtv_library.h"

using namespace std;
using namespace mgtv_library::console;


int Estrella::cantCambiosPosicion = 0;

Estrella::Estrella()
{
	posicion = { 0, 0 };
}
Estrella::~Estrella()
{
	cout << "La estrella ubicada en la posicion (" << posicion.x << "; " << posicion.y << ") ha sido liberada de la memoria.\n\n";
}


int Estrella::getCantCambiosPosicion()
{
	return cantCambiosPosicion;
}

void Estrella::draw()
{
	ConsoleExt::goToCoordinates(posicion.x, posicion.y);
	ConsoleExt::writeWithColor("*", COLOR::C_YELLOW);
}

POSICION Estrella::getPosicion()
{
	return posicion;
}
void Estrella::setPosicion(int x, int y)
{
	posicion = { x, y };

	cantCambiosPosicion++;
}

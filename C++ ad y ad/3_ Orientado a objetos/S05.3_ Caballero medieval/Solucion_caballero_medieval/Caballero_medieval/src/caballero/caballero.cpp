#include "caballero.h"

#include <iostream>
#include <cstddef>

#include "mgtv_library.h"

using namespace mgtv_library::console;


Caballero::Caballero(string nombre)
{
	this->nombre = nombre;

	posicion = {};
	espada = NULL;
}
Caballero::~Caballero()
{
	cout << "El caballero " << nombre << " fue liberado de la memoria." << endl << endl;
}


void Caballero::setPosicion(int x, int y)
{
	posicion = { x, y };
}

string Caballero::getNombre()
{
	return nombre;
}

bool Caballero::tieneUnaEspada()
{
	return espada != NULL;
}

void Caballero::agarrarEspada(Espada* espada)
{
	this->espada = espada;
}
void Caballero::soltarEspada()
{
	espada = NULL;
}
void Caballero::atacar()
{
	if (espada != NULL)
	{
		cout << nombre << " ataco con su espada de " << espada->getMaterial() << " e hizo " << espada->getDanio() << " de danio al maniqui." << endl;
	}
	else
	{
		cout << "Para atacar, " << nombre << " debe tener una espada." << endl;
	}
}
void Caballero::observarPiedra(PiedraPreciosa* piedra)
{
	cout << nombre << " observa una piedra. Su tipo es " << piedra->getTipo() << "." << endl;
}

void Caballero::draw()
{
	ConsoleExt::goToCoordinates(posicion.x + 1, posicion.y);
	cout << "O";
	ConsoleExt::goToCoordinates(posicion.x, posicion.y + 1);
	cout << "/|\\";
	ConsoleExt::goToCoordinates(posicion.x, posicion.y + 2);
	cout << "/ \\";
}

#include "maniqui.h"

#include <iostream>

#include "mgtv_library.h"

using namespace std;
using namespace mgtv_library::console;


Maniqui::Maniqui(int vida)
{
	this->vida = vida;

	posicion = {};
}
Maniqui::~Maniqui()
{
	ConsoleExt::writeDestructionMessage(GENDER::MASCULINE, "maniqui", 2);
}


void Maniqui::setPosicion(int x, int y)
{
	posicion = { x, y };
}

bool Maniqui::estaVivo()
{
	return vida > 0;
}

void Maniqui::recibirDanio(int danio)
{
	vida >= danio ? vida -= danio : vida = 0;
}

void Maniqui::draw()
{
	if (estaVivo())
	{
		ConsoleExt::goToCoordinates(posicion.x + 1, posicion.y);
		cout << "0";
		ConsoleExt::goToCoordinates(posicion.x, posicion.y + 1);
		cout << "-|-";
	}

	ConsoleExt::goToCoordinates(posicion.x + 1, posicion.y + 2);
	cout << "|";
	ConsoleExt::goToCoordinates(posicion.x, posicion.y + 3);
	cout << "___";
}

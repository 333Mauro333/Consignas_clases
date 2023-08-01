#include "piedra.h"

#include <iostream>


Piedra::Piedra(string tamanio, string color)
{
	this->tamanio = tamanio;
	this->color = color;
}
Piedra::~Piedra()
{
	cout << "La piedra " << tamanio << " de color " << color << " fue liberada de la memoria." << endl << endl;
}


string Piedra::getTamanio()
{
	return tamanio;
}
string Piedra::getColor()
{
	return color;
}

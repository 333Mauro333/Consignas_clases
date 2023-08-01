#include "espada.h"

#include <iostream>


Espada::Espada(string material, int danio)
{
	this->material = material;
	this->danio = danio;
}
Espada::~Espada()
{
	cout << "La espada de material " << material << " y " << danio << " de danio fue liberada de la memoria." << endl << endl;
}


string Espada::getMaterial()
{
	return material;
}
int Espada::getDanio()
{
	return danio;
}

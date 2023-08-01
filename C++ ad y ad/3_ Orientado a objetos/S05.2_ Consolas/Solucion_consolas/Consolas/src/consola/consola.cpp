#include "consola.h"

#include <iostream>

using namespace std;


Consola::Consola()
{
	volumen = 100;
	brillo = 100;
}
Consola::~Consola()
{
	cout << "La consola ha sido liberada de la memoria." << endl << endl;
}


int Consola::getVolumen()
{
	return volumen;
}
int Consola::getBrillo()
{
	return brillo;
}

void Consola::setVolumen(int volumen)
{
	this->volumen = volumen;
}
void Consola::setBrillo(int brillo)
{
	this->brillo = brillo;
}

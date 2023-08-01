#include "arbol.h"

#include <iostream>


Arbol::Arbol(float altura, string cantidadDeHojas)
{
	this->altura = altura;
	this->cantidadDeHojas = cantidadDeHojas;
}
Arbol::~Arbol()
{
	cout << "El arbol con " << altura << " m. de altura y " << cantidadDeHojas << " hojas fue liberado de la memoria." << endl << endl;
}


float Arbol::getAltura()
{
	return altura;
}
string Arbol::getCantidadDeHojas()
{
	return cantidadDeHojas;
}

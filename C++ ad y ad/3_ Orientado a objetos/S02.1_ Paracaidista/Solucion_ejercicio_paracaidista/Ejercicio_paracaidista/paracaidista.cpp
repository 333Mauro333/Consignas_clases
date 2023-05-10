#include "paracaidista.h"


Paracaidista::Paracaidista()
{
	nombre = "";
	edad = 0;
	terrenoDondeCaer = "";
}
Paracaidista::~Paracaidista()
{
	cout << "El paracaidista " << nombre << " ha sido liberado de la memoria.\n\n";
}


string Paracaidista::getNombre()
{
	return nombre;
}
int Paracaidista::getEdad()
{
	return edad;
}
string Paracaidista::getTerrenoDondeCaer()
{
	return terrenoDondeCaer;
}

void Paracaidista::setNombre(string nombre)
{
	this->nombre = nombre;
}
void Paracaidista::setEdad(int edad)
{
	this->edad = edad;
}
void Paracaidista::setTerrenoDondeCaer(string terrenoDondeCaer)
{
	this->terrenoDondeCaer = terrenoDondeCaer;
}

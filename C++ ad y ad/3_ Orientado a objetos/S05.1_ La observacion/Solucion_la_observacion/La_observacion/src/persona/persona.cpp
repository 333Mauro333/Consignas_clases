#include "persona.h"

#include <iostream>

using namespace std;


Persona::Persona(string nombre)
{
	this->nombre = nombre;
}
Persona::~Persona()
{
	cout << "La persona con el nombre " << nombre << " fue liberada de la memoria." << endl << endl;
}


void Persona::observar(Arbol* arbol)
{
	cout << nombre << " ve un arbol con una altura de " << arbol->getAltura() << " m. Cantidad de hojas: " << arbol->getCantidadDeHojas() << "." << endl;
}
void Persona::observar(Piedra* piedra)
{
	cout << nombre << " observa una piedra. Su color: " << piedra->getColor() << ". Su tamanio: " << piedra->getTamanio() << "." << endl;
}
void Persona::observar(Nube* nube)
{
	cout << nombre << " mira a una nube en el cielo. Su color: " << nube->getColor() << "." << endl;
}

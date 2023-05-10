#include "personaje.h"


Personaje::Personaje(string nombre, int numero)
{
	this->nombre = nombre;
	this->numero = numero;
}
Personaje::~Personaje()
{
	cout << "El personaje " << nombre << " ha sido liberado de la memoria.\n\n";
}


void Personaje::presentarse()
{
	cout << "Hola! Me llamo " << nombre << "! Participo en la solucion de este ejercicio.\n";
}
void Personaje::decirNumeroGuardado()
{
	cout << "El numero guardado de " << nombre << " es " << numero << ".\n";
}
void Personaje::despedirse()
{
	cout << nombre << " se despide. Hasta luego!\n";
}

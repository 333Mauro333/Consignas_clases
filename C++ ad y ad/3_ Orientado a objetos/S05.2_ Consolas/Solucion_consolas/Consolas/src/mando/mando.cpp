#include "mando.h"

#include <iostream>
#include <cstddef>

using namespace std;


Mando::Mando()
{
	consola = NULL;
}
Mando::~Mando()
{
	cout << "El mando fue liberado de la memoria." << endl << endl;
}


void Mando::cambiarVolumenConsola(int volumen)
{
	consola->setVolumen(volumen);
}
void Mando::cambiarBrilloConsola(int brillo)
{
	consola->setBrillo(brillo);
}

void Mando::conectarALaConsola(Consola* consola)
{
	this->consola = consola;
}
void Mando::desconectar()
{
	consola = NULL;
}

bool Mando::estaConectado()
{
	return consola != NULL;
}

Consola* Mando::getConsola()
{
	return consola;
}

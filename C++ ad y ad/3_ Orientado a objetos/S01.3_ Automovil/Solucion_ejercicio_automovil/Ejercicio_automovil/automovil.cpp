#include "automovil.h"


Automovil::Automovil(string color)
{
	this->color = color;

	estaPrendido = false;
	estaEnMovimiento = false;
}
Automovil::~Automovil()
{
	cout << "El auto " << color << " fue liberado de la memoria.\n\n";
}


void Automovil::prender()
{
	if (!estaPrendido)
	{
		estaPrendido = true;

		cout << "El auto se prendio. Esta listo para empezar a andar!\n";
	}
	else
	{
		cout << "El auto ya esta prendido.\n";
	}
}
void Automovil::apagar()
{
	if (estaPrendido)
	{
		if (estaEnMovimiento)
		{
			cout << "El auto debe estar detenido para poder apagarse.\n";
		}
		else
		{
			estaPrendido = false;

			cout << "El auto apago sus motores.\n";
		}
	}
	else
	{
		cout << "El auto ya esta apagado.\n";
	}
}

void Automovil::acelerar()
{
	if (estaPrendido)
	{
		if (!estaEnMovimiento)
		{
			estaEnMovimiento = true;

			cout << "El auto acelero y empezo a recorrer su camino.\n";
		}
		else
		{
			cout << "El auto ya acelero!\n";
		}
	}
	else
	{
		cout << "Para acelerar, el auto debe prenderse.\n";
	}
}
void Automovil::frenar()
{
	if (estaPrendido)
	{
		if (estaEnMovimiento)
		{
			estaEnMovimiento = false;

			cout << "El auto detuvo su marcha lentamente hasta quedarse quieto.\n";
		}
		else
		{
			cout << "El auto ya esta quieto.\n";
		}
	}
	else
	{
		cout << "Para poder frenar, el auto debe estar prendido y en marcha.\n";
	}
}

void Automovil::mostrarDatos()
{
	cout << "Color del auto: " << color << ".\n";
	cout << "Estado del auto: ";
	
	if (estaPrendido)
	{
		cout << "Prendido y ";

		if (estaEnMovimiento)
		{
			cout << "andando.\n";
		}
		else
		{
			cout << "quieto.\n";
		}
	}
	else
	{
		cout << "Apagado.\n";
	}
}

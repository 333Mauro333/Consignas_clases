#include "corredor.h"


Corredor::Corredor(string nombre, float velocidadMax)
{
	this->nombre = nombre;
	this->velocidadMax = velocidadMax;

	tieneEnergia = true;
}
Corredor::~Corredor()
{
	cout << "El corredor " << nombre << " fue liberado de la memoria.\n\n";
}


void Corredor::correr()
{
	if (tieneEnergia)
	{
		tieneEnergia = false;

		cout << nombre << " corrio con todas sus fuerzas, alcanzando una velocidad de " << velocidadMax << ".\n";
	}
	else
	{
		cout << nombre << " no tiene energia.\n";
	}
}
void Corredor::descansar()
{
	if (!tieneEnergia)
	{
		tieneEnergia = true;

		cout << nombre << " ha descansado!\n";
	}
	else
	{
		cout << nombre << " ya cuenta con energia!\n";
	}
}

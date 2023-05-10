#pragma once

#include <iostream>

using namespace std;


class Corredor
{
public:
	Corredor(string nombre, float velocidadMax);
	~Corredor();

	void correr();
	void descansar();

private:
	string nombre;
	float velocidadMax;
	bool tieneEnergia;

};

#pragma once

#include <string>

using namespace std;


class Arbol
{
public:
	Arbol(float altura, string cantidadDeHojas);
	~Arbol();

	float getAltura();
	string getCantidadDeHojas();

private:
	float altura;
	string cantidadDeHojas;
};

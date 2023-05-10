#pragma once

#include <iostream>

using namespace std;


class Personaje
{
public:
	Personaje(string nombre, int numero);
	~Personaje();

	void presentarse();
	void decirNumeroGuardado();
	void despedirse();

private:
	string nombre;
	int numero;

};

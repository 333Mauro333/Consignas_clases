#pragma once

#include <iostream>

using namespace std;


class Paracaidista
{
public:
	Paracaidista();
	~Paracaidista();

	string getNombre();
	int getEdad();
	string getTerrenoDondeCaer();

	void setNombre(string nombre);
	void setEdad(int edad);
	void setTerrenoDondeCaer(string terrenoDondeCaer);

private:
	string nombre;
	int edad;
	string terrenoDondeCaer;

};

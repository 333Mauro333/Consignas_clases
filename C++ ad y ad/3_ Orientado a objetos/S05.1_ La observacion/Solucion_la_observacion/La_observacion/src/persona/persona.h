#pragma once

#include <string>

#include "arbol/arbol.h"
#include "piedra/piedra.h"
#include "nube/nube.h"

using namespace std;


class Persona
{
public:
	Persona(string nombre);
	~Persona();

	void observar(Arbol* arbol);
	void observar(Piedra* piedra);
	void observar(Nube* nube);

private:
	string nombre;
};

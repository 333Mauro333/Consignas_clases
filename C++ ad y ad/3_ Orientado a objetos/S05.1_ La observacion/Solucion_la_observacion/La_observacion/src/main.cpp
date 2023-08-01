#include <iostream>

#include "persona/persona.h"
#include "arbol/arbol.h"
#include "piedra/piedra.h"
#include "nube/nube.h"

using namespace std;


int main()
{
	Persona* persona = new Persona("Mauro");
	Arbol* arbol = new Arbol(7.25f, "Muchas");
	Piedra* piedra = new Piedra("Mediano", "Verde");
	Nube* nube = new Nube("Blanco");


	persona->observar(arbol);
	persona->observar(piedra);
	persona->observar(nube);

	cout << endl;

	delete persona;
	delete arbol;
	delete piedra;
	delete nube;

	system("pause");


	return 0;
}

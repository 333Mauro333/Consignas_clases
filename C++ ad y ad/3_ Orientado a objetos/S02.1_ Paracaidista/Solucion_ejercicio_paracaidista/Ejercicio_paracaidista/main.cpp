#include <iostream>

#include "paracaidista.h"

using namespace std;


int main()
{
	Paracaidista* paracaidista = new Paracaidista();

	string nombreParacaidista = "";
	int edadParacaidista = 0;
	string terrenoParacaidista = "";


	cout << "Ingrese el nombre del paracaidista: ";
	cin >> nombreParacaidista;

	cout << "Ingrese la edad del paracaidista: ";
	cin >> edadParacaidista;

	cout << "Ingrese el terreno donde va a caer: ";
	cin >> terrenoParacaidista;

	paracaidista->setNombre(nombreParacaidista);
	paracaidista->setEdad(edadParacaidista);
	paracaidista->setTerrenoDondeCaer(terrenoParacaidista);

	cout << "\n\nDatos del paracaidista:\n\n";
	cout << "Nombre: " << paracaidista->getNombre() << ".\n";
	cout << "Edad: " << paracaidista->getEdad() << " anios.\n";
	cout << "Terreno donde va a caer: " << paracaidista->getTerrenoDondeCaer() << ".\n\n";

	delete paracaidista;


	return 0;
}

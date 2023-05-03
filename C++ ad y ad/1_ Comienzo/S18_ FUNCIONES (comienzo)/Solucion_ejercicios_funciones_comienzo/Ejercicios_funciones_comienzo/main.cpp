#include <iostream>

using namespace std;


void mostrarUnMensaje();

void mostrarMenuDePremio();
void mostrarPremio1();
void mostrarPremio2();

int main()
{
	int opcion = 0;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	mostrarUnMensaje();

	cout << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	mostrarMenuDePremio();

	do
	{
		cout << "Opcion elegida: ";
		cin >> opcion;

	} while (opcion < 1 || opcion > 2);

	cout << endl;

	if (opcion == 1)
	{
		mostrarPremio1();
	}
	else
	{
		mostrarPremio2();
	}

	cout << endl;



	return 0;
}

void mostrarUnMensaje()
{
	cout << "Este mensaje es mostrado mediante una funcion.\n";
}

void mostrarMenuDePremio()
{
	cout << "Ganaste un premio! Reclamalo eligiendo una puerta a continuacion:\n\n";
	cout << "1. PUERTA ROJA\n";
	cout << "2. PUERTA AZUL\n\n";
}
void mostrarPremio1()
{
	cout << "Has recibido un traje a prueba de fuego!\n\n";
}
void mostrarPremio2()
{
	cout << "Has recibido un respirador! Podras mantenerte un tiempo prolongado bajo el agua!\n\n";
}

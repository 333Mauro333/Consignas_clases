#include <iostream>

using namespace std;


int main()
{
	int anio = 0;

	int numero = 0;
	char opcionChar = '\0';



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese un anio: ";
	cin >> anio;

	if (anio % 4 == 0)
	{
		cout << "El anio es bisiesto";
	}
	else
	{
		cout << "Se ingreso un anio no bisiesto";
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "     1. JUGAR" << endl;
	cout << "    2. OPCIONES" << endl;
	cout << "     3. SALIR" << endl << endl;

	cout << "Ingrese la opcion deseada: ";
	cin >> numero;

	if (numero == 1)
	{
		cout << "Cargando el juego...";
	}
	else if (numero == 2)
	{
		cout << "Se mostraran las opciones del juego.";
	}
	else if (numero == 3)
	{
		cout << "Saliendo del juego. Gracias por jugar!";
	}
	else
	{
		cout << "Ingresaste una opcion no valida.";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Desea salir del juego? Responda con y/n: ";
	cin >> opcionChar;

	cout << endl;

	if (opcionChar == 'Y' || opcionChar == 'y')
	{
		cout << "Saliendo de juego. Gracias por jugar!";
	}
	else if (opcionChar == 'N' || opcionChar == 'n')
	{
		cout << "Volviendo al menu principal...";
	}
	else
	{
		cout << "Opcion no valida.";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Ingrese un numero (debe estar entre 5 y 20 o entre 25 y 40): ";
	cin >> numero;

	cout << endl;

	if (numero >= 5 && numero <= 20)
	{
		cout << "El numero se encuenra entre 5 y 20";
	}
	else if (numero >= 25 && numero <= 40)
	{
		cout << "El numero se encuenra entre 25 y 40";
	}
	else
	{
		cout << "El numero no se encuentra dentro de ningun limite";
	}

	cout << "." << endl << endl << endl;



	return 0;
}

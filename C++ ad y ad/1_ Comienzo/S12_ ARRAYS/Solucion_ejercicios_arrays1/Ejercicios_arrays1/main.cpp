#include <iostream>

using namespace std;


int main()
{
	const int tamanio1 = 5;
	int arreglo1[tamanio1] = { 2, 4, 7, 9, 10 };

	const int tamanio3 = 10;
	int arreglo3[tamanio3] = {};

	const int tamanio4 = 10;
	int arreglo4[tamanio4] = {};

	const int tamanio5 = 5;
	int arreglo5[tamanio5] = {};

	int numero = 0;


	srand(time(NULL));



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	for (int i = 0; i < tamanio1; i++)
	{
		cout << arreglo1[i] << " ";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	for (int i = tamanio1 - 1; i >= 0; i--)
	{
		cout << arreglo1[i] << " ";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero;
	cout << endl;

	for (int i = 0; i < tamanio3; i++)
	{
		arreglo3[i] = numero;
	}

	for (int i = 0; i < tamanio3; i++)
	{
		cout << "Posicion " << i + 1 << " del arreglo: " << arreglo3[i] << endl;
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	for (int i = 0; i < tamanio4; i++)
	{
		arreglo4[i] = rand() % 51;
	}

	for (int i = 0; i < tamanio4; i++)
	{
		cout << arreglo4[i] << " ";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 5 ---" << endl << endl;

	for (int i = 0; i < tamanio5; i++)
	{
		cout << "Ingrese el numero " << i + 1 << " del arreglo: ";
		cin >> numero;

		arreglo5[i] = numero;
	}

	cout << endl;

	for (int i = 0; i < tamanio5; i++)
	{
		cout << arreglo5[i] << " ";
	}

	cout << endl << endl << endl;



	return 0;
}

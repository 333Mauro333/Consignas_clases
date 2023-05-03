#include <iostream>

using namespace std;


int main()
{
	const int tamanio1 = 10;
	int arreglo1[tamanio1] = { 5, 10, 10, 15, 20, 15, 20, 15, 20, 20 };
	int vecesEncontrado = 0;

	const int tamanio2 = 10;
	float arreglo2[tamanio2] = {};

	const int tamanio3 = 10;
	int arreglo3[tamanio3] = {};
	int posicion = 0;

	const int tamanio4 = 10;
	int arreglo4[tamanio4] = { 10, 5, 3, 20, 45, 50, 85, 1, 77, 50 };
	int numeroMasGrande = arreglo4[0];
	int numeroMasChico = arreglo4[0];

	const int tamanio5 = 5;
	float arreglo5[tamanio5] = {};
	float promedio = 0.0f;

	int numero = 0;


	srand(time(NULL));



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Numeros del arreglo: ";

	for (int i = 0; i < tamanio1; i++)
	{
		cout << arreglo1[i] << " ";
	}

	cout << endl << endl;
	cout << "Ingrese un numero: ";
	cin >> numero;

	for (int i = 0; i < tamanio1; i++)
	{
		if (numero == arreglo1[i])
		{
			vecesEncontrado++;
		}
	}

	if (vecesEncontrado == 1)
	{
		cout << "El numero se encontro una vez en el arreglo.";
	}
	else if (vecesEncontrado > 1)
	{
		cout << "El numero se encontro " << vecesEncontrado << " veces en el arreglo.";
	}
	else
	{
		cout << "El numero no se encontro en el arreglo.";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	for (int i = 0; i < tamanio2; i++)
	{
		arreglo2[i] = rand() % 10001;
	}

	for (int i = 0; i < tamanio2; i++)
	{
		arreglo2[i] /= 100.0f;
	}

	for (int i = 0; i < tamanio2; i++)
	{
		cout << "Numero " << i + 1 << ": " << arreglo2[i] << endl;
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	for (int i = 0; i < tamanio3; i++)
	{
		arreglo3[i] = rand() % 100 + 1;
	}

	cout << "Numeros del arreglo: ";

	for (int i = 0; i < tamanio3; i++)
	{
		cout << arreglo3[i] << " ";
	}

	cout << endl << endl;
	cout << "Ingrese un numero: ";
	cin >> numero;

	do
	{
		cout << "Ingrese un numero de posicion (entre 1 y " << tamanio3 << "): ";
		cin >> posicion;

	} while (posicion < 1 || posicion > tamanio3);

	arreglo3[posicion - 1] = numero;

	cout << endl;
	cout << "Numeros del arreglo: ";

	for (int i = 0; i < tamanio3; i++)
	{
		cout << arreglo3[i] << " ";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Numeros del arreglo: ";

	for (int i = 0; i < tamanio4; i++)
	{
		cout << arreglo4[i] << " ";
	}

	cout << endl << endl;

	for (int i = 0; i < tamanio4; i++)
	{
		if (arreglo4[i] < numeroMasChico)
		{
			numeroMasChico = arreglo4[i];
		}

		if (arreglo4[i] > numeroMasGrande)
		{
			numeroMasGrande = arreglo4[i];
		}
	}

	cout << "El numero mas grande del arreglo es " << numeroMasGrande << endl;
	cout << "El numero mas chico del arreglo es " << numeroMasChico << endl << endl << endl;



	cout << "--- EJERCICIO 5 ---" << endl << endl;

	for (int i = 0; i < tamanio5; i++)
	{
		cout << "Ingrese el numero " << i + 1 << " de " << tamanio5 << " del arreglo: ";
		cin >> arreglo5[i];
	}

	for (int i = 0; i < tamanio5; i++)
	{
		promedio += arreglo5[i];
	}

	promedio /= tamanio5;

	cout << "\nEl promedio da " << promedio << endl << endl << endl;



	return 0;
}

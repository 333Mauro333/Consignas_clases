#include <iostream>

using namespace std;


int main()
{
	const int tamanio1 = 5;
	int arreglo1[tamanio1] = { 3, 10, 25, 4, 8 };
	bool estaDentroDelArray = false;

	const int tamanio2 = 10;
	int arreglo2[tamanio2] = { 2, 7, 18, 46, 35, 25, 72, 30, 88, 51 };

	const int tamanio3 = 10;
	int arreglo3[tamanio3] = {};

	const int tamanio4 = 10;
	int arreglo4[tamanio4] = { 25, 45, 30, 1, 22, 51, 50, 30, 99, 75 };

	const int tamanio5 = 5;
	int arreglo5[tamanio5] = { 3, 48, 15, 123, 45 };

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
		if (arreglo1[i] == numero)
		{
			estaDentroDelArray = true;
			break;
		}
	}

	if (estaDentroDelArray)
	{
		cout << "El numero se encuentra en el arreglo. ";
	}
	else
	{
		cout << "El numero no esta en el arreglo. ";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Numeros del arreglo: ";

	for (int i = 0; i < tamanio2; i++)
	{
		cout << arreglo2[i] << " ";
	}

	cout << endl << endl;
	cout << "Numeros impares: ";

	for (int i = 0; i < tamanio2; i++)
	{
		if (arreglo2[i] % 2 == 1)
		{
			cout << arreglo2[i] << " ";
		}
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	for (int i = 0; i < tamanio3; i++)
	{
		arreglo3[i] = rand() % (50 - 20 + 1) + 20;
	}

	cout << "Numeros del arreglo: ";

	for (int i = 0; i < tamanio3; i++)
	{
		cout << arreglo3[i] << " ";
	}

	cout << endl << endl;
	cout << "Numeros con indice par: ";

	for (int i = 0; i < tamanio3; i++)
	{
		if (i % 2 == 0)
		{
			cout << arreglo3[i] << " ";
		}
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Numeros del arreglo: ";

	for (int i = 0; i < tamanio4; i++)
	{
		cout << arreglo4[i] << " ";
	}

	cout << endl << endl;

	do
	{
		cout << "Ingrese 1 para mostrar los numeros pares." << endl;
		cout << "Ingrese 2 para mostrar los numeros impares." << endl << endl;
		cout << "Opcion ingresada: ";
		cin >> numero;

	} while (numero < 1 || numero > 2);

	cout << endl;

	if (numero == 1)
	{
		cout << "Numeros pares del arreglo: ";
	}
	else
	{
		cout << "Numeros impares del arreglo: ";
	}

	for (int i = 0; i < tamanio4; i++)
	{
		if (numero == 1 && arreglo4[i] % 2 == 0)
		{
			cout << arreglo4[i] << " ";
		}
		else if (numero == 2 && arreglo4[i] % 2 == 1)
		{
			cout << arreglo4[i] << " ";
		}
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 5 ---" << endl << endl;

	cout << "Numeros del arreglo: ";

	for (int i = 0; i < tamanio5; i++)
	{
		cout << arreglo5[i] << " ";
	}

	cout << endl << endl;

	do
	{
		cout << "Ingrese la posicion del numero que desea que se escriba (entre 1 y " << tamanio5 << "): ";
		cin >> numero;

	} while (numero < 1 || numero > tamanio5);

	cout << endl;

	cout << arreglo5[numero - 1];
	cout << endl << endl << endl;



	return 0;
}

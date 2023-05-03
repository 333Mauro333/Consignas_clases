#include <iostream>

using namespace std;


int main()
{
	int numero = 0;

	int filas = 0;
	int columnas = 0;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero;
	cout << endl;

	for (int i = 0; i < numero; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "X";
		}

		cout << endl;
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Ingrese la cantidad de filas: ";
	cin >> filas;

	cout << "Ingrese la cantidad de columnas: ";
	cin >> columnas;
	cout << endl;

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			cout << "X";
		}

		cout << endl;
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese la cantidad de filas: ";
	cin >> filas;

	cout << "Ingrese la cantidad de columnas: ";
	cin >> columnas;
	cout << endl;

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (i % 2 == 0)
			{
				cout << "X";
			}
			else
			{
				cout << "O";
			}
		}

		cout << endl;
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Ingrese el tamanio del cuadrado: ";
	cin >> numero;
	cout << endl;

	for (int i = 0; i < numero; i++)
	{
		for (int j = 0; j < numero; j++)
		{
			if (i == j)
			{
				cout << "O";
			}
			else
			{
				cout << "X";
			}
		}

		cout << endl;
	}

	cout << endl << endl << endl;



	return 0;
}

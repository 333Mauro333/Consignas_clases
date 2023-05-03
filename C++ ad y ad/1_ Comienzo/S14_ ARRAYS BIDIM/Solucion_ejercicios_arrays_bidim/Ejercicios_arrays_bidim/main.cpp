#include <iostream>

using namespace std;


int main()
{
	const int filas1 = 3;
	const int columnas1 = 5;
	char arregloBidim1[filas1][columnas1] = { {'A', 'B', 'C', 'D', 'E'},
											  {'a', 'b', 'c', 'd', 'e'},
											  {'A', 'B', 'C', 'D', 'E'} };

	const int filas2 = 7;
	const int columnas2 = 3;
	int arregloBidim2[filas2][columnas2] = { { 0, 1, 0 },
											 { 1, 1, 0 },
											 { 0, 1, 0 },
											 { 0, 1, 0 },
											 { 0, 1, 0 },
											 { 0, 1, 0 },
											 { 1, 1, 1 } };

	const int filas3 = 7;
	const int columnas3 = 7;
	char arregloBidim3[filas3][columnas3] = { { 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
											  { 'X', '-', '-', '-', '-', 'X', 'X' },
											  { 'X', '-', 'X', '-', '-', '-', 'X' },
											  { 'X', '-', '-', '-', '-', '-', 'X' },
											  { 'X', '-', 'X', '-', '-', '-', 'X' },
											  { 'X', 'J', '-', '-', '-', 'X', 'X' },
											  { 'X', 'X', 'X', 'X', 'X', 'X', 'X' } };



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	for (int i = 0; i < filas1; i++)
	{
		for (int j = 0; j < columnas1; j++)
		{
			cout << arregloBidim1[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	for (int i = 0; i < filas2; i++)
	{
		for (int j = 0; j < columnas2; j++)
		{
			cout << arregloBidim2[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	for (int i = 0; i < filas3; i++)
	{
		for (int j = 0; j < columnas3; j++)
		{
			cout << arregloBidim3[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl << endl << endl;



	return 0;
}

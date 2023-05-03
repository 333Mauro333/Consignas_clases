#include <iostream>

using namespace std;


int main()
{
	const int filas1 = 5;
	const int columnas1 = 3;
	char arregloBidim1[filas1][columnas1] = { { 'O', 'O', 'O' },
											  { 'O', 'O', 'O' },
											  { 'O', 'O', 'O' },
											  { 'O', 'O', 'O' },
											  { 'O', 'O', 'O' } };
	int num = 0;

	const int filas2 = 7;
	const int columnas2 = 7;
	char arregloBidim2[filas2][columnas2] = { { 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
											  { 'X', '-', '-', '-', '-', '-', 'X' },
											  { 'X', '-', '-', '-', '-', '-', 'X' },
											  { 'X', '-', '-', '-', '-', '-', 'X' },
											  { 'X', '-', '-', '-', '-', '-', 'X' },
											  { 'X', '-', '-', '-', '-', '-', 'X' },
											  { 'X', 'X', 'X', 'X', 'X', 'X', 'X' } };
	int posicionX = 0;
	int posicionY = 0;

	const int filas3 = 9;
	const int columnas3 = 9;
	char arregloBidim3[filas3][columnas3] = { { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
											  { 'X', '-', '-', '-', '-', '-', '-', '-', 'X' },
											  { 'X', '-', '-', '?', '-', '?', '-', '?', 'X' },
											  { 'X', '-', '-', '-', '-', '-', '-', '-', 'X' },
											  { 'X', 'J', '-', '?', '-', '?', '-', '?', 'X' },
											  { 'X', '-', '-', '-', '-', '-', '-', '-', 'X' },
											  { 'X', '-', '-', '?', '-', '?', '-', '?', 'X' },
											  { 'X', '-', '-', '-', '-', '-', '-', '-', 'X' },
											  { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' } };
	char cofre = '$';
	char agujero = 'O';
	char puntosExtra = 'P';
	char tiempoExtra = 'T';


	srand(time(NULL));



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	// Se muestra el arreglo.
	for (int i = 0; i < filas1; i++)
	{
		for (int j = 0; j < columnas1; j++)
		{
			cout << arregloBidim1[i][j] << " ";
		}

		cout << endl;
	}

	// Se pide el dato.
	do
	{
		cout << "\nIngrese el numero de fila para trazar la linea: ";
		cin >> num;

	} while (num < 1 || num > filas1);

	cout << endl;

	// Se traza la línea.
	for (int i = 0; i < columnas1; i++)
	{
		arregloBidim1[num - 1][i] = 'X';
	}

	// Se vuelve a mostrar el arreglo.
	for (int i = 0; i < filas1; i++)
	{
		for (int j = 0; j < columnas1; j++)
		{
			cout << arregloBidim1[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	// Se muestra el minimapa.
	for (int i = 0; i < filas2; i++)
	{
		for (int j = 0; j < columnas2; j++)
		{
			cout << arregloBidim2[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;

	// Se ingresa la posición X del jugador. Su límite lo va a definir la cantidad de columnas que hayan.
	do
	{
		cout << "Ingrese la posicion X del jugador: ";
		cin >> posicionX;

	} while (posicionX <= 1 || posicionX >= columnas2);

	// Se ingresa la posición Y del jugador. Su límite lo va a definir la cantidad de filas que hayan.
	do
	{
		cout << "Ingrese la posicion Y del jugador: ";
		cin >> posicionY;

	} while (posicionY <= 1 || posicionY >= filas2);

	cout << endl;

	arregloBidim2[posicionY - 1][posicionX - 1] = 'J'; // Se asigna el jugador al mapa.

	// Se muestra el minimapa con el jugador incluido.
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

	// Se asignan los elementos random.
	for (int i = 0; i < filas3; i++)
	{
		for (int j = 0; j < columnas3; j++)
		{
			if (arregloBidim3[i][j] == '?')
			{
				switch (rand() % 4)
				{
				case 0:
					arregloBidim3[i][j] = cofre;
					break;

				case 1:
					arregloBidim3[i][j] = agujero;
					break;

				case 2:
					arregloBidim3[i][j] = puntosExtra;
					break;

				case 3:
					arregloBidim3[i][j] = tiempoExtra;
					break;
				}
			}
		}
	}

	// Se muestra el minimapa.
	for (int i = 0; i < filas3; i++)
	{
		for (int j = 0; j < columnas3; j++)
		{
			cout << arregloBidim3[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl << endl;



	return 0;
}

#include <iostream>

using namespace std;


int main()
{
	int numero1 = 0;
	int numero2 = 0;
	int numero3 = 0;

	int limMin = 0;
	int limMax = 0;


	srand(time(NULL));



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	numero1 = rand() % 5 + 1;
	numero2 = rand() % 5 + 1;
	numero3 = rand() % 5 + 1;

	cout << "Los tres numeros aleatorios son " << numero1 << ", " << numero2 << " y " << numero3 << "." << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	numero1 = rand() % (20 - 10 + 1) + 10;
	numero2 = rand() % (20 - 10 + 1) + 10;
	numero3 = rand() % (20 - 10 + 1) + 10;

	cout << "Los tres numeros aleatorios son " << numero1 << ", " << numero2 << " y " << numero3 << "." << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese el limite minimo: ";
	cin >> limMin;

	cout << "Ingrese el limite maximo: ";
	cin >> limMax;
	cout << endl;

	if (limMin > limMax)
	{
		int auxiliar = 0;

		auxiliar = limMin;
		limMin = limMax;
		limMax = auxiliar;
	}

	numero1 = rand() % (limMax - limMin + 1) + limMin;

	cout << "Numero generado: " << numero1 << "." << endl << endl << endl;



	return 0;
}

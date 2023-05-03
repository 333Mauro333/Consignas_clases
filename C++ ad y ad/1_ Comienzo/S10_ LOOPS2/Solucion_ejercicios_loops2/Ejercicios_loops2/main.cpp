#include <iostream>

using namespace std;


int main()
{
	int numero = 0;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero;
	cout << endl;

	for (int i = 1; i <= numero; i++)
	{
		cout << i << " ";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero;
	cout << endl;

	for (int i = 1; i <= numero; i *= 2)
	{
		cout << i << " ";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero;
	cout << endl;

	for (int i = 1; i < numero; i++)
	{
		cout << i << " ";
	}

	for (int i = numero; i > 0; i--)
	{
		cout << i << " ";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	for (int i = 0; i <= 50; i++)
	{
		if (i % 2 == 0)
		{
			cout << i << ": Es par." << endl;
		}
		else
		{
			cout << i << ": Es impar." << endl;
		}
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 5 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero;
	cout << endl;

	for (int i = 0; i <= numero; i++)
	{
		cout << i << " - " << numero - i << endl;
	}

	cout << endl << endl << endl;



	return 0;
}

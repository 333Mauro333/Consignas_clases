#include <iostream>

using namespace std;


int main()
{
	int numero1 = 0;
	int numero2 = 0;

	int numeroGuardado = 15;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero1;

	if (numero1 > 0)
	{
		cout << "El numero es positivo";
	}
	else if (numero1 < 0)
	{
		cout << "El numero es negativo";
	}
	else
	{
		cout << "El numero es cero";
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Numero guardado: " << numeroGuardado << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero1;

	if (numero1 == numeroGuardado)
	{
		cout << "Los dos numeros son iguales";
	}
	else
	{
		cout << "El numero ingresado es distinto al numero guardado";
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese el primer numero: ";
	cin >> numero1;
	cout << "Ingrese el segundo numero: ";
	cin >> numero2;

	if (numero1 > numero2)
	{
		cout << numero1 << " es mas grande que " << numero2;
	}
	else if (numero2 > numero1)
	{
		cout << numero2 << " es mas grande que " << numero1;
	}
	else
	{
		cout << "Los dos numeros son iguales";
	}

	cout << "." << endl << endl << endl;



	return 0;
}

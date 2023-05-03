#include <iostream>

using namespace std;


enum class VALIDEZ_NUMERO { NO_VALIDO, PRIMER_LIMITE, SEGUNDO_LIMITE };

int main()
{
	VALIDEZ_NUMERO validez = VALIDEZ_NUMERO::NO_VALIDO;

	int numero = 0;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Escala de numeros: " << endl << endl;

	while (numero < 10)
	{
		cout << numero << " ";
		numero++;
	}

	cout << endl;
	numero = 0;


	do
	{
		cout << numero << " ";
		numero++;

	} while (numero < 10);

	cout << endl;


	for (int i = 0; i < 10; i++)
	{
		cout << i << " ";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;


	cout << "Escala de numeros: " << endl << endl;

	numero = 1;

	while (numero <= 10)
	{
		cout << numero << " ";
		numero++;
	}

	cout << endl;
	numero = 1;


	do
	{
		cout << numero << " ";
		numero++;

	} while (numero <= 10);

	cout << endl;


	for (int i = 1; i <= 10; i++)
	{
		cout << i << " ";
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	do
	{
		cout << "Ingrese un numero entre 10 y 20: ";
		cin >> numero;

	} while (numero < 10 || numero > 20);

	cout << "Numero valido." << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	do
	{
		cout << "Ingrese un numero entre 5 y 10 o entre 30 y 40: ";
		cin >> numero;

		if (numero >= 5 && numero <= 10)
		{
			validez = VALIDEZ_NUMERO::PRIMER_LIMITE;
		}
		else if (numero >= 30 && numero <= 40)
		{
			validez = VALIDEZ_NUMERO::SEGUNDO_LIMITE;
		}
		else
		{
			validez = VALIDEZ_NUMERO::NO_VALIDO;
		}

	} while (validez == VALIDEZ_NUMERO::NO_VALIDO);

	switch (validez)
	{
	case VALIDEZ_NUMERO::PRIMER_LIMITE:
		cout << "El numero se encuentra dentro del primer limite.";
		break;

	case VALIDEZ_NUMERO::SEGUNDO_LIMITE:
		cout << "El numero se encuentra dentro del segundo limite.";
		break;

	case VALIDEZ_NUMERO::NO_VALIDO:
		cout << "Si llegaste hasta aca es porque modificaste el programa o porque lo rompiste.";
		break;
	}



	return 0;
}

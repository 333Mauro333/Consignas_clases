#include <iostream>

using namespace std;


int main()
{
	int numero1 = 0;
	int numero2 = 0;

	int jugador1X = 0;
	int jugador1Y = 0;
	int jugador2X = 0;
	int jugador2Y = 0;

	char letra = '\0';



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese el primer numero: ";
	cin >> numero1;
	cout << "Ingrese el segundo numero: ";
	cin >> numero2;

	cout << endl;

	if (numero1 % numero2 == 0)
	{
		cout << "El primer numero es divisible por el segundo";
	}
	else
	{
		cout << "No es divisible";
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero1;

	if (numero1 % 2 == 0)
	{
		cout << "El numero ingresado es par";
	}
	else
	{
		cout << "Es impar";
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero1;

	if (numero1 % 5 == 0)
	{
		cout << "El numero ingresado es multiplo de 5";
	}
	else
	{
		cout << "No es multiplo de 5";
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Ingrese la posicion X del jugador 1: ";
	cin >> jugador1X;
	cout << "Ingrese la posicion Y del jugador 1: ";
	cin >> jugador1Y;
	cout << "Ingrese la posicion X del jugador 2: ";
	cin >> jugador2X;
	cout << "Ingrese la posicion Y del jugador 2: ";
	cin >> jugador2Y;

	cout << endl;

	if (jugador1X == jugador2X && jugador1Y == jugador2Y)
	{
		cout << "Los jugadores se encuentran en la misma posicion";
	}
	else
	{
		cout << "Los jugadores se encuentran en posiciones diferentes";
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 5 ---" << endl << endl;

	cout << "Ingrese una letra: ";
	cin >> letra;

	cout << endl;

	if (letra == 'A' || letra == 'a' || letra == 'E' || letra == 'e' || letra == 'I' || letra == 'i' || letra == 'O' || letra == 'o' || letra == 'U' || letra == 'u')
	{
		cout << "La letra ingresada es una vocal";
	}
	else
	{
		cout << "La letra ingresada es una consonante";
	}

	cout << "." << endl << endl << endl;



	return 0;
}

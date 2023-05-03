#include <iostream>

using namespace std;


int obtenerElDoble(int numero);

int obtenerSuma(int num1, int num2);

int pedirNumero(int limMin, int limMax);

bool letraEsValida(char letra);

int main()
{
	int doble = 0;

	int suma = 0;

	int limiteMinimo = 10;
	int limiteMaximo = 20;

	char letra = '\0';

	int num = 0;
	int num2 = 0;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> num;

	doble = obtenerElDoble(num);

	cout << "El doble del numero ingresado es " << doble << "." << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> num;

	cout << "Ingrese otro numero: ";
	cin >> num2;

	cout << "El resultado de la suma es " << obtenerSuma(num, num2) << ".\n\n\n";



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	num = pedirNumero(limiteMinimo, limiteMaximo);

	cout << "Numero ingresado: " << num << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Desea salir del juego? Presione y/n: ";
	cin >> letra;

	if (letraEsValida(letra) == true)
	{
		cout << "La letra ingresada es valida.";
	}
	else
	{
		cout << "Letra no valida.";
	}

	cout << endl << endl << endl;



	return 0;
}

int obtenerElDoble(int numero)
{
	int doble = numero * 2;

	return doble;
}

int obtenerSuma(int num1, int num2)
{
	int suma = num1 + num2;

	return suma;
}

int pedirNumero(int limMin, int limMax)
{
	int num = 0;


	do
	{
		cout << "Ingrese un numero (entre "<< limMin << " y " << limMax << "): ";
		cin >> num;

	} while (num < limMin || num > limMax);

	return num;
}

bool letraEsValida(char letra)
{
	bool esValida = false;

	if (letra == 'Y' || letra == 'y' || letra == 'N' || letra == 'n')
	{
		esValida = true;
	}
	else
	{
		esValida = false;
	}

	return esValida;
}

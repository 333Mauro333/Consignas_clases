#include <iostream>

using namespace std;


void mostrarNumeroElevadoAlCuadrado(int num);

void mostrarDosNumeros(int num1, int num2);

void mostrarTipoDeNumero(int num);

void mostrarArea(int ancho, int alto);

int main()
{
	int numero = 0;
	int numero2 = 0;

	int ancho = 0;
	int alto = 0;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero;
	cout << endl;

	mostrarNumeroElevadoAlCuadrado(numero);

	cout << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero;

	cout << "Ingrese otro numero: ";
	cin >> numero2;
	cout << endl;

	mostrarDosNumeros(numero, numero2);

	cout << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero;
	cout << endl;

	mostrarTipoDeNumero(numero);

	cout << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Ingrese el ancho del rectangulo: ";
	cin >> ancho;

	cout << "Ingrese el alto: ";
	cin >> alto;
	cout << endl;

	mostrarArea(ancho, alto);

	cout << endl;



	return 0;
}

void mostrarNumeroElevadoAlCuadrado(int num)
{
	cout << "El numero elevado al cuadrado es " << num * num << ".\n\n";
}

void mostrarDosNumeros(int num1, int num2)
{
	cout << "El primer numero es " << num1 << ".\n";
	cout << "El segundo numero es " << num2 << ".\n\n";
}

void mostrarTipoDeNumero(int num)
{
	if (num > 0)
	{
		cout << "El numero es positivo.";
	}
	else if (num < 0)
	{
		cout << "El numero es negativo.";
	}
	else
	{
		cout << "El numero es cero.";
	}

	cout << endl << endl;
}

void mostrarArea(int ancho, int alto)
{
	cout << "El area del rectangulo es de " << ancho * alto << ".\n\n";
}

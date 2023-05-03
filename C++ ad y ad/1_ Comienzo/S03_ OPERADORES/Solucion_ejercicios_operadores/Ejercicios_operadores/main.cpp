#include <iostream>

using namespace std;


int main()
{
	float numero1 = 0.0f;
	float numero2 = 0.0f;

	float numero = 0.0f;

	float resultado = 0.0f;

	int primerNumero = 0;
	int segundoNumero = 0;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese el primer numero: ";
	cin >> numero1;
	cout << "Ingrese el segundo numero: ";
	cin >> numero2;

	cout << endl;
	cout << "Resultado de la suma: " << numero1 + numero2 << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero;

	cout << endl;
	cout << "Su doble es " << numero * 2 << endl;
	cout << "Su mitad es " << numero / 2 << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> numero;

	resultado = numero * numero * numero; // Un número elevado al cubo da lo mismo que multiplicándolo por
										  // sí mismo 2 veces.

	cout << endl;
	cout << numero << " elevado al cubo da " << resultado << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Ingrese el primer numero: ";
	cin >> numero1;
	cout << "Ingrese el segundo numero: ";
	cin >> numero2;

	cout << endl;
	cout << "La suma da " << numero1 + numero2 << "." << endl;
	cout << "La resta da " << numero1 - numero2 << "." << endl;
	cout << "La multiplicacion da " << numero1 * numero2 << "." << endl;
	cout << "La division da " << numero1 / numero2 << "." << endl << endl << endl;



	cout << "--- EJERCICIO 5 ---" << endl << endl;

	cout << "Ingrese el primer numero: ";
	cin >> primerNumero;
	cout << "Ingrese el segundo numero: ";
	cin >> segundoNumero;

	cout << endl;
	cout << "El resultado de la division da " << primerNumero / segundoNumero << endl;
	cout << "El resto de la division da " << primerNumero % segundoNumero << endl << endl << endl;



	return 0;
}

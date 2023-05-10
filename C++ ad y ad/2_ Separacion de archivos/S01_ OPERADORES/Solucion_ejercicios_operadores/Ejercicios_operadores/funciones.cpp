#include "funciones.h"

#include <iostream>

using namespace std;


// PASAR FUNCIONES A LOS .H
// // PASAR FUNCIONES A LOS .H
// // PASAR FUNCIONES A LOS .H
// // PASAR FUNCIONES A LOS .H
// // PASAR FUNCIONES A LOS .H
// // PASAR FUNCIONES A LOS .H
// // PASAR FUNCIONES A LOS .H
// 
// General.
void mostrarTituloEjercicio(int numeroEjercicio)
{
	cout << " ----- EJERCICIO " << numeroEjercicio << " -----\n\n";
}
int pedirNumero(string mensaje)
{
	int num = 0;

	cout << mensaje;
	cin >> num;

	return num;
}
void mostrarMensajeConNumero(string mensaje, int numero)
{
	cout << mensaje << numero << endl << endl;
}

// Ejercicio 1.
int obtenerSuma(int numero1, int numero2)
{
	return numero1 + numero2;
}

// Ejercicio 2.
int obtenerDoble(int numero)
{
	return numero * 2;
}
float obtenerMitad(int numero)
{
	return numero / 2.0f;
}

// Ejercicio 3.
int obtenerNumeroElevadoAlCubo(int numero)
{
	return numero * numero * numero;
}

// Ejercicio 4.
int obtenerResultado(float primerNumero, float segundoNumero, OPERACION operacion)
{
	switch (operacion)
	{
	case OPERACION::SUMA:
		return primerNumero + segundoNumero;
		break;

	case OPERACION::RESTA:
		return primerNumero - segundoNumero;
		break;

	case OPERACION::MULTIPLICACION:
		return primerNumero * segundoNumero;
		break;

	case OPERACION::DIVISION:
		return primerNumero / segundoNumero;
		break;

	case OPERACION::RESTO:
		return (int)primerNumero % (int)segundoNumero;
		break;
	}

	return 0;
}

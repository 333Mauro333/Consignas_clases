#include "funciones.h"

#include <iostream>

using namespace std;


// General.
void mostrarTituloEjercicio(int numeroEjercicio)
{
	cout << "  ----- EJERCICIO " << numeroEjercicio << " -----\n\n";
}

// Ejercicio 1.
void mostrarMensajePidiendoNumero()
{
	cout << "Ingrese un numero: ";
}
int pedirNumero()
{
	int num = 0;

	cin >> num;

	return num;
}
void mostrarMensajeNumeroIngresado(int numero)
{
	cout << "El numero ingresado es " << numero << ".\n\n";
}

// Ejercicio 2.
int pedirNumeroConMensaje(string mensaje)
{
	int num = 0;

	cout << mensaje;
	cin >> num;

	return num;
}
void mostrarFecha(int dia, int mes, int anio, string mensajeFecha)
{
	cout << mensajeFecha << dia << "/" << mes << "/" << anio << "\n\n";
}

// Ejercicio 3.
int pedirVida()
{
	int num = 0;

	cout << "Ingrese la vida: ";
	cin >> num;

	return num;
}
int pedirEscudo()
{
	int num = 0;

	cout << "Ingrese el escudo: ";
	cin >> num;

	return num;
}
void mostrarDatosDelJugador(int vida, int escudo)
{
	cout << "Vida: " << vida << ".\n";
	cout << "Escudo: " << escudo << ".\n\n";
}

// Ejercicio 4.
string pedirNombre()
{
	string nombre = "";

	cout << "Ingrese el nombre: ";
	cin >> nombre;

	return nombre;
}
int pedirEdad()
{
	int edad = 0;

	do
	{
		cout << "Ingrese la edad: ";
		cin >> edad;

	} while (edad < 0);

	return edad;
}
float pedirAltura()
{
	float altura = 0.0f;

	cout << "Ingrese la altura (en metros): ";
	cin >> altura;

	return altura;
}
void mostrarDatosPedidos(string nombre, int edad, float altura)
{
	cout << "Nombre: " << nombre << ".\n";
	cout << "Edad: " << edad << " anios.\n";
	cout << "Altura: " << altura << " m.\n\n";
}

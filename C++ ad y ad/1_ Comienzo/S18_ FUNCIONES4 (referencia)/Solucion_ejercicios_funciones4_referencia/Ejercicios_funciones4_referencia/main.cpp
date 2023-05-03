#include <iostream>

using namespace std;


enum class ORDENAMIENTO { MENOR_A_MAYOR = 1, MAYOR_A_MENOR };

struct POSICION
{
	int x;
	int y;
};

struct JUGADOR
{
	string nombre;
	int vida;
	POSICION posicion;
};

void initJugador(JUGADOR& jugador, string nombre, int vida, int posicionX, int posicionY);
void mostrarDatosDeJugador(JUGADOR jugador);

void setPosicion(JUGADOR& jugador, POSICION posicion);
void mostrarPosicionDelJugador(JUGADOR jugador);

void moverJugador(JUGADOR& jugador, POSICION posicion);

void intercambiar(int& num1, int& num2); // Intercambia los valores de las variables.
void mostrarValores(int arregloDeNumeros[], int tamanio);
void ordenarArray(int arregloDeNumeros[], int tamanio, ORDENAMIENTO tipoDeOrden);

int main()
{
	JUGADOR jugador1 = {};
	JUGADOR jugador2 = {};

	POSICION posicion = {};

	const int tamanio = 10;
	int numeros[tamanio] = {};
	ORDENAMIENTO tipoDeOrden = ORDENAMIENTO::MENOR_A_MAYOR;

	int numero = 0;


	srand(time(NULL));



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	initJugador(jugador1, "Nick", 100, 1, 1);
	initJugador(jugador2, "Tom", 100, 9, 1);

	mostrarDatosDeJugador(jugador1);
	mostrarDatosDeJugador(jugador2);

	cout << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	setPosicion(jugador1, { 3, 2 });
	setPosicion(jugador2, { 7, 2 });

	mostrarPosicionDelJugador(jugador1);
	mostrarPosicionDelJugador(jugador2);

	cout << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Cuantos pasos avanzara " << jugador1.nombre << " sobre X? ";
	cin >> posicion.x;

	cout << "Cuantos pasos avanzara " << jugador1.nombre << " sobre Y? ";
	cin >> posicion.y;
	cout << endl;

	moverJugador(jugador1, posicion);

	cout << "Cuantos pasos avanzara " << jugador2.nombre << " sobre X? ";
	cin >> posicion.x;

	cout << "Cuantos pasos avanzara " << jugador2.nombre << " sobre Y? ";
	cin >> posicion.y;
	cout << endl;

	moverJugador(jugador2, posicion);

	mostrarPosicionDelJugador(jugador1);
	mostrarPosicionDelJugador(jugador2);

	cout << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	for (int i = 0; i < tamanio; i++)
	{
		numeros[i] = rand() % 101; // Números entre 0 y 100.
	}

	mostrarValores(numeros, tamanio);

	cout << "Como desea ordenar el arreglo?\n\n";
	cout << "1. De menor a mayor.\n";
	cout << "2. De mayor a menor.\n\n";

	do
	{
		cout << "Opcion ingresada: ";
		cin >> numero;

	} while (numero < 1 || numero > 2);
	cout << endl;

	tipoDeOrden = (ORDENAMIENTO)numero;

	ordenarArray(numeros, tamanio, tipoDeOrden);

	mostrarValores(numeros, tamanio);

	cout << endl << endl << endl;



	return 0;
}

void initJugador(JUGADOR& jugador, string nombre, int vida, int posicionX, int posicionY)
{
	jugador.nombre = nombre;
	jugador.vida = vida;
	jugador.posicion = { posicionX, posicionY };
}
void mostrarDatosDeJugador(JUGADOR jugador)
{
	cout << "Nombre del jugador: " << jugador.nombre << ".\n";
	cout << "Vida: " << jugador.vida << ".\n";
	cout << "Posicion: (" << jugador.posicion.x << "; " << jugador.posicion.y << ").\n\n";
}

void setPosicion(JUGADOR& jugador, POSICION posicion)
{
	jugador.posicion = posicion;
}
void mostrarPosicionDelJugador(JUGADOR jugador)
{
	cout << "Posicion X de " << jugador.nombre << ": " << jugador.posicion.x << ".\n";
	cout << "Posicion Y de " << jugador.nombre << ": " << jugador.posicion.y << ".\n\n";
}

void moverJugador(JUGADOR& jugador, POSICION posicion)
{
	jugador.posicion.x += posicion.x;
	jugador.posicion.y += posicion.y;
}

void intercambiar(int& num1, int& num2)
{
	int aux = num1;

	num1 = num2;
	num2 = aux;
}
void mostrarValores(int arregloDeNumeros[], int tamanio)
{
	cout << "Valores del arreglo:\n\n";

	for (int i = 0; i < tamanio; i++)
	{
		cout << arregloDeNumeros[i] << " ";
	}

	cout << endl << endl;
}
void ordenarArray(int arregloDeNumeros[], int tamanio, ORDENAMIENTO tipoDeOrden)
{
	switch (tipoDeOrden)
	{
	case ORDENAMIENTO::MENOR_A_MAYOR:

		for (int i = 0; i < tamanio; i++)
		{
			for (int j = i + 1; j < tamanio; j++)
			{
				if (arregloDeNumeros[j] < arregloDeNumeros[i])
				{
					intercambiar(arregloDeNumeros[j], arregloDeNumeros[i]);
				}
			}
		}

		break;

	case ORDENAMIENTO::MAYOR_A_MENOR:

		for (int i = 0; i < tamanio; i++)
		{
			for (int j = i + 1; j < tamanio; j++)
			{
				if (arregloDeNumeros[j] > arregloDeNumeros[i])
				{
					intercambiar(arregloDeNumeros[j], arregloDeNumeros[i]);
				}
			}
		}

		break;
	}
}

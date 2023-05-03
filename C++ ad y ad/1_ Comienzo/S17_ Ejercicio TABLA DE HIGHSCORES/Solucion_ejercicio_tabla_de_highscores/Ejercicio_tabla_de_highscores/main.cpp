#include <iostream>
#include <string>

using namespace std;


struct JUGADOR
{
	string nombre;
	int puntaje;
};

int main()
{
	const int tamanio = 5;
	JUGADOR jugadores[tamanio] = {};

	const int puntajeMax = 99999;
	JUGADOR nuevoJugador = {};


	srand(time(NULL));


	// Se establecen los mismos valores que los que muestra la consigna.
	jugadores[0].nombre = "ABC";
	jugadores[1].nombre = "DEF";
	jugadores[2].nombre = "GHI";
	jugadores[3].nombre = "JKL";
	jugadores[4].nombre = "MTV";

	jugadores[0].puntaje = 6573;
	jugadores[1].puntaje = 1291;
	jugadores[2].puntaje = 361;
	jugadores[3].puntaje = 8727;
	jugadores[4].puntaje = 1538;

	// Se presentan los puntajes.
	cout << "Presentacion de la tabla:\n\n";
	
	for (int i = 0; i < tamanio; i++)
	{
		cout << i + 1 << ". " << jugadores[i].nombre << "     " << jugadores[i].puntaje << endl;
	}
	cout << endl;

	system("pause");
	cout << endl;

	// Se ordenan los puntajes.
	for (int i = 0; i < tamanio; i++)
	{
		for (int j = i + 1; j < tamanio; j++)
		{
			if (jugadores[j].puntaje > jugadores[i].puntaje)
			{
				JUGADOR jugadorAux = jugadores[i];

				jugadores[i] = jugadores[j];
				jugadores[j] = jugadorAux;
			}
		}
	}

	// Se vuelve a mostrar la tabla.
	cout << "Presentacion de la tabla ordenada:\n\n";

	for (int i = 0; i < tamanio; i++)
	{
		cout << i + 1 << ". " << jugadores[i].nombre << "     " << jugadores[i].puntaje << endl;
	}
	cout << endl;

	system("pause");

	do
	{
		system("cls");

		// Se muestra la tabla.
		for (int i = 0; i < tamanio; i++)
		{
			cout << i + 1 << ". " << jugadores[i].nombre << "     " << jugadores[i].puntaje << endl;
		}
		cout << endl;

		// Se ingresan las iniciales.
		do
		{
			cout << "Ingrese las 3 iniciales: ";
			getline(cin, nuevoJugador.nombre);

		} while (nuevoJugador.nombre.size() > 3);

		// Se ingresa el nuevo puntaje.
		do
		{
			cout << "Ingrese el nuevo puntaje: ";
			cin >> nuevoJugador.puntaje;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Se limpia el buffer para que no hayan problemas
																 // al hacer un getline después.
		} while (nuevoJugador.puntaje < 0 || nuevoJugador.puntaje > puntajeMax);

		// Se hace la revisión del puntaje más bajo al más alto.
		for (int i = tamanio - 1; i >= 0; i--)
		{
			// Si el nuevo puntaje supera el revisado...
			if (nuevoJugador.puntaje > jugadores[i].puntaje)
			{
				// Si se está revisando la última posición de la tabla...
				if (i == tamanio - 1)
				{
					// Se sobreescribe y se termina el ciclo acá.
					jugadores[i] = nuevoJugador;
				}
				else
				{
					// Se hace un intercambio de jugadores:
					// 1. El jugador superado se reemplaza por el nuevo y se pasa para abajo.
					JUGADOR jugadorAux = jugadores[i];

					jugadores[i] = nuevoJugador;
					jugadores[i + 1] = jugadorAux;
				}
			}
			else
			{
				// Nada que hacer. Se corta acá.
				break;
			}
		}

	} while (nuevoJugador.puntaje > 0);



	return 0;
}

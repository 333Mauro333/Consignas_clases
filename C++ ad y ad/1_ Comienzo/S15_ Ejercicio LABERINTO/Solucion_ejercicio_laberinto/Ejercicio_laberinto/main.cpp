#include <iostream>

using namespace std;


int main()
{
	char pared = 'X';
	char jgdor = 'J';
	char suelo = '-';
	char vctry = 'V';
	char agjro = 'O';

	const int filas = 10;
	const int columnas = 15;
	char mapa[filas][columnas] = { { pared, pared, pared, pared, pared, pared, pared, pared, pared, pared, pared, pared, pared, pared, pared, },
								   { pared, suelo, pared, suelo, suelo, suelo, suelo, suelo, suelo, suelo, pared, suelo, suelo, suelo, pared, },
								   { pared, suelo, pared, suelo, suelo, pared, suelo, agjro, agjro, suelo, pared, suelo, agjro, suelo, pared, },
								   { pared, suelo, pared, suelo, agjro, pared, suelo, suelo, suelo, suelo, suelo, suelo, pared, suelo, pared, },
								   { pared, suelo, pared, suelo, suelo, pared, pared, pared, pared, pared, suelo, suelo, pared, suelo, pared, },
								   { pared, suelo, pared, agjro, suelo, pared, suelo, suelo, suelo, pared, suelo, suelo, pared, suelo, pared, },
								   { pared, suelo, suelo, suelo, suelo, pared, agjro, pared, suelo, pared, pared, pared, pared, suelo, pared, },
								   { pared, suelo, pared, pared, pared, pared, pared, pared, suelo, suelo, suelo, pared, pared, suelo, pared, },
								   { pared, suelo, suelo, suelo, suelo, suelo, pared, suelo, suelo, pared, suelo, suelo, suelo, suelo, pared, },
								   { pared, pared, pared, pared, pared, pared, pared, vctry, pared, pared, pared, pared, pared, pared, pared, } };
	bool validacion = false;
	bool enJuego = true;
	bool elJugadorGano = false;
	int posicionX = 0;
	int posicionY = 0;
	char opcionMovimiento = '\0';



	// Se muestra el mapa.
	for (int i = 0; i < filas; i++)
	{
		// Mensajes para escribir la numeración de las filas.
		if (i + 1 < 10)
		{
			cout << "0";
		}

		cout << i + 1 << " ";

		for (int j = 0; j < columnas; j++)
		{
			cout << mapa[i][j] << " ";
		}

		cout << endl;
	}

	cout << "   ";

	// Numeración de las columnas por debajo del mapa.
	for (int i = 1; i <= columnas; i++)
	{
		cout << i;

		if (i < 10)
		{
			cout << " ";
		}
	}

	cout << endl << endl;

	// Ingreso de la posición del jugador en el mapa.
	do
	{
		do
		{
			cout << "Ingrese la posicion X del jugador (1 - " << columnas << "): ";
			cin >> posicionX;

		} while (posicionX < 1 || posicionX > columnas);

		do
		{
			cout << "Ingrese la posicion Y del jugador (1 - " << filas << "): ";
			cin >> posicionY;

		} while (posicionY < 1 || posicionY > filas);

		if (mapa[posicionY - 1][posicionX - 1] == suelo)
		{
			validacion = true;
			mapa[posicionY - 1][posicionX - 1] = jgdor;
			cout << "\nEl jugador fue posicionado correctamente. ";
		}
		else
		{
			cout << "\nEl jugador debe posicionarse sobre el piso. ";
		}

		system("pause");

	} while (!validacion);

	posicionX--; // Se le resta 1 a las posiciones para que, al verificar posiciones
	posicionY--; // dentro del mapa, no se le deba restar 1 todo el tiempo.


	// Comienzo del loop del juego.
	while (enJuego)
	{
		validacion = false;

		system("cls");

		// Se muestra el mapa.
		for (int i = 0; i < filas; i++)
		{
			// Mensajes para escribir la numeración de las filas.
			if (i + 1 < 10)
			{
				cout << "0";
			}

			cout << i + 1 << " ";

			for (int j = 0; j < columnas; j++)
			{
				cout << mapa[i][j] << " ";
			}

			cout << endl;
		}

		cout << "   ";

		// Numeración de las columnas por debajo del mapa.
		for (int i = 1; i <= columnas; i++)
		{
			cout << i;

			if (i < 10)
			{
				cout << " ";
			}
		}

		cout << endl << endl;


		// Se ingresa la dirección hacia la que se quiere mover al jugador.
		do
		{
			cout << "Para donde desea mover al jugador? (W: Arriba. S: Abajo. A: Izquierda. D: Derecha): ";
			cin >> opcionMovimiento;

		} while (opcionMovimiento != 'W' && opcionMovimiento != 'w' && opcionMovimiento != 'S' && opcionMovimiento != 's' && opcionMovimiento != 'A' && opcionMovimiento != 'a' && opcionMovimiento != 'D' && opcionMovimiento != 'd');
		cout << endl;

		// Se verifica si puede moverse.
		switch (opcionMovimiento)
		{
		case 'W':
		case 'w':
			// Si la casilla de destino no es una pared...
			if (mapa[posicionY - 1][posicionX] != pared)
			{
				validacion = true; // Se marca el movimiento como posible.

				// Verificaciones de victoria y derrota.
				if (mapa[posicionY - 1][posicionX] == vctry)
				{
					enJuego = false;
					elJugadorGano = true;
				}
				else if (mapa[posicionY - 1][posicionX] == agjro)
				{
					enJuego = false;
					elJugadorGano = false;
				}

				mapa[posicionY][posicionX] = suelo; // La vieja posición del jugador se despeja.
				mapa[posicionY - 1][posicionX] = jgdor; // Se dibuja al jugador a la dirección deseada.
				posicionY--; // Se aplica la nueva posición.
			}

			break;

		case 'S':
		case 's':
			// Si la casilla de destino no es una pared...
			if (mapa[posicionY + 1][posicionX] != pared)
			{
				validacion = true; // Se marca el movimiento como posible.

				// Verificaciones de victoria y derrota.
				if (mapa[posicionY + 1][posicionX] == vctry)
				{
					enJuego = false;
					elJugadorGano = true;
				}
				else if (mapa[posicionY + 1][posicionX] == agjro)
				{
					enJuego = false;
					elJugadorGano = false;
				}

				mapa[posicionY][posicionX] = suelo; // La vieja posición del jugador se despeja.
				mapa[posicionY + 1][posicionX] = jgdor; // Se dibuja al jugador a la dirección deseada.
				posicionY++; // Se aplica la nueva posición.
			}
			break;

		case 'A':
		case 'a':
			// Si la casilla de destino no es una pared...
			if (mapa[posicionY][posicionX - 1] != pared)
			{
				validacion = true; // Se marca el movimiento como posible.

				// Verificaciones de victoria y derrota.
				if (mapa[posicionY][posicionX - 1] == vctry)
				{
					enJuego = false;
					elJugadorGano = true;
				}
				else if (mapa[posicionY][posicionX - 1] == agjro)
				{
					enJuego = false;
					elJugadorGano = false;
				}

				mapa[posicionY][posicionX] = suelo; // La vieja posición del jugador se despeja.
				mapa[posicionY][posicionX - 1] = jgdor; // Se dibuja al jugador a la dirección deseada.
				posicionX--; // Se aplica la nueva posición.
			}
			break;

		case 'D':
		case 'd':
			// Si la casilla de destino no es una pared...
			if (mapa[posicionY][posicionX + 1] != pared)
			{
				validacion = true; // Se marca el movimiento como posible.

				// Verificaciones de victoria y derrota.
				if (mapa[posicionY][posicionX + 1] == vctry)
				{
					enJuego = false;
					elJugadorGano = true;
				}
				else if (mapa[posicionY][posicionX + 1] == agjro)
				{
					enJuego = false;
					elJugadorGano = false;
				}

				mapa[posicionY][posicionX] = suelo; // La vieja posición del jugador se despeja.
				mapa[posicionY][posicionX + 1] = jgdor; // Se dibuja al jugador a la dirección deseada.
				posicionX++; // Se aplica la nueva posición.
			}
			break;
		}

		if (!validacion)
		{
			cout << "El jugador es incapaz de pararse sobre una pared. ";
			system("pause");
		}
	}


	system("cls");

	// Se muestra el mapa.
	for (int i = 0; i < filas; i++)
	{
		// Mensajes para escribir la numeración de las filas.
		if (i + 1 < 10)
		{
			cout << "0";
		}

		cout << i + 1 << " ";

		for (int j = 0; j < columnas; j++)
		{
			cout << mapa[i][j] << " ";
		}

		cout << endl;
	}

	cout << "   ";

	// Numeración de las columnas por debajo del mapa.
	for (int i = 1; i <= columnas; i++)
	{
		cout << i;

		if (i < 10)
		{
			cout << " ";
		}
	}

	cout << endl << endl;

	// Muestra el mensaje final.
	if (elJugadorGano)
	{
		cout << "El jugador ha llegado a la casilla de victoria. Felicitaciones!" << endl;
	}
	else
	{
		cout << "El jugador se ha caido en un agujero. Perdiste!" << endl;
	}

	system("pause");
	


	return 0;
}

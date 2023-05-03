using System;


namespace Ejercicio_laberinto
{
	class Program
	{
		static void Main()
		{
			char pared = 'X';
			char jgdor = 'J';
			char suelo = '-';
			char vctry = 'V';
			char agjro = 'O';

			char[,] mapa = new char[10, 15] { { pared, pared, pared, pared, pared, pared, pared, pared, pared, pared, pared, pared, pared, pared, pared, },
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
			for (int i = 0; i < mapa.GetLength(0); i++)
			{
				// Mensajes para escribir la numeración de las filas.
				if (i + 1 < 10)
				{
					Console.Write("0");
				}

				Console.Write((i + 1) + " ");

				for (int j = 0; j < mapa.GetLength(1); j++)
				{
					Console.Write(mapa[i, j] + " ");
				}

				Console.WriteLine();
			}

			Console.Write("   ");

			// Numeración de las columnas por debajo del mapa.
			for (int i = 1; i <= mapa.GetLength(1); i++)
			{
				Console.Write(i);

				if (i < 10)
				{
					Console.Write(" ");
				}
			}

			Console.WriteLine("\n");

			do
			{
				do
				{
					Console.Write("Ingrese la posición X del jugador (1 - " + mapa.GetLength(1) + "): ");
					posicionX = int.Parse(Console.ReadLine());

				} while (posicionX < 1 || posicionX > mapa.GetLength(1));

				do
				{
					Console.Write("Ingrese la posición Y del jugador (1 - " + mapa.GetLength(0) + "): ");
					posicionY = int.Parse(Console.ReadLine());

				} while (posicionY < 1 || posicionY > mapa.GetLength(0));

				if (mapa[posicionY - 1, posicionX - 1] == suelo)
				{
					validacion = true;
					mapa[posicionY - 1, posicionX - 1] = jgdor;
					Console.Write("\nEl jugador fue posicionado correctamente. ");
				}
				else
				{
					Console.Write("\nEl jugador debe posicionarse sobre el piso. ");
				}

				Console.Write("Presione cualquier tecla para continuar... ");
				Console.ReadKey(true);
				Console.WriteLine();

			} while (!validacion);

			posicionX--; // Se le resta 1 a las posiciones para que, al verificar posiciones
			posicionY--; // dentro del mapa, no se le deba restar 1 todo el tiempo.


			// Comienzo del loop del juego.
			while (enJuego)
			{
				validacion = false;

				Console.Clear();

				// Se muestra el mapa.
				for (int i = 0; i < mapa.GetLength(0); i++)
				{
					// Mensajes para escribir la numeración de las filas.
					if (i + 1 < 10)
					{
						Console.Write("0");
					}

					Console.Write((i + 1) + " ");

					for (int j = 0; j < mapa.GetLength(1); j++)
					{
						Console.Write(mapa[i, j] + " ");
					}

					Console.WriteLine();
				}

				Console.Write("   ");

				// Numeración de las columnas por debajo del mapa.
				for (int i = 1; i <= mapa.GetLength(1); i++)
				{
					Console.Write(i);

					if (i < 10)
					{
						Console.Write(" ");
					}
				}

				Console.WriteLine("\n");


				// Se ingresa la dirección hacia la que se quiere mover al jugador.
				do
				{
					Console.Write("Para donde desea mover al jugador? (W: Arriba. S: Abajo. A: Izquierda. D: Derecha): ");
					opcionMovimiento = char.Parse(Console.ReadLine());

				} while (opcionMovimiento != 'W' && opcionMovimiento != 'w' && opcionMovimiento != 'S' && opcionMovimiento != 's' && opcionMovimiento != 'A' && opcionMovimiento != 'a' && opcionMovimiento != 'D' && opcionMovimiento != 'd');

				Console.WriteLine();

				// Se verifica si puede moverse.
				switch (opcionMovimiento)
				{
					case 'W':
					case 'w':
						// Si la casilla de destino no es una pared...
						if (mapa[posicionY - 1, posicionX] != pared)
						{
							validacion = true; // Se marca el movimiento como posible.

							// Verificaciones de victoria y derrota.
							if (mapa[posicionY - 1, posicionX] == vctry)
							{
								enJuego = false;
								elJugadorGano = true;
							}
							else if (mapa[posicionY - 1, posicionX] == agjro)
							{
								enJuego = false;
								elJugadorGano = false;
							}

							mapa[posicionY, posicionX] = suelo; // La vieja posición del jugador se despeja.
							mapa[posicionY - 1, posicionX] = jgdor; // Se dibuja al jugador a la dirección deseada.
							posicionY--; // Se aplica la nueva posición.
						}

						break;

					case 'S':
					case 's':
						// Si la casilla de destino no es una pared...
						if (mapa[posicionY + 1, posicionX] != pared)
						{
							validacion = true; // Se marca el movimiento como posible.

							// Verificaciones de victoria y derrota.
							if (mapa[posicionY + 1, posicionX] == vctry)
							{
								enJuego = false;
								elJugadorGano = true;
							}
							else if (mapa[posicionY + 1, posicionX] == agjro)
							{
								enJuego = false;
								elJugadorGano = false;
							}

							mapa[posicionY, posicionX] = suelo; // La vieja posición del jugador se despeja.
							mapa[posicionY + 1, posicionX] = jgdor; // Se dibuja al jugador a la dirección deseada.
							posicionY++; // Se aplica la nueva posición.
						}
						break;

					case 'A':
					case 'a':
						// Si la casilla de destino no es una pared...
						if (mapa[posicionY, posicionX - 1] != pared)
						{
							validacion = true; // Se marca el movimiento como posible.

							// Verificaciones de victoria y derrota.
							if (mapa[posicionY, posicionX - 1] == vctry)
							{
								enJuego = false;
								elJugadorGano = true;
							}
							else if (mapa[posicionY, posicionX - 1] == agjro)
							{
								enJuego = false;
								elJugadorGano = false;
							}

							mapa[posicionY, posicionX] = suelo; // La vieja posición del jugador se despeja.
							mapa[posicionY, posicionX - 1] = jgdor; // Se dibuja al jugador a la dirección deseada.
							posicionX--; // Se aplica la nueva posición.
						}
						break;

					case 'D':
					case 'd':
						// Si la casilla de destino no es una pared...
						if (mapa[posicionY, posicionX + 1] != pared)
						{
							validacion = true; // Se marca el movimiento como posible.

							// Verificaciones de victoria y derrota.
							if (mapa[posicionY, posicionX + 1] == vctry)
							{
								enJuego = false;
								elJugadorGano = true;
							}
							else if (mapa[posicionY, posicionX + 1] == agjro)
							{
								enJuego = false;
								elJugadorGano = false;
							}

							mapa[posicionY, posicionX] = suelo; // La vieja posición del jugador se despeja.
							mapa[posicionY, posicionX + 1] = jgdor; // Se dibuja al jugador a la dirección deseada.
							posicionX++; // Se aplica la nueva posición.
						}
						break;
				}

				if (!validacion)
				{
					Console.Write("El jugador es incapaz de pararse sobre una pared. Presione cualquier tecla para continuar... ");
					Console.ReadKey(true);
				}
			}

			Console.Clear();

			// Se muestra el mapa.
			for (int i = 0; i < mapa.GetLength(0); i++)
			{
				// Mensajes para escribir la numeración de las filas.
				if (i + 1 < 10)
				{
					Console.Write("0");
				}

				Console.Write((i + 1) + " ");

				for (int j = 0; j < mapa.GetLength(1); j++)
				{
					Console.Write(mapa[i, j] + " ");
				}

				Console.WriteLine();
			}

			Console.Write("   ");

			// Numeración de las columnas por debajo del mapa.
			for (int i = 1; i <= mapa.GetLength(1); i++)
			{
				Console.Write(i);

				if (i < 10)
				{
					Console.Write(" ");
				}
			}

			Console.WriteLine("\n");

			// Muestra el mensaje final.
			if (elJugadorGano)
			{
				Console.Write("El jugador ha llegado a la casilla de victoria. Felicitaciones! ");
			}
			else
			{
				Console.Write("El jugador se ha caido en un agujero. Perdiste! ");
			}



			Console.ReadKey(true);
		}
	}
}

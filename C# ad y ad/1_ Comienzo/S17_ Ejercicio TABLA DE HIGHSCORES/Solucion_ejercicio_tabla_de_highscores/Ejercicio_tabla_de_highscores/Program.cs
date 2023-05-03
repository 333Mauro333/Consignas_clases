using System;


namespace Ejercicio_tabla_de_highscores
{
	class Program
	{
		struct Jugador
		{
			public string nombre;
			public int puntaje;
		}

		static void Main()
		{
			Jugador[] jugadores = new Jugador[5];

			const int puntajeMax = 99999;
			Jugador nuevoJugador = new Jugador();



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
			Console.WriteLine("Presentación de la tabla:\n");

			for (int i = 0; i < jugadores.Length; i++)
			{
				Console.WriteLine((i + 1) + ". " + jugadores[i].nombre + "     " + jugadores[i].puntaje);
			}

			Console.Write("\nPresione cualquier tecla para ordenar los puntajes... ");
			Console.ReadKey(true);

			// Se ordenan los puntajes.
			for (int i = 0; i < jugadores.Length; i++)
			{
				for (int j = i + 1; j < jugadores.Length; j++)
				{
					if (jugadores[j].puntaje > jugadores[i].puntaje)
					{
						Jugador jugadorAux = jugadores[i];

						jugadores[i] = jugadores[j];
						jugadores[j] = jugadorAux;
					}
				}
			}

			// Se vuelve a mostrar la tabla.
			Console.WriteLine("\n\nPresentación de la tabla ordenada:\n");

			for (int i = 0; i < jugadores.Length; i++)
			{
				Console.WriteLine((i + 1) + ". " + jugadores[i].nombre + "     " + jugadores[i].puntaje);
			}

			Console.Write("\nPresione cualquier tecla para empezar a ingresar nuevos puntajes... ");
			Console.ReadKey(true);

			do
			{
				Console.Clear();

				// Se muestra la tabla.
				for (int i = 0; i < jugadores.Length; i++)
				{
					Console.WriteLine((i + 1) + ". " + jugadores[i].nombre + "     " + jugadores[i].puntaje);
				}

				Console.WriteLine();

				// Se ingresan las iniciales.
				do
				{
					Console.Write("Ingrese las 3 iniciales: ");
					nuevoJugador.nombre = Console.ReadLine();

				} while (nuevoJugador.nombre.Length > 3);

				// Se ingresa el nuevo puntaje.
				do
				{
					Console.Write("Ingrese el nuevo puntaje (hasta " + puntajeMax + "): ");
					nuevoJugador.puntaje = int.Parse(Console.ReadLine());

				} while (nuevoJugador.puntaje < 0 || nuevoJugador.puntaje > puntajeMax);

				// Se hace la revisión del puntaje más bajo al más alto.
				for (int i = jugadores.Length - 1; i >= 0; i--)
				{
					// Si el nuevo puntaje supera el revisado...
					if (nuevoJugador.puntaje > jugadores[i].puntaje)
					{
						// Si se está revisando la última posición de la tabla...
						if (i == jugadores.Length - 1)
						{
							// Se sobreescribe y se termina el ciclo acá.
							jugadores[i] = nuevoJugador;
						}
						else
						{
							// Se hace un intercambio de jugadores:
							// 1. El jugador superado se reemplaza por el nuevo y se pasa para abajo.
							Jugador jugadorAux = jugadores[i];

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



			Console.ReadKey(true);
		}
	}
}

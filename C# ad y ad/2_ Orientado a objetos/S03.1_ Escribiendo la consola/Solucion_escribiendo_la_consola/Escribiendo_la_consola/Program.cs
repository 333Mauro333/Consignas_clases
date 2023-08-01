using System;

using Mgtv_Library.Console;


namespace Escribiendo_la_consola
{
	class Program
	{
		static void Main()
		{
			bool inProgram = true;

			int anchoVentana = ConsoleExt.GetScreenWidth() - 1;
			int altoVentana = ConsoleExt.GetScreenHeight() - 1;

			const string titulo = "Escribiendo la consola";
			const int distanciaDelTitulo = 4;
			int columnaDelTitulo = anchoVentana / 2 - titulo.Length / 2; // Posición para que el título quede centrado.

			int x = 0;
			int y = 0;

			const char numeral = '#';



			ConsoleExt.SetConsoleTitle(titulo); // Se cambia el título de la consola.

			// Se escribe el título en la consola.
			ConsoleExt.GoToCoordinates(columnaDelTitulo, altoVentana - distanciaDelTitulo);
			ConsoleExt.WriteWithColor(titulo.ToUpper(), ConsoleColor.Yellow);

			// Comienza el loop del programa.
			while (inProgram)
			{
				// Si el último # se ingresó sobre el título, el mismo se vuelve a escribir.
				if (x >= columnaDelTitulo && x <= columnaDelTitulo + titulo.Length && y == altoVentana - distanciaDelTitulo)
				{
					ConsoleExt.GoToCoordinates(columnaDelTitulo, altoVentana - distanciaDelTitulo);
					ConsoleExt.WriteWithColor(titulo.ToUpper(), ConsoleColor.Yellow);
				}

				// Se pide la coordenada "x".
				do
				{
					BorrarLinea(altoVentana - 2);

					ConsoleExt.GoToCoordinates(0, 0);
					ConsoleExt.GoToCoordinates(0, altoVentana - 2);

					Console.Write("Ingrese la posicion X (entre 0 y " + anchoVentana + "): ");
					x = int.Parse(Console.ReadLine());

				} while (!EstaDentroDeLosLimites(x, 0, anchoVentana));

				// Se pide la coordenada "y".
				do
				{
					BorrarLinea(altoVentana - 1);

					ConsoleExt.GoToCoordinates(0, altoVentana - 1);

					Console.Write("Ingrese la posicion Y (entre 0 y " + altoVentana + "): ");
					y = int.Parse(Console.ReadLine());

				} while (!EstaDentroDeLosLimites(y, -1, altoVentana));

				// Se verifica si la coordenada "y" no es -1 (en el caso de que lo sea, se finaliza el programa).
				if (y != -1)
				{
					// Se borra la línea donde se pidió la coordenada "y".
					BorrarLinea(altoVentana - 1);

					// Se va a las coordenadas ingresadas y se escribe el "#".
					ConsoleExt.GoToCoordinates(x, y);
					Console.Write(numeral);
				}
				else
				{
					// Se finaliza el programa.
					inProgram = false;
				}
			}

			ConsoleExt.WriteWithColor("Programa finalizado correctamente. Presione cualquier tecla para cerrar la ventana... ", ConsoleColor.Green);



			Console.ReadKey(true);
		}

		static void BorrarLinea(int linea)
		{
			ConsoleExt.GoToCoordinates(0, linea);

			for (int i = 0; i < ConsoleExt.GetScreenWidth(); i++)
			{
				Console.Write(" ");
			}
		}
		static bool EstaDentroDeLosLimites(int num, int limMin, int limMax)
		{
			return num >= limMin && num <= limMax;
		}
	}
}

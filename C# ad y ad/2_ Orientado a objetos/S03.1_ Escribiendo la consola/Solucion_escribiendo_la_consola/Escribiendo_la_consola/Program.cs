using System;

using Mgtv_Library.Console;


namespace Escribiendo_la_consola
{
	class Program
	{
		static void Main()
		{
			string titulo = "ESCRIBIENDO LA CONSOLA";
			int anchoVentana = ConsoleExt.GetScreenWidth();
			int altoVentana = ConsoleExt.GetScreenHeight();

			int distanciaDelTitulo = 4;
			int columnaDelTitulo = anchoVentana / 2 - titulo.Length / 2; // Posicion para que el título quede centrado.

			int x = 0;
			int y = 0;

			bool inProgram = true;


			ConsoleExt.SetConsoleTitle(titulo);

			ConsoleExt.GoToCoordinates(columnaDelTitulo, altoVentana - distanciaDelTitulo);
			ConsoleExt.WriteInColor(titulo, ConsoleColor.Yellow);

			while (inProgram)
			{
				if (x >= columnaDelTitulo && x <= columnaDelTitulo + titulo.Length && y == altoVentana - distanciaDelTitulo)
				{
					ConsoleExt.GoToCoordinates(columnaDelTitulo, altoVentana - distanciaDelTitulo);
					ConsoleExt.WriteInColor(titulo, ConsoleColor.Yellow);
				}

				do
				{
					ConsoleExt.GoToCoordinates(0, altoVentana - 2);
					BorrarLinea();

					ConsoleExt.GoToCoordinates(0, altoVentana - 2);

					Console.Write("Ingrese la posicion X (entre 0 y " + anchoVentana + "): ");
					x = int.Parse(Console.ReadLine());

				} while (!EstaDentroDeLosLimites(x, 0, anchoVentana));

				do
				{
					ConsoleExt.GoToCoordinates(0, altoVentana - 1);
					BorrarLinea();

					ConsoleExt.GoToCoordinates(0, altoVentana - 1);

					Console.Write("Ingrese la posicion Y (entre 0 y " + altoVentana + "): ");
					y = int.Parse(Console.ReadLine());

				} while (!EstaDentroDeLosLimites(y, -1, altoVentana));

				if (y != -1)
				{
					ConsoleExt.GoToCoordinates(0, altoVentana - 1);
					BorrarLinea();

					ConsoleExt.GoToCoordinates(x, y);
					Console.Write("#");
				}
				else
				{
					inProgram = false;
				}
			}

			ConsoleExt.SetForegroundColor(ConsoleColor.DarkGreen);

			Console.Write("Programa finalizado correctamente. Presione cualquier tecla para cerrar la ventana... ");

			ConsoleExt.SetForegroundColor(ConsoleColor.White);



			Console.ReadKey(true);
		}

		static void BorrarLinea()
		{
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

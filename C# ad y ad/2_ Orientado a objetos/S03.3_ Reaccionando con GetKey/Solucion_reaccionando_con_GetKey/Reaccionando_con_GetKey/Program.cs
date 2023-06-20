using System;

using Mgtv_Library.Console;


namespace Reaccionando_con_GetKey
{
	class Program
	{
		static void Main()
		{
			const int opcionMaxima = 5;

			int anchoVentana = ConsoleExt.GetScreenWidth();
			int altoVentana = ConsoleExt.GetScreenHeight();

			bool inProgram = true;
			int opcionSeleccionada = 1;
			ConsoleKey teclaPresionada = ConsoleKey.NoName;

			const string opcion1 = "JUGAR";
			const string opcion2 = "OPCIONES";
			const string opcion3 = "AYUDA";
			const string opcion4 = "CRÉDITOS";
			const string opcion5 = "SALIR";

			const string mensajeFinal = "Presione cualquier tecla para cerrar la ventana... ";


			ConsoleExt.HideCursor();

			while (inProgram)
			{
				Console.Clear(); // Limpia la pantalla.

				#region Muestra de opciones

				ConsoleExt.GoToCoordinates(anchoVentana / 2 - opcion1.Length / 2, altoVentana / 2 - 2);
				Console.Write(opcion1);

				ConsoleExt.GoToCoordinates(anchoVentana / 2 - opcion2.Length / 2 + 1, altoVentana / 2 - 1);
				Console.Write(opcion2);

				ConsoleExt.GoToCoordinates(anchoVentana / 2 - opcion3.Length / 2, altoVentana / 2);
				Console.Write(opcion3);

				ConsoleExt.GoToCoordinates(anchoVentana / 2 - opcion4.Length / 2 + 1, altoVentana / 2 + 1);
				Console.Write(opcion4);

				ConsoleExt.GoToCoordinates(anchoVentana / 2 - opcion5.Length / 2, altoVentana / 2 + 2);
				Console.Write(opcion5);

				#endregion

				#region Resaltado de opción actual

				switch (opcionSeleccionada)
				{
					case 1:
						ResaltarOpcion(opcion1, altoVentana / 2 - 2);
						break;

					case 2:
						ResaltarOpcion(opcion2, altoVentana / 2 - 1);
						break;

					case 3:
						ResaltarOpcion(opcion3, altoVentana / 2);
						break;

					case 4:
						ResaltarOpcion(opcion4, altoVentana / 2 + 1);
						break;

					case 5:
						ResaltarOpcion(opcion5, altoVentana / 2 + 2);
						break;
				}

				#endregion

				// Se obtiene la tecla presionada.
				teclaPresionada = ConsoleExt.GetKey(true);

				// Se reacciona ante la tecla presionada.
				switch (teclaPresionada)
				{
					case ConsoleKey.UpArrow:
						RetrocederOpcion(ref opcionSeleccionada, opcionMaxima);
						break;

					case ConsoleKey.DownArrow:
						AvanzarOpcion(ref opcionSeleccionada, opcionMaxima);
						break;

					case ConsoleKey.Enter:
						EntrarALaOpcion((OpcionDelMenu)opcionSeleccionada);

						if (opcionSeleccionada == opcionMaxima)
						{
							inProgram = false;
						}

						break;
				}
			}

			ConsoleExt.GoToCoordinates(anchoVentana / 2 - mensajeFinal.Length / 2, altoVentana / 2 + 7);
			ConsoleExt.WriteInColor(mensajeFinal, ConsoleColor.Green);


			Console.ReadKey(true);
		}

		static void ResaltarOpcion(string opcion, int posicionY)
		{
			ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - opcion.Length / 2 - 2, posicionY);
			Console.Write("►");

			ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 + opcion.Length / 2 + 2, posicionY);
			Console.Write("◄");
		}

		static void AvanzarOpcion(ref int opcion, int opcionMaxima)
		{
			if (opcion != opcionMaxima)
			{
				opcion++;
			}
			else
			{
				opcion = 1;
			}
		}
		static void RetrocederOpcion(ref int opcion, int opcionMaxima)
		{
			if (opcion != 1)
			{
				opcion--;
			}
			else
			{
				opcion = opcionMaxima;
			}
		}
		static void EntrarALaOpcion(OpcionDelMenu opcionAIngresar)
		{
			const string respuesta1 = "Este es un menú de prueba. No hay un juego para cargar. ";
			const string respuesta2 = "Acá se mostrarían las opciones. Al ser un programa de prueba, no hay opciones.";
			const string respuesta3_1 = "Podés navegar a través del menú principal con \"Flecha arriba\" y \"Flecha abajo\".";
			const string respuesta3_2 = "Para ingresar a la opción, presionar \"Enter\".";
			const string respuesta4 = "Nada que reconocer. Simplemente es un programa de ejemplo para que mis alumnos aprendan :)";
			const string respuesta5 = "Programa finalizado. ¡Gracias por utilizar!";

			int posicionY = ConsoleExt.GetScreenHeight() / 2 + 5;


			switch (opcionAIngresar)
			{
				case OpcionDelMenu.Jugar:
					ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - respuesta1.Length / 2, posicionY);
					Console.Write(respuesta1);
					break;

				case OpcionDelMenu.Opciones:
					ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - respuesta2.Length / 2, posicionY);
					Console.Write(respuesta2);
					break;

				case OpcionDelMenu.Ayuda:
					ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - respuesta3_1.Length / 2, posicionY);
					Console.Write(respuesta3_1);
					ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - respuesta3_2.Length / 2, posicionY + 1);
					Console.Write(respuesta3_2);
					break;

				case OpcionDelMenu.Creditos:
					ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - respuesta4.Length / 2, posicionY);
					Console.Write(respuesta4);
					break;

				case OpcionDelMenu.Salir:
					ConsoleExt.GoToCoordinates(ConsoleExt.GetScreenWidth() / 2 - respuesta5.Length / 2, posicionY);
					Console.Write(respuesta5);
					break;
			}

			Console.ReadKey(true);
		}
	}
}

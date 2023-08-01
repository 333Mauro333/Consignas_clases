using System;

using Mgtv_Library.Console;


namespace Estrellas_en_el_cielo
{
	class Program
	{
		static void Main()
		{
			bool enPrograma = true;

			int anchoConsola = ConsoleExt.GetScreenWidth();
			int altoConsola = ConsoleExt.GetScreenHeight();

			const string titulo = "Estrellas en el cielo";

			const int distanciaBordeX = 20;
			const int distanciaBordeYSup = 4;
			const int distanciaBordeYInf = 15;

			int marcoBordeIzquierdo = distanciaBordeX;
			int marcoBordeDerecho = anchoConsola - distanciaBordeX;
			int marcoBordeSuperior = distanciaBordeYSup;
			int marcoBordeInferior = altoConsola - distanciaBordeYInf;

			Estrella estrella1 = new Estrella();
			Estrella estrella2 = new Estrella();

			Random generar = new Random();

			int opcion = 0;

			int x = 0;
			int y = 0;



			ConsoleExt.SetConsoleTitle(titulo);

			x = generar.Next(marcoBordeIzquierdo + 1, marcoBordeDerecho);
			y = generar.Next(marcoBordeSuperior + 1, marcoBordeInferior);

			estrella1.SetPosicion(x, y);

			x = generar.Next(marcoBordeIzquierdo + 1, marcoBordeDerecho);
			y = generar.Next(marcoBordeSuperior + 1, marcoBordeInferior);

			estrella2.SetPosicion(x, y);

			ConsoleExt.SetBackgroundColor(ConsoleColor.DarkBlue);
			ConsoleExt.SetForegroundColor(ConsoleColor.Gray);

			while (enPrograma)
			{
				Console.Clear();

				ConsoleExt.GoToCoordinates(anchoConsola / 2 - titulo.Length / 2, marcoBordeSuperior - 1);
				ConsoleExt.WriteWithColor(titulo.ToUpper(), ConsoleColor.White);

				ConsoleExt.DrawFrame(marcoBordeIzquierdo, marcoBordeSuperior, marcoBordeDerecho, marcoBordeInferior);

				estrella1.Draw();
				estrella2.Draw();

				ConsoleExt.GoToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 1);
				Console.Write("Cambios de posición totales: " + Estrella.GetCambiosDePosicion() + ".");

				ConsoleExt.GoToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 3);
				EscribirPosicionEstrella(estrella1, 1);

				ConsoleExt.GoToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 4);
				EscribirPosicionEstrella(estrella2, 2);

				ConsoleExt.GoToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 7);
				Console.Write("1. Establecer posiciones aleatorias");
				ConsoleExt.GoToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 8);
				Console.Write("2. Definir una nueva posición");
				ConsoleExt.GoToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 9);
				Console.Write("3. Salir del programa");

				opcion = PedirNumero(1, 3, marcoBordeIzquierdo, marcoBordeInferior + 11, "Opción ingresada: ", false);

				switch (opcion)
				{
					case 1:

						#region Posicionamiento aleatorio de las estrellas

						x = generar.Next(marcoBordeIzquierdo + 1, marcoBordeDerecho);
						y = generar.Next(marcoBordeSuperior + 1, marcoBordeInferior);

						estrella1.SetPosicion(x, y);

						x = generar.Next(marcoBordeIzquierdo + 1, marcoBordeDerecho);
						y = generar.Next(marcoBordeSuperior + 1, marcoBordeInferior);

						estrella2.SetPosicion(x, y);

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 37, marcoBordeInferior + 12);
						Console.Write("Posiciones cambiadas correctamente. Presione cualquier tecla para continuar... ");
						Console.ReadKey(true);

						#endregion

						break;

					case 2:

						#region Pedido de coordenadas y estrella

						BorrarMenu(marcoBordeInferior + 6);

						ConsoleExt.GoToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 7);
						Console.Write("1. Cambiar posición de la primera estrella");
						ConsoleExt.GoToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 8);
						Console.Write("2. Cambiar posición de la segunda estrella");
						ConsoleExt.GoToCoordinates(marcoBordeIzquierdo, marcoBordeInferior + 9);
						Console.Write("3. Volver al menú principal");

						opcion = PedirNumero(1, 3, marcoBordeIzquierdo, marcoBordeInferior + 11, "Opción ingresada: ", false);

						if (opcion != 3)
						{
							BorrarMenu(marcoBordeInferior + 6);

							x = PedirNumero(marcoBordeIzquierdo + 1, marcoBordeDerecho - 1, marcoBordeIzquierdo, marcoBordeInferior + 7, "Ingrese la posición X", true);
							y = PedirNumero(marcoBordeSuperior + 1, marcoBordeInferior - 1, marcoBordeIzquierdo, marcoBordeInferior + 8, "Ingrese la posición Y", true);

							switch (opcion)
							{
								case 1:
									estrella1.SetPosicion(x, y);
									break;

								case 2:
									estrella2.SetPosicion(x, y);
									break;
							}

							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 37, marcoBordeInferior + 10);
							Console.Write("Estrella posicionada correctamente. Presione cualquier tecla para continuar... ");
							Console.ReadKey(true);
						}

						#endregion

						break;

					case 3:

						#region Salida del programa

						enPrograma = false;

						ConsoleExt.GoToCoordinates(marcoBordeIzquierdo - 5, marcoBordeInferior + 13);
						Console.Write("Programa finalizado. ¡Muchas gracias por utilizar! ");

						#endregion

						break;
				}
			}

			Console.Write("Presione cualquier tecla para cerrar la ventana... ");



			Console.ReadKey(true);
		}

		static int PedirNumero(int limMin, int limMax, int x, int y, string mensaje, bool muestraLimites)
		{
			int num = 0;
			bool esValido = false;


			do
			{
				BorrarMenu(y);
				ConsoleExt.GoToCoordinates(x, y);

				Console.Write(mensaje);

				if (muestraLimites)
				{
					Console.Write(" (entre " + limMin + " y " + limMax + "): ");
				}

				try
				{
					num = int.Parse(Console.ReadLine());

					esValido = num >= limMin && num <= limMax;
				}
				catch (Exception e)
				{

				}

			} while (!esValido);

			return num;
		}

		static void EscribirPosicionEstrella(Estrella estrella, int numeroDeEstrella)
		{
			Console.Write("Posición de la estrella " + numeroDeEstrella + ": (" + estrella.GetPosicion().x + "; " + estrella.GetPosicion().y + ").");
		}

		static void BorrarLinea(int linea)
		{
			ConsoleExt.GoToCoordinates(0, linea);

			for (int i = 0; i < ConsoleExt.GetScreenWidth(); i++)
			{
				Console.Write(" ");
			}
		}
		static void BorrarMenu(int inicioDeBorrado)
		{
			for (int i = inicioDeBorrado; i <= ConsoleExt.GetScreenHeight(); i++)
			{
				BorrarLinea(i);
			}

			ConsoleExt.GoToCoordinates(0, 0);
		}
	}
}

using System;

using Mgtv_Library.Console;


namespace Control_de_luces
{
	class Program
	{
		static void Main()
		{
			bool enPrograma = true;

			int anchoConsola = ConsoleExt.GetScreenWidth();

			Luz[] luces = new Luz[5];

			const string titulo = "Control de luces";
			int posicionTituloX = anchoConsola / 2 - titulo.Length / 2;
			int posicionTituloY = 2;

			int opcionIngresada = 0;



			ConsoleExt.SetConsoleTitle(titulo);

			for (int i = 0; i < luces.Length; i++)
			{
				luces[i] = new Luz();
			}

			for (int i = 0; i < luces.Length; i++)
			{
				luces[i].SetPosicion(anchoConsola / luces.Length * i + 1, posicionTituloY + 3);
			}

			while (enPrograma)
			{
				Console.Clear();

				#region Muestra de menú

				ConsoleExt.GoToCoordinates(posicionTituloX, posicionTituloY);
				ConsoleExt.WriteWithColor(titulo.ToUpper(), ConsoleColor.Cyan);

				for (int i = 0; i < luces.Length; i++)
				{
					luces[i].Draw();
				}

				ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, posicionTituloY + 14);
				Console.Write("Cantidad de luces encendidas: " + Luz.GetLucesEncendidas() + ".");

				ConsoleExt.GoToCoordinates(anchoConsola / 2 - 15, posicionTituloY + 17);
				Console.Write("1. ENCENDER TODAS LAS LUCES");
				ConsoleExt.GoToCoordinates(anchoConsola / 2 - 15, posicionTituloY + 18);
				Console.Write("2. APAGAR TODAS LAS LUCES");
				ConsoleExt.GoToCoordinates(anchoConsola / 2 - 15, posicionTituloY + 19);
				Console.Write("3. ENCENDER UNA LUZ");
				ConsoleExt.GoToCoordinates(anchoConsola / 2 - 15, posicionTituloY + 20);
				Console.Write("4. APAGAR UNA LUZ");
				ConsoleExt.GoToCoordinates(anchoConsola / 2 - 15, posicionTituloY + 21);
				Console.Write("5. SALIR");

				#endregion

				ConsoleExt.GoToCoordinates(anchoConsola / 2 - 20, posicionTituloY + 23);
				Console.Write("Opción ingresada: ");
				opcionIngresada = int.Parse(Console.ReadLine());

				switch (opcionIngresada)
				{
					case 1:

						#region Encendido de todas las luces

						if (Luz.GetLucesEncendidas() < luces.Length)
						{
							for (int i = 0; i < luces.Length; i++)
							{
								if (!luces[i].GetEstaEncendida())
								{
									luces[i].Encender();
								}
							}

							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 37, posicionTituloY + 25);
							ConsoleExt.WriteWithColor("Todas las luces fueron prendidas. ", ConsoleColor.Green);
						}
						else
						{
							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 38, posicionTituloY + 25);
							ConsoleExt.WriteWithColor("Todas las luces ya están prendidas. ", ConsoleColor.Green);
						}

						ConsoleExt.WriteWithColor("Presione cualquier tecla para continuar... ", ConsoleColor.Green);
						Console.ReadKey(true);

						#endregion

						break;

					case 2:

						#region Apagado de todas las luces

						if (Luz.GetLucesEncendidas() > 0)
						{
							for (int i = 0; i < luces.Length; i++)
							{
								if (luces[i].GetEstaEncendida())
								{
									luces[i].Apagar();
								}
							}

							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 36, posicionTituloY + 25);
							ConsoleExt.WriteWithColor("Todas las luces fueron apagadas. ", ConsoleColor.Green);
						}
						else
						{
							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 34, posicionTituloY + 25);
							ConsoleExt.WriteWithColor("Las luces ya están apagadas. ", ConsoleColor.Green);
						}

						ConsoleExt.WriteWithColor("Presione cualquier tecla para continuar... ", ConsoleColor.Green);
						Console.ReadKey(true);

						#endregion

						break;

					case 3:

						#region Encendido de una luz

						if (Luz.GetLucesEncendidas() != luces.Length)
						{
							do
							{
								BorrarPantalla(posicionTituloY + 17);

								ConsoleExt.GoToCoordinates(anchoConsola / 2 - 25, posicionTituloY + 17);
								Console.Write("Ingrese el número de luz que desea encender (entre 1 y " + luces.Length + "): ");
								opcionIngresada = int.Parse(Console.ReadLine());

							} while (opcionIngresada < 1 || opcionIngresada > luces.Length);

							if (!luces[opcionIngresada - 1].GetEstaEncendida())
							{
								luces[opcionIngresada - 1].Encender();

								ConsoleExt.GoToCoordinates(anchoConsola / 2 - 29, posicionTituloY + 19);
								ConsoleExt.WriteWithColor("La luz fue encendida. ", ConsoleColor.Green);
							}
							else
							{
								ConsoleExt.GoToCoordinates(anchoConsola / 2 - 31, posicionTituloY + 19);
								ConsoleExt.WriteWithColor("La luz ya está encendida. ", ConsoleColor.Green);
							}
						}
						else
						{
							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 38, posicionTituloY + 25);
							ConsoleExt.WriteWithColor("Todas las luces ya están prendidas.", ConsoleColor.Green);
						}

						ConsoleExt.WriteWithColor("Presione cualquier tecla para continuar... ", ConsoleColor.Green);
						Console.ReadKey(true);

						#endregion

						break;

					case 4:

						#region Apagado de una luz

						if (Luz.GetLucesEncendidas() != 0)
						{
							do
							{
								BorrarPantalla(posicionTituloY + 17);

								ConsoleExt.GoToCoordinates(anchoConsola / 2 - 25, posicionTituloY + 17);
								Console.Write("Ingrese el número de luz que desea apagar (entre 1 y " + luces.Length + "): ");
								opcionIngresada = int.Parse(Console.ReadLine());

							} while (opcionIngresada < 1 || opcionIngresada > luces.Length);

							if (luces[opcionIngresada - 1].GetEstaEncendida())
							{
								luces[opcionIngresada - 1].Apagar();

								ConsoleExt.GoToCoordinates(anchoConsola / 2 - 28, posicionTituloY + 19);
								ConsoleExt.WriteWithColor("La luz fue apagada. ", ConsoleColor.Green);
							}
							else
							{
								ConsoleExt.GoToCoordinates(anchoConsola / 2 - 30, posicionTituloY + 19);
								ConsoleExt.WriteWithColor("La luz ya está apagada. ", ConsoleColor.Green);
							}
						}
						else
						{
							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 34, posicionTituloY + 25);
							ConsoleExt.WriteWithColor("Las luces ya están apagadas. ", ConsoleColor.Green);
						}

						ConsoleExt.WriteWithColor("Presione cualquier tecla para continuar... ", ConsoleColor.Green);
						Console.ReadKey(true);

						#endregion

						break;

					case 5:

						// Se finaliza el programa.
						enPrograma = false;

						break;
				}
			}

			ConsoleExt.GoToCoordinates(anchoConsola / 2 - 37, posicionTituloY + 25);
			ConsoleExt.WriteWithColor("Gracias por utilizar. Presione cualquier tecla para cerrar la ventana... ", ConsoleColor.Green);



			Console.ReadKey(true);
		}

		static void BorrarLinea(int linea)
		{
			for (int i = 0; i < ConsoleExt.GetScreenWidth(); i++)
			{
				ConsoleExt.GoToCoordinates(i, linea);
				Console.Write(" ");
			}
		}
		static void BorrarPantalla(int lineaDesdeDondeBorrar)
		{
			for (int i = lineaDesdeDondeBorrar; i < ConsoleExt.GetScreenHeight(); i++)
			{
				BorrarLinea(i);
			}

			ConsoleExt.GoToCoordinates(0, 0);
		}
	}
}

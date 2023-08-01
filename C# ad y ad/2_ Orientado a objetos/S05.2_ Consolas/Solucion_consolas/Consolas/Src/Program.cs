using System;

using Mgtv_Library.Console;


namespace Consolas
{
	class Program
	{
		static void Main()
		{
			bool enPrograma = true;

			int anchoConsola = ConsoleExt.GetScreenWidth();
			int altoConsola = ConsoleExt.GetScreenHeight();

			Pantalla pantallaActual = Pantalla.MenuPrincipal;

			// Menu principal.
			const string tituloPrograma = "Consolas";
			int posicionTituloProgramaX = anchoConsola / 2 - tituloPrograma.Length / 2 - 6;
			int posicionTituloProgramaY = 2;

			const string opcion1 = "1. CONECTAR A UNA CONSOLA";
			const string opcion2 = "2. DESCONECTAR";
			const string opcion3 = "3. CAMBIAR VOLUMEN";
			const string opcion4 = "4. CAMBIAR BRILLO";
			const string opcion5 = "5. SALIR DEL PROGRAMA";

			// Conexion a una consola.
			const string tituloConectar = "----- CONECTAR A UNA CONSOLA -----";
			int posicionTituloConectarX = anchoConsola / 2 - tituloConectar.Length / 2;
			int posicionTituloConectarY = 2;

			// Cambio de volumen.
			const string tituloVolumen = "----- CAMBIAR VOLUMEN -----";
			int posicionTituloVolumenX = anchoConsola / 2 - tituloVolumen.Length / 2;
			int posicionTituloVolumenY = 2;

			// Cambio de brillo.
			const string tituloBrillo = "----- CAMBIAR BRILLO -----";
			int posicionTituloBrilloX = anchoConsola / 2 - tituloBrillo.Length / 2;
			int posicionTituloBrilloY = 2;

			// Objetos.
			Consola[] consolas = new Consola[3];

			Mando mando = new Mando();

			// Otras variables.
			bool seConectan = false;

			const int distanciaEntreTeles = 32;
			int margenParaEscribir = anchoConsola / 2 - 15;
			int volumenTemporal = 0;
			int brilloTemporal = 0;
			int auxiliar = 0;

			int opcionIngresada = 0;
			ConsoleKey teclaPresionada = ConsoleKey.NoName;



			ConsoleExt.SetConsoleTitle(tituloPrograma);

			for (int i = 0; i < consolas.Length; i++)
			{
				consolas[i] = new Consola();
			}

			while (enPrograma)
			{
				Console.Clear();

				switch (pantallaActual)
				{
					case Pantalla.MenuPrincipal:

						#region Muestra del menú

						auxiliar = -distanciaEntreTeles - 10;

						ConsoleExt.GoToCoordinates(posicionTituloProgramaX, posicionTituloProgramaY);
						Console.Write("----- " + tituloPrograma.ToUpper() + " -----");

						for (int i = 0; i < consolas.Length; i++)
						{
							// "mando->getConsola() == consolas[i]", al final de la comparacion, se convierte en un
							// "true" o en un "false". Es por eso que ese valor se puede guardar en una variable bool.
							seConectan = mando.GetConsola() == consolas[i];

							DibujarTele(anchoConsola / 2 + auxiliar, posicionTituloProgramaY + 3, seConectan, consolas[i]);

							auxiliar += distanciaEntreTeles; // Se aplica la distancia sobre X.
						}

						auxiliar = 0;

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - opcion1.Length / 2, posicionTituloProgramaY + 17);
						Console.Write(opcion1);
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - opcion2.Length / 2, posicionTituloProgramaY + 18);
						Console.Write(opcion2);
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - opcion3.Length / 2, posicionTituloProgramaY + 19);
						Console.Write(opcion3);
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - opcion4.Length / 2, posicionTituloProgramaY + 20);
						Console.Write(opcion4);
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - opcion5.Length / 2, posicionTituloProgramaY + 21);
						Console.Write(opcion5);

						#endregion

						#region Petición del número

						ConsoleExt.GoToCoordinates(margenParaEscribir, posicionTituloProgramaY + 23);
						Console.Write("Opcion ingresada: ");
						opcionIngresada = int.Parse(Console.ReadLine());

						#endregion

						#region Reacción al número ingresado

						switch (opcionIngresada)
						{
							case 1: // Conectar a una consola.

								if (!mando.EstaConectado())
								{
									pantallaActual = Pantalla.ConectarAConsola;
								}
								else
								{
									ConsoleExt.GoToCoordinates(anchoConsola / 2 - 41, posicionTituloProgramaY + 25);
									ConsoleExt.WriteWithColor("El mando ya esta conectado a una consola. Presione cualquier tecla para continuar... ", ConsoleColor.DarkRed);
									ConsoleExt.GetKey(true);
								}

								break;

							case 2: // Desconectar.

								if (mando.EstaConectado())
								{
									mando.Desconectar();

									ConsoleExt.GoToCoordinates(anchoConsola / 2 - 40, posicionTituloProgramaY + 25);
									ConsoleExt.WriteWithColor("El mando fue desconectado de la consola. ", ConsoleColor.DarkGreen);
									ConsoleExt.WriteWithColor("Presione cualquier tecla para continuar... ", ConsoleColor.DarkGreen);
								}
								else
								{
									ConsoleExt.GoToCoordinates(anchoConsola / 2 - 43, posicionTituloProgramaY + 25);
									ConsoleExt.WriteWithColor("El mando no estaba conectado a ninguna consola. ", ConsoleColor.DarkRed);
									ConsoleExt.WriteWithColor("Presione cualquier tecla para continuar... ", ConsoleColor.DarkRed);
								}

								ConsoleExt.GetKey(true);

								break;

							case 3: // Cambiar volumen.

								if (mando.EstaConectado())
								{
									pantallaActual = Pantalla.CambiarVolumen;
								}
								else
								{
									ConsoleExt.GoToCoordinates(anchoConsola / 2 - 56, posicionTituloProgramaY + 25);
									ConsoleExt.WriteWithColor("Para cambiar el volumen, el mando debe estar conectado a una consola. ", ConsoleColor.DarkRed);
									ConsoleExt.WriteWithColor("Presione cualquier tecla para continuar... ", ConsoleColor.DarkRed);
									ConsoleExt.GetKey(true);
								}

								break;

							case 4: // Cambiar volumen.

								if (mando.EstaConectado())
								{
									pantallaActual = Pantalla.CambiarBrillo;
								}
								else
								{
									ConsoleExt.GoToCoordinates(anchoConsola / 2 - 55, posicionTituloProgramaY + 25);
									ConsoleExt.WriteWithColor("Para cambiar el brillo, el mando debe estar conectado a una consola. ", ConsoleColor.DarkRed);
									ConsoleExt.WriteWithColor("Presione cualquier tecla para continuar... ", ConsoleColor.DarkRed);
									ConsoleExt.GetKey(true);
								}

								break;

							case 5:

								enPrograma = false;
								ConsoleExt.GoToCoordinates(anchoConsola / 2 - 30, posicionTituloProgramaY + 25);
								ConsoleExt.WriteWithColor("El programa se ha finalizado. Muchas gracias por utilizar!", ConsoleColor.DarkGreen);

								break;
						}

						#endregion

						break;

					case Pantalla.ConectarAConsola:

						#region Muestra del menú

						auxiliar = -1;

						ConsoleExt.GoToCoordinates(posicionTituloConectarX, posicionTituloConectarY);
						Console.Write(tituloConectar);

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 47, altoConsola / 2 - 3);
						Console.Write("Ingrese el numero de consola a la que desea conectarse (ingrese " + (consolas.Length + 1) + " para volver al menu principal):");

						for (int i = 0; i < consolas.Length; i++)
						{
							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 25, altoConsola / 2 + auxiliar);
							Console.Write("Consola " + (i + 1) + ". Volumen: " + consolas[i].GetVolumen() + "%. Brillo: " + consolas[i].GetBrillo() + "%.");
							auxiliar++;
						}

						#endregion

						#region Petición de número

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 25, altoConsola / 2 + 3);
						Console.Write("Opcion ingresada: ");
						opcionIngresada = int.Parse(Console.ReadLine());

						#endregion

						#region Reacción al número ingresado

						if (opcionIngresada >= 1 && opcionIngresada <= consolas.Length)
						{
							mando.ConectarALaConsola(consolas[opcionIngresada - 1]);

							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 25, altoConsola / 2 + 5);
							ConsoleExt.WriteWithColor("El mando fue conectado a la consola elegida correctamente!", ConsoleColor.DarkGreen);
							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 25, altoConsola / 2 + 6);
							ConsoleExt.WriteWithColor("Presione cualquier tecla para volver al menu principal... ", ConsoleColor.DarkGreen);
							ConsoleExt.GetKey(true);

							pantallaActual = Pantalla.MenuPrincipal;
						}
						else if (opcionIngresada == consolas.Length + 1)
						{
							pantallaActual = Pantalla.MenuPrincipal;
						}

						#endregion

						break;

					case Pantalla.CambiarVolumen:

						#region Cambio de volumen

						volumenTemporal = mando.GetConsola().GetVolumen();

						ConsoleExt.GoToCoordinates(posicionTituloVolumenX, posicionTituloVolumenY);
						Console.Write(tituloVolumen);

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 - 3);
						Console.Write("Modifique el volumen actual con \"Flecha arriba\" y \"Flecha abajo\".");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 - 2);
						Console.Write("Presione ENTER para aplicar el nuevo volumen.");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 - 1);
						Console.Write("Presione ESC para volver al menu sin aplicar el nuevo volumen.");

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 13, altoConsola / 2 + 1);
						Console.Write("▲");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 + 2);
						Console.Write("Volumen actual: ");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 13, altoConsola / 2 + 3);
						Console.Write("▼");

						while (teclaPresionada != ConsoleKey.Escape && teclaPresionada != ConsoleKey.Enter)
						{
							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 14, altoConsola / 2 + 2);
							Console.Write(volumenTemporal + "%. ");

							teclaPresionada = ConsoleExt.GetKey(true);

							switch (teclaPresionada)
							{
								case ConsoleKey.UpArrow:

									if (volumenTemporal < 100)
									{
										volumenTemporal++;
									}

									break;

								case ConsoleKey.DownArrow:

									if (volumenTemporal > 0)
									{
										volumenTemporal--;
									}

									break;

								case ConsoleKey.Enter:

									mando.GetConsola().SetVolumen(volumenTemporal);

									ConsoleExt.GoToCoordinates(anchoConsola / 2 - 43, altoConsola / 2 + 5);
									ConsoleExt.WriteWithColor("Se ha aplicado el nuevo volumen! ", ConsoleColor.DarkGreen);
									ConsoleExt.WriteWithColor("Presione cualquier tecla para volver al menu principal... ", ConsoleColor.DarkGreen);
									ConsoleExt.GetKey(true);

									break;
							}
						}

						teclaPresionada = ConsoleKey.NoName;
						pantallaActual = Pantalla.MenuPrincipal;

						#endregion

						break;

					case Pantalla.CambiarBrillo:

						#region Cambio de brillo

						brilloTemporal = mando.GetConsola().GetBrillo();

						ConsoleExt.GoToCoordinates(posicionTituloBrilloX, posicionTituloBrilloY);
						Console.Write(tituloBrillo);

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 - 3);
						Console.Write("Modifique el brillo actual con \"Flecha arriba\" y \"Flecha abajo\".");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 - 2);
						Console.Write("Presione ENTER para aplicar el nuevo brillo.");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 - 1);
						Console.Write("Presione ESC para volver al menu sin aplicar el nuevo brillo.");

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 14, altoConsola / 2 + 1);
						Console.Write("▲");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 30, altoConsola / 2 + 2);
						Console.Write("Brillo actual: ");
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - 14, altoConsola / 2 + 3);
						Console.Write("▼");

						while (teclaPresionada != ConsoleKey.Escape && teclaPresionada != ConsoleKey.Enter)
						{
							ConsoleExt.GoToCoordinates(anchoConsola / 2 - 15, altoConsola / 2 + 2);
							Console.Write(brilloTemporal + "%. ");

							teclaPresionada = ConsoleExt.GetKey(true);

							switch (teclaPresionada)
							{
								case ConsoleKey.UpArrow:

									if (brilloTemporal < 100)
									{
										brilloTemporal++;
									}

									break;

								case ConsoleKey.DownArrow:

									if (brilloTemporal > 0)
									{
										brilloTemporal--;
									}

									break;

								case ConsoleKey.Enter:

									mando.GetConsola().SetBrillo(brilloTemporal);

									ConsoleExt.GoToCoordinates(anchoConsola / 2 - 42, altoConsola / 2 + 5);
									ConsoleExt.WriteWithColor("Se ha aplicado el nuevo brillo! ", ConsoleColor.DarkGreen);
									ConsoleExt.WriteWithColor("Presione cualquier tecla para volver al menu principal... ", ConsoleColor.DarkGreen);
									ConsoleExt.GetKey(true);

									break;
							}
						}

						teclaPresionada = ConsoleKey.NoName;
						pantallaActual = Pantalla.MenuPrincipal;

						#endregion

						break;
				}
			}

			ConsoleExt.GoToCoordinates(anchoConsola / 2 - 26, posicionTituloProgramaY + 26);
			ConsoleExt.WriteWithColor("Presione cualquier tecla para cerrar la ventana... ", ConsoleColor.DarkGreen);

			ConsoleExt.GetKey(true);


			Console.ReadKey(true);
		}

		static void DibujarTele(int x, int y, bool conMando, Consola consola)
		{
			ConsoleColor colorAnterior = ConsoleExt.GetForegroundColor();
			ConsoleColor colorDeTele = ConsoleColor.DarkGray;


			ConsoleExt.SetForegroundColor(colorDeTele);

			ConsoleExt.DrawFrame(x, y, x + 20, y + 5); // Monitor.
			ConsoleExt.GoToCoordinates(x + 10, y + 5);
			Console.Write("╦");

			// Tronco que sostiene el monitor.
			for (int i = 0; i < 3; i++)
			{
				ConsoleExt.GoToCoordinates(x + 10, y + 6 + i);
				Console.Write("║");
			}

			ConsoleExt.DrawFrame(x + 5, y + 8, x + 15, y + 9); // Consola.

			ConsoleExt.GoToCoordinates(x + 1, y + 2);

			// Texto que indica si el mando esta conectado o no.
			if (conMando)
			{
				ConsoleExt.WriteWithColor("  Mando conectado!", ConsoleColor.Green);
				ConsoleExt.SetForegroundColor(ConsoleColor.Green);
			}
			else
			{
				ConsoleExt.WriteWithColor("   Ningun mando", ConsoleColor.DarkRed);
				ConsoleExt.GoToCoordinates(x + 5, y + 3);
				ConsoleExt.WriteWithColor("detectado.", ConsoleColor.DarkRed);
				ConsoleExt.SetForegroundColor(ConsoleColor.DarkRed);
			}

			ConsoleExt.GoToCoordinates(x + 4, y + 11);
			Console.Write("Volumen: " + consola.GetVolumen() + "%.");
			ConsoleExt.GoToCoordinates(x + 4, y + 12);
			Console.Write("Brillo: " + consola.GetBrillo() + "%.");

			ConsoleExt.SetForegroundColor(colorAnterior);
		}
	}
}

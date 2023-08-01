using System;

using Mgtv_Library.Console;


namespace Configurando_la_consola
{
	class Program
	{
		static void Main()
		{
			bool enPrograma = true;

			Pantalla pantallaActual = Pantalla.MenuPrincipal;

			int anchoConsola = ConsoleExt.GetScreenWidth() - 1;
			int altoConsola = ConsoleExt.GetScreenHeight() - 1;

			const string tituloVentana = "Configuración de la consola";

			bool seDibujaElMarco = true;

			// mp: Menú principal.
			const string mpTitulo = "----- CONFIGURACIÓN DE LA CONSOLA -----";
			const string mpOpcion1 = "1. Cambiar visibilidad del marco: ";
			const string mpOpcion2 = "2. Seleccionar color del texto";
			const string mpOpcion3 = "3. Seleccionar color del fondo";
			const string mpOpcion4 = "4. Cambiar el título de la ventana";
			const string mpOpcion5 = "5. Probar reacción de teclas";
			const string mpOpcion6 = "6. Cerrar";
			int mpPosicionTituloX = anchoConsola / 2 - mpTitulo.Length / 2;
			int mpPosicionTituloY = altoConsola / 2 - 5;

			// ct: Color del texto.
			const string ctTitulo = "--- COLOR DEL TEXTO ---";
			const string ctOracion = "Elija un nuevo color de texto:";
			int ctPosicionTituloX = anchoConsola / 2 - ctTitulo.Length / 2;
			int ctPosicionTituloY = 3;

			// cf: Color del fondo.
			const string cfTitulo = "--- COLOR DEL FONDO ---";
			const string cfOracion = "Elija un nuevo color de fondo:";
			int cfPosicionTituloX = anchoConsola / 2 - cfTitulo.Length / 2;
			int cfPosicionTituloY = 3;

			// tv: Título de la ventana.
			const string tvTitulo = "--- CAMBIO DE TÍTULO DE LA VENTANA ---";
			const string tvOracion = "Ingrese el nuevo título para la ventana: ";
			int tvPosicionTituloX = anchoConsola / 2 - tvTitulo.Length / 2;
			int tvPosicionTituloY = 3;
			string nuevaOracion = "";

			// rt: Reacción de teclas.
			const string rtTitulo = "--- REACCIÓN DE TECLAS PRESIONADAS ---";
			const string rtOracion1 = "En esta sección, se escribirán las teclas que ha presionado.";
			const string rtOracion2 = "Para finalizar, presione la tecla Escape.";
			int rtPosicionTituloX = anchoConsola / 2 - rtTitulo.Length / 2;
			int rtPosicionTituloY = 3;

			int rtPosicionInicialX = 3;
			int rtPosicionInicialY = rtPosicionTituloY + 7;
			int rtPosicionActualCursorY = rtPosicionInicialY;

			// cs: Confirmación de salida
			const string csTitulo = "--- CONFIRMACIÓN DE SALIDA ---";
			const string csPregunta = "¿Desea cerrar el programa?";
			int csPosicionTituloX = anchoConsola / 2 - csTitulo.Length / 2;
			int csPosicionTituloY = 3;

			int opcionIngresada = 0;

			ConsoleKey teclaPresionada = ConsoleKey.NoName;



			ConsoleExt.SetConsoleTitle(tituloVentana);

			while (enPrograma)
			{
				Console.Clear();

				if (seDibujaElMarco)
				{
					ConsoleExt.DrawFrame(0, 0, anchoConsola, altoConsola);
				}

				switch (pantallaActual)
				{
					case Pantalla.MenuPrincipal:

						#region Menú Principal

						ConsoleExt.GoToCoordinates(mpPosicionTituloX, mpPosicionTituloY);
						Console.Write(mpTitulo);

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - mpOpcion1.Length / 2, mpPosicionTituloY + 2);
						Console.Write(mpOpcion1);

						if (seDibujaElMarco)
						{
							Console.Write("Sí.");
						}
						else
						{
							Console.Write("No.");
						}
						
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - mpOpcion2.Length / 2, mpPosicionTituloY + 3);
						Console.Write(mpOpcion2);
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - mpOpcion3.Length / 2, mpPosicionTituloY + 4);
						Console.Write(mpOpcion3);
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - mpOpcion4.Length / 2, mpPosicionTituloY + 5);
						Console.Write(mpOpcion4);
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - mpOpcion5.Length / 2, mpPosicionTituloY + 6);
						Console.Write(mpOpcion5);
						ConsoleExt.GoToCoordinates(anchoConsola / 2 - mpOpcion6.Length / 2, mpPosicionTituloY + 7);
						Console.Write(mpOpcion6);

						ConsoleExt.GoToCoordinates(mpPosicionTituloX - mpTitulo.Length / 4, mpPosicionTituloY + 9);
						Console.Write("Opción ingresada: ");
						opcionIngresada = int.Parse(Console.ReadLine());

						if (opcionIngresada >= 2 && opcionIngresada <= 6)
						{
							pantallaActual = (Pantalla)opcionIngresada;
						}
						else if (opcionIngresada == 1)
						{
							seDibujaElMarco = !seDibujaElMarco;
						}

						#endregion

						break;

					case Pantalla.ColorDelTexto:

						#region Color del texto

						ConsoleExt.GoToCoordinates(ctPosicionTituloX, ctPosicionTituloY);
						Console.Write(ctTitulo);
						
						ConsoleExt.GoToCoordinates(3, ctPosicionTituloY + 2);
						Console.Write("Color actual: ");
						EscribirColor(ConsoleExt.GetForegroundColor());

						ConsoleExt.GoToCoordinates(3, ctPosicionTituloY + 4);
						Console.Write(ctOracion);

						MostrarListaDeColores(3, ctPosicionTituloY + 6);

						ConsoleExt.GoToCoordinates(3, ctPosicionTituloY + 23);
						Console.Write("Opción elegida: ");
						opcionIngresada = int.Parse(Console.ReadLine());

						if (opcionIngresada >= 1 && opcionIngresada <= 16)
						{
							ConsoleExt.GoToCoordinates(3, ctPosicionTituloY + 25);
							Console.Write("¡El color del texto fue cambiado correctamente! Presione cualquier tecla para volver al menú principal... ");
							Console.ReadKey(true);

							ConsoleExt.SetForegroundColor((ConsoleColor)(opcionIngresada - 1));
							pantallaActual = Pantalla.MenuPrincipal;
						}

						#endregion

						break;

					case Pantalla.ColorDelFondo:

						#region Color del fondo

						ConsoleExt.GoToCoordinates(cfPosicionTituloX, cfPosicionTituloY);
						Console.Write(cfTitulo);

						ConsoleExt.GoToCoordinates(3, cfPosicionTituloY + 2);
						Console.Write("Color actual: ");
						EscribirColor(ConsoleExt.GetBackgroundColor());

						ConsoleExt.GoToCoordinates(3, cfPosicionTituloY + 4);
						Console.Write(cfOracion);

						MostrarListaDeColores(3, cfPosicionTituloY + 6);

						ConsoleExt.GoToCoordinates(3, cfPosicionTituloY + 23);
						Console.Write("Opción elegida: ");
						opcionIngresada = int.Parse(Console.ReadLine());

						if (opcionIngresada >= 1 && opcionIngresada <= 16)
						{
							ConsoleExt.GoToCoordinates(3, cfPosicionTituloY + 25);
							Console.Write("¡El color del fondo fue cambiado correctamente! Presione cualquier tecla para volver al menú principal... ");
							Console.ReadKey(true);

							ConsoleExt.SetBackgroundColor((ConsoleColor)(opcionIngresada - 1));
							pantallaActual = Pantalla.MenuPrincipal;
						}

						#endregion

						break;

					case Pantalla.CambiarTitulo:

						#region Cambiar título

						ConsoleExt.GoToCoordinates(tvPosicionTituloX, tvPosicionTituloY);
						Console.Write(tvTitulo);

						ConsoleExt.GoToCoordinates(3, altoConsola / 2 - 1);
						Console.Write(tvOracion);

						nuevaOracion = Console.ReadLine();

						ConsoleExt.SetConsoleTitle(nuevaOracion);

						ConsoleExt.GoToCoordinates(3, altoConsola / 2 + 1);
						Console.Write("¡El título fue aplicado correctamente! Presione cualquier tecla para volver al menú principal... ");
						Console.ReadKey(true);
						pantallaActual = Pantalla.MenuPrincipal;

						#endregion

						break;

					case Pantalla.ReaccionDeTeclas:

						#region Reacción de teclas

						ConsoleExt.GoToCoordinates(rtPosicionTituloX, rtPosicionTituloY);
						Console.Write(rtTitulo);

						ConsoleExt.GoToCoordinates(rtPosicionInicialX, rtPosicionTituloY + 3);
						Console.Write(rtOracion1);

						ConsoleExt.GoToCoordinates(rtPosicionInicialX, rtPosicionTituloY + 4);
						Console.Write(rtOracion2);

						while (rtPosicionActualCursorY < altoConsola - 4 && teclaPresionada != ConsoleKey.Escape)
						{
							ConsoleExt.GoToCoordinates(rtPosicionInicialX, rtPosicionActualCursorY);
							Console.Write("Tecla presionada: ");

							teclaPresionada = ConsoleExt.GetKey(true);

							Console.Write(teclaPresionada);

							rtPosicionActualCursorY++;
						}

						ConsoleExt.GoToCoordinates(rtPosicionInicialX, rtPosicionActualCursorY + 1);
						Console.Write("Prueba finalizada. Presione cualquier tecla para volver al menú principal... ");
						Console.ReadKey(true);

						teclaPresionada = 0;
						rtPosicionActualCursorY = rtPosicionInicialY;
						pantallaActual = Pantalla.MenuPrincipal;

						#endregion

						break;

					case Pantalla.ConfirmacionDeSalida:

						#region Confirmación de salida

						ConsoleExt.GoToCoordinates(csPosicionTituloX, csPosicionTituloY);
						Console.Write(csTitulo);

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - csPregunta.Length / 2, altoConsola / 2 - 3);
						Console.Write(csPregunta);

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - csPregunta.Length / 2, altoConsola / 2 - 1);
						Console.Write("1. SÍ");

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - csPregunta.Length / 2, altoConsola / 2);
						Console.Write("2. NO");

						ConsoleExt.GoToCoordinates(anchoConsola / 2 - csPregunta.Length / 2, altoConsola / 2 + 2);
						Console.Write("Opción elegida: ");
						opcionIngresada = int.Parse(Console.ReadLine());

						switch (opcionIngresada)
						{
							case 1:
								enPrograma = false;

								ConsoleExt.GoToCoordinates(anchoConsola / 2 - csPregunta.Length / 2, altoConsola / 2 + 4);
								ConsoleExt.WriteWithColor("Presione cualquier tecla para cerrar la ventana... ", ConsoleColor.Green);

								break;

							case 2:

								pantallaActual = Pantalla.MenuPrincipal;

								break;
						}

						#endregion

						break;
				}
			}



			Console.ReadKey(true);
		}

		static void EscribirColor(ConsoleColor color)
		{
			switch (color)
			{
				case ConsoleColor.Black:
					Console.Write("Negro");
					break;

				case ConsoleColor.DarkBlue:
					Console.Write("Azul oscuro");
					break;

				case ConsoleColor.DarkGreen:
					Console.Write("Verde oscuro");
					break;

				case ConsoleColor.DarkCyan:
					Console.Write("Cian oscuro");
					break;

				case ConsoleColor.DarkRed:
					Console.Write("Rojo oscuro");
					break;

				case ConsoleColor.DarkMagenta:
					Console.Write("Magenta oscuro");
					break;

				case ConsoleColor.DarkYellow:
					Console.Write("Amarillo oscuro");
					break;

				case ConsoleColor.Gray:
					Console.Write("Gris");
					break;

				case ConsoleColor.DarkGray:
					Console.Write("Gris oscuro");
					break;

				case ConsoleColor.Blue:
					Console.Write("Azul");
					break;

				case ConsoleColor.Green:
					Console.Write("Verde");
					break;

				case ConsoleColor.Cyan:
					Console.Write("Cian");
					break;

				case ConsoleColor.Red:
					Console.Write("Rojo");
					break;

				case ConsoleColor.Magenta:
					Console.Write("Magenta");
					break;

				case ConsoleColor.Yellow:
					Console.Write("Amarillo");
					break;

				case ConsoleColor.White:
					Console.Write("Blanco");
					break;
			}
		}
		static void MostrarListaDeColores(int x, int y)
		{
			const int cantColores = 16;


			for (int i = 0; i < cantColores; i++)
			{
				ConsoleExt.GoToCoordinates(x, y + i);
				Console.Write((i + 1) + ". ");
				EscribirColor((ConsoleColor)i);
			}
		}
	}
}

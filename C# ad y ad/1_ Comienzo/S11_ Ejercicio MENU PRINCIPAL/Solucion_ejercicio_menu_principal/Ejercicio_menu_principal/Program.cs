using System;


namespace Ejercicio_menu_principal
{
	class Program
	{
		enum Pantalla { MenuPrincipal, Opciones, Ayuda, Dificultad, Calidad, Brillo, VolumenMusica, VolumenSFX }
		enum Dificultad { Facil = 1, Medio, Dificil, Experto }
		enum CalidadGraficos { Baja = 1, Media, Alta }

		static void Main()
		{
			bool enElJuego = true;

			Pantalla pantallaActual = Pantalla.MenuPrincipal;
			Dificultad dificultad = Dificultad.Medio;
			CalidadGraficos calidadGraficos = CalidadGraficos.Media;

			int brillo = 100;
			int volumenMusica = 100;
			int volumenSfx = 100;

			int opcion = 0;

			int num = 0;


			while (enElJuego)
			{
				Console.Clear();

				switch (pantallaActual)
				{
					case Pantalla.MenuPrincipal:
						Console.WriteLine("--- MENU PRINCIPAL ---\n");
						Console.WriteLine("         1. JUGAR");
						Console.WriteLine("        2. OPCIONES");
						Console.WriteLine("         3. AYUDA");
						Console.WriteLine("         4. SALIR\n");

						Console.Write("Opción elegida: ");
						opcion = int.Parse(Console.ReadLine());
						Console.WriteLine();

						switch (opcion)
						{
							case 1:
								Console.Write("Cargando el juego...");
								enElJuego = false;
								break;

							case 2:
								pantallaActual = Pantalla.Opciones;
								break;

							case 3:
								pantallaActual = Pantalla.Ayuda;
								break;

							case 4:
								Console.Write("Saliendo del juego. Gracias Por jugar! ");
								enElJuego = false;
								break;
						}

						break;


					case Pantalla.Opciones:
						Console.WriteLine("           --- OPCIONES ---\n");
						Console.Write("1. Elegir dificultad (");

						switch (dificultad)
						{
							case Dificultad.Facil:
								Console.Write("Fácil");
								break;

							case Dificultad.Medio:
								Console.Write("Medio");
								break;

							case Dificultad.Dificil:
								Console.Write("Difícil");
								break;

							case Dificultad.Experto:
								Console.Write("Experto");
								break;
						}

						Console.WriteLine(")");
						Console.Write("2. Ver calidad de los gráficos (");

						switch (calidadGraficos)
						{
							case CalidadGraficos.Baja:
								Console.Write("Baja");
								break;

							case CalidadGraficos.Media:
								Console.Write("Media");
								break;

							case CalidadGraficos.Alta:
								Console.Write("Alta");
								break;
						}

						Console.WriteLine(")");
						Console.WriteLine("3. Brillo (" + brillo + "%)");
						Console.WriteLine("4. Volumen de la musica (" + volumenMusica + "%)");
						Console.WriteLine("5. Volumen de SFX (" + volumenSfx + "%)");
						Console.WriteLine("6. Volver al menu principal\n");

						Console.Write("Opción ingresada: ");
						opcion = int.Parse(Console.ReadLine());
						Console.WriteLine();

						switch (opcion)
						{
							case 1:
								pantallaActual = Pantalla.Dificultad;
								break;

							case 2:
								pantallaActual = Pantalla.Calidad;
								break;

							case 3:
								pantallaActual = Pantalla.Brillo;
								break;

							case 4:
								pantallaActual = Pantalla.VolumenMusica;
								break;

							case 5:
								pantallaActual = Pantalla.VolumenSFX;
								break;

							case 6:
								pantallaActual = Pantalla.MenuPrincipal;
								break;
						}

						break;


					case Pantalla.Dificultad:
						Console.WriteLine("  --- DIFICULTAD ---\n");
						Console.WriteLine("Elija la nueva dificultad:\n");
						Console.WriteLine("1. Fácil");
						Console.WriteLine("2. Medio");
						Console.WriteLine("3. Difícil");
						Console.WriteLine("4. Experto\n");

						Console.Write("Opción elegida: ");
						opcion = int.Parse(Console.ReadLine());
						Console.WriteLine();

						if (opcion >= 1 && opcion <= 4)
						{
							dificultad = (Dificultad)opcion;

							pantallaActual = Pantalla.Opciones;
						}

						break;



					case Pantalla.Calidad:
						Console.WriteLine("  --- CALIDAD DE GRÁFICOS ---\n");
						Console.WriteLine("Elija la nueva calidad:\n");
						Console.WriteLine("1. Baja");
						Console.WriteLine("2. Media");
						Console.WriteLine("3. Alta\n");

						Console.Write("Opción elegida: ");
						opcion = int.Parse(Console.ReadLine());
						Console.WriteLine();

						if (opcion >= 1 && opcion <= 3)
						{
							calidadGraficos = (CalidadGraficos)opcion;

							pantallaActual = Pantalla.Opciones;
						}

						break;


					case Pantalla.Brillo:
						Console.WriteLine("  --- BRILLO ---\n");

						do
						{
							Console.Write("Ingrese el nuevo brillo: ");
							brillo = int.Parse(Console.ReadLine());

						} while (brillo < 0 || brillo > 100);

						pantallaActual = Pantalla.Opciones;

						break;



					case Pantalla.VolumenMusica:
						Console.WriteLine("  --- VOLUMEN DE LA MÚSICA ---\n");

						do
						{
							Console.Write("Ingrese el nuevo volumen de la música: ");
							volumenMusica = int.Parse(Console.ReadLine());

						} while (volumenMusica < 0 || volumenMusica > 100);

						pantallaActual = Pantalla.Opciones;

						break;


					case Pantalla.VolumenSFX:
						Console.WriteLine("  --- VOLUMEN DE SFX ---\n");

						do
						{
							Console.Write("Ingrese el nuevo volumen de SFX: ");
							volumenSfx = int.Parse(Console.ReadLine());

						} while (volumenSfx < 0 || volumenSfx > 100);

						pantallaActual = Pantalla.Opciones;

						break;


					case Pantalla.Ayuda:
						Console.WriteLine("         --- AYUDA ---\n");
						Console.Write("Acá se leería la ayuda del juego. ");
						System.Threading.Thread.Sleep(750);
						Console.Write("\nPresione cualquier tecla para volver al menú principal. ");
						Console.ReadKey(true);

						pantallaActual = Pantalla.MenuPrincipal;

						break;
				}
			}

			Console.WriteLine();



			Console.ReadKey(true);
		}
	}
}

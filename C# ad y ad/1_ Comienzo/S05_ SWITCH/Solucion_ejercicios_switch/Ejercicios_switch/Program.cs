using System;


namespace Ejercicios_switch
{
	class Program
	{
		static void Main()
		{
			int opcion = 0;
			char opcionConLetra = '\0';



			Console.WriteLine("--- EJERCICIO 1 ---\n");


			Console.WriteLine("    1. JUGAR"); 
			Console.WriteLine("   2. OPCIONES");
			Console.WriteLine("    3. AYUDA");
			Console.WriteLine("    4. SALIR\n");

			Console.Write("Opción elegida: ");
			opcion = int.Parse(Console.ReadLine());

			Console.WriteLine();

			switch (opcion)
			{
				case 1:
					Console.Write("Cargando el juego... prepárese...");
					break;

				case 2:
					Console.Write("Entrando a la configuración del juego...");
					break;

				case 3:
					Console.Write("Esta sería la pantalla donde se explica el juego.");
					break;

				case 4:
					Console.Write("Cerrando el juego. ¡Gracias por jugar!");
					break;

				default:
					Console.Write("Opción no válida.");
					break;
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("¿Desea salir del juego? Responda con y/n: ");
			opcionConLetra = char.Parse(Console.ReadLine());

			Console.WriteLine();

			switch (opcionConLetra)
			{
				case 'Y':
				case 'y':
					Console.Write("Cerrando el juego...");
					break;

				case 'N':
				case 'n':
					Console.Write("Se vuelve al menú principal.");
					break;

				default:
					Console.Write("Opción no válida.");
					break;
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.WriteLine("    1. JUGAR");
			Console.WriteLine("   2. OPCIONES");
			Console.WriteLine("    3. AYUDA");
			Console.WriteLine("   4. RÉCORDS");
			Console.WriteLine("   5. CRÉDITOS");
			Console.WriteLine("    6. SALIR\n");

			Console.Write("Opción elegida: ");
			opcion = int.Parse(Console.ReadLine());

			Console.WriteLine();

			switch (opcion)
			{
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
					Console.Write("La opción ingresada es válida.");
					break;

				case 50:
					Console.Write("¡Truco activado! ¡Ahora tu jugador es invencible!");
					break;

				default:
					Console.Write("Opción no válida.");
					break;
			}

			Console.WriteLine("\n\n");



			Console.ReadKey(true);
		}
	}
}

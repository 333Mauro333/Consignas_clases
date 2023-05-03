using System;


namespace Ejercicios_funciones_comienzo
{
	class Program
	{
		static void Main()
		{
			int opcion = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			MostrarUnMensaje();

			Console.WriteLine("\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			MostrarMenuDePremio();

			do
			{
				Console.Write("Opción elegida: ");
				opcion = int.Parse(Console.ReadLine());

			} while (opcion < 1 || opcion > 2);

			Console.WriteLine();

			if (opcion == 1)
			{
				MostrarPremio1();
			}
			else
			{
				MostrarPremio2();
			}

			Console.WriteLine();



			Console.ReadKey(true);
		}

		static void MostrarUnMensaje()
		{
			Console.WriteLine("Este mensaje es mostrado mediante una función.");
		}

		static void MostrarMenuDePremio()
		{
			Console.WriteLine("¡Ganaste un premio! Podés reclamarlo eligiendo una puerta a continuación:\n");
			Console.WriteLine("1. PUERTA ROJA");
			Console.WriteLine("2. PUERTA AZUL\n");
		}
		static void MostrarPremio1()
		{
			Console.WriteLine("¡Has recibido un traje a prueba de fuego!\n");
		}
		static void MostrarPremio2()
		{
			Console.WriteLine("¡Has recibido un respirador! ¡Podrás mantenerte un tiempo prolongado bajo el agua!\n");
		}
	}
}

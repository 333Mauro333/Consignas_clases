using System;


namespace Ejercicios_output
{
	class Program
	{
		static void Main()
		{
			int numero = 20;
			int vida = 50;
			char inicial = 'A';



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.WriteLine("Hola, este texto fue escrito por un programador.");
			Console.WriteLine();
			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.WriteLine("Esta es la primera oracion.");
			Console.WriteLine("De la misma forma, escribo la segunda.");
			Console.WriteLine("Con la tercera, resuelvo este ejercicio.");
			Console.WriteLine();
			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.WriteLine("Mi número guardado es " + numero + ".");
			Console.WriteLine();
			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.WriteLine("La vida del jugador es " + vida + " y su inicial es una " + inicial + ".");
			Console.WriteLine();
			Console.WriteLine();



			Console.ReadKey(true);
		}
	}
}

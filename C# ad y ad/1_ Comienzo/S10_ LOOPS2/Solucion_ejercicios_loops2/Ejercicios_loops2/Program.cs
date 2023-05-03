using System;


namespace Ejercicios_loops2
{
	class Program
	{
		static void Main()
		{
			int numero = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese un número: ");
			numero = int.Parse(Console.ReadLine());
			Console.WriteLine();

			for (int i = 1; i <= numero; i++)
			{
				Console.Write(i + " ");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Ingrese un número: ");
			numero = int.Parse(Console.ReadLine());
			Console.WriteLine();

			for (int i = 1; i <= numero; i *= 2)
			{
				Console.Write(i + " ");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese un número: ");
			numero = int.Parse(Console.ReadLine());
			Console.WriteLine();

			for (int i = 1; i < numero; i++)
			{
				Console.Write(i + " ");
			}

			for (int i = numero; i > 0; i--)
			{
				Console.Write(i + " ");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			for (int i = 0; i <= 50; i++)
			{
				if (i % 2 == 0)
				{
					Console.WriteLine(i + ": Es par.");
				}
				else
				{
					Console.WriteLine(i + ": Es impar.");
				}
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 5 ---\n");

			Console.Write("Ingrese un número: ");
			numero = int.Parse(Console.ReadLine());
			Console.WriteLine();

			for (int i = 0; i <= numero; i++)
			{
				Console.WriteLine(i + " - " + (numero - i));
			}



			Console.ReadKey(true);
		}
	}
}

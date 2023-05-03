using System;


namespace Ejercicios_loops3
{
	class Program
	{
		static void Main()
		{
			int numero = 0;

			int filas = 0;
			int columnas = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese un número: ");
			numero = int.Parse(Console.ReadLine());
			Console.WriteLine();

			for (int i = 0; i < numero; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					Console.Write("X");
				}

				Console.WriteLine();
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Ingrese la cantidad de filas: ");
			filas = int.Parse(Console.ReadLine());

			Console.Write("Ingrese la cantidad de columnas: ");
			columnas = int.Parse(Console.ReadLine());
			Console.WriteLine();

			for (int i = 0; i < filas; i++)
			{
				for (int j = 0; j < columnas; j++)
				{
					Console.Write("X");
				}

				Console.WriteLine();
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese la cantidad de filas: ");
			filas = int.Parse(Console.ReadLine());

			Console.Write("Ingrese la cantidad de columnas: ");
			columnas = int.Parse(Console.ReadLine());
			Console.WriteLine();

			for (int i = 0; i < filas; i++)
			{
				for (int j = 0; j < columnas; j++)
				{
					if (i % 2 == 0)
					{
						Console.Write("X");
					}
					else
					{
						Console.Write("O");
					}
				}

				Console.WriteLine();
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Ingrese el tamaño del cuadrado: ");
			numero = int.Parse(Console.ReadLine());
			Console.WriteLine();

			for (int i = 0; i < numero; i++)
			{
				for (int j = 0; j < numero; j++)
				{
					if (i == j)
					{
						Console.Write("O");
					}
					else
					{
						Console.Write("X");
					}
				}

				Console.WriteLine();
			}



			Console.ReadKey(true);
		}
	}
}

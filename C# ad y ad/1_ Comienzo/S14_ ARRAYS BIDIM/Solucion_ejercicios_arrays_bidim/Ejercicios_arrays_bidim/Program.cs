using System;


namespace Ejercicios_arrays_bidim
{
	class Program
	{
		static void Main()
		{
			char[,] arregloBidim1 = new char[3, 5] { { 'A', 'B', 'C', 'D', 'E' },
													 { 'a', 'b', 'c', 'd', 'e' },
													 { 'A', 'B', 'C', 'D', 'E' } };

			int[,] arregloBidim2 = new int[7, 3] { { 0, 1, 0 },
												   { 1, 1, 0 },
												   { 0, 1, 0 },
												   { 0, 1, 0 },
												   { 0, 1, 0 },
												   { 0, 1, 0 },
												   { 1, 1, 1 } };

			char[,] arregloBidim3 = new char[7, 7] { { 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
													 { 'X', '-', '-', '-', '-', 'X', 'X' },
													 { 'X', '-', 'X', '-', '-', '-', 'X' },
													 { 'X', '-', '-', '-', '-', '-', 'X' },
													 { 'X', '-', 'X', '-', '-', '-', 'X' },
													 { 'X', 'J', '-', '-', '-', 'X', 'X' },
													 { 'X', 'X', 'X', 'X', 'X', 'X', 'X' } };



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			for (int i = 0; i < arregloBidim1.GetLength(0); i++)
			{
				for (int j = 0; j < arregloBidim1.GetLength(1); j++)
				{
					Console.Write(arregloBidim1[i, j] + " ");
				}

				Console.WriteLine();
			}

			Console.WriteLine("\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			for (int i = 0; i < arregloBidim2.GetLength(0); i++)
			{
				for (int j = 0; j < arregloBidim2.GetLength(1); j++)
				{
					Console.Write(arregloBidim2[i, j] + " ");
				}

				Console.WriteLine();
			}

			Console.WriteLine("\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			for (int i = 0; i < arregloBidim3.GetLength(0); i++)
			{
				for (int j = 0; j < arregloBidim3.GetLength(1); j++)
				{
					Console.Write(arregloBidim3[i, j] + " ");
				}

				Console.WriteLine();
			}

			Console.WriteLine("\n");



			Console.ReadKey(true);
		}
	}
}

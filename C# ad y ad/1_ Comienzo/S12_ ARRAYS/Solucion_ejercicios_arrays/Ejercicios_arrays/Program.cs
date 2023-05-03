using System;


namespace Ejercicios_arrays
{
	class Program
	{
		static void Main()
		{
			Random generar = new Random();

			int[] arreglo1 = new int[5] { 2, 4, 7, 9, 10 };
			int[] arreglo3 = new int[10];
			int[] arreglo4 = new int[10];
			int[] arreglo5 = new int[5];

			int numero = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			for (int i = 0; i < arreglo1.Length; i++)
			{
				Console.Write(arreglo1[i] + " ");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			for (int i = arreglo1.Length - 1; i >= 0; i--)
			{
				Console.Write(arreglo1[i] + " ");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese un número: ");
			numero = int.Parse(Console.ReadLine());
			Console.WriteLine();

			for (int i = 0; i < arreglo3.Length; i++)
			{
				arreglo3[i] = numero;
			}

			for (int i = 0; i < arreglo3.Length; i++)
			{
				Console.WriteLine("Posición " + (i + 1) + " del arreglo: " + arreglo3[i]);
			}

			Console.WriteLine("\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			for (int i = 0; i < arreglo4.Length; i++)
			{
				arreglo4[i] = generar.Next(51);
			}

			for (int i = 0; i < arreglo4.Length; i++)
			{
				Console.Write(arreglo4[i] + " ");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 5 ---\n");

			for (int i = 0; i < arreglo5.Length; i++)
			{
				Console.Write("Ingrese el numero " + (i + 1) + " del arreglo: ");
				numero = int.Parse(Console.ReadLine());

				arreglo5[i] = numero;
			}

			Console.WriteLine();

			for (int i = 0; i < arreglo5.Length; i++)
			{
				Console.Write(arreglo5[i] + " ");
			}



			Console.ReadKey(true);
		}
	}
}

using System;


namespace Ejercicios_arrays2
{
	class Program
	{
		static void Main()
		{
			Random generar = new Random();

			int[] arreglo1 = new int[5] { 3, 10, 25, 4, 8 };
			bool estaDentroDelArray = false;

			int[] arreglo2 = new int[10] { 2, 7, 18, 46, 35, 25, 72, 30, 88, 51 };

			int[] arreglo3 = new int[5];

			int[] arreglo4 = new int[10] { 25, 45, 30, 1, 22, 51, 50, 30, 99, 75 };

			int[] arreglo5 = new int[5] { 3, 48, 15, 123, 45 };

			int numero = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Numeros del arreglo: ");

			for (int i = 0; i < arreglo1.Length; i++)
			{
				Console.Write(arreglo1[i] + " ");
			}


			Console.Write("\n\nIngrese un número: ");
			numero = int.Parse(Console.ReadLine());

			for (int i = 0; i < arreglo1.Length; i++)
			{
				if (arreglo1[i] == numero)
				{
					estaDentroDelArray = true;
					break;
				}
			}

			if (estaDentroDelArray)
			{
				Console.Write("El numero se encuentra en el arreglo. ");
			}
			else
			{
				Console.Write("El numero no está en el arreglo. ");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Numeros del arreglo: ");

			for (int i = 0; i < arreglo2.Length; i++)
			{
				Console.Write(arreglo2[i] + " ");
			}

			Console.Write("\n\nNúmeros impares: ");

			for (int i = 0; i < arreglo2.Length; i++)
			{
				if (arreglo2[i] % 2 == 1)
				{
					Console.Write(arreglo2[i] + " ");
				}
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			for (int i = 0; i < arreglo3.Length; i++)
			{
				arreglo3[i] = generar.Next(20, 51);
			}

			Console.Write("Numeros del arreglo: ");

			for (int i = 0; i < arreglo3.Length; i++)
			{
				Console.Write(arreglo3[i] + " ");
			}

			Console.Write("\n\nNúmeros con índice par: ");

			for (int i = 0; i < arreglo3.Length; i++)
			{
				if (i % 2 == 0)
				{
					Console.Write(arreglo3[i] + " ");
				}
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Numeros del arreglo: ");

			for (int i = 0; i < arreglo4.Length; i++)
			{
				Console.Write(arreglo4[i] + " ");
			}

			Console.WriteLine("\n");

			do
			{
				Console.WriteLine("Ingrese 1 para mostrar los numeros pares.");
				Console.WriteLine("Ingrese 2 para mostrar los numeros impares.\n");
				Console.Write("Opción ingresada: ");
				numero = int.Parse(Console.ReadLine());

			} while (numero < 1 || numero > 2);

			Console.WriteLine();

			if (numero == 1)
			{
				Console.Write("Números pares del arreglo: ");
			}
			else
			{
				Console.Write("Números impares del arreglo: ");
			}

			for (int i = 0; i < arreglo4.Length; i++)
			{
				if (numero == 1 && arreglo4[i] % 2 == 0)
				{
					Console.Write(arreglo4[i] + " ");
				}
				else if (numero == 2 && arreglo4[i] % 2 == 1)
				{
					Console.Write(arreglo4[i] + " ");
				}
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 5 ---\n");

			Console.Write("Numeros del arreglo: ");

			for (int i = 0; i < arreglo5.Length; i++)
			{
				Console.Write(arreglo5[i] + " ");
			}

			Console.WriteLine("\n");

			do
			{
				Console.Write("Ingrese la posición del número que desea que se escriba (entre 1 y " + arreglo5.Length + "): ");
				numero = int.Parse(Console.ReadLine());

			} while (numero < 1 || numero > arreglo5.Length);

			Console.Write("\n" + arreglo5[numero - 1]);



			Console.ReadKey(true);
		}
	}
}

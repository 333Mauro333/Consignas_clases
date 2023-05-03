using System;


namespace Ejercicios_arrays3
{
	class Program
	{
		static void Main()
		{
			Random generar = new Random();

			int[] arreglo1 = new int[10] { 5, 10, 10, 15, 20, 15, 20, 15, 20, 20 };
			int vecesEncontrado = 0;

			float[] arreglo2 = new float[10];

			int[] arreglo3 = new int[10];
			int posicion = 0;

			int[] arreglo4 = new int[10] { 10, 5, 3, 20, 45, 50, 85, 1, 77, 50 };
			int numeroMasGrande = arreglo4[0];
			int numeroMasChico = arreglo4[0];

			float[] arreglo5 = new float[5];
			float promedio = 0.0f;

			int numero = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Números del arreglo: ");

			for (int i = 0; i < arreglo1.Length; i++)
			{
				Console.Write(arreglo1[i] + " ");
			}

			Console.Write("\n\nIngrese un número: ");
			numero = int.Parse(Console.ReadLine());

			for (int i = 0; i < arreglo1.Length; i++)
			{
				if (numero == arreglo1[i])
				{
					vecesEncontrado++;
				}
			}

			if (vecesEncontrado == 1)
			{
				Console.Write("El número se encontró una vez en el arreglo. ");
			}
			else if (vecesEncontrado > 1)
			{
				Console.Write("El número se encontró " + vecesEncontrado + " veces en el arreglo. ");
			}
			else
			{
				Console.Write("El número no se encontró en el arreglo. ");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			for (int i = 0; i < arreglo2.Length; i++)
			{
				arreglo2[i] = generar.Next(10001);
			}

			for (int i = 0; i < arreglo2.Length; i++)
			{
				arreglo2[i] /= 100.0f;
			}

			for (int i = 0; i < arreglo2.Length; i++)
			{
				Console.WriteLine("Número " + (i + 1) + ": " + arreglo2[i]);
			}

			Console.WriteLine("\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			for (int i = 0; i < arreglo3.Length; i++)
			{
				arreglo3[i] = generar.Next(1, 101);
			}

			Console.Write("Números del arreglo: ");

			for (int i = 0; i < arreglo3.Length; i++)
			{
				Console.Write(arreglo3[i] + " ");
			}

			Console.Write("\n\nIngrese un número: ");
			numero = int.Parse(Console.ReadLine());

			do
			{
				Console.Write("Ingrese un numero de posicion (entre 1 y " + arreglo3.Length + "): ");
				posicion = int.Parse(Console.ReadLine());

			} while (posicion < 1 || posicion > arreglo3.Length);

			arreglo3[posicion - 1] = numero;

			Console.Write("\nNúmeros del arreglo: ");

			for (int i = 0; i < arreglo3.Length; i++)
			{
				Console.Write(arreglo3[i] + " ");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Números del arreglo: ");

			for (int i = 0; i < arreglo4.Length; i++)
			{
				Console.Write(arreglo4[i] + " ");
			}

			Console.WriteLine("\n");

			for (int i = 0; i < arreglo4.Length; i++)
			{
				if (arreglo4[i] < numeroMasChico)
				{
					numeroMasChico = arreglo4[i];
				}
				else if (arreglo4[i] > numeroMasGrande)
				{
					numeroMasGrande = arreglo4[i];
				}
			}

			Console.WriteLine("El número más grande del arreglo es " + numeroMasGrande);
			Console.WriteLine("El número más chico del arreglo es " + numeroMasChico + "\n\n");



			Console.WriteLine("--- EJERCICIO 5 ---\n");

			for (int i = 0; i < arreglo5.Length; i++)
			{
				Console.Write("Ingrese el número " + (i + 1) + " de " + arreglo5.Length + " del arreglo: ");
				arreglo5[i] = float.Parse(Console.ReadLine());
			}

			for (int i = 0; i < arreglo5.Length; i++)
			{
				promedio += arreglo5[i];
			}

			promedio /= arreglo5.Length;

			Console.Write("\nEl promedio da " + promedio);



			Console.ReadKey(true);
		}
	}
}

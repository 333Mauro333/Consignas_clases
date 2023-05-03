using System;


namespace Ejercicios_funciones5_sobrecarga
{
	class Program
	{
		static void Main()
		{
			int[] numeros = new int[5] { 5, 10, 15, 20, 25 };

			string[] nombres = new string[3] { "Mauro", "Guillermo", "José" };



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			MostrarArray(numeros);
			MostrarArray(nombres);

			Console.WriteLine("\n");



			Console.ReadKey(true);
		}


		static void MostrarArray(int[] arregloDeNumeros)
		{
			Console.WriteLine("Arreglo de números: ");

			for (int i = 0; i < arregloDeNumeros.Length; i++)
			{
				Console.Write(arregloDeNumeros[i] + " ");
			}

			Console.WriteLine("\n");		
		}
		static void MostrarArray(string[] arregloDeStrings)
		{
			Console.WriteLine("Arreglo de strings: ");

			for (int i = 0; i < arregloDeStrings.Length; i++)
			{
				Console.Write(arregloDeStrings[i]);

				if (i != arregloDeStrings.Length - 1)
				{
					Console.Write(", ");
				}
			}

			Console.WriteLine("\n");
		}
	}
}

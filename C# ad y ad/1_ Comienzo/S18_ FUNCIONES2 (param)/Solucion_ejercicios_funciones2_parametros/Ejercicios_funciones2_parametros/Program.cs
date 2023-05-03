using System;


namespace Ejercicios_funciones2_parametros
{
	class Program
	{
		static void Main()
		{
			int numero = 0;
			int numero2 = 0;

			int ancho = 0;
			int alto = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese un número: ");
			numero = int.Parse(Console.ReadLine());
			Console.WriteLine();

			MostrarNumeroElevadoAlCuadrado(numero);

			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Ingrese un número: ");
			numero = int.Parse(Console.ReadLine());

			Console.Write("Ingrese otro número: ");
			numero2 = int.Parse(Console.ReadLine());
			Console.WriteLine();

			MostrarDosNumeros(numero, numero2);

			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese un número: ");
			numero = int.Parse(Console.ReadLine());
			Console.WriteLine();

			MostrarTipoDeNumero(numero);

			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Ingrese el ancho del rectángulo: ");
			ancho = int.Parse(Console.ReadLine());

			Console.Write("Ingrese el alto: ");
			alto = int.Parse(Console.ReadLine());
			Console.WriteLine();

			MostrarArea(ancho, alto);



			Console.ReadKey(true);
		}


		static void MostrarNumeroElevadoAlCuadrado(int num)
		{
			Console.WriteLine("El número elevado al cuadrado es " + (num * num) + ".\n");
		}

		static void MostrarDosNumeros(int num1, int num2)
		{
			Console.WriteLine("El primer número es " + num1 + ".");
			Console.WriteLine("El segundo número es " + num2 + ".\n");
		}

		static void MostrarTipoDeNumero(int num)
		{
			if (num > 0)
			{
				Console.Write("El número es positivo.");
			}
			else if (num < 0)
			{
				Console.Write("El número es negativo.");
			}
			else
			{
				Console.Write("El número es cero.");
			}

			Console.WriteLine("\n");
		}

		static void MostrarArea(int ancho, int alto)
		{
			Console.WriteLine("El área del rectángulo es de " + (ancho * alto) + ".\n");
		}
	}
}

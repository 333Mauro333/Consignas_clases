using System;


namespace Ejercicios_loops
{
	class Program
	{
		enum ValidezNumero { NoValido, PrimerLimite, SegundoLimite }

		static void Main()
		{
			ValidezNumero validez = ValidezNumero.NoValido;

			int numero = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.WriteLine("Escala de números:\n");

			while (numero < 10)
			{
				Console.Write(numero + " ");
				numero++;
			}

			Console.WriteLine();
			numero = 0;


			do
			{
				Console.Write(numero + " ");
				numero++;

			} while (numero < 10);

			Console.WriteLine();

			for (int i = 0; i < 10; i++)
			{
				Console.Write(i + " ");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			numero = 1;

			while (numero <= 10)
			{
				Console.Write(numero + " ");
				numero++;
			}

			Console.WriteLine();
			numero = 1;


			do
			{
				Console.Write(numero + " ");
				numero++;

			} while (numero <= 10);

			Console.WriteLine();

			for (int i = 1; i <= 10; i++)
			{
				Console.Write(i + " ");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			do
			{
				Console.Write("Ingrese un número entre 10 y 20: ");
				numero = int.Parse(Console.ReadLine());

			} while (numero < 10 || numero > 20);

			Console.WriteLine("Número válido.\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			do
			{
				Console.Write("Ingrese un número entre 5 y 10 o entre 30 y 40: ");
				numero = int.Parse(Console.ReadLine());

				if (numero >= 5 && numero <= 10)
				{
					validez = ValidezNumero.PrimerLimite;
				}
				else if (numero >= 30 && numero <= 40)
				{
					validez = ValidezNumero.SegundoLimite;
				}
				else
				{
					validez = ValidezNumero.NoValido;
				}

			} while (validez == ValidezNumero.NoValido);

			switch (validez)
			{
				case ValidezNumero.PrimerLimite:
					Console.Write("El número se encuentra dentro del primer límite. ");
					break;

				case ValidezNumero.SegundoLimite:
					Console.Write("El número se encuentra dentro del segundo límite. ");
					break;

				case ValidezNumero.NoValido:
					Console.Write("Si llegaste hasta acá es porque modificaste el código. ");
					break;
			}



			Console.ReadKey(true);
		}
	}
}

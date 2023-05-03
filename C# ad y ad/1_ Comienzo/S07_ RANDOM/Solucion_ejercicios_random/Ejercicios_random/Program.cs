using System;


namespace Ejercicios_random
{
	class Program
	{
		static void Main()
		{
			Random generar = new Random();

			int numero1 = 0;
			int numero2 = 0;
			int numero3 = 0;

			int limMin = 0;
			int limMax = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			numero1 = generar.Next(1, 6);
			numero2 = generar.Next(1, 6);
			numero3 = generar.Next(1, 6);

			Console.WriteLine("Los tres números aleatorios son " + numero1 + ", " + numero2 + " y " + numero3 + ".\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			numero1 = generar.Next(10, 21);
			numero2 = generar.Next(10, 21);
			numero3 = generar.Next(10, 21);

			Console.WriteLine("Los tres números aleatorios son " + numero1 + ", " + numero2 + " y " + numero3 + ".\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese el límite mínimo: ");
			limMin = int.Parse(Console.ReadLine());
			Console.Write("Ingrese el límite máximo: ");
			limMax = int.Parse(Console.ReadLine());

			if (limMin > limMax)
			{
				int auxiliar = 0;

				auxiliar = limMin;
				limMin = limMax;
				limMax = auxiliar;
			}

			numero1 = generar.Next(limMin, limMax + 1);

			Console.WriteLine("Número generado: " + numero1 + ".\n\n");



			Console.ReadKey(true);
		}
	}
}

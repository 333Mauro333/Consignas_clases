using System;


namespace Ejercicios_condicionales
{
	class Program
	{
		static void Main()
		{
			int numero1 = 0;
			int numero2 = 0;

			int numeroGuardado = 15;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese un número: ");
			numero1 = int.Parse(Console.ReadLine());

			if (numero1 > 0)
			{
				Console.Write("El número es positivo");
			}
			else if (numero1 < 0)
			{
				Console.Write("El número es negativo");
			}
			else
			{
				Console.Write("El número es cero");
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.WriteLine("Número guardado: " + numeroGuardado + "\n");

			Console.Write("Ingrese un número: ");
			numero1 = int.Parse(Console.ReadLine());

			if (numero1 == numeroGuardado)
			{
				Console.Write("Los dos números son iguales");
			}
			else
			{
				Console.Write("El numero ingresado es distinto al numero guardado");
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese el primer número: ");
			numero1 = int.Parse(Console.ReadLine());
			Console.Write("Ingrese el segundo número: ");
			numero2 = int.Parse(Console.ReadLine());

			if (numero1 > numero2)
			{
				Console.Write(numero1 + " es más grande que " + numero2);
			}
			else if (numero2 > numero1)
			{
				Console.Write(numero2 + " es más grande que " + numero1);
			}
			else
			{
				Console.Write("Los dos numeros son iguales");
			}

			Console.WriteLine(".\n\n");



			Console.ReadKey(true);
		}
	}
}

using System;


namespace Ejercicios_condicionales3
{
	class Program
	{
		static void Main()
		{
			int anio = 0;

			int numero = 0;
			char opcionChar = '\0';



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese un año: ");
			anio = int.Parse(Console.ReadLine());

			if (anio % 4 == 0)
			{
				Console.Write("El año es bisiesto");
			}
			else
			{
				Console.Write("Se ingresó un año no bisiesto");
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.WriteLine("      1. JUGAR");
			Console.WriteLine("    2. OPCIONES");
			Console.WriteLine("      3. SALIR\n");

			Console.Write("Ingrese la opción deseada: ");
			numero = int.Parse(Console.ReadLine());

			if (numero == 1)
			{
				Console.Write("Cargando el juego...");
			}
			else if (numero == 2)
			{
				Console.Write("Se mostrarán las opciones del juego.");
			}
			else if (numero == 3)
			{
				Console.Write("Saliendo del juego. ¡Gracias por jugar!");
			}
			else
			{
				Console.Write("Ingresaste una opción no válida.");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("¿Desea salir del juego? Responda con y/n: ");
			opcionChar = char.Parse(Console.ReadLine());

			Console.WriteLine();

			if (opcionChar == 'Y' || opcionChar == 'y')
			{
				Console.Write("Saliendo de juego. ¡Gracias por jugar!");
			}
			else if (opcionChar == 'N' || opcionChar == 'n')
			{
				Console.Write("Volviendo al menu principal...");
			}
			else
			{
				Console.Write("Opción no válida.");
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Ingrese un número (debe estar entre 5 y 20 o entre 25 y 40): ");
			numero = int.Parse(Console.ReadLine());

			Console.WriteLine();

			if (numero >= 5 && numero <= 20)
			{
				Console.Write("El número se encuentra entre 5 y 20");
			}
			else if (numero >= 25 && numero <= 40)
			{
				Console.Write("El número se encuentra entre 25 y 20");
			}
			else
			{
				Console.Write("El número no se encuentra dentro de ningún límite");
			}

			Console.WriteLine(".\n\n");



			Console.ReadKey(true);
		}
	}
}

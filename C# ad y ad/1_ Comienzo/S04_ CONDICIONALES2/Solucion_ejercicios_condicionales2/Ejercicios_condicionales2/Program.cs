using System;


namespace Ejercicios_condicionales2
{
	class Program
	{
		static void Main()
		{
			int numero1 = 0;
			int numero2 = 0;

			int jugador1X = 0;
			int jugador1Y = 0;
			int jugador2X = 0;
			int jugador2Y = 0;

			char letra = '\0';



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese el primer número: ");
			numero1 = int.Parse(Console.ReadLine());
			Console.Write("Ingrese el segundo número: ");
			numero2 = int.Parse(Console.ReadLine());

			Console.WriteLine();

			if (numero1 % numero2 == 0)
			{
				Console.Write("El primer numero es divisible por el segundo");
			}
			else
			{
				Console.Write("No es divisible");
			}


			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Ingrese un número: ");
			numero1 = int.Parse(Console.ReadLine());

			if (numero1 % 2 == 0)
			{
				Console.Write("El numero ingresado es par");
			}
			else
			{
				Console.Write("Es impar");
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese un número: ");
			numero1 = int.Parse(Console.ReadLine());

			if (numero1 % 5 == 0)
			{
				Console.Write("El numero ingresado es múltiplo de 5");
			}
			else
			{
				Console.Write("No es múltiplo de 5");
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Ingrese la posición X del jugador 1: ");
			jugador1X = int.Parse(Console.ReadLine());
			Console.Write("Ingrese la posición Y del jugador 1: ");
			jugador1Y = int.Parse(Console.ReadLine());
			Console.Write("Ingrese la posición X del jugador 2: ");
			jugador2X = int.Parse(Console.ReadLine());
			Console.Write("Ingrese la posición Y del jugador 2: ");
			jugador2Y = int.Parse(Console.ReadLine());

			Console.WriteLine();

			if (jugador1X == jugador2X && jugador1Y == jugador2Y)
			{
				Console.Write("Los jugadores se encuentran en la misma posicion");
			}
			else
			{
				Console.Write("Los jugadores se encuentran en posiciones diferentes");
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 5 ---\n");

			Console.Write("Ingrese una letra: ");
			letra = char.Parse(Console.ReadLine());

			Console.WriteLine();

			if (letra == 'A' || letra == 'a' || letra == 'E' || letra == 'e' || letra == 'I' || letra == 'i' || letra == 'O' || letra == 'o' || letra == 'U' || letra == 'u')
			{
				Console.Write("La letra ingresada es una vocal");
			}
			else
			{
				Console.Write("La letra ingresada es una consonante");
			}

			Console.WriteLine(".\n\n");



			Console.ReadKey(true);
		}
	}
}

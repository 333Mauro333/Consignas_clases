using System;


namespace Ejercicios_funciones3_retorno
{
	class Program
	{
		static void Main()
		{
			int doble = 0;

			int limiteMinimo = 10;
			int limiteMaximo = 20;

			char letra = '\0';

			int num = 0;
			int num2 = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese un número: ");
			num = int.Parse(Console.ReadLine());

			doble = ObtenerElDoble(num);

			Console.WriteLine("El doble del número ingresado es " + doble + ".\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Ingrese un número: ");
			num = int.Parse(Console.ReadLine());

			Console.Write("Ingrese otro número: ");
			num2 = int.Parse(Console.ReadLine());

			Console.WriteLine("El resultado de la suma es " + ObtenerSuma(num, num2) + ".\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			num = PedirNumero(limiteMinimo, limiteMaximo);

			Console.WriteLine("Número ingresado: " + num + ".\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("¿Desea salir del juego? Responda con y/n: ");
			letra = char.Parse(Console.ReadLine());

			if (LetraEsValida(letra))
			{
				Console.Write("La letra ingresada es válida. ");
			}
			else
			{
				Console.Write("Letra no válida. ");
			}



			Console.ReadKey(true);
		}


		static int ObtenerElDoble(int numero)
		{
			int doble = numero * 2;

			return doble;
		}

		static int ObtenerSuma(int num1, int num2)
		{
			int suma = num1 + num2;

			return suma;
		}

		static int PedirNumero(int limMin, int limMax)
		{
			int num = 0;


			do
			{
				Console.Write("Ingrese un número (entre " + limMin + " y " + limMax + "): ");
				num = int.Parse(Console.ReadLine());

			} while (num < limMin || num > limMax);

			return num;
		}

		static bool LetraEsValida(char letra)
		{
			bool esValida = false;

			if (letra == 'Y' || letra == 'y' || letra == 'N' || letra == 'n')
			{
				esValida = true;
			}
			else
			{
				esValida = false;
			}

			return esValida;
		}
	}
}

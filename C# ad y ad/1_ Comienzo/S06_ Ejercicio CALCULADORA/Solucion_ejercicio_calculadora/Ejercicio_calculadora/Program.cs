using System;


namespace Ejercicio_calculadora
{
	class Program
	{
		static void Main()
		{
			float numero1 = 0;
			float numero2 = 0;
			float resultado = 0;

			int opcion = 0;



			Console.WriteLine("--- CALCULADORA ---\n\n");

			Console.Write("Ingrese el primer número: ");
			numero1 = float.Parse(Console.ReadLine());

			Console.WriteLine("\n¿Qué operación desea realizar?\n");

			Console.WriteLine("1. SUMA");
			Console.WriteLine("2. RESTA");
			Console.WriteLine("3. MULTIPLICACIÓN");
			Console.WriteLine("4. DIVISIÓN\n");

			Console.Write("Opción a elegir: ");
			opcion = int.Parse(Console.ReadLine());

			Console.Write("Ingrese el segundo número: ");
			numero2 = float.Parse(Console.ReadLine());

			// Tiempo de espera.
			Console.Write("Calculando.");
			System.Threading.Thread.Sleep(1000);
			Console.Write(".");
			System.Threading.Thread.Sleep(1000);
			Console.Write(".");
			System.Threading.Thread.Sleep(2000);

			Console.Write("\n\nEl resultado de la ");

			switch (opcion)
			{
				case 1:
					resultado = numero1 + numero2;
					Console.Write("suma");
					break;

				case 2:
					resultado = numero1 - numero2;
					Console.Write("resta");
					break;

				case 3:
					resultado = numero1 * numero2;
					Console.Write("multiplicación");
					break;

				case 4:
					resultado = numero1 / numero2;
					Console.Write("división");
					break;
			}

			Console.WriteLine(" es " + resultado + ".\n\n");



			Console.ReadKey(true);
		}
	}
}

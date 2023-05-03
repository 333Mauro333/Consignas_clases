using System;


namespace Ejercicios_input
{
	class Program
	{
		static void Main()
		{
			int numero = 0;

			int dia = 0;
			int mes = 0;
			int anio = 0;

			int vida = 0;
			int escudo = 0;

			string nombre = "";
			int edad = 0;
			float altura = 0.0f;


			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese un número: ");
			numero = int.Parse(Console.ReadLine());

			Console.WriteLine("El número ingresado es " + numero + ".");
			Console.WriteLine();
			Console.WriteLine();

			

			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Ingrese el día: ");
			dia = int.Parse(Console.ReadLine());

			Console.Write("Ingrese el mes: ");
			mes = int.Parse(Console.ReadLine());

			Console.Write("Ingrese el año: ");
			anio = int.Parse(Console.ReadLine());

			Console.WriteLine("Fecha ingresada: " + dia + "/" + mes + "/" + anio);
			Console.WriteLine();
			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese la vida del personaje: ");
			vida = int.Parse(Console.ReadLine());

			Console.Write("Ingrese el escudo del personaje: ");
			escudo = int.Parse(Console.ReadLine());

			Console.WriteLine();
			Console.WriteLine("Vida: " + vida + ".");
			Console.WriteLine("Escudo: " + escudo + ".");
			Console.WriteLine();
			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Ingrese su nombre: ");
			nombre = Console.ReadLine();

			Console.Write("Ingrese su edad: ");
			edad = int.Parse(Console.ReadLine());

			Console.Write("Ingrese su altura: ");
			altura = float.Parse(Console.ReadLine());

			Console.WriteLine();
			Console.WriteLine("Nombre: " + nombre + ".");
			Console.WriteLine("Edad: " + edad + " años.");
			Console.WriteLine("Altura: " + altura + " m.");
			Console.WriteLine();
			Console.WriteLine();



			Console.ReadKey(true);
		}
	}
}

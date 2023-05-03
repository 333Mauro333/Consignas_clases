using System;


namespace Ejercicios_operadores2
{
	class Program
	{
		static void Main()
		{
			float tempCelsius = 0.0f;
			float distanciaEnKM = 0.0f;
			float pesoEnGramos = 0.0f;
			float resultado = 0.0f;

			int bytes = 0;

			int vida = 0;
			int danio = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese la temperatura (en grados Celsius): ");
			tempCelsius = float.Parse(Console.ReadLine());

			Console.WriteLine();
			Console.WriteLine("Temperatura en grados Kelvin: " + (tempCelsius + 273.15f) + "\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Ingrese la distancia en kilómetros: ");
			distanciaEnKM = float.Parse(Console.ReadLine());

			Console.WriteLine();
			Console.WriteLine("Distancia en metros: " + distanciaEnKM * 1000.0f + "\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese el peso en gramos: ");
			pesoEnGramos = float.Parse(Console.ReadLine());

			resultado = pesoEnGramos / 1000.0f;

			Console.WriteLine();
			Console.WriteLine("Peso en kilogramos: " + resultado + "\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Ingrese la cantidad de bytes: ");
			bytes = int.Parse(Console.ReadLine());

			Console.WriteLine();
			Console.WriteLine("Cantidad convertida a bits: " + bytes * 8 + "\n\n");



			Console.WriteLine("--- EJERCICIO 5 ---\n");

			Console.Write("Ingrese la vida del personaje: ");
			vida = int.Parse(Console.ReadLine());
			Console.Write("Ingrese el daño que va a recibir: ");
			danio = int.Parse(Console.ReadLine());

			vida -= danio;

			Console.WriteLine();
			Console.WriteLine("Vida del personaje: " + vida + ".\n\n");



			Console.ReadKey(true);
		}
	}
}

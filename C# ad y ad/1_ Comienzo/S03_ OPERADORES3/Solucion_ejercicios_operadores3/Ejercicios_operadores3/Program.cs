using System;


namespace Ejercicios_operadores3
{
	class Program
	{
		static void Main()
		{
			const float pi = 3.1415926535f;

			float velocidadEnKMH = 0.0f;

			float nota1 = 0.0f;
			float nota2 = 0.0f;
			float nota3 = 0.0f;
			float promedio = 0.0f;

			float diametro = 0.0f;
			float radio = 0.0f;
			float area = 0.0f;
			float perimetro = 0.0f;

			float grados = 0.0f;
			float radianes = 0.0f;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese la velocidad (en KM/H): ");
			velocidadEnKMH = float.Parse(Console.ReadLine());

			Console.WriteLine("\nVelocidad en metros por segundo: " + velocidadEnKMH * 1000.0f / 3600.0f + "\n\n");
			// Otra forma de resolverlo es haciendo directamente:     velocidadEnKMH / 3.6f.



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Ingrese la primera nota: ");
			nota1 = float.Parse(Console.ReadLine());
			Console.Write("Ingrese la segunda nota: ");
			nota2 = float.Parse(Console.ReadLine());
			Console.Write("Ingrese la tercera nota: ");
			nota3 = float.Parse(Console.ReadLine());

			promedio = (nota1 + nota2 + nota3) / 3.0f;

			Console.WriteLine("\nLa nota promedio es " + promedio + ".\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese el diámetro del círculo: ");
			diametro = float.Parse(Console.ReadLine());

			radio = diametro / 2.0f; // El radio es igual a la mitad del diametro.
			area = pi * (radio * radio); // El área es igual a PI por la elevación al cuadrado del radio.
			perimetro = 2 * radio * pi; // El perímetro es igual a 2 por radio por PI.
										// También se puede hacer directamente: diametro * PI.

			Console.WriteLine("Su radio: " + radio);
			Console.WriteLine("Su área: " + area);
			Console.WriteLine("Su perímetro: " + perimetro + "\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Ingrese un ángulo (en grados): ");
			grados = float.Parse(Console.ReadLine());

			radianes = grados * pi / 180.0f;

			Console.WriteLine("\nResultado: " + radianes + " rad.\n\n");



			Console.ReadKey(true);
		}

		// Calculadora de valores del círculo a partir del radio: https://www.calkoo.com/es/calculadora-circulo
		// Calculadora de grados a radianes: https://es.planetcalc.com/71/
	}
}

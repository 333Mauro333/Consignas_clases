using System;


namespace Ejercicios_operadores
{
	class Program
	{
		static void Main()
		{
			float numero1 = 0.0f;
			float numero2 = 0.0f;

			float numero = 0.0f;

			float resultado = 0.0f;

			int primerNumero = 0;
			int segundoNumero = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese el primer número: ");
			numero1 = float.Parse(Console.ReadLine());
			Console.Write("Ingrese el segundo número: ");
			numero2 = float.Parse(Console.ReadLine());

			Console.WriteLine();
			Console.WriteLine("Resultado de la suma: " + (numero1 + numero2) + ".\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Ingrese un número: ");
			numero = float.Parse(Console.ReadLine());

			Console.WriteLine("Su doble es " + numero * 2);
			Console.WriteLine("Su mitad es " + numero / 2 + "\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese un número: ");
			numero = float.Parse(Console.ReadLine());

			resultado = numero * numero * numero;

			Console.WriteLine(numero + " elevado al cubo da " + resultado + "\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Ingrese el primer número: ");
			numero1 = float.Parse(Console.ReadLine());
			Console.Write("Ingrese el segundo número: ");
			numero2 = float.Parse(Console.ReadLine());

			Console.WriteLine();
			Console.WriteLine("La suma da " + (numero1 + numero2));
			Console.WriteLine("La resta da " + (numero1 - numero2));
			Console.WriteLine("La multiplicación da " + (numero1 * numero2));
			Console.WriteLine("La división da " + (numero1 / numero2) + "\n\n");



			Console.WriteLine("--- EJERCICIO 5 ---\n");

			Console.Write("Ingrese el primer número: ");
			primerNumero = int.Parse(Console.ReadLine());
			Console.Write("Ingrese el segundo número: ");
			segundoNumero = int.Parse(Console.ReadLine());

			Console.WriteLine("El resultado de la división da " + primerNumero / segundoNumero);
			Console.WriteLine("El resto de la división da " + primerNumero % segundoNumero + "\n\n");



			Console.ReadKey(true);
		}
	}
}

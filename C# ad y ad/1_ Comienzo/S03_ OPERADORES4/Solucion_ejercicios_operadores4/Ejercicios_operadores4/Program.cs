using System;


namespace Ejercicios_operadores4
{
	class Program
	{
		static void Main()
		{
			int numero = 0;

			int unidades = 0;
			int decenas = 0;
			int centenas = 0;
			int unidadesDeMil = 0;

			int dia = 0;
			int mes = 0;
			int anio = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese un número de 4 cifras: ");
			numero = int.Parse(Console.ReadLine());

			unidades = numero % 10; // Obtengo el resto tras dividirlo por 10. Darían las unidades.
			decenas = numero / 10 % 10; // Lo divido por 10 (las decenas quedan como unidades) y repito el paso de arriba.
			centenas = numero / 100 % 10; // Lo divido por 100 (las centenas quedan como unidades) y lo mismo de arriba.
			unidadesDeMil = numero / 1000; // Al dividir por 1000, solamente la unidad de mil queda en la parte entera.

			Console.WriteLine("\nUnidades de mil: " + unidadesDeMil);
			Console.WriteLine("Centenas: " + centenas);
			Console.WriteLine("Decenas: " + decenas);
			Console.WriteLine("Unidades: " + unidades + "\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			numero = 25122022;

			Console.WriteLine("Número a descomponer: " + numero + "\n");

			dia = numero / 1000000;     // Cada "0" saca una cifra del número. Se sacan las necesarias para que
										// quede solamente el 25.

			mes = numero / 10000 % 100; // Sacando 4 cifras, el resultado da "2512". Se obtiene el resto al dividir por 100
										// y finalmente nos queda el mes.

			anio = numero % 10000;      // Cantidad de "0" que ponemos, cantidad de cifras que nos quedan. 4 ceros, 4 cifras.

			Console.WriteLine("Fecha: " + dia + "/" + mes + "/" + anio + "\n\n");



			Console.ReadKey(true);
		}
	}
}

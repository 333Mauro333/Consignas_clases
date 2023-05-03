using System;


namespace Ejercicios_arrays4_chars
{
	class Program
	{
		static void Main()
		{
			char letra = '\0';
			int vecesEncontrada = 0;

			int cantidadVocales = 0;
			int cantidadConsonantes = 0;

			int vocalesA = 0;
			int vocalesE = 0;
			int vocalesI = 0;
			int vocalesO = 0;
			int vocalesU = 0;

			string oracion = "";



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese una oración: ");
			oracion = Console.ReadLine();

			Console.Write("\nLa oración tiene " + oracion.Length + " ");

			if (oracion.Length != 1)
			{
				Console.Write("caracteres");
			}
			else
			{
				Console.Write("carácter");
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Ingrese una oración: ");
			oracion = Console.ReadLine();

			Console.Write("Ingrese una letra: ");
			letra = char.Parse(Console.ReadLine());
			Console.WriteLine();

			for (int i = 0; i < oracion.Length; i++)
			{
				if (oracion[i] == letra)
				{
					vecesEncontrada++;
				}
			}

			Console.Write("La letra se encuentra " + vecesEncontrada + " ve");

			if (vecesEncontrada != 1)
			{
				Console.Write("ces");
			}
			else
			{
				Console.Write("z");
			}

			Console.WriteLine(" en la oración.\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese una oración: ");
			oracion = Console.ReadLine();

			for (int i = 0; i < oracion.Length; i++)
			{
				if ((oracion[i] >= 65 && oracion[i] <= 90) || (oracion[i] >= 97 && oracion[i] <= 122))
				{
					if (oracion[i] == 'a' || oracion[i] == 'e' || oracion[i] == 'i' || oracion[i] == 'o' || oracion[i] == 'u' || oracion[i] == 'A' || oracion[i] == 'E' || oracion[i] == 'I' || oracion[i] == 'O' || oracion[i] == 'U')
					{
						cantidadVocales++;
					}
					else
					{
						cantidadConsonantes++;
					}
				}
			}

			Console.Write("\nEn la oración hay " + cantidadVocales + " vocal");

			if (cantidadVocales != 1)
			{
				Console.Write("es");
			}

			Console.Write(" y " + cantidadConsonantes + " consonante");

			if (cantidadConsonantes != 1)
			{
				Console.Write("s");
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Ingrese una oración: ");
			oracion = Console.ReadLine();

			for (int i = 0; i < oracion.Length; i++)
			{
				if (oracion[i] == 'A' || oracion[i] == 'a')
				{
					vocalesA++;
				}
				else if (oracion[i] == 'E' || oracion[i] == 'e')
				{
					vocalesE++;
				}
				else if (oracion[i] == 'I' || oracion[i] == 'i')
				{
					vocalesI++;
				}
				else if (oracion[i] == 'O' || oracion[i] == 'o')
				{
					vocalesO++;
				}
				else if (oracion[i] == 'U' || oracion[i] == 'u')
				{
					vocalesU++;
				}
			}

			Console.WriteLine("Cantidad de vocales:\n");
			Console.WriteLine("Vocales A: " + vocalesA);
			Console.WriteLine("Vocales E: " + vocalesE);
			Console.WriteLine("Vocales I: " + vocalesI);
			Console.WriteLine("Vocales O: " + vocalesO);
			Console.WriteLine("Vocales U: " + vocalesU + "\n\n");



			Console.WriteLine("--- EJERCICIO 5 ---\n");

			Console.Write("Ingrese una oración: ");
			oracion = Console.ReadLine();

			Console.WriteLine("\nOración normal: " + oracion);
			Console.Write("Oración invertida: ");

			for (int i = oracion.Length - 1; i >= 0; i--)
			{
				Console.Write(oracion[i]);
			}

			Console.WriteLine("\n\n");



			Console.WriteLine("--- EJERCICIO 6 ---\n");

			Console.Write("Ingrese una oración: ");
			oracion = Console.ReadLine();

			Console.WriteLine("\nOración normal: " + oracion);
			Console.Write("Oración en mayúsculas: ");

			for (int i = 0; i < oracion.Length; i++)
			{
				if (oracion[i] >= 97 && oracion[i] <= 122)
				{
					Console.Write((char)(oracion[i] - 32));
				}
				else
				{
					Console.Write(oracion[i]);
				}
			}



			Console.ReadKey(true);
		}
	}
}

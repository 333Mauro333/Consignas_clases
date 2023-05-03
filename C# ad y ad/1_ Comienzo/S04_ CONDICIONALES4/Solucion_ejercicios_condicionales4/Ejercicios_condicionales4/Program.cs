using System;


namespace Ejercicios_condicionales4
{
	class Program
	{
		static void Main()
		{
			char letra = '\0';



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese un carácter: ");
			letra = char.Parse(Console.ReadLine());

			if ((letra >= 65 && letra <= 90) || (letra >= 97 && letra <= 122))
			{
				Console.Write("Se ha ingresado una letra");
			}
			else
			{
				Console.Write("El carácter ingresado no es una letra");
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			if (letra >= 65 && letra <= 90)
			{
				Console.Write("Se ha ingresado una letra mayúscula");
			}
			else if (letra >= 97 && letra <= 122)
			{
				Console.Write("Se ha ingresado una letra minúscula");
			}
			else
			{
				Console.Write("El carácter ingresado no es una letra");
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			if (letra >= 65 && letra <= 90)
			{
				Console.Write("Se ha ingresado una letra mayúscula ");

				if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
				{
					Console.Write("vocal");
				}
				else
				{
					Console.Write("consonante");
				}
			}
			else if (letra >= 97 && letra <= 122)
			{
				Console.Write("Se ha ingresado una letra minúscula ");

				if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
				{
					Console.Write("vocal");
				}
				else
				{
					Console.Write("consonante");
				}
			}
			else
			{
				Console.Write("El carácter ingresado no es una letra");
			}

			Console.WriteLine(".\n\n");



			Console.ReadKey(true);
		}
	}
}

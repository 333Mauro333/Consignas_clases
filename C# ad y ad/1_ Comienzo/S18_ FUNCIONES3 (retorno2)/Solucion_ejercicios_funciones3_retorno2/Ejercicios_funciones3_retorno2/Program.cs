using System;


namespace Ejercicios_funciones3_retorno2
{
	class Program
	{
		struct Fecha
		{
			public int dia;
			public int mes;
			public int anio;
		}
		struct Persona
		{
			public string nombre;
			public Fecha fechaNac;
		}

		static void Main()
		{
			int num = 0;
			int num2 = 0;
			int numMasGrande = 0;

			string oracion = "";
			string oracionEnMayuscula = "";

			Persona[] persona = new Persona[2];
			Persona personaMasGrande = new Persona();



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese un número: ");
			num = int.Parse(Console.ReadLine());

			Console.Write("Ingrese otro número: ");
			num2 = int.Parse(Console.ReadLine());

			numMasGrande = ObtenerNumeroMasGrande(num, num2);

			Console.WriteLine("El número más grande es " + numMasGrande + ".\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Ingrese una oración: ");
			oracion = Console.ReadLine();

			oracionEnMayuscula = ObtenerOracionEnMayuscula(oracion);
			
			// Afortunadamente, en C#, se pueden contar con un montón de funciones que parten de las variables.
			// Se hace mención de esto porque entre tantas funciones, ya existe una que devuelve el texto con
			// letras mayúsculas. A partir de esto, la forma alternativa de resolver este ejercicio es:
			//
			// oracionEnMayuscula = oracion.ToUpper();

			Console.WriteLine("Oración original: " + oracion);
			Console.WriteLine("Oración en mayúscula: " + oracionEnMayuscula + "\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			for (int i = 0; i < persona.Length; i++)
			{
				Console.Write("Ingrese el nombre de la persona " + (i + 1) + ": ");
				persona[i].nombre = Console.ReadLine();

				Console.WriteLine("\nIngrese la fecha de nacimiento: ");
				Console.Write("Día: ");
				persona[i].fechaNac.dia = int.Parse(Console.ReadLine());

				Console.Write("Mes: ");
				persona[i].fechaNac.mes = int.Parse(Console.ReadLine());

				Console.Write("Año: ");
				persona[i].fechaNac.anio = int.Parse(Console.ReadLine());
			}

			personaMasGrande = ObtenerLaPersonaMasGrande(persona[0], persona[1]);

			Console.WriteLine();

			MostrarDatosDeLaPersona(personaMasGrande);



			Console.ReadKey(true);
		}


		static int ObtenerNumeroMasGrande(int num1, int num2)
		{
			if (num1 >= num2)
			{
				return num1;
			}
			else
			{
				return num2;
			}
		}

		static string ObtenerOracionEnMayuscula(string oracion)
		{
			string oracionEnMayusc = oracion;


			for (int i = 0; i < oracionEnMayusc.Length; i++)
			{
				if (oracionEnMayusc[i] >= 97 && oracionEnMayusc[i] <= 122)
				{
					oracionEnMayusc = oracionEnMayusc.Replace(oracionEnMayusc[i], (char)(oracionEnMayusc[i] - (char)32));
				}
			}


			return oracionEnMayusc;
		}

		static Persona ObtenerLaPersonaMasGrande(Persona persona1, Persona persona2)
		{
			if (persona1.fechaNac.anio < persona2.fechaNac.anio) // Año más chico (nació antes)...
			{
				return persona1;
			}
			else if (persona1.fechaNac.anio > persona2.fechaNac.anio) // Año más grande (nació después)...
			{
				return persona2;
			}
			else
			{
				if (persona1.fechaNac.mes < persona2.fechaNac.mes) // Nació meses antes...
				{
					return persona1;
				}
				else if (persona1.fechaNac.mes > persona2.fechaNac.mes) // Nació meses después...
				{
					return persona2;
				}
				else
				{
					if (persona1.fechaNac.dia <= persona2.fechaNac.dia) // Nació días antes o el mismo día...
					{
						return persona1;
					}
					else
					{
						return persona2;
					}
				}
			}
		}
		static void MostrarDatosDeLaPersona(Persona persona)
		{
			Console.WriteLine("Nombre: " + persona.nombre);
			Console.Write("Fecha de nacimiento: ");

			if (persona.fechaNac.dia < 10)
			{
				Console.Write("0");
			}

			Console.Write(persona.fechaNac.dia + "/");

			if (persona.fechaNac.mes < 10)
			{
				Console.Write("0");
			}

			Console.Write(persona.fechaNac.mes + "/" + persona.fechaNac.anio + ".\n");
		}
	}
}

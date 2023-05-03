using System;


namespace Ejercicios_structs
{
	class Program
	{
		struct Fecha
		{
			public int dia;
			public int mes;
			public int anio;
		};
		struct Usuario
		{
			public string nombre;
			public string apellido;
			public int edad;
			public Fecha fechaNac;
		};
		struct Posicion
		{
			public int x;
			public int y;
		};
		struct Personaje
		{
			public string nombre;
			public int energia;
			public Posicion posicion;
		};

		static void Main()
		{
			Usuario usuario1 = new Usuario();

			Fecha fecha = new Fecha();
			bool fechaValida = false;

			Posicion posicion = new Posicion();

			Usuario usuario4 = new Usuario();

			Personaje[] personajes = new Personaje[3];



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese su nombre: ");
			usuario1.nombre = Console.ReadLine();

			Console.Write("Ingrese su edad: ");
			usuario1.edad = int.Parse(Console.ReadLine());

			Console.WriteLine("Su nombre es " + usuario1.nombre + ". Su edad es: " + usuario1.edad + " años.\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			do
			{
				do
				{
					Console.Write("Ingrese el día: ");
					fecha.dia = int.Parse(Console.ReadLine());

				} while (fecha.dia < 1 || fecha.dia > 31);

				do
				{
					Console.Write("Ingrese el mes (número entre 1 y 12): ");
					fecha.mes = int.Parse(Console.ReadLine());

				} while (fecha.mes < 1 || fecha.mes > 12);

				do
				{
					Console.Write("Ingrese el año: ");
					fecha.anio = int.Parse(Console.ReadLine());

				} while (fecha.anio < 0);

				// Meses con 31 días.
				if (fecha.mes == 1 || fecha.mes == 3 || fecha.mes == 5 || fecha.mes == 7 || fecha.mes == 8 || fecha.mes == 10 || fecha.mes == 12)
				{
					fechaValida = true;
				}
				else if ((fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11) && fecha.dia <= 30)  // Meses con 30.
				{
					fechaValida = true;
				}
				else // Febrero.
				{
					if (fecha.anio % 4 == 0 && fecha.dia <= 29) // Si es bisiesto...
					{
						fechaValida = true;
					}
					else if (fecha.dia <= 28) // Si el día ingresado es 28 como máximo...
					{
						fechaValida = true;
					}
				}

				if (!fechaValida)
				{
					Console.Write("Fecha no válida. Presione cualquier tecla para volver a ingresar la fecha... ");
					Console.ReadKey(true);
					Console.Clear();
					Console.WriteLine("--- EJERCICIO 2 ---\n");
				}

			} while (!fechaValida);

			Console.WriteLine("\nFecha: " + fecha.dia + "/" + fecha.mes + "/" + fecha.anio + "\n");
			Console.Write("Fecha: " + fecha.dia + " de ");

			switch (fecha.mes)
			{
				case 1:
					Console.Write("enero");
					break;

				case 2:
					Console.Write("febrero");
					break;

				case 3:
					Console.Write("marzo");
					break;

				case 4:
					Console.Write("abril");
					break;

				case 5:
					Console.Write("mayo");
					break;

				case 6:
					Console.Write("junio");
					break;

				case 7:
					Console.Write("julio");
					break;

				case 8:
					Console.Write("agosto");
					break;

				case 9:
					Console.Write("septiembre");
					break;

				case 10:
					Console.Write("octubre");
					break;

				case 11:					
					Console.Write("noviembre");
					break;

				case 12:
					Console.Write("diciembre");
					break;
			}

			Console.WriteLine(" de " + fecha.anio + "\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese la posición X: ");
			posicion.x = int.Parse(Console.ReadLine());

			Console.Write("Ingrese la posición Y: ");
			posicion.y = int.Parse(Console.ReadLine());

			Console.WriteLine("\nPosición ingresada: (" + posicion.x + "; " + posicion.y + ").\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Ingrese su nombre: ");
			usuario4.nombre = Console.ReadLine();

			Console.Write("Ingrese su apellido: ");
			usuario4.apellido = Console.ReadLine();

			// Se podría verificar la validez de la fecha como en el ejercicio 2, pero en este caso
			// se va a omitir para no repetir lo mismo y hacerlo más extenso.
			Console.WriteLine("Ingrese su fecha de nacimiento:\n");

			Console.Write("Día: ");
			usuario4.fechaNac.dia = int.Parse(Console.ReadLine());

			Console.Write("Mes (en número): ");
			usuario4.fechaNac.mes = int.Parse(Console.ReadLine());

			Console.Write("Año: ");
			usuario4.fechaNac.anio = int.Parse(Console.ReadLine());

			Console.WriteLine("\nNombre: " + usuario4.nombre + ".");
			Console.WriteLine("Apellido: " + usuario4.apellido + ".");
			Console.WriteLine("Fecha de nacimiento: " + usuario4.fechaNac.dia + "/" + usuario4.fechaNac.mes + "/" + usuario4.fechaNac.anio + ".\n\n");



			Console.WriteLine("--- EJERCICIO 5 ---\n");

			for (int i = 0; i < personajes.Length; i++)
			{
				Console.WriteLine("Datos del personaje " + (i + 1) + " de " + personajes.Length + ":\n");

				Console.Write("Ingrese el nombre: ");
				personajes[i].nombre = Console.ReadLine();

				do
				{
					Console.Write("Ingrese la cantidad de energía del personaje: ");
					personajes[i].energia = int.Parse(Console.ReadLine());

				} while (personajes[i].energia < 0 || personajes[i].energia > 100);

				Console.Write("Ingrese la posición X del personaje: ");
				personajes[i].posicion.x = int.Parse(Console.ReadLine());

				Console.Write("Ingrese la posición Y del personaje: ");
				personajes[i].posicion.y = int.Parse(Console.ReadLine());
				Console.WriteLine("\n");
			}

			for (int i = 0; i < personajes.Length; i++)
			{
				Console.WriteLine("Datos del personaje " + (i + 1) + ":\n");
				Console.WriteLine("Nombre: " + personajes[i].nombre);
				Console.WriteLine("Energía: " + personajes[i].energia);
				Console.WriteLine("Posición: (" + personajes[i].posicion.x + "; " + personajes[i].posicion.y + ").\n");
			}



			Console.ReadKey(true);
		}
	}
}

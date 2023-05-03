using System;


namespace Ejercicios_input2
{
	class Program
	{
		static void Main()
		{
			int dia = 0;
			int mes = 0;
			int anio = 0;
			int hora = 0;
			int minutos = 0;

			string nombre = "";
			int velocidad = 0;
			int fuerza = 0;
			string poderEspecial = "";



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.WriteLine("--- INGRESO DE FECHA Y HORA ---");
			Console.WriteLine();
			Console.Write("Ingrese el día actual: ");
			dia = int.Parse(Console.ReadLine());
			Console.Write("Ingrese el mes actual: ");
			mes = int.Parse(Console.ReadLine());
			Console.Write("Ingrese el año actual: ");
			anio = int.Parse(Console.ReadLine());

			Console.WriteLine();
			Console.Write("Ingrese la hora actual: ");
			hora = int.Parse(Console.ReadLine());
			Console.Write("Ingrese los minutos actuales: ");
			minutos = int.Parse(Console.ReadLine());

			Console.Write("Datos guardados. Se procederá al menú de creación de personaje. ");
			Console.ReadKey(true);
			Console.Clear();


			Console.WriteLine("--- CREACIÓN DE PERSONAJE ---\n");

			Console.Write("Ingrese el nombre de su personaje: ");
			nombre = Console.ReadLine();
			Console.Write("Ingrese su velocidad: ");
			velocidad = int.Parse(Console.ReadLine());
			Console.Write("Ingrese su fuerza: ");
			fuerza = int.Parse(Console.ReadLine());
			Console.Write("Describa el poder especial de su personaje: ");
			poderEspecial = Console.ReadLine();

			
			// Se limpia la pantalla y se muestran todos los datos.
			Console.Clear();
			Console.WriteLine("--- CREACIÓN DE PERSONAJE ---\n\n");
			Console.WriteLine("Nombre: " + nombre + ".");
			Console.WriteLine("Velocidad: " + velocidad + ".");
			Console.WriteLine("Fuerza: " + fuerza + ".");
			Console.WriteLine("Poder especial: " + poderEspecial + ".\n\n");

			Console.WriteLine("Personaje creado el " + dia + "/" + mes + "/" + anio + " a las " + hora + ":" + minutos + " hs.\n\n");



			Console.ReadKey(true);
		}
	}
}

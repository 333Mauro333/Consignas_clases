using System;


namespace Ejercicio_paracaidista
{
	class Program
	{
		static void Main()
		{
			Paracaidista paracaidista = new Paracaidista();

			string nombreParacaidista = "";
			int edadParacaidista = 0;
			string terrenoParacaidista = "";


			Console.Write("Ingrese el nombre del paracaidista: ");
			nombreParacaidista = Console.ReadLine();

			Console.Write("Ingrese la edad del paracaidista: ");
			edadParacaidista = int.Parse(Console.ReadLine());

			Console.Write("Ingrese el terreno donde va a caer: ");
			terrenoParacaidista = Console.ReadLine();
			Console.WriteLine();
			Console.WriteLine();

			paracaidista.SetNombre(nombreParacaidista);
			paracaidista.SetEdad(edadParacaidista);
			paracaidista.SetTerrenoDondeCaer(terrenoParacaidista);

			Console.WriteLine("Datos del paracaidista: ");
			Console.WriteLine();

			Console.WriteLine("Nombre: " + paracaidista.GetNombre() + ".");
			Console.WriteLine("Edad: " + paracaidista.GetEdad() + " años.");
			Console.WriteLine("Terreno donde va a caer: " + paracaidista.GetTerrenoDondeCaer() + ".");


			Console.ReadKey(true);
		}
	}
}

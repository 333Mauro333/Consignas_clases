using System;

using Mgtv_Library.Console;


namespace Inclusion_de_libreria
{
	class Program
	{
		static void Main()
		{
			int anchoConsola = ConsoleExt.GetScreenWidth();
			int altoConsola = ConsoleExt.GetScreenHeight();
			int distanciaBordesX = 10;
			int distanciaBordesY = 3;

			string titulo = "ESTA ES UNA PRUEBA";
			string descripcion = "Esta es una introducción a la novedosa librería MGTV.";
			string descripcion2 = "¡Una nueva forma de encarar los ejercicios se aproxima!";


			ConsoleExt.SetConsoleTitle("PRUEBA DE LIBRERÍA MGTV");

			ConsoleExt.GoToCoordinates(anchoConsola / 2 - titulo.Length / 2, 1);
			ConsoleExt.WriteInColor(titulo, ConsoleColor.DarkGreen);

			ConsoleExt.DrawFrame(distanciaBordesX, distanciaBordesY, anchoConsola - distanciaBordesX, altoConsola - distanciaBordesY, ConsoleColor.Yellow);

			ConsoleExt.GoToCoordinates(anchoConsola / 2 - descripcion.Length / 2, altoConsola / 2 - 1);
			ConsoleExt.WriteInColor(descripcion, ConsoleColor.Green);

			ConsoleExt.GoToCoordinates(anchoConsola / 2 - descripcion2.Length / 2, altoConsola / 2);
			ConsoleExt.WriteInColor(descripcion2, ConsoleColor.Green);

			ConsoleExt.GoToCoordinates(0, altoConsola - distanciaBordesY + 2);
			Console.Write("Presione cualquier tecla para cerrar la ventana... ");


			Console.ReadKey(true);
		}
	}
}

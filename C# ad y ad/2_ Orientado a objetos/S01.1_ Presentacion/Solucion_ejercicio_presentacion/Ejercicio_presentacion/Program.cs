using System;


namespace Ejercicio_presentacion
{
	class Program
	{
		static void Main()
		{
			Personaje personaje = new Personaje("Mauro", 7);


			personaje.Presentarse();
			personaje.DecirNumeroGuardado();
			personaje.Despedirse();


			Console.ReadKey(true);
		}
	}
}

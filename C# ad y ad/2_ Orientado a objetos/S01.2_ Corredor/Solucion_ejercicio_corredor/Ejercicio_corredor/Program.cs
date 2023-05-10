using System;


namespace Ejercicio_corredor
{
	class Program
	{
		static void Main()
		{
			Corredor corredor = new Corredor("Mauro", 50.0f);


			corredor.Correr();    // Corre.
			corredor.Descansar(); // Descansa.
			Console.WriteLine();

			corredor.Correr();    // Vuelve a correr.
			corredor.Correr();    // Intenta correr sin haber descansado.
			Console.WriteLine();

			corredor.Descansar(); // Descansa.
			corredor.Descansar(); // Intenta descansar habiendo descansado.
			Console.WriteLine();


			Console.ReadKey(true);
		}
	}
}

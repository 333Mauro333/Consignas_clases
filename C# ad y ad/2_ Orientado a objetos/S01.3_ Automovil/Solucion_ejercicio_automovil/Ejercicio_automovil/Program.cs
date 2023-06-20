using System;


namespace Ejercicio_automovil
{
	class Program
	{
		static void Main()
		{
			Automovil automovil = new Automovil("Verde");



			// Probando el auto normalmente.
			automovil.Prender();
			automovil.Acelerar();
			automovil.Frenar();
			automovil.Apagar();
			Console.WriteLine();
			Console.WriteLine();


			// Probando sus posibilidades en cuanto a encendido y apagado.
			automovil.Prender();
			automovil.Prender();
			automovil.Apagar();
			automovil.Apagar();
			Console.WriteLine();
			Console.WriteLine();


			// Probando acelerar y frenar mientras está apagado.
			automovil.Acelerar();
			automovil.Frenar();
			Console.WriteLine();
			Console.WriteLine();


			// Probando sus posibilidades en cuanto a acelerado y frenado.
			automovil.Prender();
			automovil.Acelerar();
			automovil.Acelerar();
			automovil.Apagar();
			automovil.Frenar();
			automovil.Frenar();
			automovil.Apagar();
			Console.WriteLine();
			Console.WriteLine();


			// Mostrando datos en cada estado del auto.
			automovil.MostrarDatos();
			Console.WriteLine();

			automovil.Prender();
			Console.WriteLine();

			automovil.MostrarDatos();
			Console.WriteLine();

			automovil.Acelerar();
			Console.WriteLine();

			automovil.MostrarDatos();
			Console.WriteLine();

			automovil.Frenar();
			Console.WriteLine();

			automovil.MostrarDatos();
			Console.WriteLine();

			automovil.Apagar();
			Console.WriteLine();



			Console.ReadKey(true);
		}
	}
}

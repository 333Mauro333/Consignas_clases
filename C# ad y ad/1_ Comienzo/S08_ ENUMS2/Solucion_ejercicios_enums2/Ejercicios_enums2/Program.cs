using System;


namespace Ejercicios_enums2
{
	class Program
	{
		enum Clima { Soleado = 1, Nublado, Lluvioso }
		enum Color { Rojo = 1, Azul, Amarillo, Verde }

		static void Main()
		{
			Random generar = new Random();

			Clima climaDelJuego = Clima.Soleado;

			Color colorJugador1 = Color.Rojo;
			Color colorCPU2 = Color.Rojo;
			Color colorCPU3 = Color.Rojo;
			Color colorCPU4 = Color.Rojo;

			int numeroRandom = 0;
			int opcion = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.WriteLine("¿Qué clima desea en su juego?\n");
			Console.WriteLine("1. SOLEADO");
			Console.WriteLine("2. NUBLADO");
			Console.WriteLine("3. LLUVIOSO");
			Console.WriteLine("4. ALEATORIO\n");

			Console.Write("Opción elegida: ");
			opcion = int.Parse(Console.ReadLine());

			Console.WriteLine();

			if (opcion >= 1 && opcion <= 3)
			{
				climaDelJuego = (Clima)opcion;
			}
			else if (opcion == 4)
			{
				numeroRandom = generar.Next(1, 4);
				climaDelJuego = (Clima)numeroRandom;
			}

			Console.Write("Clima establecido: ");

			switch (climaDelJuego)
			{
				case Clima.Soleado:
					Console.Write("Soleado");
					break;

				case Clima.Nublado:
					Console.Write("Nublado");
					break;

				case Clima.Lluvioso:
					Console.Write("Lluvioso");
					break;
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.WriteLine("Jugador 1, elija su color:\n");
			Console.WriteLine("1. ROJO");
			Console.WriteLine("2. AZUL");
			Console.WriteLine("3. AMARILLO");
			Console.WriteLine("4. VERDE\n");

			Console.Write("Opción elegida: ");
			opcion = int.Parse(Console.ReadLine());

			colorJugador1 = (Color)opcion;

			numeroRandom = generar.Next(1, 5);
			colorCPU2 = (Color)numeroRandom;

			numeroRandom = generar.Next(1, 5);
			colorCPU3 = (Color)numeroRandom;

			numeroRandom = generar.Next(1, 5);
			colorCPU4 = (Color)numeroRandom;

			// Se muestran los colores elegidos de los 4 jugadores.
			Console.Write("\nColor del JUGADOR: ");

			switch (colorJugador1)
			{
				case Color.Rojo:
					Console.Write("Rojo");
					break;

				case Color.Azul:
					Console.Write("Azul");
					break;

				case Color.Amarillo:
					Console.Write("Amarillo");
					break;

				case Color.Verde:
					Console.Write("Verde");
					break;
			}

			Console.WriteLine(".");
			Console.Write("Color de la CPU 2: ");

			switch (colorCPU2)
			{
				case Color.Rojo:
					Console.Write("Rojo");
					break;

				case Color.Azul:
					Console.Write("Azul");
					break;

				case Color.Amarillo:
					Console.Write("Amarillo");
					break;

				case Color.Verde:
					Console.Write("Verde");
					break;
			}

			Console.WriteLine(".");
			Console.Write("Color de la CPU 3: ");

			switch (colorCPU3)
			{
				case Color.Rojo:
					Console.Write("Rojo");
					break;

				case Color.Azul:
					Console.Write("Azul");
					break;

				case Color.Amarillo:
					Console.Write("Amarillo");
					break;

				case Color.Verde:
					Console.Write("Verde");
					break;
			}

			Console.WriteLine(".");
			Console.Write("Color de la CPU 4: ");

			switch (colorCPU4)
			{
				case Color.Rojo:
					Console.Write("Rojo");
					break;

				case Color.Azul:
					Console.Write("Azul");
					break;

				case Color.Amarillo:
					Console.Write("Amarillo");
					break;

				case Color.Verde:
					Console.Write("Verde");
					break;
			}

			Console.WriteLine(".\n\n");


			
			Console.ReadKey(true);
		}
	}
}

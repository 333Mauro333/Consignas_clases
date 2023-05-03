using System;


namespace Ejercicios_enums
{
	class Program
	{
		enum Velocidad { Lenta, Media, Rapida }
		enum CalidadGraficos { Baja, Media, Alta }
		enum Dificultad { Novato, Facil, Medio, Dificil, Experto }
		enum ClasePersonaje { Guerrero, Arquero, Mago }

		static void Main()
		{
			Velocidad miVelocidad = Velocidad.Media;
			CalidadGraficos calidadActual = CalidadGraficos.Media;
			Dificultad dificultad = Dificultad.Medio;
			ClasePersonaje clasePersonaje = ClasePersonaje.Guerrero;

			int vida = 0;
			int velocidad = 0;
			int fuerza = 0;

			int opcion = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Velocidad actual: ");

			switch (miVelocidad)
			{
				case Velocidad.Lenta:
					Console.Write("Lenta");
					break;

				case Velocidad.Media:
					Console.Write("Media");
					break;

				case Velocidad.Rapida:
					Console.Write("Rápida");
					break;
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Calidad actual: ");

			switch (calidadActual)
			{
				case CalidadGraficos.Baja:
					Console.Write("Baja");
					break;

				case CalidadGraficos.Media:
					Console.Write("Media");
					break;

				case CalidadGraficos.Alta:
					Console.Write("Alta");
					break;
			}

			Console.WriteLine(".\n\n");
			Console.WriteLine("Elija la calidad de los gráficos:\n");
			Console.WriteLine("1. BAJA");
			Console.WriteLine("2. MEDIA");
			Console.WriteLine("3. ALTA\n");

			Console.Write("Opción ingresada: ");
			opcion = int.Parse(Console.ReadLine());

			Console.WriteLine();

			switch (opcion)
			{
				case 1:
					calidadActual = CalidadGraficos.Baja;
					break;

				case 2:
					calidadActual = CalidadGraficos.Media;
					break;

				case 3:
					calidadActual = CalidadGraficos.Alta;
					break;
			}

			Console.Write("Calidad actual: ");

			switch (calidadActual)
			{
				case CalidadGraficos.Baja:
					Console.Write("Baja");
					break;

				case CalidadGraficos.Media:
					Console.Write("Media");
					break;

				case CalidadGraficos.Alta:
					Console.Write("Alta");
					break;
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.WriteLine("Elija la dificultad del juego:\n");
			Console.WriteLine("1. NOVATO");
			Console.WriteLine("2. FÁCIL");
			Console.WriteLine("3. MEDIO");
			Console.WriteLine("4. DIFÍCIL");
			Console.WriteLine("5. EXPERTO\n");

			Console.Write("Opción elegida: ");
			opcion = int.Parse(Console.ReadLine());

			switch (opcion)
			{
				case 1:
					dificultad = Dificultad.Novato;
					break;

				case 2:
					dificultad = Dificultad.Facil;
					break;

				case 3:
					dificultad = Dificultad.Medio;
					break;

				case 4:
					dificultad = Dificultad.Dificil;
					break;

				case 5:
					dificultad = Dificultad.Experto;
					break;
			}

			Console.Write("Dificultad elegida: ");

			switch (dificultad)
			{
				case Dificultad.Novato:
					Console.Write("Novato");
					break;

				case Dificultad.Facil:
					Console.Write("Fácil");
					break;

				case Dificultad.Medio:
					Console.Write("Medio");
					break;

				case Dificultad.Dificil:
					Console.Write("Difícil");
					break;

				case Dificultad.Experto:
					Console.Write("Experto");
					break;
			}

			Console.WriteLine(".\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.WriteLine("Elija la clase de su personaje:\n");
			Console.WriteLine("1. GUERRERO");
			Console.WriteLine("2. ARQUERO");
			Console.WriteLine("3. MAGO\n");

			Console.Write("Opción elegida: ");
			opcion = int.Parse(Console.ReadLine());

			switch (opcion)
			{
				case 1:
					clasePersonaje = ClasePersonaje.Guerrero;
					break;

				case 2:
					clasePersonaje = ClasePersonaje.Arquero;
					break;

				case 3:
					clasePersonaje = ClasePersonaje.Mago;
					break;
			}

			switch (clasePersonaje)
			{
				case ClasePersonaje.Guerrero:
					vida = 100;
					velocidad = 25;
					fuerza = 75;
					break;

				case ClasePersonaje.Arquero:
					vida = 50;
					velocidad = 50;
					fuerza = 40;
					break;

				case ClasePersonaje.Mago:
					vida = 30;
					velocidad = 40;
					fuerza = 100;
					break;
			}

			Console.Write("\nClase elegida: ");

			switch (clasePersonaje)
			{
				case ClasePersonaje.Guerrero:
					Console.Write("Guerrero");
					break;

				case ClasePersonaje.Arquero:
					Console.Write("Arquero");
					break;

				case ClasePersonaje.Mago:
					Console.Write("Mago");
					break;
			}

			Console.WriteLine(".\n");
			Console.WriteLine("Vida: " + vida + ".");
			Console.WriteLine("Velocidad: " + velocidad + ".");
			Console.WriteLine("Fuerza: " + fuerza + ".\n\n");



			Console.ReadKey(true);
		}
	}
}

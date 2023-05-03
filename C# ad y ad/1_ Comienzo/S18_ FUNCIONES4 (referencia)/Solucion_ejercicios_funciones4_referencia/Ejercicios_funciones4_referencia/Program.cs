using System;


namespace Ejercicios_funciones4_referencia
{
	class Program
	{
		enum Ordenamiento { MenorAMayor = 1, MayorAMenor }

		struct Posicion
		{
			public int x;
			public int y;
		}
		struct Jugador
		{
			public string nombre;
			public int vida;
			public Posicion posicion;
		}

		static void Main()
		{
			Random generar = new Random();

			Jugador jugador1 = new Jugador();
			Jugador jugador2 = new Jugador();

			Posicion posicion = new Posicion();

			int[] numeros = new int[10];
			Ordenamiento tipoDeOrden = Ordenamiento.MenorAMayor;

			int numero = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			InitJugador(ref jugador1, "Nick", 100, 1, 1);
			InitJugador(ref jugador2, "Tom", 100, 9, 1);

			MostrarDatosDeJugador(jugador1);
			MostrarDatosDeJugador(jugador2);

			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			posicion.x = 3;
			posicion.y = 2;

			SetPosicion(ref jugador1, posicion);

			posicion.x = 7;
			posicion.y = 2;

			SetPosicion(ref jugador2, posicion);

			MostrarPosicionDelJugador(jugador1);
			MostrarPosicionDelJugador(jugador2);

			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("¿Cuántos pasos avanzará " + jugador1.nombre + " sobre X? ");
			posicion.x = int.Parse(Console.ReadLine());

			Console.Write("¿Cuántos pasos avanzará " + jugador1.nombre + " sobre Y? ");
			posicion.y = int.Parse(Console.ReadLine());

			MoverJugador(ref jugador1, posicion);

			Console.Write("¿Cuántos pasos avanzará " + jugador2.nombre + " sobre X? ");
			posicion.x = int.Parse(Console.ReadLine());

			Console.Write("¿Cuántos pasos avanzará " + jugador2.nombre + " sobre Y? ");
			posicion.y = int.Parse(Console.ReadLine());

			MoverJugador(ref jugador2, posicion);

			MostrarPosicionDelJugador(jugador1);
			MostrarPosicionDelJugador(jugador2);

			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			for (int i = 0; i < numeros.Length; i++)
			{
				numeros[i] = generar.Next(101); // Números entre 0 y 100.
			}

			MostrarValores(numeros);

			Console.WriteLine("¿Cómo desea ordenar el arreglo?\n");
			Console.WriteLine("1. De menor a mayor.");
			Console.WriteLine("2. De mayor a menor.\n");

			do
			{
				Console.Write("Opción ingresada: ");
				numero = int.Parse(Console.ReadLine());

			} while (numero < 1 || numero > 2);

			Console.WriteLine();

			tipoDeOrden = (Ordenamiento)numero;

			OrdenarArray(numeros, tipoDeOrden);

			MostrarValores(numeros);



			Console.ReadKey(true);
		}


		static void InitJugador(ref Jugador jugador, string nombre, int vida, int posicionX, int posicionY)
		{
			jugador.nombre = nombre;
			jugador.vida = vida;
			jugador.posicion.x = posicionX;
			jugador.posicion.y = posicionY;
		}
		static void MostrarDatosDeJugador(Jugador jugador)
		{
			Console.WriteLine("Nombre del jugador:" + jugador.nombre + ".");
			Console.WriteLine("Vida: " + jugador.vida + ".");
			Console.WriteLine("Posición: (" + jugador.posicion.x + "; " + jugador.posicion.y + ").\n");
		}

		static void SetPosicion(ref Jugador jugador, Posicion posicion)
		{
			jugador.posicion = posicion;
		}
		static void MostrarPosicionDelJugador(Jugador jugador)
		{
			Console.WriteLine("Posicion X de " + jugador.nombre + ": " + jugador.posicion.x + ".");
			Console.WriteLine("Posicion Y de " + jugador.nombre + ": " + jugador.posicion.y + ".\n");
		}

		static void MoverJugador(ref Jugador jugador, Posicion posicion)
		{
			jugador.posicion.x += posicion.x;
			jugador.posicion.y += posicion.y;
		}

		static void Intercambiar(ref int num1, ref int num2)
		{
			int aux = num1;

			num1 = num2;
			num2 = aux;
		}
		static void MostrarValores(int[] arregloDeNumeros)
		{
			Console.WriteLine("Valores del arreglo:\n");

			for (int i = 0; i < arregloDeNumeros.Length; i++)
			{
				Console.Write(arregloDeNumeros[i] + " ");
			}

			Console.WriteLine("\n");
		}
		static void OrdenarArray(int[] arregloDeNumeros, Ordenamiento tipoDeOrden)
		{
			switch (tipoDeOrden)
			{
				case Ordenamiento.MenorAMayor:

					for (int i = 0; i < arregloDeNumeros.Length; i++)
					{
						for (int j = i + 1; j < arregloDeNumeros.Length; j++)
						{
							if (arregloDeNumeros[j] < arregloDeNumeros[i])
							{
								Intercambiar(ref arregloDeNumeros[j], ref arregloDeNumeros[i]);
							}
						}
					}

					break;

				case Ordenamiento.MayorAMenor:

					for (int i = 0; i < arregloDeNumeros.Length; i++)
					{
						for (int j = i + 1; j < arregloDeNumeros.Length; j++)
						{
							if (arregloDeNumeros[j] > arregloDeNumeros[i])
							{
								Intercambiar(ref arregloDeNumeros[j], ref arregloDeNumeros[i]);
							}
						}
					}

					break;
			}
		}
	}
}

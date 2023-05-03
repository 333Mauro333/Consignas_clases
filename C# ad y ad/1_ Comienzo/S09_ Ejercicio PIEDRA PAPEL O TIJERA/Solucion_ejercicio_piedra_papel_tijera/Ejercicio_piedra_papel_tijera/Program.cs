using System;
using System.Threading;


namespace Ejercicio_piedra_papel_tijera
{
	class Program
	{
		enum OpcionJuego { Piedra = 1, Papel, Tijera }
		enum ResultadoFinal { GanaJugador, GanaCPU, Empate }

		static void Main()
		{
			Random generar = new Random();

			OpcionJuego opcionJugador = OpcionJuego.Piedra;
			OpcionJuego opcionCPU = OpcionJuego.Piedra;
			ResultadoFinal resultado = ResultadoFinal.GanaJugador;

			int opcion = 0;



			Console.WriteLine("--- PIEDRA, PAPEL O TIJERA ---\n");
			Console.Write("A continuación, usted jugará un enfrentamiento contra la CPU. ¿Quién ganará? ");

			Thread.Sleep(2000);

			Console.Write("\nPresione cualquier tecla para comenzar... ");
			Console.ReadKey(true);
			Console.Clear();

			Console.WriteLine("--- PIEDRA, PAPEL O TIJERA ---\n\n");
			Console.WriteLine("Elija una opción:\n");
			Console.WriteLine("1. PIEDRA");
			Console.WriteLine("2. PAPEL");
			Console.WriteLine("3. TIJERA\n");

			Console.Write("Opción elegida: ");
			opcion = int.Parse(Console.ReadLine());
			Console.WriteLine();

			opcionJugador = (OpcionJuego)opcion;

			opcion = generar.Next(1, 4);
			opcionCPU = (OpcionJuego)opcion;

			//Console.Write("Piedra...");
			//Thread.Sleep(500);

			//Console.Write("\n...papel...");
			//Thread.Sleep(500);

			//Console.Write("\n...o tijera! ");
			//Thread.Sleep(1000);

			Console.WriteLine("\n");

			switch (opcionJugador)
			{
				case OpcionJuego.Piedra:

					Console.WriteLine("El jugador ha sacado PIEDRA. ");

					switch (opcionCPU)
					{
						case OpcionJuego.Piedra:
							Console.Write("La CPU ha sacado PIEDRA. ");
							resultado = ResultadoFinal.Empate;
							break;

						case OpcionJuego.Papel:
							Console.Write("La CPU ha sacado PAPEL. ");
							resultado = ResultadoFinal.GanaCPU;
							break;

						case OpcionJuego.Tijera:
							Console.Write("La CPU ha sacado TIJERA. ");
							resultado = ResultadoFinal.GanaJugador;
							break;
					}

					break;

				case OpcionJuego.Papel:
					Console.WriteLine("El jugador ha sacado PAPEL. ");

					switch (opcionCPU)
					{
						case OpcionJuego.Piedra:
							Console.Write("La CPU ha sacado PIEDRA. ");
							resultado = ResultadoFinal.GanaJugador;
							break;

						case OpcionJuego.Papel:
							Console.Write("La CPU ha sacado PAPEL. ");
							resultado = ResultadoFinal.Empate;
							break;

						case OpcionJuego.Tijera:
							Console.Write("La CPU ha sacado TIJERA. ");
							resultado = ResultadoFinal.GanaCPU;
							break;
					}

					break;

				case OpcionJuego.Tijera:
					Console.WriteLine("El jugador ha sacado TIJERA. ");

					switch (opcionCPU)
					{
						case OpcionJuego.Piedra:
							Console.Write("La CPU ha sacado PIEDRA. ");
							resultado = ResultadoFinal.GanaCPU;
							break;

						case OpcionJuego.Papel:
							Console.Write("La CPU ha sacado PAPEL. ");
							resultado = ResultadoFinal.GanaJugador;
							break;

						case OpcionJuego.Tijera:
							Console.Write("La CPU ha sacado TIJERA. ");
							resultado = ResultadoFinal.Empate;
							break;
					}

					break;

				default:
					Console.WriteLine("El jugador no supo qué elegir... ");
					resultado = ResultadoFinal.GanaCPU;
					break;
			}

			Console.WriteLine("\n");

			switch (resultado)
			{
				case ResultadoFinal.GanaJugador:
					Console.Write("¡El jugador ha ganado el enfrentamiento! ");
					break;

				case ResultadoFinal.GanaCPU:
					Console.Write("La CPU ha ganado el enfrentamiento. ");
					break;

				case ResultadoFinal.Empate:
					Console.Write("Se ha empatado la ronda. ");
					break;
			}



			Console.ReadKey(true);
		}
	}
}

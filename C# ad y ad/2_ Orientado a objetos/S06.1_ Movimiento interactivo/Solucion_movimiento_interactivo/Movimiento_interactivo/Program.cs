using System;

using Mgtv_Library.Console;


namespace Movimiento_interactivo
{
	class Program
	{
		static void Main()
		{
			bool enPrograma = true;
			int fps = 10;

			int anchoConsola = ConsoleExt.GetScreenWidth();
			int altoConsola = ConsoleExt.GetScreenHeight();

			const int distanciaBordesX = 15;
			const int distanciaBordesY = 5;

			int marcoBordeSuperior = distanciaBordesY;
			int marcoBordeInferior = altoConsola - distanciaBordesY;
			int marcoBordeIzquierdo = distanciaBordesX;
			int marcoBordeDerecho = anchoConsola - distanciaBordesX;

			const string mensajeVictoria1 = "¡Enhorabuena! ¡Has llegado a la cantidad necesaria de movimientos!";
			const string mensajeVictoria2 = "Presione cualquier tecla para finalizar el juego... ";

			Jugador jugador = new Jugador(anchoConsola / 2, altoConsola / 2);

			const int movimientosNecesarios = 50;



			ConsoleExt.HideCursor();

			jugador.SetControles(ConsoleKey.UpArrow, ConsoleKey.DownArrow, ConsoleKey.LeftArrow, ConsoleKey.RightArrow);
			jugador.SetLimites(marcoBordeSuperior, marcoBordeInferior, marcoBordeIzquierdo, marcoBordeDerecho);

			while (enPrograma)
			{
				ConsoleExt.Sleep(1.0f / fps); // Se ocupa de controlar la cantidad de fotogramas por segundo.

				#region Update

				jugador.Update();

				if (jugador.GetCantidadDeMovimientosHechos() >= movimientosNecesarios)
				{
					enPrograma = false;
				}

				#endregion

				#region Draw

				Console.Clear();

				ConsoleExt.DrawFrame(marcoBordeIzquierdo, marcoBordeSuperior, marcoBordeDerecho, marcoBordeInferior);

				ConsoleExt.GoToCoordinates(marcoBordeIzquierdo + 5, marcoBordeSuperior - 1);
				Console.Write("Movimientos hechos: " + jugador.GetCantidadDeMovimientosHechos());
				ConsoleExt.GoToCoordinates(marcoBordeDerecho - 31, marcoBordeSuperior - 1);
				Console.Write("Movimientos necesarios: " + movimientosNecesarios);

				jugador.Draw();

				if (jugador.GetCantidadDeMovimientosHechos() >= movimientosNecesarios)
				{
					ConsoleExt.ShowCursor();

					ConsoleExt.GoToCoordinates(anchoConsola / 2 - mensajeVictoria1.Length / 2, altoConsola / 2 - 1);
					ConsoleExt.WriteInColor(mensajeVictoria1, ConsoleColor.Green);
					ConsoleExt.GoToCoordinates(anchoConsola / 2 - mensajeVictoria2.Length / 2, altoConsola / 2);
					ConsoleExt.WriteInColor(mensajeVictoria2, ConsoleColor.Green);

					enPrograma = false;
				}

				#endregion
			}



			Console.ReadKey(true);

			ConsoleExt.GoToCoordinates(1, marcoBordeInferior + 1);
		}
	}
}

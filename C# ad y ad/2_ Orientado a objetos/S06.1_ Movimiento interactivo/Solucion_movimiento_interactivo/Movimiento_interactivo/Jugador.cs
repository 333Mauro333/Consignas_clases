using System;

using Mgtv_Library.Console;


namespace Movimiento_interactivo
{
	class Jugador
	{
		Controles controles;
		Posicion posicion;
		Limites limites;

		int cantidadDeMovimientosHechos;


		public Jugador(int x, int y)
		{
			controles = new Controles();
			posicion = new Posicion();
			limites = new Limites();

			cantidadDeMovimientosHechos = 0;


			posicion.x = x;
			posicion.y = y;
		}


		public void Update()
		{
			ConsoleKey teclaPresionada = ConsoleExt.GetKey(false);


			if (teclaPresionada == controles.arriba)
			{
				if (posicion.y > limites.superior + 1)
				{
					posicion.y--;
					cantidadDeMovimientosHechos++;
				}
			}
			else if (teclaPresionada == controles.abajo)
			{
				if (posicion.y < limites.inferior - 1)
				{
					posicion.y++;
					cantidadDeMovimientosHechos++;
				}
			}
			else if (teclaPresionada == controles.izquierda)
			{
				if (posicion.x > limites.izquierdo + 1)
				{
					posicion.x--;
					cantidadDeMovimientosHechos++;
				}
			}
			else if (teclaPresionada == controles.derecha)
			{
				if (posicion.x < limites.derecho - 1)
				{
					posicion.x++;
					cantidadDeMovimientosHechos++;
				}
			}
		}
		public void Draw()
		{
			ConsoleExt.GoToCoordinates(posicion.x, posicion.y);
			Console.Write("*");
		}

		public int GetCantidadDeMovimientosHechos()
		{
			return cantidadDeMovimientosHechos;
		}
		public void SetControles(ConsoleKey arriba, ConsoleKey abajo, ConsoleKey izquierda, ConsoleKey derecha)
		{
			controles.arriba = arriba;
			controles.abajo = abajo;
			controles.izquierda = izquierda;
			controles.derecha = derecha;
		}
		public void SetLimites(int superior, int inferior, int izquierdo, int derecho)
		{
			limites.superior = superior;
			limites.inferior = inferior;
			limites.izquierdo = izquierdo;
			limites.derecho = derecho;
		}
	}
}

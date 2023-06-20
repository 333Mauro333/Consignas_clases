using System;

using Mgtv_Library.Console;


namespace Estrellas_en_el_cielo
{
	class Estrella
	{
		static int cambiosPosicion = 0;

		Posicion posicion;


		public Estrella()
		{
			posicion = new Posicion();
		}


		public static int GetCambiosDePosicion()
		{
			return cambiosPosicion;
		}

		public void Draw()
		{
			ConsoleExt.GoToCoordinates(posicion.x, posicion.y);
			ConsoleExt.WriteInColor("*", ConsoleColor.Yellow);
		}

		public Posicion GetPosicion()
		{
			return posicion;
		}
		public void SetPosicion(int x, int y)
		{
			posicion.x = x;
			posicion.y = y;

			cambiosPosicion++;
		}
	}
}

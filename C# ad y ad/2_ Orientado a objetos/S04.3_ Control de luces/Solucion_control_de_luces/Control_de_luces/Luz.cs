using System;


namespace Control_de_luces
{
	class Luz
	{
		public static int lucesEncendidas;

		bool estaEncendida;
		Posicion posicion;


		public Luz()
		{
			estaEncendida = false;
			posicion = new Posicion();
		}


		public static int GetLucesEncendidas()
		{
			return lucesEncendidas;
		}

		public void Draw()
		{

		}

		public void Encender()
		{

		}
		public void Apagar()
		{

		}

		public bool GetEstaEncendida()
		{
			return estaEncendida;
		}
		public void SetPosicion(int x, int y)
		{
			posicion.x = x;
			posicion.y = y;
		}


		string ObtenerCaracteres(char caracter, int cantidad)
		{
			string texto = "";


			for (int i = 0; i < cantidad; i++)
			{
				texto += caracter;
			}

			return texto;
		}
	}
}

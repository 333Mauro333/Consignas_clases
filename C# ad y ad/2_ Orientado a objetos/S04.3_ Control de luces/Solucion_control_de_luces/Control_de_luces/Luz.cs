using System;

using Mgtv_Library.Console;


namespace Control_de_luces
{
	class Luz
	{
		static int lucesEncendidas = 0;

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
			//"    ╔═╦════════╦══╗";
			//"    ║ ╠════════╣  ║";
			//"    ║ ║        ╚══╝";
			//"    ║ ║        ████";
			//"    ║ ║       ▓▓▓▓▓▓";
			//"    ║ ║      ▒▒▒▒▒▒▒▒";
			//"    ║ ║     ░░░░░░░░░░";
			//"    ║ ║";
			//" ╔══╩═╩══╗";
			//" ╚═══════╝";

			ConsoleExt.GoToCoordinates(posicion.x + 4, posicion.y);
			Console.Write("╔═╦════════╦══╗");
			ConsoleExt.GoToCoordinates(posicion.x + 4, posicion.y + 1);
			Console.Write("║ ╠════════╣  ║");
			ConsoleExt.GoToCoordinates(posicion.x + 4, posicion.y + 2);
			Console.Write("║ ║        ╚══╝");

			for (int i = 3; i <= 7; i++)
			{
				ConsoleExt.GoToCoordinates(posicion.x + 4, posicion.y + i);
				Console.Write("║ ║");
			}

			ConsoleExt.GoToCoordinates(posicion.x + 1, posicion.y + 8);
			Console.Write("╔══╩═╩══╗");
			ConsoleExt.GoToCoordinates(posicion.x + 1, posicion.y + 9);
			Console.Write("╚═══════╝");

			if (estaEncendida)
			{
				ConsoleExt.GoToCoordinates(posicion.x + 15, posicion.y + 3);
				ConsoleExt.WriteWithColor("████", ConsoleColor.Yellow);
				ConsoleExt.GoToCoordinates(posicion.x + 14, posicion.y + 4);
				ConsoleExt.WriteWithColor("▓▓▓▓▓▓", ConsoleColor.Yellow);
				ConsoleExt.GoToCoordinates(posicion.x + 13, posicion.y + 5);
				ConsoleExt.WriteWithColor("▒▒▒▒▒▒▒▒", ConsoleColor.Yellow);
				ConsoleExt.GoToCoordinates(posicion.x + 12, posicion.y + 6);
				ConsoleExt.WriteWithColor("░░░░░░░░░░", ConsoleColor.Yellow);
			}

			ConsoleExt.GoToCoordinates(0, posicion.y + 10);
		}

		public void Encender()
		{
			estaEncendida = true;

			lucesEncendidas++;
		}
		public void Apagar()
		{
			estaEncendida = false;

			lucesEncendidas--;
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
	}
}

using System;


namespace Ejercicios_random2
{
	class Program
	{
		static void Main()
		{
			Random generar = new Random();

			int hora = 0;
			int minutos = 0;

			int dia = 0;
			int mes = 0;
			int anio = 0;

			float precio1 = 0.0f;
			float precio2 = 0.0f;
			float precio3 = 0.0f;
			float precio4 = 0.0f;
			float precio5 = 0.0f;

			char letra1 = '\0';
			char letra2 = '\0';
			char letra3 = '\0';
			int puntaje = 0;



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			hora = generar.Next(24);
			minutos = generar.Next(60);

			Console.Write("Hora generada: ");

			if (hora < 10)
			{
				Console.Write("0");
			}

			Console.Write(hora + ":");

			if (minutos < 10)
			{
				Console.Write("0");
			}

			Console.WriteLine(minutos + "\n\n");



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			anio = generar.Next(1900, 2101);
			mes = generar.Next(1, 13);

			switch (mes)
			{
				case 1: // Enero.
				case 3: // Marzo.
				case 5: // Mayo.
				case 7: // Julio.
				case 8: // Agosto.
				case 10: // Octubre.
				case 12:  // Diciembre.
					dia = generar.Next(1, 32);
					break;

				case 2: // Febrero.
					if (anio % 4 == 0) // Si el año es bisiesto...
					{
						dia = generar.Next(1, 30);
					}
					else
					{
						dia = generar.Next(1, 29);
					}
					break;

				default: // Todos los demás meses (abril, junio, septiembre y noviembre).
					dia = generar.Next(1, 31);
					break;
			}

			Console.WriteLine("Fecha generada: " + dia + "/" + mes + "/" + anio + "\n\n");



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			precio1 = generar.Next(30000, 40001);
			precio2 = generar.Next(30000, 40001);
			precio3 = generar.Next(30000, 40001);
			precio4 = generar.Next(30000, 40001);
			precio5 = generar.Next(30000, 40001);

			precio1 /= 100;
			precio2 /= 100;
			precio3 /= 100;
			precio4 /= 100;
			precio5 /= 100;

			Console.WriteLine("Precio del primer producto: $" + precio1);
			Console.WriteLine("Precio del segundo producto: $" + precio2);
			Console.WriteLine("Precio del tercer producto: $" + precio3);
			Console.WriteLine("Precio del cuarto producto: $" + precio4);
			Console.WriteLine("Precio del quinto producto: $" + precio5 + "\n\n");



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			letra1 = (char)generar.Next(65, 91);
			letra2 = (char)generar.Next(65, 91);
			letra3 = (char)generar.Next(65, 91);
			puntaje = generar.Next(10000, 20001);

			Console.WriteLine("   HIGHSCORES\n");
			Console.WriteLine(" " + letra1 + letra2 + letra3 + "       " + puntaje);
			Console.WriteLine(" ...       00000");
			Console.WriteLine(" ...       00000");
			Console.WriteLine(" ...       00000");
			Console.WriteLine(" ...       00000\n\n");



			Console.ReadKey(true);
		}
	}
}

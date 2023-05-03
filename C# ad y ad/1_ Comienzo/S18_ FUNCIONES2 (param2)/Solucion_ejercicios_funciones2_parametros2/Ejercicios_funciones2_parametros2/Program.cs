using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicios_funciones2_parametros2
{
	class Program
	{
		struct Fecha
		{
			public int dia;
			public int mes;
			public int anio;
		}
		struct Hora
		{
			public int horas;
			public int minutos;
		}
		struct Jugador
		{
			public string nombre;
			public int vida;
			public int escudo;
			public int danio;
		}
		struct Paciente
		{
			public string nombre;
			public string apellido;
			public Fecha fechaTurno;
			public Hora horaTurno;
			public string motivo;
		}

		static void Main()
		{
			float kmH = 0.0f;

			Jugador jugador = new Jugador();

			int jugadorVida = 0;
			int enemigoDanio = 0;

			Paciente paciente = new Paciente();



			Console.WriteLine("--- EJERCICIO 1 ---\n");

			Console.Write("Ingrese una velocidad (en km/h): ");
			kmH = float.Parse(Console.ReadLine());
			Console.WriteLine();

			MostrarEnMps(kmH);

			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 2 ---\n");

			Console.Write("Ingrese el nombre del jugador: ");
			jugador.nombre = Console.ReadLine();

			do
			{
				Console.Write("Ingrese la vida (entre 50 y 100): ");
				jugador.vida = int.Parse(Console.ReadLine());

			} while (jugador.vida < 50 || jugador.vida > 100);

			do
			{
				Console.Write("Ingrese el escudo (entre 0 y 100): ");
				jugador.escudo = int.Parse(Console.ReadLine());

			} while (jugador.escudo < 0 || jugador.escudo > 100);

			do
			{
				Console.Write("Ingrese el daño (entre 5 y 30): ");
				jugador.danio = int.Parse(Console.ReadLine());

			} while (jugador.danio < 5 || jugador.danio > 30);

			Console.WriteLine();

			MostrarDatosDelJugador(jugador);

			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 3 ---\n");

			Console.Write("Ingrese la vida del jugador: ");
			jugadorVida = int.Parse(Console.ReadLine());

			Console.Write("Ingrese los puntos de daño del enemigo: ");
			enemigoDanio = int.Parse(Console.ReadLine());

			MostrarAguanteDelJugador(jugadorVida, enemigoDanio);

			Console.WriteLine();



			Console.WriteLine("--- EJERCICIO 4 ---\n");

			Console.Write("Ingrese el nombre del paciente: ");
			paciente.nombre = Console.ReadLine();

			Console.Write("Ingrese el apellido: ");
			paciente.apellido = Console.ReadLine();

			// Se omite el proceso de validez de fecha, que fue aplicado en ejercicios anteriores.
			Console.WriteLine("Fecha del turno:\n");

			Console.Write("Ingrese el día: ");
			paciente.fechaTurno.dia = int.Parse(Console.ReadLine());

			Console.Write("Ingrese el mes (entre 1 y 12): ");
			paciente.fechaTurno.mes = int.Parse(Console.ReadLine());

			Console.Write("Ingrese el año: ");
			paciente.fechaTurno.anio = int.Parse(Console.ReadLine());
			Console.WriteLine();

			Console.WriteLine("Hora del turno:\n");

			do
			{
				Console.Write("Ingrese las horas: ");
				paciente.horaTurno.horas = int.Parse(Console.ReadLine());

			} while (paciente.horaTurno.horas < 0 || paciente.horaTurno.horas > 23);

			do
			{
				Console.Write("Ingrese los minutos: ");
				paciente.horaTurno.minutos = int.Parse(Console.ReadLine());

			} while (paciente.horaTurno.minutos < 0 || paciente.horaTurno.minutos > 59);

			Console.Write("Describa el motivo de la visita: ");
			paciente.motivo = Console.ReadLine();

			Console.WriteLine("\n       --- DATOS DEL PACIENTE ---\n");

			MostrarDatosDelPaciente(paciente);



			Console.ReadKey(true);
		}


		static void MostrarEnMps(float velocidadEnKmh)
		{
			Console.WriteLine("La velocidad es de " + (velocidadEnKmh / 3.6f) + " m/s.\n");
		}

		static void MostrarDatosDelJugador(Jugador jugador)
		{
			Console.WriteLine("Estadísticas de " + jugador.nombre + ":\n");

			Console.WriteLine("Vida: " + jugador.vida + ".");
			Console.WriteLine("Escudo: " + jugador.escudo + ".");
			Console.WriteLine("Daño: " + jugador.danio + ".\n");
		}

		static void MostrarAguanteDelJugador(int vida, int danioRecibido)
		{
			int cantidadGolpes = -1;


			do
			{
				vida -= danioRecibido;
				cantidadGolpes++;

			} while (vida > 0);

			Console.Write("El jugador ");

			if (cantidadGolpes == 0)
			{
				Console.Write("no puede aguantar ningún golpe");
			}
			else
			{
				Console.Write("puede aguantar " + cantidadGolpes + " golpe");

				if (cantidadGolpes > 1)
				{
					Console.Write("s");
				}
			}

			Console.WriteLine(".\n");
		}

		static void MostrarFecha(Fecha fecha)
		{
			if (fecha.dia < 10)
			{
				Console.Write("0");
			}

			Console.Write(fecha.dia + " de ");

			switch (fecha.mes)
			{
				case 1:
					Console.Write("enero");
					break;

				case 2:
					Console.Write("febrero");
					break;

				case 3:
					Console.Write("marzo");
					break;

				case 4:
					Console.Write("abril");
					break;

				case 5:
					Console.Write("mayo");
					break;

				case 6:
					Console.Write("junio");
					break;

				case 7:
					Console.Write("julio");
					break;

				case 8:
					Console.Write("agosto");
					break;

				case 9:
					Console.Write("septiembre");
					break;

				case 10:
					Console.Write("octubre");
					break;

				case 11:
					Console.Write("noviembre");
					break;

				case 12:
					Console.Write("diciembre");
					break;
			}

			Console.WriteLine(" de " + fecha.anio + ".");
		}
		static void MostrarHora(Hora hora)
		{
			if (hora.horas < 10)
			{
				Console.Write("0");
			}

			Console.Write(hora.horas + ":");

			if (hora.minutos < 10)
			{
				Console.Write("0");
			}

			Console.WriteLine(hora.minutos + " hs.");
		}
		static void MostrarDatosDelPaciente(Paciente paciente)
		{
			Console.WriteLine("Nombre: " + paciente.nombre + ".");
			Console.WriteLine("Apellido: " + paciente.apellido + ".");
			Console.Write("Fecha del turno: ");
			MostrarFecha(paciente.fechaTurno);
			Console.Write("Hora del turno: ");
			MostrarHora(paciente.horaTurno);
			Console.WriteLine("Motivo: " + paciente.motivo + ".\n");
		}
	}
}

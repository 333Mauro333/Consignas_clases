using System;

namespace Ejercicio_automovil
{
	class Automovil
	{
		string color;
		bool estaPrendido;
		bool estaEnMovimiento;


		public Automovil(string color)
		{
			this.color = color;

			estaPrendido = false;
			estaEnMovimiento = false;
		}


		public void Prender()
		{
			if (!estaPrendido)
			{
				estaPrendido = true;

				Console.WriteLine("El auto se prendió. ¡Está listo para empezar a andar!");
			}
			else
			{
				Console.WriteLine("El auto ya está prendido.");
			}
		}
		public void Apagar()
		{
			if (estaPrendido)
			{
				if (estaEnMovimiento)
				{
					Console.WriteLine("El auto debe estar detenido para poder apagarse.");
				}
				else
				{
					estaPrendido = false;

					Console.WriteLine("El auto apagó sus motores.");
				}
			}
			else
			{
				Console.WriteLine("El auto ya está apagado.");
			}
		}

		public void Acelerar()
		{
			if (estaPrendido)
			{
				if (!estaEnMovimiento)
				{
					estaEnMovimiento = true;

					Console.WriteLine("El auto aceleró y empezó a recorrer su camino.");
				}
				else
				{
					Console.WriteLine("¡El auto ya aceleró!");
				}
			}
			else
			{
				Console.WriteLine("Para acelerar, el auto debe prenderse.");
			}
		}
		public void Frenar()
		{
			if (estaPrendido)
			{
				if (estaEnMovimiento)
				{
					estaEnMovimiento = false;

					Console.WriteLine("El auto detuvo su marcha lentamente hasta quedarse quieto.");
				}
				else
				{
					Console.WriteLine("El auto ya está quieto.");
				}
			}
			else
			{
				Console.WriteLine("Para poder frenar, el auto debe estar prendido y en marcha.");
			}
		}

		public void MostrarDatos()
		{
			Console.WriteLine("Color del auto: " + color + ".");
			Console.Write("Estado del auto: ");

			if (estaPrendido)
			{
				Console.Write("Prendido y ");

				if (estaEnMovimiento)
				{
					Console.WriteLine("andando.");
				}
				else
				{
					Console.WriteLine("quieto.");
				}
			}
			else
			{
				Console.WriteLine("Apagado.");
			}
		}

	}
}

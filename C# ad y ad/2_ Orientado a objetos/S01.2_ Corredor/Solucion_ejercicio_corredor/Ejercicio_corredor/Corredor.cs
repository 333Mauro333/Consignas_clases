using System;


namespace Ejercicio_corredor
{
	class Corredor
	{
		string nombre;
		float velocidadMax;
		bool tieneEnergia;


		public Corredor(string nombre, float velocidadMax)
		{
			this.nombre = nombre;
			this.velocidadMax = velocidadMax;

			tieneEnergia = true;
		}


		public void Correr()
		{
			if (tieneEnergia)
			{
				tieneEnergia = false;

				Console.WriteLine(nombre + " corrió con todas sus fuerzas, alcanzando una velocidad de " + velocidadMax + ".");
			}
			else
			{
				Console.WriteLine(nombre + " no tiene energía.");
			}
		}
		public void Descansar()
		{
			if (!tieneEnergia)
			{
				tieneEnergia = true;

				Console.WriteLine("¡" + nombre + " ha descansado!");
			}
			else
			{
				Console.WriteLine("¡" + nombre + " ya cuenta con energía!");
			}
		}
	}
}

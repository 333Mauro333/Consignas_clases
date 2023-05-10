using System;


namespace Ejercicio_presentacion
{
	class Personaje
	{
		string nombre;
		int numero;


		public Personaje(string nombre, int numero)
		{
			this.nombre = nombre;
			this.numero = numero;
		}


		public void Presentarse()
		{
			Console.WriteLine("¡Hola! ¡Me llamo " + nombre + "! Participo en la solución de este ejercicio.");
		}
		public void DecirNumeroGuardado()
		{
			Console.WriteLine("El número guardado de " + nombre + " es " + numero + ".");
		}
		public void Despedirse()
		{
			Console.WriteLine(nombre + " se despide. ¡Hasta luego!");
		}
	}
}

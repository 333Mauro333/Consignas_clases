using System;


namespace La_observacion
{
	class Persona
	{
		string nombre;


		public Persona(string nombre)
		{
			this.nombre = nombre;
		}


		public void Observar(Arbol arbol)
		{
			Console.WriteLine(nombre + " ve un arbol con una altura de " + arbol.GetAltura() + " m. Cantidad de hojas: " + arbol.GetCantidadDeHojas() + ".");
		}
		public void Observar(Piedra piedra)
		{
			Console.WriteLine(nombre + " observa una piedra. Su color: " + piedra.GetColor() + ". Su tamanio: " + piedra.GetTamanio() + ".");
		}
		public void Observar(Nube nube)
		{
			Console.WriteLine(nombre + " mira a una nube en el cielo. Su color: " + nube.GetColor() + ".");
		}
	}
}

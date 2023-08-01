using System;


namespace La_observacion
{
	class Program
	{
		static void Main()
		{
			Persona persona = new Persona("Mauro");
			Arbol arbol = new Arbol(7.25f, "Muchas");
			Piedra piedra = new Piedra("Mediano", "Verde");
			Nube nube = new Nube("Blanco");


			persona.Observar(arbol);
			persona.Observar(piedra);
			persona.Observar(nube);


			Console.ReadKey(true);
		}
	}
}

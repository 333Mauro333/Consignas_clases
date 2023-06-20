
namespace Ejercicio_paracaidista
{
	class Paracaidista
	{
		string nombre;
		int edad;
		string terrenoDondeCaer;


		public Paracaidista()
		{
			nombre = "";
			edad = 0;
			terrenoDondeCaer = "";
		}


		public string GetNombre()
		{
			return nombre;
		}
		public int GetEdad()
		{
			return edad;
		}
		public string GetTerrenoDondeCaer()
		{
			return terrenoDondeCaer;
		}

		public void SetNombre(string nombre)
		{
			this.nombre = nombre;
		}
		public void SetEdad(int edad)
		{
			this.edad = edad;
		}
		public void SetTerrenoDondeCaer(string terrenoDondeCaer)
		{
			this.terrenoDondeCaer = terrenoDondeCaer;
		}
	}
}

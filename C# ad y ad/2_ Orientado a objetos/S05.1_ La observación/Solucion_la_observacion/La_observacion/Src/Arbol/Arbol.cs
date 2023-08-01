
namespace La_observacion
{
	class Arbol
	{
		float altura;
		string cantidadDeHojas;


		public Arbol(float altura, string cantidadDeHojas)
		{
			this.altura = altura;
			this.cantidadDeHojas = cantidadDeHojas;
		}


		public float GetAltura()
		{
			return altura;
		}
		public string GetCantidadDeHojas()
		{
			return cantidadDeHojas;
		}
	}
}

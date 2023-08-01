
namespace La_observacion
{
	class Piedra
	{
		string tamanio;
		string color;


		public Piedra(string tamanio, string color)
		{
			this.tamanio = tamanio;
			this.color = color;
		}


		public string GetTamanio()
		{
			return tamanio;
		}
		public string GetColor()
		{
			return color;
		}
	}
}

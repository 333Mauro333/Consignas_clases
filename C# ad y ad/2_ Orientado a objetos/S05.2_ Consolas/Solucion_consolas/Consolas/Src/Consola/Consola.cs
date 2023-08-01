
namespace Consolas
{
	class Consola
	{
		int volumen;
		int brillo;


		public Consola()
		{
			volumen = 100;
			brillo = 100;
		}


		public int GetVolumen()
		{
			return volumen;
		}
		public int GetBrillo()
		{
			return brillo;
		}

		public void SetVolumen(int volumen)
		{
			this.volumen = volumen;
		}
		public void SetBrillo(int brillo)
		{
			this.brillo = brillo;
		}
	}
}

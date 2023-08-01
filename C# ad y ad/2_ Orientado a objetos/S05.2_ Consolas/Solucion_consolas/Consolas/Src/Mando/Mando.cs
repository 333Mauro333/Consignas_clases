
namespace Consolas
{
	class Mando
	{
		Consola consola;


		public Mando()
		{
			consola = null;
		}


		public void CambiarVolumenConsola(int volumen)
		{
			consola.SetVolumen(volumen);
		}
		public void CambiarBrilloConsola(int brillo)
		{
			consola.SetBrillo(brillo);
		}

		public void ConectarALaConsola(Consola consola)
		{
			this.consola = consola;
		}
		public void Desconectar()
		{
			consola = null;
		}

		public bool EstaConectado()
		{
			return consola != null;
		}

		public Consola GetConsola()
		{
			return consola;
		}
	}
}

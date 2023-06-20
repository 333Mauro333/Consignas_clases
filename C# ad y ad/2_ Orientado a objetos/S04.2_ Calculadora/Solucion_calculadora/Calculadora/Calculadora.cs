using System;


namespace Calculadora
{
	static class Calculadora
	{
		static int cuentasHechasComun = 0;
		static int cuentasHechasCientifica = 0;

		static TipoDeCalculadora tipoDeCalculadora = TipoDeCalculadora.Comun;


		public static float Sumar(float numero1, float numero2)
		{
			cuentasHechasComun++;

			return numero1 + numero2;
		}
		public static float Restar(float numero1, float numero2)
		{
			cuentasHechasComun++;

			return numero1 - numero2;
		}
		public static float Multiplicar(float numero1, float numero2)
		{
			cuentasHechasComun++;

			return numero1 * numero2;
		}
		public static float Dividir(float numero1, float numero2)
		{
			cuentasHechasComun++;

			return numero1 / numero2;
		}

		public static float ObtenerPotencia(float numeroAElevar, float aCuantoElevar)
		{
			cuentasHechasCientifica++;

			return (float)Math.Pow(numeroAElevar, aCuantoElevar);
		}
		public static float ObtenerRaiz(float numeroAEstablecerRaiz, float tipoDeRaiz)
		{
			cuentasHechasCientifica++;

			return (float)Math.Pow(numeroAEstablecerRaiz, 1.0f / tipoDeRaiz);
		}

		public static void CambiarTipoDeCalculadora()
		{
			if (tipoDeCalculadora == TipoDeCalculadora.Comun)
			{
				tipoDeCalculadora = TipoDeCalculadora.Cientifica;
			}
			else
			{
				tipoDeCalculadora = TipoDeCalculadora.Comun;
			}
		}
		public static void RestablecerEstadisticas()
		{
			cuentasHechasComun = 0;
			cuentasHechasCientifica = 0;
		}

		public static int GetCuentasHechasComun()
		{
			return cuentasHechasComun;
		}
		public static int GetCuentasHechasCientifica()
		{
			return cuentasHechasCientifica;
		}
		public static TipoDeCalculadora GetTipoDeCalculadora()
		{
			return tipoDeCalculadora;
		}
	}
}

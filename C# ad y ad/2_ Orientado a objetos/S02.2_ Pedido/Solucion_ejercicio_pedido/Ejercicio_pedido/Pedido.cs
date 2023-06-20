using System;


namespace Ejercicio_pedido
{
	class Pedido
	{
		string nombreCliente;
		string comidaPedida;
		bool seConsumeEnElLugar;


		public Pedido()
		{
			nombreCliente = "";
			comidaPedida = "";
			seConsumeEnElLugar = false;
		}


		public string GetNombreCliente()
		{
			return nombreCliente;
		}
		public string GetComidaPedida()
		{
			return comidaPedida;
		}
		public bool GetSeConsumeEnElLugar()
		{
			return seConsumeEnElLugar;
		}

		public void SetNombreCliente(string nombreCliente)
		{
			this.nombreCliente = nombreCliente;
		}
		public void SetComidaPedida(string comidaPedida)
		{
			this.comidaPedida = comidaPedida;
		}
		public void SetSeConsumeEnElLugar(bool seConsumeEnElLugar)
		{
			this.seConsumeEnElLugar = seConsumeEnElLugar;
		}
	}
}

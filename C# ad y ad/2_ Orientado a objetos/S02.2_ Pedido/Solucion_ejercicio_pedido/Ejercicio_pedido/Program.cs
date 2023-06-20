using System;


namespace Ejercicio_pedido
{
	class Program
	{
		static void Main()
		{
			Pedido pedido = new Pedido();

			string nombreCliente = "";
			string comidaPedida = "";
			int opcion = 0;


			Console.Write("Ingrese el nombre del cliente: ");
			nombreCliente = Console.ReadLine();

			Console.Write("¿Qué comida va a llevar? ");
			comidaPedida = Console.ReadLine();

			do
			{
				Console.WriteLine("¿Desea consumir en el lugar?\n");
				Console.WriteLine("1. SÍ");
				Console.WriteLine("2. NO\n");
				Console.Write("Opción elegida: ");
				opcion = int.Parse(Console.ReadLine());

			} while (opcion < 1 || opcion > 2);

			pedido.SetNombreCliente(nombreCliente);
			pedido.SetComidaPedida(comidaPedida);

			if (opcion == 1)
			{
				pedido.SetSeConsumeEnElLugar(true);
			}
			else
			{
				pedido.SetSeConsumeEnElLugar(false);
			}

			Console.WriteLine("\n\nInformación del pedido:\n");
			Console.WriteLine("Nombre del cliente: " + pedido.GetNombreCliente() + ".");
			Console.WriteLine("Comida pedida: " + pedido.GetComidaPedida() + ".");
			Console.Write("Se consume en el lugar: ");

			if (pedido.GetSeConsumeEnElLugar())
			{
				Console.WriteLine("SÍ\n");
			}
			else
			{
				Console.WriteLine("NO\n");
			}


			Console.ReadKey(true);
		}
	}
}

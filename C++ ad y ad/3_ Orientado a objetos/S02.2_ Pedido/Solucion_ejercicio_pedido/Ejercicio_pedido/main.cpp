#include <string>

#include "pedido.h"


int main()
{
	Pedido* pedido = new Pedido();

	string nombreCliente = "";
	string comidaPedida = "";
	int opcion = 0;


	cout << "Ingrese el nombre del cliente: ";
	cin >> nombreCliente;

	cout << "Que comida va a llevar? ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer para poder ingresar el string.
	getline(cin, comidaPedida);

	do
	{
		cout << "Desea consumir en el lugar?\n\n";
		cout << "1. SI\n";
		cout << "2. NO\n\n";
		cout << "Opcion elegida: ";
		cin >> opcion;

	} while (opcion < 1 || opcion > 2);

	pedido->setNombreCliente(nombreCliente);
	pedido->setComidaPedida(comidaPedida);

	if (opcion == 1)
	{
		pedido->setSeConsumeEnElLugar(true);
	}
	else
	{
		pedido->setSeConsumeEnElLugar(false);
	}

	cout << "\n\nInformacion del pedido:\n\n";
	cout << "Nombre del cliente: " << pedido->getNombreCliente() << ".\n";
	cout << "Comida pedida: " << pedido->getComidaPedida() << ".\n";
	cout << "Se consume en el lugar: ";

	if (pedido->getSeConsumeEnElLugar())
	{
		cout << "SI\n\n";
	}
	else
	{
		cout << "NO\n\n";
	}

	delete pedido;


	return 0;
}

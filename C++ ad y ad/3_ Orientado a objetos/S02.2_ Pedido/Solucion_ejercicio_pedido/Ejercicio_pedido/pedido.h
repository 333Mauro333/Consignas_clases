#pragma once

#include <iostream>

using namespace std;


class Pedido
{
public:
	Pedido();
	~Pedido();

	string getNombreCliente();
	string getComidaPedida();
	bool getSeConsumeEnElLugar();

	void setNombreCliente(string nombreCliente);
	void setComidaPedida(string comidaPedida);
	void setSeConsumeEnElLugar(bool seConsumeEnElLugar);

private:
	string nombreCliente;
	string comidaPedida;
	bool seConsumeEnElLugar;
};

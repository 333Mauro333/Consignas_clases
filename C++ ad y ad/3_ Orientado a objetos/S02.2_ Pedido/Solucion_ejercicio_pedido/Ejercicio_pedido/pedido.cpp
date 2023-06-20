#include "pedido.h"


Pedido::Pedido()
{
	nombreCliente = "";
	comidaPedida = "";
	seConsumeEnElLugar = false;
}
Pedido::~Pedido()
{
	cout << "El pedido de " << nombreCliente << " ha sido liberado de la memoria.\n\n";
}


string Pedido::getNombreCliente()
{
	return nombreCliente;
}
string Pedido::getComidaPedida()
{
	return comidaPedida;
}
bool Pedido::getSeConsumeEnElLugar()
{
	return seConsumeEnElLugar;
}

void Pedido::setNombreCliente(string nombreCliente)
{
	this->nombreCliente = nombreCliente;
}
void Pedido::setComidaPedida(string comidaPedida)
{
	this->comidaPedida = comidaPedida;
}
void Pedido::setSeConsumeEnElLugar(bool seConsumeEnElLugar)
{
	this->seConsumeEnElLugar = seConsumeEnElLugar;
}

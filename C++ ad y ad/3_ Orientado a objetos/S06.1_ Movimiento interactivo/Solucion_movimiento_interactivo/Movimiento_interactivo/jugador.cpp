#include "jugador.h"

#include <iostream>

#include "mgtv_library.h"

using namespace std;
using namespace mgtv_library::console;


Jugador::Jugador(int x, int y)
{
	controles = {};
	controlesAlternativos = {};
	posicion = { x, y };
	limites = {};

	cantidadDeMovimientosHechos = 0;
}
Jugador::~Jugador()
{
	cout << "El jugador ha sido liberado de la memoria." << endl << endl;
}


void Jugador::update()
{
	int teclaPresionada = ConsoleExt::getKey(false);


	if (teclaPresionada == controles.arriba || teclaPresionada == controlesAlternativos.arriba)
	{
		if (posicion.y > limites.superior + 1)
		{
			posicion.y--;
			cantidadDeMovimientosHechos++;
		}
	}
	else if (teclaPresionada == controles.abajo || teclaPresionada == controlesAlternativos.abajo)
	{
		if (posicion.y < limites.inferior - 1)
		{
			posicion.y++;
			cantidadDeMovimientosHechos++;
		}
	}
	else if (teclaPresionada == controles.izquierda || teclaPresionada == controlesAlternativos.izquierda)
	{
		if (posicion.x > limites.izquierdo + 1)
		{
			posicion.x--;
			cantidadDeMovimientosHechos++;
		}
	}
	else if (teclaPresionada == controles.derecha || teclaPresionada == controlesAlternativos.derecha)
	{
		if (posicion.x < limites.derecho - 1)
		{
			posicion.x++;
			cantidadDeMovimientosHechos++;
		}
	}
}
void Jugador::draw()
{
	ConsoleExt::goToCoordinates(posicion.x, posicion.y);
	cout << "*";
}

int Jugador::getCantidadDeMovimientosHechos()
{
	return cantidadDeMovimientosHechos;
}
void Jugador::setControles(int arriba, int abajo, int izquierda, int derecha)
{
	controles.arriba = arriba;
	controles.abajo = abajo;
	controles.izquierda = izquierda;
	controles.derecha = derecha;
}
void Jugador::setControlesAlternativos(int arriba, int abajo, int izquierda, int derecha)
{
	controlesAlternativos.arriba = arriba;
	controlesAlternativos.abajo = abajo;
	controlesAlternativos.izquierda = izquierda;
	controlesAlternativos.derecha = derecha;
}
void Jugador::setLimites(int superior, int inferior, int izquierdo, int derecho)
{
	limites.superior = superior;
	limites.inferior = inferior;
	limites.izquierdo = izquierdo;
	limites.derecho = derecho;
}

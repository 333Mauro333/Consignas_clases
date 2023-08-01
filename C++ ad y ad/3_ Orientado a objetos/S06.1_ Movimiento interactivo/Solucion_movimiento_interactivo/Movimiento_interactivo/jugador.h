#pragma once

#include "controles.h"
#include "posicion.h"
#include "limites.h"


class Jugador
{
public:
	Jugador(int x, int y);
	~Jugador();

	void update();
	void draw();

	int getCantidadDeMovimientosHechos();
	void setControles(int arriba, int abajo, int izquierda, int derecha);
	void setControlesAlternativos(int arriba, int abajo, int izquierda, int derecha);
	void setLimites(int superior, int inferior, int izquierdo, int derecho);

private:
	CONTROLES controles;
	CONTROLES controlesAlternativos;
	POSICION posicion;
	LIMITES limites;
	
	int cantidadDeMovimientosHechos;
};

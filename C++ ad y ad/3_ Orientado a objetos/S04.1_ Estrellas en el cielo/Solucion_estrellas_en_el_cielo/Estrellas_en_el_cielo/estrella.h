#pragma once

#include "posicion.h"


class Estrella
{
public:
	Estrella();
	~Estrella();

	static int getCantCambiosPosicion();

	void draw();
	
	POSICION getPosicion();
	void setPosicion(int x, int y);

private:
	static int cantCambiosPosicion;

	POSICION posicion;
};

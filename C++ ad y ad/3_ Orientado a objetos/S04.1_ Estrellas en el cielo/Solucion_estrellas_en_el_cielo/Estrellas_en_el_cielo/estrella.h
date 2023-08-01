#ifndef ESTRELLA_H
#define ESTRELLA_H

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

#endif // !ESTRELLA_H

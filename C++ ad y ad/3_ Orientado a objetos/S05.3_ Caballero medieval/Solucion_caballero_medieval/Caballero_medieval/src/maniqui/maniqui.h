#ifndef MANIQUI_H
#define MANIQUI_H

#include "structs/posicion/posicion.h"


class Maniqui
{
public:
	Maniqui(int vida);
	~Maniqui();

	void setPosicion(int x, int y);

	bool estaVivo();

	void recibirDanio(int danio);

	void draw();

private:
	int vida;

	POSICION posicion;
};

#endif // !MANIQUI_H

#ifndef LUZ_H
#define LUZ_H

#include <iostream>

#include "mgtv_library.h"

#include "posicion.h"

using namespace std;
using namespace mgtv_library::console;


class Luz
{
public:
	Luz();
	~Luz();

	static int getLucesEncendidas();

	void draw();

	void encender();
	void apagar();

	bool getEstaEncendida();
	void setPosicion(int x, int y);

private:
	static int lucesEncendidas;

	bool estaEncendida;
	POSICION posicion;

	string obtenerCaracteres(char caracter, int cantidad);
};

#endif // !LUZ_H

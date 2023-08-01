#ifndef CABALLERO_H
#define CABALLERO_H

#include <string>

#include "espada/espada.h"
#include "piedra_preciosa/piedra_preciosa.h"

#include "structs/posicion/posicion.h"

using namespace std;


class Caballero
{
public:
	Caballero(string nombre);
	~Caballero();

	void setPosicion(int x, int y);

	string getNombre();

	bool tieneUnaEspada();

	void agarrarEspada(Espada* espada);
	void soltarEspada();
	void atacar();
	void observarPiedra(PiedraPreciosa* piedraPreciosa);

	void draw();

private:
	string nombre;

	POSICION posicion;
	Espada* espada;
};

#endif // !CABALLERO_H

#include "piedra_preciosa.h"

#include <iostream>


PiedraPreciosa::PiedraPreciosa(string tipo)
{
	this->tipo = tipo;
}
PiedraPreciosa::~PiedraPreciosa()
{
	cout << "La piedra preciosa de tipo " << tipo << " fue liberada de la memoria." << endl << endl;
}


string PiedraPreciosa::getTipo()
{
	return tipo;
}

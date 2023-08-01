#include "nube.h"

#include <iostream>


Nube::Nube(string color)
{
	this->color = color;
}
Nube::~Nube()
{
	cout << "La nube de color " << color << " fue liberada de la memoria." << endl << endl;
}


string Nube::getColor()
{
	return color;
}

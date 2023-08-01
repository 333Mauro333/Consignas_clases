#pragma once

#include <string>

using namespace std;


class Espada
{
public:
	Espada(string material, int danio);
	~Espada();

	string getMaterial();
	int getDanio();

private:
	string material;
	int danio;
};

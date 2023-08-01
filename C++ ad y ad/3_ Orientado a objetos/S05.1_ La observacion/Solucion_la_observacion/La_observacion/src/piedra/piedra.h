#pragma once

#include <string>

using namespace std;


class Piedra
{
public:
	Piedra(string tamanio, string color);
	~Piedra();

	string getTamanio();
	string getColor();

private:
	string tamanio;
	string color;
};

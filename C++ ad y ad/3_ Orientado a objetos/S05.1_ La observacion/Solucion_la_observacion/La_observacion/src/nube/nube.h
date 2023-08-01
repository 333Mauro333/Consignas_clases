#pragma once

#include <string>

using namespace std;


class Nube
{
public:
	Nube(string color);
	~Nube();

	string getColor();

private:
	string color;
};

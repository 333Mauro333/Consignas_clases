#pragma once

#include <string>

using namespace std;


class PiedraPreciosa
{
public:
	PiedraPreciosa(string tipo);
	~PiedraPreciosa();

	string getTipo();

private:
	string tipo;
};

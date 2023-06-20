#pragma once

#include <iostream>

using namespace std;


class Automovil
{
	public:
		Automovil(string color);
		~Automovil();

		void prender();
		void apagar();

		void acelerar();
		void frenar();
		
		void mostrarDatos();

	private:
		string color;
		bool estaPrendido;
		bool estaEnMovimiento;
};

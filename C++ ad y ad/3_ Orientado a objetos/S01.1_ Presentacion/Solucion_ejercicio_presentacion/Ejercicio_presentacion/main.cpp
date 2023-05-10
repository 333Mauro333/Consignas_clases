#include <iostream>

#include "personaje.h"

using namespace std;


int main()
{
	Personaje* personaje = new Personaje("Mauro", 7);


	personaje->presentarse();
	personaje->decirNumeroGuardado();
	personaje->despedirse();

	delete personaje;


	return 0;
}

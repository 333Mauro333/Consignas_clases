#include <iostream>

#include "corredor.h"

using namespace std;


int main()
{
	Corredor* corredor = new Corredor("Mauro", 50.0f);


	corredor->correr();    // Corre.
	corredor->descansar(); // Descansa.
	cout << endl;

	corredor->correr();    // Vuelve a correr.
	corredor->correr();    // Intenta correr sin haber descansado.
	cout << endl;

	corredor->descansar(); // Descansa.
	corredor->descansar(); // Intenta descansar habiendo descansado.
	cout << endl;

	delete corredor;


	return 0;
}

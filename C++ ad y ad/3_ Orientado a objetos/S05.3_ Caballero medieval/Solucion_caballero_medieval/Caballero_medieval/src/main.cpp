#include <iostream>

#include "mgtv_library.h"

#include "caballero/caballero.h"
#include "espada/espada.h"
#include "piedra_preciosa/piedra_preciosa.h"

using namespace std;
using namespace mgtv_library::console;


int main()
{
	int anchoVentana = ConsoleExt::getScreenWidth();
	int altoConsola = ConsoleExt::getScreenHeight();

	Caballero* caballero = new Caballero("Mauro");
	Espada* espada = new Espada("Hierro", 75);
	PiedraPreciosa* piedraPreciosa = new PiedraPreciosa("Zafiro");





	return 0;
}

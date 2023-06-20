#include <iostream>

#include "mgtv_library.h"

using namespace std;
using namespace mgtv_library::console;


int main()
{
	int anchoConsola = ConsoleExt::getScreenWidth();
	int altoConsola = ConsoleExt::getScreenHeight();
	int distanciaBordesX = 10;
	int distanciaBordesY = 3;

	string titulo = "ESTA ES UNA PRUEBA";
	string descripcion = "Esta es una introduccion a la novedosa libreria MGTV.";
	string descripcion2 = "Una nueva forma de encarar los ejercicios se aproxima!";
	

	ConsoleExt::setConsoleTitle("PRUEBA DE LIBRERIA MGTV");

	ConsoleExt::goToCoordinates(anchoConsola / 2 - titulo.size() / 2, 1);
	ConsoleExt::writeWithColor(titulo, COLOR::C_GREEN);

	ConsoleExt::drawFrame(distanciaBordesX, distanciaBordesY, anchoConsola - distanciaBordesX, altoConsola - distanciaBordesY, COLOR::C_YELLOW);

	ConsoleExt::goToCoordinates(anchoConsola / 2 - descripcion.size() / 2, altoConsola / 2 - 1);
	ConsoleExt::writeWithColor(descripcion, COLOR::C_LGREEN);

	ConsoleExt::goToCoordinates(anchoConsola / 2 - descripcion2.size() / 2, altoConsola / 2);
	ConsoleExt::writeWithColor(descripcion2, COLOR::C_LGREEN);

	ConsoleExt::goToCoordinates(1, altoConsola - distanciaBordesY + 2);

	system("pause");


	return 0;
}

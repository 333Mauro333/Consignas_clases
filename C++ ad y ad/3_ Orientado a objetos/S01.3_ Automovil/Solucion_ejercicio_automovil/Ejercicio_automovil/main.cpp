#include "automovil.h"


int main()
{
	Automovil* automovil = new Automovil("Verde");



	// Probando el auto normalmente.
	automovil->prender();
	automovil->acelerar();
	automovil->frenar();
	automovil->apagar();
	cout << endl << endl;


	// Probando sus posibilidades en cuanto a encendido y apagado.
	automovil->prender();
	automovil->prender();
	automovil->apagar();
	automovil->apagar();
	cout << endl << endl;


	// Probando acelerar y frenar mientras está apagado.
	automovil->acelerar();
	automovil->frenar();
	cout << endl << endl;

	
	// Probando sus posibilidades en cuanto a acelerado y frenado.
	automovil->prender();
	automovil->acelerar();
	automovil->acelerar();
	automovil->apagar();
	automovil->frenar();
	automovil->frenar();
	automovil->apagar();
	cout << endl << endl;

	
	// Mostrando datos en cada estado del auto.
	automovil->mostrarDatos();
	cout << endl;

	automovil->prender();
	cout << endl;

	automovil->mostrarDatos();
	cout << endl;

	automovil->acelerar();
	cout << endl;

	automovil->mostrarDatos();
	cout << endl;

	automovil->frenar();
	cout << endl;

	automovil->mostrarDatos();
	cout << endl;

	automovil->apagar();
	cout << endl;

	delete automovil;


	return 0;
}

#include <iostream>

using namespace std;


int main()
{
	int numero = 0;

	int unidades = 0;
	int decenas = 0;
	int centenas = 0;
	int unidadesDeMil = 0;

	int dia = 0;
	int mes = 0;
	int anio = 0;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese un numero de 4 cifras: ";
	cin >> numero;

	unidades = numero % 10; // Obtengo el resto tras dividirlo por 10. Darían las unidades.
	decenas = numero / 10 % 10; // Lo divido por 10 (las decenas quedan como unidades) y repito el paso de arriba.
	centenas = numero / 100 % 10; // Lo divido por 100 (las centenas quedan como unidades) y lo mismo de arriba.
	unidadesDeMil = numero / 1000; // Al dividir por 1000, solamente la unidad de mil queda en la parte entera.


	cout << endl;
	cout << "Unidades de mil: " << unidadesDeMil << endl;
	cout << "Centenas: " << centenas << endl;
	cout << "Decenas: " << decenas << endl;
	cout << "Unidades: " << unidades << endl << endl << endl;


	cout << "--- EJERCICIO 2 ---" << endl << endl;

	numero = 25122020;
	cout << "Numero a descomponer: " << numero << endl << endl;

	dia = numero / 1000000;		// Cada "0" saca una cifra del número. Se sacan las necesarias para que
								// quede solamente el 25.

	mes = numero / 10000 % 100; // Sacando 4 cifras, el resultado da "2512". Se obtiene el resto al dividir por 100
								// y finalmente nos queda el mes.

	anio = numero % 10000;		// Cantidad de "0" que ponemos, cantidad de cifras que nos quedan. 4 ceros, 4 cifras.

	cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl << endl << endl;



	return 0;
}

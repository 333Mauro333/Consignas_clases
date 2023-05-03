#include <iostream>
#include <Windows.h>

using namespace std;


int pedirNumero(string mensaje = "Ingrese un numero: ");

void mostrarPrecios(int costo1Clase, int costo5Clases);

int main()
{
	float costoAnterior = 0.0f;
	float promo5Anterior = 0.0f;

	float costoNuevo = 0.0f;
	float promo5Nuevo = 0.0f;


	cout << "             ----- CALCULADORA DE COSTOS -----" << endl << endl << endl;

	costoAnterior = pedirNumero("Ingrese el costo anterior de las clases: ");

	cout << "\nLa promo de 5 clases vale " << costoAnterior * 5.0f - costoAnterior / 3.0f << "." << endl;
	promo5Anterior = pedirNumero("Ingrese el costo deseado en el caso de necesitar redondearse: ");

	cout << endl;
	mostrarPrecios(costoAnterior, promo5Anterior);


	costoNuevo = pedirNumero("Ingrese el costo nuevo de las clases: ");

	cout << "\nLa promo de 5 clases vale " << costoNuevo * 5.0f - costoNuevo / 3.0f << "." << endl;
	promo5Nuevo = pedirNumero("Ingrese el costo deseado en el caso de necesitar redondearse: ");

	cout << endl;
	mostrarPrecios(costoNuevo, promo5Nuevo);


	system("pause");


	return 0;
}

int pedirNumero(string mensaje)
{
	int numero = 0;


	cout << mensaje;
	cin >> numero;


	return numero;
}

void mostrarPrecios(int costo1Clase, int costo5Clases)
{
	cout << "Costo por 1 clase: $" << costo1Clase << endl;
	cout << "Costo por 2 clases: $" << costo1Clase * 2.0f << endl;
	cout << "Costo por 3 clases: $" << costo1Clase * 3.0f << endl;
	cout << "Costo por 4 clases: $" << costo1Clase * 4.0f << endl;
	cout << "Costo por 5 clases: $" << costo5Clases << " ($-" << costo1Clase * 5.0f - costo5Clases << " de promo)" << endl;
	cout << "Costo por 6 clases: $" << costo5Clases + costo1Clase << endl;
	cout << "Costo por 7 clases: $" << costo5Clases + costo1Clase * 2.0f << endl;
	cout << "Costo por 8 clases: $" << costo5Clases + costo1Clase * 3.0f << endl;
	cout << "Costo por 9 clases: $" << costo5Clases + costo1Clase * 4.0f << endl;
	cout << "Costo por 10 clases: $" << costo1Clase * 10.0f - costo1Clase << " (1 clase de regalo)" << endl << endl << endl;
}

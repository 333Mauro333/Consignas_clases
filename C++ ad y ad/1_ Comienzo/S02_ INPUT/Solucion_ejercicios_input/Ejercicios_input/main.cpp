#include <iostream>

using namespace std;


int main()
{
	int num = 0;
	
	int dia = 0;
	int mes = 0;
	int anio = 0;

	int vida = 0;
	int escudo = 0;

	string nombre = "";
	int edad = 0;
	float altura = 0.0f;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> num;

	cout << "El numero ingresado es " << num << "." << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Ingrese el dia: ";
	cin >> dia;
	cout << "Ingrese el mes: ";
	cin >> mes;
	cout << "Ingrese el anio: ";
	cin >> anio;

	cout << endl;
	cout << "Fecha ingresada: " << dia << "/" << mes << "/" << anio << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese la vida de su personaje: ";
	cin >> vida;
	cout << "Ingrese el escudo de su personaje: ";
	cin >> escudo;

	cout << endl;
	cout << "Vida: " << vida << "." << endl;
	cout << "Escudo: " << escudo << "." << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Ingrese su nombre: ";
	cin >> nombre;
	cout << "Ingrese su edad: ";
	cin >> edad;
	cout << "Ingrese la altura (en metros): ";
	cin >> altura;

	cout << endl;
	cout << "Nombre: " << nombre << "." << endl;
	cout << "Edad: " << edad << " anios." << endl;
	cout << "Altura: " << altura << " m." << endl << endl << endl;



	return 0;
}

#include <iostream>

using namespace std;


int main()
{
	float tempCelsius = 0.0f;
	float distanciaEnKM = 0.0f;
	float pesoEnGramos = 0.0f;
	float resultado = 0.0f;

	int bytes = 0;

	int vida = 0;
	int danio = 0;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese la temperatura (en grados Celsius): ";
	cin >> tempCelsius;

	cout << endl;
	cout << "Temperatura en grados Kelvin: " << tempCelsius + 273.15f << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Ingrese la distancia en kilometros: ";
	cin >> distanciaEnKM;

	cout << endl;
	cout << "Distancia en metros: " << distanciaEnKM * 1000.0f << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese el peso en gramos: ";
	cin >> pesoEnGramos;

	resultado = pesoEnGramos / 1000.0f;

	cout << "Peso en kilogramos: " << resultado << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Ingrese la cantidad de bytes: ";
	cin >> bytes;

	cout << "Cantidad convertida a bits: " << bytes * 8 << endl << endl << endl;



	cout << "--- EJERCICIO 5 ---" << endl << endl;

	cout << "Ingrese la vida del personaje: ";
	cin >> vida;
	cout << "Ingrese el danio que va a recibir: ";
	cin >> danio;

	vida -= danio;

	cout << endl;
	cout << "Vida del personaje: " << vida << "." << endl << endl << endl;



	return 0;
}

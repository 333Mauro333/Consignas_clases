#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	const float pi = 3.1415926535f;

	float velocidadEnKMH = 0.0f;

	float nota1 = 0.0f;
	float nota2 = 0.0f;
	float nota3 = 0.0f;
	float promedio = 0.0f;

	float diametro = 0.0f;
	float radio = 0.0f;
	float area = 0.0f;
	float perimetro = 0.0f;

	float grados = 0.0f;
	float radianes = 0.0f;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese la velocidad (en KM/H): ";
	cin >> velocidadEnKMH;

	cout << endl;
	cout << "Velocidad en metros por segundo: " << velocidadEnKMH * 1000.0f / 3600.0f << endl << endl << endl;
	
	// Otra forma de resolverlo es haciendo directamente:    velocidadEnKMH / 3.6f.


	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Ingrese la primera nota: ";
	cin >> nota1;
	cout << "Ingrese la segunda nota: ";
	cin >> nota2;
	cout << "Ingrese la tercera nota: ";
	cin >> nota3;

	promedio = (nota1 + nota2 + nota3) / 3.0f;

	cout << endl;
	cout << "La nota promedio es " << promedio << "." << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "  Ingrese el diametro del circulo: ";
	cin >> diametro;

	radio = diametro / 2.0f; // El radio es igual a la mitad del diametro.
	area = pi * (radio * radio); // El área es igual a PI por la elevación al cuadrado del radio.
	perimetro = 2 * radio * pi; // El perímetro es igual a 2 por radio por PI.
								// También se puede hacer directamente: diametro * PI.

	cout << endl;
	cout << "  Su radio: " << radio << endl;
	cout << "  Su area: " << area << endl;
	cout << "  Su perimetro: " << perimetro << endl << endl << endl;


	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Ingrese un angulo en grados: ";
	cin >> grados;

	radianes = grados * pi / 180.0f;

	cout << endl;
	cout << "Resultado: " << radianes << " rad." << endl << endl << endl;



	return 0;
}

// Calculadora de valores del círculo a partir del radio: https://www.calkoo.com/es/calculadora-circulo
// Calculadora de grados a radianes: https://es.planetcalc.com/71/

#include <iostream>

using namespace std;


void mostrarArray(int numeros[], int tamanio);
void mostrarArray(string textos[], int tamanio);

int main()
{
	const int tamanio1 = 5;
	int arregloDeNumeros[tamanio1] = { 5, 10, 15, 20, 25 };

	const int tamanio2 = 3;
	string arregloDeStrings[tamanio2] = { "Mauro", "Guillermo", "Jose" };



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	mostrarArray(arregloDeNumeros, tamanio1);
	mostrarArray(arregloDeStrings, tamanio2);

	cout << endl;



	return 0;
}

void mostrarArray(int numeros[], int tamanio)
{
	cout << "Arreglo de numeros:\n";

	for (int i = 0; i < tamanio; i++)
	{
		cout << numeros[i] << " ";
	}

	cout << endl << endl;
}
void mostrarArray(string textos[], int tamanio)
{
	cout << "Arreglo de strings:\n";
	
	for (int i = 0; i < tamanio; i++)
	{
		cout << textos[i];

		if (i != tamanio - 1)
		{
			cout << ", ";
		}
	}

	cout << endl << endl;
}

#include <iostream>
#include <Windows.h>

using namespace std;


int main()
{
	float numero1 = 0;
	float numero2 = 0;
	float resultado = 0;

	int opcion = 0;


	cout << "--- CALCULADORA ---" << endl << endl << endl;

	cout << "Ingrese el primer numero: ";
	cin >> numero1;
	cout << endl;

	cout << "Que operacion desea realizar?" << endl << endl;
	cout << "1. SUMA" << endl;
	cout << "2. RESTA" << endl;
	cout << "3. MULTIPLICACION" << endl;
	cout << "4. DIVISION" << endl << endl;

	cout << "Opcion a elegir: ";
	cin >> opcion;
	cout << endl;

	cout << "Ingrese el segundo numero: ";
	cin >> numero2;
	cout << endl;

	cout << "Calculando.";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(2000);


	cout << endl << endl;
	cout << "El resultado de ";

	switch (opcion)
	{
	case 1:
		resultado = numero1 + numero2;
		cout << "la suma";
		break;

	case 2:
		resultado = numero1 - numero2;
		cout << "la resta";
		break;

	case 3:
		resultado = numero1 * numero2;
		cout << "la multiplicacion";
		break;

	case 4:
		resultado = numero1 / numero2;
		cout << "la division";
		break;
	}

	cout << " es " << resultado << endl << endl;
	system("pause");


	return 0;
}

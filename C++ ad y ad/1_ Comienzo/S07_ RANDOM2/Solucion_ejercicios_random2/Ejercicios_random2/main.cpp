#include <iostream>

using namespace std;


int main()
{
	int hora = 0;
	int minutos = 0;

	int dia = 0;
	int mes = 0;
	int anio = 0;

	float precio1 = 0.0f;
	float precio2 = 0.0f;
	float precio3 = 0.0f;
	float precio4 = 0.0f;
	float precio5 = 0.0f;

	char letra1 = '\0';
	char letra2 = '\0';
	char letra3 = '\0';
	int puntaje = 0;


	srand(time(NULL));



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	hora = rand() % 24;
	minutos = rand() % 60;

	cout << "Hora generada: ";

	if (hora < 10)
	{
		cout << "0";
	}

	cout << hora << ":";

	if (minutos < 10)
	{
		cout << "0";
	}

	cout << minutos << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	anio = rand() % (2100 - 1900 + 1) + 1900;
	mes = rand() % 12 + 1;

	switch (mes)
	{
	case 1: // Enero.
	case 3: // Marzo.
	case 5: // Mayo.
	case 7: // Julio.
	case 8: // Agosto.
	case 10: // Octubre.
	case 12:  // Diciembre.
		dia = rand() % 31 + 1;
		break;

	case 2: // Febrero.
		if (anio % 4 == 0) // Si el año es bisiesto...
		{
			dia = rand() % 29 + 1;
		}
		else
		{
			dia = rand() % 28 + 1;
		}
		break;

	default: // Todos los demás meses (abril, junio, septiembre y noviembre).
		dia = rand() % 30 + 1;
		break;
	}

	cout << "Fecha generada: " << dia << "/" << mes << "/" << anio << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	precio1 = rand() % (40000 - 30000 + 1) + 30000;
	precio2 = rand() % (40000 - 30000 + 1) + 30000;
	precio3 = rand() % (40000 - 30000 + 1) + 30000;
	precio4 = rand() % (40000 - 30000 + 1) + 30000;
	precio5 = rand() % (40000 - 30000 + 1) + 30000;

	precio1 /= 100;
	precio2 /= 100;
	precio3 /= 100;
	precio4 /= 100;
	precio5 /= 100;

	cout << "Precio del primer producto: $" << precio1 << endl;
	cout << "Precio del segundo producto: $" << precio2 << endl;
	cout << "Precio del tercer producto: $" << precio3 << endl;
	cout << "Precio del cuarto producto: $" << precio4 << endl;
	cout << "Precio del quinto producto: $" << precio5 << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	letra1 = rand() % (90 - 65 + 1) + 65;
	letra2 = rand() % (90 - 65 + 1) + 65;
	letra3 = rand() % (90 - 65 + 1) + 65;
	puntaje = rand() % (20000 - 10000 + 1) + 10000;

	cout << "   HIGHSCORES" << endl << endl;
	cout << " " << letra1 << letra2 << letra3 << "       " << puntaje << endl;
	cout << " ...       00000" << endl;
	cout << " ...       00000" << endl;
	cout << " ...       00000" << endl;
	cout << " ...       00000" << endl << endl << endl;



	return 0;
}

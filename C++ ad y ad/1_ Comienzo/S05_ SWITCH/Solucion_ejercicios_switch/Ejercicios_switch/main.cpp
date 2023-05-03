#include <iostream>

using namespace std;


int main()
{
	int opcion = 0;
	char opcionConLetra = '\0';



	cout << "--- EJERCICIO 1 ---" << endl << endl;
	
	cout << "    1. JUGAR" << endl; 
	cout << "   2. OPCIONES" << endl; 
	cout << "    3. AYUDA" << endl;
	cout << "    4. SALIR" << endl << endl;

	cout << "Opcion elegida: ";
	cin >> opcion;
	cout << endl;

	switch (opcion)
	{
	case 1:
		cout << "Cargando el juego... preparese...";
		break;

	case 2:
		cout << "Entrando a la configuracion del juego...";
		break;

	case 3:
		cout << "Esta seria la pantalla donde se explica el juego.";
		break;

	case 4:
		cout << "Cerrando el juego. Gracias por jugar!";
		break;

	default:
		cout << "Opcion no valida.";
		break;
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Desea salir del juego? Responda con y/n: ";
	cin >> opcionConLetra;
	cout << endl;

	switch (opcionConLetra)
	{
	case 'Y':
	case 'y':
		cout << "Cerrando el juego...";
		break;

	case 'N':
	case 'n':
		cout << "Se vuelve al menu principal.";
		break;

	default:
		cout << "Opcion no valida.";
		break;
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "    1. JUGAR" << endl;
	cout << "   2. OPCIONES" << endl;
	cout << "    3. AYUDA" << endl;
	cout << "   4. RECORDS" << endl;
	cout << "   5. CREDITOS" << endl;
	cout << "    6. SALIR" << endl << endl;

	cout << "Opcion elegida: ";
	cin >> opcion;
	cout << endl;

	switch (opcion)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		cout << "La opcion ingresada es valida.";
		break;

	case 50:
		cout << "Truco activado! Ahora tu jugador es invencible!";
		break;

	default:
		cout << "Opcion no valida.";
		break;
	}

	cout << endl << endl << endl;



	return 0;
}

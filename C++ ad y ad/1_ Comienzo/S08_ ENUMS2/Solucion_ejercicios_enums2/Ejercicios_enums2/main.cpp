#include <iostream>

using namespace std;


enum class CLIMA { SOLEADO = 1, NUBLADO, LLUVIOSO };
enum class COLOR { ROJO = 1, AZUL, AMARILLO, VERDE };

int main()
{
	CLIMA climaDelJuego = CLIMA::SOLEADO;

	COLOR colorJugador1 = COLOR::ROJO;
	COLOR colorCPU2 = COLOR::ROJO;
	COLOR colorCPU3 = COLOR::ROJO;
	COLOR colorCPU4 = COLOR::ROJO;

	int numeroRandom = 0;
	int opcion = 0;


	srand(time(NULL));



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Que clima desea en su juego?" << endl << endl;
	cout << "1. Soleado" << endl;
	cout << "2. Nublado" << endl;
	cout << "3. Lluvioso" << endl;
	cout << "4. Aleatorio" << endl << endl;
	
	cout << "Opcion elegida: ";
	cin >> opcion;
	cout << endl;

	if (opcion >= 1 && opcion <= 3)
	{
		climaDelJuego = (CLIMA)opcion;
	}
	else if (opcion == 4)
	{
		numeroRandom = rand() % 3 + 1;
		climaDelJuego = (CLIMA)numeroRandom;
	}

	cout << "Clima establecido: ";

	switch (climaDelJuego)
	{
	case CLIMA::SOLEADO:
		cout << "Soleado";
		break;

	case CLIMA::NUBLADO:
		cout << "Nublado";
		break;

	case CLIMA::LLUVIOSO:
		cout << "Lluvioso";
		break;
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Jugador 1, elija un color:" << endl << endl;
	cout << "1. Rojo" << endl;
	cout << "2. Azul" << endl;
	cout << "3. Amarillo" << endl;
	cout << "4. Verde" << endl << endl;

	cout << "Opcion elegida: ";
	cin >> opcion;
	cout << endl;

	colorJugador1 = (COLOR)opcion;

	numeroRandom = rand() % 4 + 1;
	colorCPU2 = (COLOR)numeroRandom;

	numeroRandom = rand() % 4 + 1;
	colorCPU3 = (COLOR)numeroRandom;

	numeroRandom = rand() % 4 + 1;
	colorCPU4 = (COLOR)numeroRandom;

	cout << "Color del JUGADOR: ";

	switch (colorJugador1)
	{
	case COLOR::ROJO:
		cout << "Rojo";
		break;

	case COLOR::AZUL:
		cout << "Azul";
		break;

	case COLOR::AMARILLO:
		cout << "Amarillo";
		break;

	case COLOR::VERDE:
		cout << "Verde";
		break;
	}


	cout << "." << endl;
	cout << "Color de la CPU 2: ";

	switch (colorCPU2)
	{
	case COLOR::ROJO:
		cout << "Rojo";
		break;

	case COLOR::AZUL:
		cout << "Azul";
		break;

	case COLOR::AMARILLO:
		cout << "Amarillo";
		break;

	case COLOR::VERDE:
		cout << "Verde";
		break;
	}


	cout << "." << endl;
	cout << "Color de la CPU 3: ";

	switch (colorCPU3)
	{
	case COLOR::ROJO:
		cout << "Rojo";
		break;

	case COLOR::AZUL:
		cout << "Azul";
		break;

	case COLOR::AMARILLO:
		cout << "Amarillo";
		break;

	case COLOR::VERDE:
		cout << "Verde";
		break;
	}


	cout << "." << endl;
	cout << "Color de la CPU 4: ";

	switch (colorCPU4)
	{
	case COLOR::ROJO:
		cout << "Rojo";
		break;

	case COLOR::AZUL:
		cout << "Azul";
		break;

	case COLOR::AMARILLO:
		cout << "Amarillo";
		break;

	case COLOR::VERDE:
		cout << "Verde";
		break;
	}

	cout << "." << endl << endl << endl;



	return 0;
}

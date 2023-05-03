#include <iostream>
#include <Windows.h>

using namespace std;


enum class OPCION_JUEGO { PIEDRA = 1, PAPEL, TIJERA };
enum class RESULTADO_FINAL { GANA_JUGADOR, GANA_CPU, EMPATE };

int main()
{
	OPCION_JUEGO opcionJugador = OPCION_JUEGO::PIEDRA;
	OPCION_JUEGO opcionCPU = OPCION_JUEGO::PIEDRA;
	RESULTADO_FINAL resultado = RESULTADO_FINAL::GANA_JUGADOR;

	int opcion = 0;


	srand(time(NULL));


	cout << "--- PIEDRA, PAPEL O TIJERA ---" << endl << endl;

	cout << "A continuacion, usted jugara un enfrentamiento contra la CPU. Quien ganara?" << endl << endl;
	system("pause");
	system("cls");

	cout << "--- PIEDRA, PAPEL O TIJERA ---" << endl << endl << endl;

	cout << "Elija una opcion:" << endl << endl;
	cout << "1. PIEDRA" << endl;
	cout << "2. PAPEL" << endl;
	cout << "3. TIJERA" << endl << endl;

	cout << "Opcion elegida: ";
	cin >> opcion;
	cout << endl;

	opcionJugador = (OPCION_JUEGO)opcion;

	opcion = rand() % 3 + 1;
	opcionCPU = (OPCION_JUEGO)opcion;


	cout << "Piedra...";

	Sleep(500);
	cout << endl;
	cout << "...papel...";

	Sleep(500);
	cout << endl;
	cout << "...o tijera!";

	Sleep(1000);
	cout << endl << endl;

	switch (opcionJugador)
	{
	case OPCION_JUEGO::PIEDRA:
		cout << "El jugador ha sacado PIEDRA." << endl;

		switch (opcionCPU)
		{
		case OPCION_JUEGO::PIEDRA:
			cout << "La CPU ha sacado PIEDRA";
			resultado = RESULTADO_FINAL::EMPATE;
			break;

		case OPCION_JUEGO::PAPEL:
			cout << "La CPU ha sacado PAPEL";
			resultado = RESULTADO_FINAL::GANA_CPU;
			break;

		case OPCION_JUEGO::TIJERA:
			cout << "La CPU ha sacado TIJERA";
			resultado = RESULTADO_FINAL::GANA_JUGADOR;
			break;
		}

		break;

	case OPCION_JUEGO::PAPEL:
		cout << "El jugador ha sacado PAPEL." << endl;

		switch (opcionCPU)
		{
		case OPCION_JUEGO::PIEDRA:
			cout << "La CPU ha sacado PIEDRA";
			resultado = RESULTADO_FINAL::GANA_JUGADOR;
			break;

		case OPCION_JUEGO::PAPEL:
			cout << "La CPU ha sacado PAPEL";
			resultado = RESULTADO_FINAL::EMPATE;
			break;

		case OPCION_JUEGO::TIJERA:
			cout << "La CPU ha sacado TIJERA";
			resultado = RESULTADO_FINAL::GANA_CPU;
			break;
		}

		break;

	case OPCION_JUEGO::TIJERA:
		cout << "El jugador ha sacado TIJERA." << endl;

		switch (opcionCPU)
		{
		case OPCION_JUEGO::PIEDRA:
			cout << "La CPU ha sacado PIEDRA";
			resultado = RESULTADO_FINAL::GANA_CPU;
			break;

		case OPCION_JUEGO::PAPEL:
			cout << "La CPU ha sacado PAPEL";
			resultado = RESULTADO_FINAL::GANA_JUGADOR;
			break;

		case OPCION_JUEGO::TIJERA:
			cout << "La CPU ha sacado TIJERA";
			resultado = RESULTADO_FINAL::EMPATE;
			break;
		}

		break;
	}

	cout << endl << endl;

	switch (resultado)
	{
	case RESULTADO_FINAL::GANA_JUGADOR:
		cout << "El jugador ha ganado el enfrentamiento!";
		break;

	case RESULTADO_FINAL::GANA_CPU:
		cout << "La CPU ha ganado el enfrentamiento.";
		break;

	case RESULTADO_FINAL::EMPATE:
		cout << "Se ha empatado la ronda.";
		break;
	}

	cout << endl << endl;
	system("pause");


	return 0;
}


//if (opcionJugador == OPCION_JUEGO::PIEDRA && opcionCPU == OPCION_JUEGO::PIEDRA)
//{
//	cout << mensajeJugadorPiedra << endl;
//	cout << mensajeCPUPiedra << endl;
//
//	resultado = RESULTADO_FINAL::EMPATE;
//}
//else if (opcionJugador == OPCION_JUEGO::PIEDRA && opcionCPU == OPCION_JUEGO::PAPEL)
//{
//	cout << mensajeJugadorPiedra << endl;
//	cout << mensajeCPUPapel << endl;
//
//	resultado = RESULTADO_FINAL::GANA_CPU;
//}
//else if (opcionJugador == OPCION_JUEGO::PIEDRA && opcionCPU == OPCION_JUEGO::TIJERA)
//{
//	cout << mensajeJugadorPiedra << endl;
//	cout << mensajeCPUTijera << endl;
//
//	resultado = RESULTADO_FINAL::GANA_JUGADOR;
//}
//else if (opcionJugador == OPCION_JUEGO::PAPEL && opcionCPU == OPCION_JUEGO::PIEDRA)
//{
//	cout << mensajeJugadorPapel << endl;
//	cout << mensajeCPUPiedra << endl;
//
//	resultado = RESULTADO_FINAL::GANA_JUGADOR;
//}
//else if (opcionJugador == OPCION_JUEGO::PAPEL && opcionCPU == OPCION_JUEGO::PAPEL)
//{
//	cout << mensajeJugadorPapel << endl;
//	cout << mensajeCPUPapel << endl;
//
//	resultado = RESULTADO_FINAL::EMPATE;
//}
//else if (opcionJugador == OPCION_JUEGO::PAPEL && opcionCPU == OPCION_JUEGO::TIJERA)
//{
//	cout << mensajeJugadorPapel << endl;
//	cout << mensajeCPUTijera << endl;
//
//	resultado = RESULTADO_FINAL::GANA_CPU;
//}
//else if (opcionJugador == OPCION_JUEGO::TIJERA && opcionCPU == OPCION_JUEGO::PIEDRA)
//{
//	cout << mensajeJugadorTijera << endl;
//	cout << mensajeCPUPiedra << endl;
//
//	resultado = RESULTADO_FINAL::GANA_CPU;
//}
//else if (opcionJugador == OPCION_JUEGO::TIJERA && opcionCPU == OPCION_JUEGO::PAPEL)
//{
//	cout << mensajeJugadorTijera << endl;
//	cout << mensajeCPUPapel << endl;
//
//	resultado = RESULTADO_FINAL::GANA_JUGADOR;
//}
//else if (opcionJugador == OPCION_JUEGO::TIJERA && opcionCPU == OPCION_JUEGO::TIJERA)
//{
//	cout << mensajeJugadorTijera << endl;
//	cout << mensajeCPUTijera << endl;
//
//	resultado = RESULTADO_FINAL::EMPATE;
//}
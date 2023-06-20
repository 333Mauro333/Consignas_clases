#include <iostream>

#include "mgtv_library.h"

#include "pantalla.h"
#include "operacion.h"
#include "calculadora.h"

using namespace std;
using namespace mgtv_library::console;


void borrarLinea(int linea);
void borrarPantalla(int lineaDesdeDondeBorrar);

string obtenerOperacionEnString(OPERACION operacion, bool enMayuscula = true);
void mostrarMenuDeResultado(float primerNumero, float segundoNumero, float resultado, OPERACION operacion);

int main()
{
	bool enPrograma = true;

	int anchoConsola = ConsoleExt::getScreenWidth();
	int altoConsola = ConsoleExt::getScreenHeight();

	PANTALLA pantallaActual = PANTALLA::MENU_PRINCIPAL;
	OPERACION operacionElegida = OPERACION::SUMA;

	string opcion1 = "1. REALIZAR UNA OPERACION";
	string opcion2 = "2. CAMBIAR EL TIPO DE CALCULADORA";
	string opcion3 = "3. ESTADISTICAS";
	string opcion4 = "4. APAGAR";

	string mensajeFinal = "Gracias por utilizar! Presione cualquier tecla para cerrar la ventana... ";

	float primerNumero = 0.0f;
	float segundoNumero = 0.0f;
	float resultado = 0.0f;

	int opcionIngresada = 0;


	while (enPrograma)
	{
		system("cls");

		switch (pantallaActual)
		{
		case PANTALLA::MENU_PRINCIPAL:

			#pragma region MENU PRINCIPAL

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 10, altoConsola / 2 - 6);
			cout << "--- CALCULADORA ---";

			if (Calculadora::getTipoDeCalculadora() == TIPO_DE_CALCULADORA::COMUN)
			{
				ConsoleExt::goToCoordinates(anchoConsola / 2 - 6, altoConsola / 2 - 5);
				cout << "Tipo: Comun.";
			}
			else
			{
				ConsoleExt::goToCoordinates(anchoConsola / 2 - 8, altoConsola / 2 - 5);
				cout << "Tipo: Cientifica.";
			}

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 9, altoConsola / 2 - 2);
			cout << "Elija una opcion: ";

			ConsoleExt::goToCoordinates(anchoConsola / 2 - opcion1.size() / 2, altoConsola / 2);
			cout << opcion1;

			ConsoleExt::goToCoordinates(anchoConsola / 2 - opcion2.size() / 2, altoConsola / 2 + 1);
			cout << opcion2;

			ConsoleExt::goToCoordinates(anchoConsola / 2 - opcion3.size() / 2, altoConsola / 2 + 2);
			cout << opcion3;

			ConsoleExt::goToCoordinates(anchoConsola / 2 - opcion4.size() / 2, altoConsola / 2 + 3);
			cout << opcion4;

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 + 6);
			cout << "Opcion elegida: ";
			cin >> opcionIngresada;

			switch (opcionIngresada)
			{
			case 1:

				#pragma region CARGA DEL MENU DE OPERACIONES

				if (Calculadora::getTipoDeCalculadora() == TIPO_DE_CALCULADORA::COMUN)
				{
					pantallaActual = PANTALLA::MENU_COMUN;
				}
				else
				{
					pantallaActual = PANTALLA::MENU_CIENTIFICA;
				}

				#pragma endregion

				break;

			case 2:

				// Se cambia el tipo de calculadora inmediatamente.
				Calculadora::cambiarTipoDeCalculadora();

				break;

			case 3:

				// Se cambia la pantalla a la de las estadísticas.
				pantallaActual = PANTALLA::ESTADISTICAS;

				break;

			case 4:

				#pragma region FINALIZACION DEL PROGRAMA

				enPrograma = false;

				ConsoleExt::goToCoordinates(anchoConsola / 2 - mensajeFinal.size() / 2, altoConsola / 2 + 8);
				ConsoleExt::writeWithColor(mensajeFinal, COLOR::C_LGREEN);

				#pragma endregion

				break;
			}

			#pragma endregion

			break;

		case PANTALLA::MENU_COMUN:

			#pragma region OPERACIONES CON CALCULADORA COMUN

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 13, altoConsola / 2 - 12);
			cout << "--- REALIZAR OPERACION ---";

			// 1. SE PIDE EL PRIMER NÚMERO.
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 9);
			cout << "Ingrese el primer numero: ";
			cin >> primerNumero;

			// 2. SE PIDE EL TIPO DE OPERACIÓN.
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 7);
			cout << "Elija una operacion:";

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 5);
			cout << "1. SUMA";
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 4);
			cout << "2. RESTA";
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 3);
			cout << "3. MULTIPLICACION";
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 2);
			cout << "4. DIVISION";

			do
			{
				borrarPantalla(altoConsola / 2);

				ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2);
				cout << "Opcion elegida: ";
				cin >> opcionIngresada;

			} while (opcionIngresada < 1 || opcionIngresada > 4);

			operacionElegida = (OPERACION)opcionIngresada;

			// Se pide el segundo número.
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 + 2);
			cout << "Ingrese el segundo numero: ";
			cin >> segundoNumero;

			// Se realiza la operación con la ayuda de la calculadora.
			switch (operacionElegida)
			{
			case OPERACION::SUMA:
				resultado = Calculadora::sumar(primerNumero, segundoNumero);
				break;

			case OPERACION::RESTA:
				resultado = Calculadora::restar(primerNumero, segundoNumero);
				break;

			case OPERACION::MULTIPLICACION:
				resultado = Calculadora::multiplicar(primerNumero, segundoNumero);
				break;

			case OPERACION::DIVISION:
				resultado = Calculadora::dividir(primerNumero, segundoNumero);
				break;
			}

			borrarPantalla(altoConsola / 2 - 12);

			// Se muestra el resultado.
			mostrarMenuDeResultado(primerNumero, segundoNumero, resultado, operacionElegida);

			do
			{
				borrarPantalla(altoConsola / 2 + 3);

				ConsoleExt::goToCoordinates(anchoConsola / 2 - 25, altoConsola / 2 + 3);
				cout << "Opcion elegida: ";
				cin >> opcionIngresada;

			} while (opcionIngresada < 1 || opcionIngresada > 2);

			if (opcionIngresada == 2)
			{
				pantallaActual = PANTALLA::MENU_PRINCIPAL;
			}

			#pragma endregion

			break;

		case PANTALLA::MENU_CIENTIFICA:

			#pragma region OPERACIONES CON CALCULADORA CIENTIFICA

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 13, altoConsola / 2 - 12);
			cout << "--- REALIZAR OPERACION ---";

			// 1. SE PIDE EL NÚMERO.
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 9);
			cout << "Ingrese un numero: ";
			cin >> primerNumero;

			// 2. SE PIDE EL TIPO DE OPERACIÓN.
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 7);
			cout << "Elija una operacion:";

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 5);
			cout << "1. POTENCIA";
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 4);
			cout << "2. RAIZ";

			do
			{
				borrarPantalla(altoConsola / 2 - 2);

				ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2 - 2);
				cout << "Opcion elegida: ";
				cin >> opcionIngresada;

			} while (opcionIngresada < 1 || opcionIngresada > 2);

			operacionElegida = (OPERACION)(opcionIngresada + 4);

			// Se pide el numero y se realiza la operacion correspondiente.
			switch (operacionElegida)
			{
			case OPERACION::POTENCIA:

				ConsoleExt::goToCoordinates(anchoConsola / 2 - 20, altoConsola / 2);
				cout << "Ingrese a cuanto lo quiere elevar: ";
				cin >> segundoNumero;
				
				resultado = Calculadora::obtenerPotencia(primerNumero, segundoNumero);

				break;

			case OPERACION::RAIZ:

				ConsoleExt::goToCoordinates(anchoConsola / 2 - 37, altoConsola / 2);
				cout << "Ingrese el tipo de raiz (2 = Cuadrada; 3 = Cubica. 4 = Cuarta; etcetera): ";
				cin >> segundoNumero;

				resultado = Calculadora::obtenerRaiz(primerNumero, segundoNumero);

				break;
			}

			borrarPantalla(altoConsola / 2 - 12);

			// Se muestra el resultado.
			mostrarMenuDeResultado(primerNumero, segundoNumero, resultado, operacionElegida);

			do
			{
				borrarPantalla(altoConsola / 2 + 3);

				ConsoleExt::goToCoordinates(anchoConsola / 2 - 25, altoConsola / 2 + 3);
				cout << "Opcion elegida: ";
				cin >> opcionIngresada;

			} while (opcionIngresada < 1 || opcionIngresada > 2);

			if (opcionIngresada == 2)
			{
				pantallaActual = PANTALLA::MENU_PRINCIPAL;
			}

			#pragma endregion

			break;

		case PANTALLA::ESTADISTICAS:

			#pragma region MUESTRA DE ESTADISTICAS

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 10, altoConsola / 2 - 10);
			cout << "--- ESTADISTICAS ---";

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 14, altoConsola / 2 - 8);
			cout << "Cantidad de cuentas hechas: ";

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 11, altoConsola / 2 - 5);
			cout << "Calculadora comun: " << Calculadora::getCuentasHechasComun() << ".";

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 13, altoConsola / 2 - 3);
			cout << "Calculadora cientifica: " << Calculadora::getCuentasHechasCientifica() << ".";

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 14, altoConsola / 2);
			cout << "1. RESTABLECER ESTADISTICAS";
			ConsoleExt::goToCoordinates(anchoConsola / 2 - 14, altoConsola / 2 + 1);
			cout << "2. VOLVER AL MENU PRINCIPAL";

			ConsoleExt::goToCoordinates(anchoConsola / 2 - 14, altoConsola / 2 + 3);
			cout << "Opcion elegida: ";
			cin >> opcionIngresada;

			switch (opcionIngresada)
			{
			case 1:

				Calculadora::restablecerEstadisticas();
				ConsoleExt::goToCoordinates(anchoConsola / 2 - 34, altoConsola / 2 + 5);
				cout << "Estadisticas restablecidas! Presione cualquier tecla para continuar... ";
				ConsoleExt::getKey(true);

				break;

			case 2:
				pantallaActual = PANTALLA::MENU_PRINCIPAL;
				break;
			}

			#pragma endregion

			break;
		}
	}


	ConsoleExt::getKey(true);

	return 0;
}

void borrarLinea(int linea)
{
	for (int i = 0; i < ConsoleExt::getScreenWidth(); i++)
	{
		ConsoleExt::goToCoordinates(i + 1, linea);
		cout << " ";
	}
}
void borrarPantalla(int lineaDesdeDondeBorrar)
{
	for (int i = lineaDesdeDondeBorrar; i <= ConsoleExt::getScreenHeight(); i++)
	{
		borrarLinea(i);
	}
}

string obtenerOperacionEnString(OPERACION operacion, bool enMayuscula)
{
	string nombreOperacion = "";


	switch (operacion)
	{
	case OPERACION::SUMA:
		nombreOperacion = enMayuscula == true ? "SUMA" : "Suma";
		break;

	case OPERACION::RESTA:
		nombreOperacion = enMayuscula == true ? "RESTA" : "Resta";
		break;

	case OPERACION::MULTIPLICACION:
		nombreOperacion = enMayuscula == true ? "MULTIPLICACION" : "Multiplicacion";
		break;

	case OPERACION::DIVISION:
		nombreOperacion = enMayuscula == true ? "DIVISION" : "Division";
		break;

	case OPERACION::POTENCIA:
		nombreOperacion = enMayuscula == true ? "POTENCIA" : "Potencia";
		break;

	case OPERACION::RAIZ:
		nombreOperacion = enMayuscula == true ? "RAIZ" : "Raiz";
		break;
	}

	return nombreOperacion;
}
void mostrarMenuDeResultado(float primerNumero, float segundoNumero, float resultado, OPERACION operacion)
{
	// Se muestra el resultado.
	ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - 19, ConsoleExt::getScreenHeight() / 2 - 12);
	cout << "--- RESULTADO DE LA OPERACION ---";

	ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - 25, ConsoleExt::getScreenHeight() / 2 - 10);
	cout << "Primer numero: " << primerNumero;

	ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - 25, ConsoleExt::getScreenHeight() / 2 - 8);
	cout << "Operacion realizada: " << obtenerOperacionEnString(operacion);

	ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - 25, ConsoleExt::getScreenHeight() / 2 - 6);
	cout << "Segundo numero: " << segundoNumero;

	ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - 25, ConsoleExt::getScreenHeight() / 2 - 3);
	cout << "Resultado: " << resultado;

	ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - 24, ConsoleExt::getScreenHeight() / 2);
	cout << "1. REALIZAR OTRA OPERACION";
	ConsoleExt::goToCoordinates(ConsoleExt::getScreenWidth() / 2 - 24, ConsoleExt::getScreenHeight() / 2 + 1);
	cout << "2. VOLVER AL MENU PRINCIPAL";
}

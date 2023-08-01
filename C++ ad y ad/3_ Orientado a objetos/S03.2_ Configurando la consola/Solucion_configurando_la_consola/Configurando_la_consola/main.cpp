#include <iostream>
#include <string>

#include "mgtv_library.h"

#include "pantalla.h"

using namespace std;
using namespace mgtv_library::console;


void escribirColor(COLOR color);
void mostrarListaDeColores(int x, int y);

int main()
{
	PANTALLA pantallaActual = PANTALLA::MENU_PRINCIPAL;

	int anchoConsola = ConsoleExt::getScreenWidth() - 1;
	int altoConsola = ConsoleExt::getScreenHeight() - 1;

	string tituloVentana = "CONFIGURACION DE LA CONSOLA";

	bool seDibujaElMarco = true;

	// mp: Menú principal.
	string mpTitulo = "----- CONFIGURACION DE LA CONSOLA -----";
	string mpOpcion1 = "1. Cambiar visibilidad del marco: ";
	string mpOpcion2 = "2. Seleccionar color del texto";
	string mpOpcion3 = "3. Seleccionar color del fondo";
	string mpOpcion4 = "4. Cambiar el titulo de la ventana";
	string mpOpcion5 = "5. Probar reaccion de teclas";
	string mpOpcion6 = "6. Cerrar";
	int mpPosicionTituloX = anchoConsola / 2 - mpTitulo.size() / 2;
	int mpPosicionTituloY = altoConsola / 2 - 5;

	// ct: Color del texto.
	string ctTitulo = "--- COLOR DEL TEXTO ---";
	string ctOracion = "Elija un nuevo color de texto:";
	int ctPosicionTituloX = anchoConsola / 2 - ctTitulo.size() / 2;
	int ctPosicionTituloY = 3;

	// cf: Color del fondo.
	string cfTitulo = "--- COLOR DEL FONDO ---";
	string cfOracion = "Elija un nuevo color de fondo:";
	int cfPosicionTituloX = anchoConsola / 2 - cfTitulo.size() / 2;
	int cfPosicionTituloY = 3;

	// tv: Título de la ventana.
	string tvTitulo = "--- CAMBIO DE TITULO DE LA VENTANA ---";
	string tvOracion = "Ingrese el nuevo titulo para la ventana: ";
	int tvPosicionTituloX = anchoConsola / 2 - tvTitulo.size() / 2;
	int tvPosicionTituloY = 3;
	string nuevaOracion = "";

	// rt: Reacción de teclas.
	string rtTitulo = "--- REACCION DE TECLAS PRESIONADAS ---";
	string rtOracion1 = "En esta seccion, se escribiran las teclas que ha presionado.";
	string rtOracion2 = "Para finalizar, presione la tecla ESC.";
	int rtPosicionTituloX = anchoConsola / 2 - rtTitulo.size() / 2;
	int rtPosicionTituloY = 3;

	int rtPosicionInicialX = 3;
	int rtPosicionInicialY = rtPosicionTituloY + 7;
	int rtPosicionActualCursorY = rtPosicionInicialY;

	// cs: Confirmación de salida
	string csTitulo = "--- CONFIRMACION DE SALIDA ---";
	string csPregunta = "Desea cerrar el programa?";
	int csPosicionTituloX = anchoConsola / 2 - csTitulo.size() / 2;
	int csPosicionTituloY = 3;


	int teclaPresionada = 0;

	bool enPrograma = true;
	int opcion = 0;



	ConsoleExt::setConsoleTitle(tituloVentana.c_str());

	while (enPrograma)
	{
		system("cls");

		if (seDibujaElMarco)
		{
			ConsoleExt::drawFrame(0, 0, anchoConsola, altoConsola);
		}

		switch (pantallaActual)
		{
		case PANTALLA::MENU_PRINCIPAL:

			#pragma region MENU PRINCIPAL

			ConsoleExt::goToCoordinates(mpPosicionTituloX, mpPosicionTituloY);
			cout << mpTitulo;

			ConsoleExt::goToCoordinates(anchoConsola / 2 - mpOpcion1.size() / 2, mpPosicionTituloY + 2);
			cout << mpOpcion1;

			if (seDibujaElMarco)
			{
				cout << "Si.";
			}
			else
			{
				cout << "No.";
			}

			ConsoleExt::goToCoordinates(anchoConsola / 2 - mpOpcion2.size() / 2, mpPosicionTituloY + 3);
			cout << mpOpcion2;
			ConsoleExt::goToCoordinates(anchoConsola / 2 - mpOpcion3.size() / 2, mpPosicionTituloY + 4);
			cout << mpOpcion3;
			ConsoleExt::goToCoordinates(anchoConsola / 2 - mpOpcion4.size() / 2, mpPosicionTituloY + 5);
			cout << mpOpcion4;
			ConsoleExt::goToCoordinates(anchoConsola / 2 - mpOpcion5.size() / 2, mpPosicionTituloY + 6);
			cout << mpOpcion5;
			ConsoleExt::goToCoordinates(anchoConsola / 2 - mpOpcion6.size() / 2, mpPosicionTituloY + 7);
			cout << mpOpcion6;

			ConsoleExt::goToCoordinates(mpPosicionTituloX - mpTitulo.size() / 4, mpPosicionTituloY + 9);
			cout << "Opcion ingresada: ";
			cin >> opcion;

			if (opcion >= 2 && opcion <= 6)
			{
				pantallaActual = (PANTALLA)opcion;
			}
			else if (opcion == 1)
			{
				seDibujaElMarco = !seDibujaElMarco;
			}

			#pragma endregion

			break;

		case PANTALLA::COLOR_DEL_TEXTO:

			#pragma region COLOR DEL TEXTO

			ConsoleExt::goToCoordinates(ctPosicionTituloX, ctPosicionTituloY);
			cout << ctTitulo;

			ConsoleExt::goToCoordinates(3, ctPosicionTituloY + 2);
			cout << "Color actual: ";
			escribirColor(ConsoleExt::getForegroundColor());

			ConsoleExt::goToCoordinates(3, ctPosicionTituloY + 4);
			cout << ctOracion;

			mostrarListaDeColores(3, ctPosicionTituloY + 6);

			ConsoleExt::goToCoordinates(3, ctPosicionTituloY + 23);
			cout << "Opcion elegida: ";
			cin >> opcion;

			if (opcion >= 1 && opcion <= 16)
			{
				ConsoleExt::goToCoordinates(3, ctPosicionTituloY + 25);
				cout << "El color del texto fue cambiado correctamente! Presione cualquier tecla para volver al menu principal... ";
				ConsoleExt::getKey(true);

				ConsoleExt::setForegroundColor((COLOR)(opcion - 1));
				pantallaActual = PANTALLA::MENU_PRINCIPAL;
			}

			#pragma endregion

			break;

		case PANTALLA::COLOR_DEL_FONDO:

			#pragma region COLOR DEL FONDO

			ConsoleExt::goToCoordinates(cfPosicionTituloX, cfPosicionTituloY);
			cout << cfTitulo;

			ConsoleExt::goToCoordinates(3, cfPosicionTituloY + 2);
			cout << "Color actual : ";
			escribirColor(ConsoleExt::getForegroundColor());

			ConsoleExt::goToCoordinates(3, cfPosicionTituloY + 4);
			cout << cfOracion;

			mostrarListaDeColores(3, cfPosicionTituloY + 6);

			ConsoleExt::goToCoordinates(3, cfPosicionTituloY + 23);
			cout << "Opcion elegida: ";
			cin >> opcion;

			if (opcion >= 1 && opcion <= 16)
			{
				ConsoleExt::goToCoordinates(3, cfPosicionTituloY + 25);
				cout << "El color del fondo fue cambiado correctamente! Presione cualquier tecla para volver al menu principal... ";
				ConsoleExt::getKey(true);

				ConsoleExt::setBackgroundColor((COLOR)(opcion - 1));
				pantallaActual = PANTALLA::MENU_PRINCIPAL;
			}

			#pragma endregion

			break;

		case PANTALLA::CAMBIAR_TITULO:

			#pragma region CAMBIAR TITULO

			ConsoleExt::goToCoordinates(tvPosicionTituloX, tvPosicionTituloY);
			cout << tvTitulo;

			ConsoleExt::goToCoordinates(3, altoConsola / 2 - 1);
			cout << tvOracion;

			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer para poder ingresar el string.
			getline(cin, nuevaOracion);

			ConsoleExt::setConsoleTitle(nuevaOracion);

			ConsoleExt::goToCoordinates(3, altoConsola / 2 + 1);
			cout << "El titulo fue aplicado correctamente! Presione cualquier tecla para volver al menu principal... ";
			ConsoleExt::getKey(true);

			pantallaActual = PANTALLA::MENU_PRINCIPAL;

			#pragma endregion

			break;

		case PANTALLA::REACCION_DE_TECLAS:

			#pragma region REACCION DE TECLAS

			ConsoleExt::goToCoordinates(rtPosicionTituloX, rtPosicionTituloY);
			cout << rtTitulo;

			ConsoleExt::goToCoordinates(rtPosicionInicialX, rtPosicionTituloY + 3);
			cout << rtOracion1;
			ConsoleExt::goToCoordinates(rtPosicionInicialX, rtPosicionTituloY + 4);
			cout << rtOracion2;

			while (rtPosicionActualCursorY < altoConsola - 4 && teclaPresionada != KEY_ESC)
			{
				ConsoleExt::goToCoordinates(rtPosicionInicialX, rtPosicionActualCursorY);
				cout << "Tecla presionada: ";

				teclaPresionada = ConsoleExt::getKey(true);

				cout << (char)teclaPresionada;

				rtPosicionActualCursorY++;
			}

			ConsoleExt::goToCoordinates(rtPosicionInicialX, rtPosicionActualCursorY + 1);
			cout << "Prueba finalizada. Presione cualquier tecla para volver al menu principal... ";
			ConsoleExt::getKey(true);

			teclaPresionada = 0;
			rtPosicionActualCursorY = rtPosicionInicialY;
			pantallaActual = PANTALLA::MENU_PRINCIPAL;

			#pragma endregion

			break;

		case PANTALLA::CONFIRMACION_DE_SALIDA:

			#pragma region CONFIRMACION DE SALIDA

			ConsoleExt::goToCoordinates(csPosicionTituloX, csPosicionTituloY);
			cout << csTitulo;

			ConsoleExt::goToCoordinates(anchoConsola / 2 - csPregunta.size() / 2, altoConsola / 2 - 3);
			cout << csPregunta;

			ConsoleExt::goToCoordinates(anchoConsola / 2 - csPregunta.size() / 2, altoConsola / 2 - 1);
			cout << "1. SI";
			ConsoleExt::goToCoordinates(anchoConsola / 2 - csPregunta.size() / 2, altoConsola / 2);
			cout << "2. NO";

			ConsoleExt::goToCoordinates(anchoConsola / 2 - csPregunta.size() / 2, altoConsola / 2 + 2);
			cout << "Opcion elegida: ";
			cin >> opcion;

			switch (opcion)
			{
			case 1:
				enPrograma = false;
				break;

			case 2:
				pantallaActual = PANTALLA::MENU_PRINCIPAL;
				break;
			}

			#pragma endregion

			break;
		}
	}

	ConsoleExt::goToCoordinates(anchoConsola / 2 - csPregunta.size() / 2, altoConsola / 2 + 4);
	cout << "Presione cualquier tecla para cerrar la ventana... ";

	ConsoleExt::getKey(true);


	return 0;
}

void escribirColor(COLOR color)
{
	switch (color)
	{
	case COLOR::C_BLACK:
		cout << "Negro";
		break;

	case COLOR::C_BLUE:
		cout << "Azul";
		break;

	case COLOR::C_GREEN:
		cout << "Verde";
		break;

	case COLOR::C_CYAN:
		cout << "Cian";
		break;

	case COLOR::C_RED:
		cout << "Rojo";
		break;

	case COLOR::C_MAGENTA:
		cout << "Magenta";
		break;

	case COLOR::C_BROWN:
		cout << "Marron";
		break;

	case COLOR::C_WHITE:
		cout << "Blanco";
		break;

	case COLOR::C_GRAY:
		cout << "Gris";
		break;

	case COLOR::C_LBLUE:
		cout << "Azul claro";
		break;

	case COLOR::C_LGREEN:
		cout << "Verde claro";
		break;

	case COLOR::C_LCYAN:
		cout << "Cian claro";
		break;

	case COLOR::C_LRED:
		cout << "Rojo claro";
		break;

	case COLOR::C_LMAGENTA:
		cout << "Magenta claro";
		break;

	case COLOR::C_YELLOW:
		cout << "Amarillo";
		break;

	case COLOR::C_BWHITE:
		cout << "Blanco intenso";
		break;
	}
}
void mostrarListaDeColores(int x, int y)
{
	for (int i = 0; i < 16; i++)
	{
		ConsoleExt::goToCoordinates(x, y + i);

		cout << i + 1 << ". ";
		escribirColor((COLOR)i);
	}
}

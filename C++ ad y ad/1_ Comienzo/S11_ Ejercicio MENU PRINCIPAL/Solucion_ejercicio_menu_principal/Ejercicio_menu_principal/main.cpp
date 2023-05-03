#include <iostream>

using namespace std;


enum class PANTALLA { MENU_PRINCIPAL, OPCIONES, AYUDA, DIFICULTAD, CALIDAD, BRILLO, VOLUMEN_MUSICA, VOLUMEN_SFX };
enum class DIFICULTAD { FACIL = 1, MEDIO, DIFICIL, EXPERTO };
enum class CALIDAD_GRAFICOS { BAJA = 1, MEDIA, ALTA };

int main()
{
	bool enElJuego = true;

	PANTALLA pantallaActual = PANTALLA::MENU_PRINCIPAL;
	DIFICULTAD dificultad = DIFICULTAD::MEDIO;
	CALIDAD_GRAFICOS calidadGraficos = CALIDAD_GRAFICOS::MEDIA;

	int brillo = 100;
	int volumenMusica = 100;
	int volumenSfx = 100;

	int opcion = 0;



	while (enElJuego)
	{
		system("cls");

		switch (pantallaActual)
		{
		case PANTALLA::MENU_PRINCIPAL:
			cout << "  --- MENU PRINCIPAL ---" << endl << endl;
			cout << "         1. JUGAR" << endl;
			cout << "        2. OPCIONES" << endl;
			cout << "         3. AYUDA" << endl;
			cout << "         4. SALIR" << endl << endl;

			cout << "Opcion elegida: ";
			cin >> opcion;
			cout << endl;

			switch (opcion)
			{
			case 1:
				cout << "Cargando el juego...";
				enElJuego = false;
				break;

			case 2:
				pantallaActual = PANTALLA::OPCIONES;
				break;

			case 3:
				pantallaActual = PANTALLA::AYUDA;
				break;

			case 4:
				cout << "Saliendo del juego. Gracias Por jugar!";
				enElJuego = false;
				break;
			}

			break;



		case PANTALLA::OPCIONES:
			cout << "           --- OPCIONES ---" << endl << endl;
			cout << "1. Elegir dificultad (";

			switch (dificultad)
			{
			case DIFICULTAD::FACIL:
				cout << "Facil";
				break;

			case DIFICULTAD::MEDIO:
				cout << "Medio";
				break;

			case DIFICULTAD::DIFICIL:
				cout << "Dificil";
				break;

			case DIFICULTAD::EXPERTO:
				cout << "Experto";
				break;
			}

			cout << ")" << endl;
			cout << "2. Ver calidad de los graficos (";

			switch (calidadGraficos)
			{
			case CALIDAD_GRAFICOS::BAJA:
				cout << "Baja";
				break;

			case CALIDAD_GRAFICOS::MEDIA:
				cout << "Media";
				break;

			case CALIDAD_GRAFICOS::ALTA:
				cout << "Alta";
				break;
			}

			cout << ")" << endl;
			cout << "3. Brillo (" << brillo << "%)" << endl;
			cout << "4. Volumen de la musica (" << volumenMusica << "%)" << endl;
			cout << "5. Volumen de SFX (" << volumenSfx << "%)" << endl;
			cout << "6. Volver al menu principal" << endl << endl;

			cout << "Opcion ingresada: ";
			cin >> opcion;
			cout << endl;

			switch (opcion)
			{
			case 1:
				pantallaActual = PANTALLA::DIFICULTAD;
				break;

			case 2:
				pantallaActual = PANTALLA::CALIDAD;
				break;

			case 3:
				pantallaActual = PANTALLA::BRILLO;
				break;

			case 4:
				pantallaActual = PANTALLA::VOLUMEN_MUSICA;
				break;

			case 5:
				pantallaActual = PANTALLA::VOLUMEN_SFX;
				break;

			case 6:
				pantallaActual = PANTALLA::MENU_PRINCIPAL;
				break;
			}

			break;



		case PANTALLA::DIFICULTAD:
			cout << "  --- DIFICULTAD ---" << endl << endl;
			cout << "Elija la nueva dificultad: " << endl << endl;
			cout << "1. Facil" << endl;
			cout << "2. Medio" << endl;
			cout << "3. Dificil" << endl;
			cout << "4. Experto" << endl << endl;

			cout << "Opcion elegida: ";
			cin >> opcion;
			cout << endl;

			if (opcion >= 1 && opcion <= 4)
			{
				dificultad = (DIFICULTAD)opcion;

				pantallaActual = PANTALLA::OPCIONES;
			}

			break;



		case PANTALLA::CALIDAD:
			cout << "  --- CALIDAD DE GRAFICOS ---" << endl << endl;
			cout << "Elija la nueva calidad: " << endl << endl;
			cout << "1. Baja" << endl;
			cout << "2. Media" << endl;
			cout << "3. Alta" << endl << endl;

			cout << "Opcion elegida: ";
			cin >> opcion;
			cout << endl;

			if (opcion >= 1 && opcion <= 3)
			{
				calidadGraficos = (CALIDAD_GRAFICOS)opcion;

				pantallaActual = PANTALLA::OPCIONES;
			}

			break;



		case PANTALLA::BRILLO:
			cout << "  --- BRILLO ---" << endl << endl;

			do
			{
				cout << "Ingrese el nuevo brillo: ";
				cin >> brillo;

			} while (brillo < 0 || brillo > 100);

			pantallaActual = PANTALLA::OPCIONES;

			break;



		case PANTALLA::VOLUMEN_MUSICA:
			cout << "  --- VOLUMEN DE LA MUSICA ---" << endl << endl;

			do
			{
				cout << "Ingrese el nuevo volumen de la musica: ";
				cin >> volumenMusica;

			} while (volumenMusica < 0 || volumenMusica > 100);

			pantallaActual = PANTALLA::OPCIONES;

			break;



		case PANTALLA::VOLUMEN_SFX:
			cout << "  --- VOLUMEN DE SFX ---" << endl << endl;

			do
			{
				cout << "Ingrese el nuevo volumen de SFX: ";
				cin >> volumenSfx;

			} while (volumenSfx < 0 || volumenSfx > 100);

			pantallaActual = PANTALLA::OPCIONES;

			break;



		case PANTALLA::AYUDA:
			cout << "         --- AYUDA ---" << endl << endl;

			cout << "Aca se leeria la ayuda del juego." << endl;
			system("pause");

			pantallaActual = PANTALLA::MENU_PRINCIPAL;

			break;
		}
	}

	cout << endl;
	system("pause");



	return 0;
}

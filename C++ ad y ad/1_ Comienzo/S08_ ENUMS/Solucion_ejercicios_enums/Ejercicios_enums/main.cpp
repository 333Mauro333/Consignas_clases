#include <iostream>

using namespace std;


enum class VELOCIDAD { LENTA, MEDIA, RAPIDA };
enum class CALIDAD_GRAFICOS { BAJA, MEDIA, ALTA };
enum class DIFICULTAD { NOVATO, FACIL, MEDIO, DIFICIL, EXPERTO };
enum class CLASE_PERSONAJE { GUERRERO, ARQUERO, MAGO };

int main()
{
	VELOCIDAD miVelocidad = VELOCIDAD::MEDIA;
	CALIDAD_GRAFICOS calidadActual = CALIDAD_GRAFICOS::MEDIA;
	DIFICULTAD dificultad = DIFICULTAD::MEDIO;
	CLASE_PERSONAJE clasePersonaje = CLASE_PERSONAJE::GUERRERO;

	int vida = 0;
	int velocidad = 0;
	int fuerza = 0;

	int opcion = 0;



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Velocidad actual: ";

	switch (miVelocidad)
	{
	case VELOCIDAD::LENTA:
		cout << "Lenta";
		break;

	case VELOCIDAD::MEDIA:
		cout << "Media";
		break;

	case VELOCIDAD::RAPIDA:
		cout << "Rapida";
		break;
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Calidad actual: ";

	switch (calidadActual)
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

	cout << "." << endl << endl << endl;
	cout << "Elija la calidad de los graficos: " << endl << endl;

	cout << "1. Baja." << endl;
	cout << "2. Media." << endl;
	cout << "3. Alta." << endl << endl;

	cout << "Opcion ingresada: ";
	cin >> opcion;
	cout << endl;

	switch (opcion)
	{
	case 1:
		calidadActual = CALIDAD_GRAFICOS::BAJA;
		break;

	case 2:
		calidadActual = CALIDAD_GRAFICOS::MEDIA;
		break;

	case 3:
		calidadActual = CALIDAD_GRAFICOS::ALTA;
		break;
	}

	cout << "Calidad actual: ";

	switch (calidadActual)
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

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Elija la dificultad del juego: " << endl << endl;

	cout << "1. Novato" << endl;
	cout << "2. Facil" << endl;
	cout << "3. Medio" << endl;
	cout << "4. Dificil" << endl;
	cout << "5. Experto" << endl << endl;

	cout << "Opcion elegida: ";
	cin >> opcion;
	cout << endl;

	switch (opcion)
	{
	case 1:
		dificultad = DIFICULTAD::NOVATO;
		break;

	case 2:
		dificultad = DIFICULTAD::FACIL;
		break;

	case 3:
		dificultad = DIFICULTAD::MEDIO;
		break;

	case 4:
		dificultad = DIFICULTAD::DIFICIL;
		break;

	case 5:
		dificultad = DIFICULTAD::EXPERTO;
		break;
	}

	cout << "Dificultad elegida: ";

	switch (dificultad)
	{
	case DIFICULTAD::NOVATO:
		cout << "Novato";
		break;

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

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Elija la clase de su personaje: " << endl << endl;

	cout << "1. Guerrero" << endl;
	cout << "2. Arquero" << endl;
	cout << "3. Mago" << endl << endl;

	cout << "Opcion elegida: ";
	cin >> opcion;
	cout << endl;

	switch (opcion)
	{
	case 1:
		clasePersonaje = CLASE_PERSONAJE::GUERRERO;
		break;

	case 2:
		clasePersonaje = CLASE_PERSONAJE::ARQUERO;
		break;

	case 3:
		clasePersonaje = CLASE_PERSONAJE::MAGO;
		break;
	}

	switch (clasePersonaje)
	{
	case CLASE_PERSONAJE::GUERRERO:
		vida = 100;
		velocidad = 25;
		fuerza = 75;
		break;

	case CLASE_PERSONAJE::ARQUERO:
		vida = 50;
		velocidad = 50;
		fuerza = 40;
		break;

	case CLASE_PERSONAJE::MAGO:
		vida = 30;
		velocidad = 40;
		fuerza = 100;
		break;
	}

	cout << "Clase elegida: ";

	switch (clasePersonaje)
	{
	case CLASE_PERSONAJE::GUERRERO:
		cout << "Guerrero";
		break;

	case CLASE_PERSONAJE::ARQUERO:
		cout << "Arquero";
		break;

	case CLASE_PERSONAJE::MAGO:
		cout << "Mago";
		break;
	}

	cout << "." << endl << endl;
	cout << "Vida: " << vida << "." << endl;
	cout << "Velocidad: " << velocidad << "." << endl;
	cout << "Fuerza: " << fuerza << "." << endl << endl << endl;



	return 0;
}

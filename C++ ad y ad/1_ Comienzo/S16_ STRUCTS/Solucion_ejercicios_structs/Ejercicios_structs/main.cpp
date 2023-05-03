#include <iostream>
#include <string>

using namespace std;


struct FECHA
{
	int dia;
	int mes;
	int anio;
};

struct USUARIO
{
	string nombre;
	string apellido;
	int edad;
	FECHA fechaNac;
};

struct POSICION
{
	int x;
	int y;
};

struct PERSONAJE
{
	string nombre;
	int energia;
	POSICION posicion;
};

int main()
{
	USUARIO usuario1 = {};

	FECHA fecha = {};
	bool fechaValida = false;

	POSICION posicion = {};

	USUARIO usuario4 = {};

	const int tamanio5 = 3;
	PERSONAJE personajes[tamanio5] = {};



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese su nombre: ";
	getline(cin, usuario1.nombre);

	cout << "Ingrese su edad: ";
	cin >> usuario1.edad;

	cout << "Su nombre es " << usuario1.nombre << ". Su edad es: " << usuario1.edad << " anios." << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	do
	{
		do
		{
			cout << "Ingrese el dia: ";
			cin >> fecha.dia;

		} while (fecha.dia < 1 || fecha.dia > 31);

		do
		{
			cout << "Ingrese el mes (numero entre 1 y 12): ";
			cin >> fecha.mes;

		} while (fecha.mes < 1 || fecha.mes > 12);

		do
		{
			cout << "Ingrese el anio: ";
			cin >> fecha.anio;

		} while (fecha.anio < 0);

		// Meses con 31 días.
		if (fecha.mes == 1 || fecha.mes == 3 || fecha.mes == 5 || fecha.mes == 7 || fecha.mes == 8 || fecha.mes == 10 || fecha.mes == 12)
		{
			fechaValida = true;
		}
		else if ((fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11) && fecha.dia <= 30)  // Meses con 30.
		{
			fechaValida = true;
		}
		else // Febrero.
		{
			if (fecha.anio % 4 == 0 && fecha.dia <= 29) // Si es bisiesto...
			{
				fechaValida = true;
			}
			else if (fecha.dia <= 28) // Si el día ingresado es 28 como máximo...
			{
				fechaValida = true;
			}
		}

		if (!fechaValida)
		{
			cout << "Fecha no valida. ";
			system("pause");
			system("cls");
			cout << "--- EJERCICIO 2 ---" << endl << endl;
		}

	} while (!fechaValida);

	cout << "\nFecha: " << fecha.dia << "/" << fecha.mes << "/" << fecha.anio << endl << endl;
	cout << "Fecha: " << fecha.dia << " de ";

	switch (fecha.mes)
	{
	case 1:
		cout << "enero";
		break;

	case 2:
		cout << "febrero";
		break;

	case 3:
		cout << "marzo";
		break;

	case 4:
		cout << "abril";
		break;

	case 5:
		cout << "mayo";
		break;

	case 6:
		cout << "junio";
		break;

	case 7:
		cout << "julio";
		break;

	case 8:
		cout << "agosto";
		break;

	case 9:
		cout << "septiembre";
		break;

	case 10:
		cout << "octubre";
		break;

	case 11:
		cout << "noviembre";
		break;

	case 12:
		cout << "diciembre";
		break;
	}

	cout << " de " << fecha.anio << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese la posicion X: ";
	cin >> posicion.x;

	cout << "Ingrese la posicion Y: ";
	cin >> posicion.y;
	cout << endl;

	cout << "Posicion ingresada: (" << posicion.x << "; " << posicion.y << ")." << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Ingrese su nombre: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, usuario4.nombre);

	cout << "Ingrese su apellido: ";
	getline(cin, usuario4.apellido);

	// Se podría verificar la validez de la fecha como en el ejercicio 2, pero en este caso
	// se va a omitir para no repetir lo mismo y hacerlo más extenso.
	cout << "Ingrese su fecha de nacimiento: " << endl << endl;
	
	cout << "Dia: ";
	cin >> usuario4.fechaNac.dia;

	cout << "Mes (en numero): ";
	cin >> usuario4.fechaNac.mes;

	cout << "Anio: ";
	cin >> usuario4.fechaNac.anio;
	cout << endl;

	cout << "Nombre: " << usuario4.nombre << ".\n";
	cout << "Apellido: " << usuario4.apellido << ".\n";
	cout << "Fecha de nacimiento: " << usuario4.fechaNac.dia << "/" << usuario4.fechaNac.mes << "/" << usuario4.fechaNac.anio << ".\n\n\n";



	cout << "--- EJERCICIO 5 ---" << endl << endl;

	for (int i = 0; i < tamanio5; i++)
	{
		cout << "Datos del personaje " << i + 1 << " de " << tamanio5 << ":\n\n";

		cout << "Ingrese el nombre: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, personajes[i].nombre);

		do
		{
			cout << "Ingrese la cantidad de energia del personaje: ";
			cin >> personajes[i].energia;

		} while (personajes[i].energia < 0 || personajes[i].energia > 100);

		cout << "Ingrese la posicion X del personaje: ";
		cin >> personajes[i].posicion.x;

		cout << "Ingrese la posicion Y del personaje: ";
		cin >> personajes[i].posicion.y;
		cout << endl << endl;
	}

	for (int i = 0; i < tamanio5; i++)
	{
		cout << "Datos del personaje " << i + 1 << ":\n\n";
		cout << "Nombre: " << personajes[i].nombre << endl;
		cout << "Energia: " << personajes[i].energia << endl;
		cout << "Posicion: (" << personajes[i].posicion.x << "; " << personajes[i].posicion.y << ").\n\n";
	}



	return 0;
}

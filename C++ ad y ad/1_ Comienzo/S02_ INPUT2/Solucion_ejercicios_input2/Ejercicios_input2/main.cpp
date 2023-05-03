#include <iostream>
#include <string>

using namespace std;


int main()
{
	int dia = 0;
	int mes = 0;
	int anio = 0;
	int hora = 0;
	int minutos = 0;

	string nombre = "";
	int velocidad = 0;
	int fuerza = 0;
	string poderEspecial = "";



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "--- INGRESO DE LA FECHA Y HORA --- " << endl << endl;
	cout << "Ingrese el dia actual: ";
	cin >> dia;
	cout << "Ingrese el mes actual: ";
	cin >> mes;
	cout << "Ingrese el anio actual: ";
	cin >> anio;

	cout << endl;
	cout << "Ingrese la hora actual: ";
	cin >> hora;
	cout << "Ingrese los minutos actuales: ";
	cin >> minutos;

	cout << "Datos guardados. Se procedera al menu de creacion de personaje. ";
	system("pause");
	system("cls");


	cout << "--- CREACION DE PERSONAJE ---" << endl << endl << endl;

	cout << "Ingrese el nombre de su personaje: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer para poder ingresar el string.
	getline(cin, nombre);

	cout << "Ingrese su velocidad: ";
	cin >> velocidad;

	cout << "Ingrese su fuerza: ";
	cin >> fuerza;

	cout << "Describa el poder especial de su personaje: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer para poder ingresar el string.
	getline(cin, poderEspecial);


	// Se muestran todos los datos.
	system("cls");

	cout << "--- CREACION DE PERSONAJE ---" << endl << endl << endl;
	cout << "Nombre: " << nombre << "." << endl;
	cout << "Velocidad: " << velocidad << "." << endl;
	cout << "Fuerza: " << fuerza << "." << endl;
	cout << "Poder especial: " << poderEspecial << endl << endl << endl;

	cout << "Personaje creado el " << dia << "/" << mes << "/" << anio << " a las " << hora << ":" << minutos << " hs." << endl << endl;



	return 0;
}

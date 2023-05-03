#include <iostream>
#include <string>

using namespace std;


struct FECHA
{
	int dia;
	int mes;
	int anio;
};

struct PERSONA
{
	string nombre;
	FECHA fechaNac;
};

int obtenerNumeroMasGrande(int num1, int num2);

string obtenerOracionEnMayuscula(string oracion);

PERSONA obtenerLaPersonaMasGrande(PERSONA persona1, PERSONA persona2);
void mostrarDatosDeLaPersona(PERSONA persona);

int main()
{
	int num = 0;
	int num2 = 0;
	int numMasGrande = 0;

	string oracion = "";
	string oracionEnMayuscula = "";

	const int tamanio = 2;
	PERSONA persona[tamanio] = {};
	PERSONA personaMasGrande = {};



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese un numero: ";
	cin >> num;

	cout << "Ingrese otro numero: ";
	cin >> num2;

	numMasGrande = obtenerNumeroMasGrande(num, num2);

	cout << "El numero mas grande es " << numMasGrande << ".\n\n\n";



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Ingrese una oracion: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, oracion);

	oracionEnMayuscula = obtenerOracionEnMayuscula(oracion);

	cout << "Oracion original: " << oracion << endl;
	cout << "Oracion en mayuscula: " << oracionEnMayuscula << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	for (int i = 0; i < tamanio; i++)
	{
		cout << "Ingrese el nombre de la persona " << i + 1 << ": ";
		getline(cin, persona[i].nombre);

		cout << "\nIngrese la fecha de nacimiento:\n";
		cout << "Dia: ";
		cin >> persona[i].fechaNac.dia;
		cout << "Mes: ";
		cin >> persona[i].fechaNac.mes;
		cout << "Anio: ";
		cin >> persona[i].fechaNac.anio;
		cout << endl;

		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Se limpia el buffer antes de hacer el getline.
	}

	personaMasGrande = obtenerLaPersonaMasGrande(persona[0], persona[1]);

	mostrarDatosDeLaPersona(personaMasGrande);

	cout << endl;



	return 0;
}

int obtenerNumeroMasGrande(int num1, int num2)
{
	if (num1 >= num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}

string obtenerOracionEnMayuscula(string oracion)
{
	string enMayuscula = oracion;
	
	for (int i = 0; i < oracion.size(); i++)
	{
		if (enMayuscula[i] >= 97 && enMayuscula[i] <= 122)
		{
			enMayuscula[i] -= 32;
		}
	}

	return enMayuscula;
}

PERSONA obtenerLaPersonaMasGrande(PERSONA persona1, PERSONA persona2)
{
	if (persona1.fechaNac.anio < persona2.fechaNac.anio) // Año más chico (nació antes)...
	{
		return persona1;
	}
	else if (persona1.fechaNac.anio > persona2.fechaNac.anio) // Año más grande (nació después)...
	{
		return persona2;
	}
	else
	{
		if (persona1.fechaNac.mes < persona2.fechaNac.mes) // Nació meses antes...
		{
			return persona1;
		}
		else if (persona1.fechaNac.mes > persona2.fechaNac.mes) // Nació meses después...
		{
			return persona2;
		}
		else
		{
			if (persona1.fechaNac.dia <= persona2.fechaNac.dia) // Nació días antes o el mismo día...
			{
				return persona1;
			}
			else
			{
				return persona2;
			}
		}
	}
}
void mostrarDatosDeLaPersona(PERSONA persona)
{
	cout << "Nombre: " << persona.nombre << endl;
	cout << "Fecha de nacimiento: ";

	if (persona.fechaNac.dia < 10)
	{
		cout << "0";
	}

	cout << persona.fechaNac.dia << "/";

	if (persona.fechaNac.mes < 10)
	{
		cout << "0";
	}

	cout << persona.fechaNac.mes << "/" << persona.fechaNac.anio << ".\n\n";
}

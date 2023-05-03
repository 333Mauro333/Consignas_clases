#include <iostream>
#include <string>

using namespace std;


int main()
{
	char letra = '\0';
	int vecesEncontrada = 0;

	int cantidadVocales = 0;
	int cantidadConsonantes = 0;

	int vocalesA = 0;
	int vocalesE = 0;
	int vocalesI = 0;
	int vocalesO = 0;
	int vocalesU = 0;

	string oracion = "";



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese una oracion: ";
	getline(cin, oracion);

	cout << "La oracion tiene " << oracion.size() << " caracter";

	if (oracion.size() != 1)
	{
		cout << "es";
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	cout << "Ingrese una oracion: ";
	getline(cin, oracion);

	cout << "Ingrese una letra: ";
	cin >> letra;
	cout << endl;

	for (int i = 0; i < oracion.size(); i++)
	{
		if (oracion[i] == letra)
		{
			vecesEncontrada++;
		}
	}

	cout << "La letra se encuentra " << vecesEncontrada << " ve";

	if (vecesEncontrada != 1)
	{
		cout << "ces";
	}
	else
	{
		cout << "z";
	}

	cout << " en la oracion." << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	cout << "Ingrese una oracion: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, oracion);

	for (int i = 0; i < oracion.size(); i++)
	{
		if ((oracion[i] >= 65 && oracion[i] <= 90) || (oracion[i] >= 97 && oracion[i] <= 122))
		{
			if (oracion[i] == 'a' || oracion[i] == 'e' || oracion[i] == 'i' || oracion[i] == 'o' || oracion[i] == 'u' || oracion[i] == 'A' || oracion[i] == 'E' || oracion[i] == 'I' || oracion[i] == 'O' || oracion[i] == 'U')
			{
				cantidadVocales++;
			}
			else
			{
				cantidadConsonantes++;
			}
		}
	}

	cout << "En la oracion hay " << cantidadVocales << " vocal";

	if (cantidadVocales != 1)
	{
		cout << "es";
	}

	cout << " y " << cantidadConsonantes << " consonante";

	if (cantidadConsonantes != 1)
	{
		cout << "s";
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 4 ---" << endl << endl;

	cout << "Ingrese una oracion: ";
	getline(cin, oracion);

	for (int i = 0; i < oracion.size(); i++)
	{
		if (oracion[i] == 'A' || oracion[i] == 'a')
		{
			vocalesA++;
		}
		else if (oracion[i] == 'E' || oracion[i] == 'e')
		{
			vocalesE++;
		}
		else if (oracion[i] == 'I' || oracion[i] == 'i')
		{
			vocalesI++;
		}
		else if (oracion[i] == 'O' || oracion[i] == 'o')
		{
			vocalesO++;
		}
		else if (oracion[i] == 'U' || oracion[i] == 'u')
		{
			vocalesU++;
		}
	}

	cout << "Cantidad de vocales:" << endl << endl;
	cout << "Vocales A: " << vocalesA << endl;
	cout << "Vocales E: " << vocalesE << endl;
	cout << "Vocales I: " << vocalesI << endl;
	cout << "Vocales O: " << vocalesO << endl;
	cout << "Vocales U: " << vocalesU << endl << endl << endl;



	cout << "--- EJERCICIO 5 ---" << endl << endl;

	cout << "Ingrese una oracion: ";
	getline(cin, oracion);

	cout << "\nOracion normal: " << oracion << endl;
	cout << "Oracion invertida: ";

	for (int i = oracion.size() - 1; i >= 0; i--)
	{
		cout << oracion[i];
	}

	cout << endl << endl << endl;



	cout << "--- EJERCICIO 6 ---" << endl << endl;

	cout << "Ingrese una oracion: ";
	getline(cin, oracion);
	
	cout << "\nOracion normal: " << oracion << endl;
	cout << "Oracion en mayusculas: ";

	for (int i = 0; i < oracion.size(); i++)
	{
		if (oracion[i] >= 97 && oracion[i] <= 122)
		{
			cout << (char)(oracion[i] - 32);
		}
		else
		{
			cout << oracion[i];
		}
	}

	cout << endl << endl << endl;



	return 0;
}

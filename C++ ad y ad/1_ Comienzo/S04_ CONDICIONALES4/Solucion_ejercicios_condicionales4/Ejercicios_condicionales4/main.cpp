#include <iostream>

using namespace std;


int main()
{
	char letra = '\0';



	cout << "--- EJERCICIO 1 ---" << endl << endl;

	cout << "Ingrese un caracter: ";
	cin >> letra;
	cout << endl;

	if ((letra >= 65 && letra <= 90) || (letra >= 97 && letra <= 122))
	{
		cout << "Se ha ingresado una letra";
	}
	else
	{
		cout << "El caracter ingresado no es una letra";
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 2 ---" << endl << endl;

	if (letra >= 65 && letra <= 90)
	{
		cout << "Se ha ingresado una letra mayuscula";
	}
	else if (letra >= 97 && letra <= 122)
	{
		cout << "Se ha ingresado una letra minuscula";
	}
	else
	{
		cout << "El caracter ingresado no es una letra";
	}

	cout << "." << endl << endl << endl;



	cout << "--- EJERCICIO 3 ---" << endl << endl;

	if (letra >= 65 && letra <= 90)
	{
		cout << "Se ha ingresado una letra mayuscula ";

		if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
		{
			cout << "vocal";
		}
		else
		{
			cout << "consonante";
		}
	}
	else if (letra >= 97 && letra <= 122)
	{
		cout << "Se ha ingresado una letra minuscula ";

		if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
		{
			cout << "vocal";
		}
		else
		{
			cout << "consonante";
		}
	}
	else
	{
		cout << "El caracter ingresado no es una letra";
	}

	cout << "." << endl << endl << endl;



	return 0;
}

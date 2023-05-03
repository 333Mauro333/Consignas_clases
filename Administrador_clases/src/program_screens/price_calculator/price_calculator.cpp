#include "price_calculator.h"

using std::cout;
using std::cin;
using std::endl;


namespace administrador_clases
{
	PriceCalculator::PriceCalculator()
	{
		priceForOneClass = 0.0f;
		priceForFiveClasses = 0.0f;
	}
	PriceCalculator::~PriceCalculator()
	{

	}


	void PriceCalculator::update()
	{
		system("cls");
		cout << "---------- CALCULADORA DE COSTOS ----------\n\n\n";

		priceForOneClass = askForNumber("Ingrese el costo anterior de las clases: ", 1);

		cout << "La promo de 5 clases vale " << priceForOneClass * 5.0f - priceForOneClass / 3.0f << ".\n";
		priceForFiveClasses = askForNumber("Ingrese el costo deseado en el caso de necesitar redondearse: ", 1);

		showCosts();

		system("pause"); // Ver mejor el tema de los valores tras hacer la cuenta.
	}


	int PriceCalculator::askForNumber(string message, int spacesAfterInput)
	{
		int number = 0;


		cout << message;
		cin >> number;

		for (int i = 0; i < spacesAfterInput; i++)
		{
			cout << "\n";
		}


		return number;
	}
	void PriceCalculator::showCosts()
	{
		cout << "Costo por 1 clase: $" << priceForOneClass << endl;
		cout << "Costo por 2 clases: $" << priceForOneClass * 2.0f << endl;
		cout << "Costo por 3 clases: $" << priceForOneClass * 3.0f << endl;
		cout << "Costo por 4 clases: $" << priceForOneClass * 4.0f << endl;
		cout << "Costo por 5 clases: $" << priceForFiveClasses << " ($" << priceForOneClass * 5.0f - priceForFiveClasses << " de promo)" << endl;
		cout << "Costo por 6 clases: $" << priceForFiveClasses + priceForOneClass << endl;
		cout << "Costo por 7 clases: $" << priceForFiveClasses + priceForOneClass * 2.0f << endl;
		cout << "Costo por 8 clases: $" << priceForFiveClasses + priceForOneClass * 3.0f << endl;
		cout << "Costo por 9 clases: $" << priceForFiveClasses + priceForOneClass * 4.0f << endl;
		cout << "Costo por 10 clases: $" << priceForOneClass * 10.0f - priceForOneClass << " (1 clase de regalo)" << endl << endl << endl;
	}
}

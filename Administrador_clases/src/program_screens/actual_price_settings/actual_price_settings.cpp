#include "actual_price_settings.h"

#include <iostream>

#include "program_screens/main_menu/main_menu.h"

using std::cout;
using std::cin;


namespace administrador_clases
{
	ActualPriceSettings::ActualPriceSettings()
	{
		price = 0.0f;
		priceForFiveClasses = 0.0f;

		date = {};
		time = {};
	}
	ActualPriceSettings::~ActualPriceSettings()
	{

	}


	void ActualPriceSettings::update()
	{
		cout << " ----- AJUSTE DE PRECIO -----\n\n";
		cout << "Ingrese el nuevo precio de las clases: ";
		cin >> price;
		cout << "\nEl precio por 5 clases es de " << price * 5.0f << ".\n";
		cout << "Ingrese el precio ajustado de 5 clases: ";
		cin >> priceForFiveClasses;

		enterDate();
		enterTime();

		MainMenu::setActualPrice(price, priceForFiveClasses);
		MainMenu::setLastDate(date);
		MainMenu::setLastTime(time);
		MainMenu::saveDataTimePrices()

		// Mensaje de que se hizo todo correctamente.
	}


	void ActualPriceSettings::enterDate()
	{
		bool isACorrectDate = true;

		do
		{
			if (!isACorrectDate)
			{
				cout << "La fecha ingresada no es valida.\n";
			}

			do
			{
				cout << "Ingrese el dia actual: ";
				cin >> date.day;

			} while (date.day < 1 || date.day > 31);

			do
			{
				cout << "Ingrese el mes actual: ";
				cin >> date.month;

			} while (date.month < 1 || date.month > 12);

			do
			{
				cout << "Ingrese el anio: ";
				cin >> date.year;

			} while (date.year < 2000 || date.year > 2100);

			isACorrectDate = isAValidDate();

		} while (isACorrectDate);
	}
	void ActualPriceSettings::enterTime()
	{
		do
		{
			cout << "Ingrese la hora actual: ";
			cin >> time.hour;

		} while (time.hour < 0 || time.hour > 23);

		do
		{
			cout << "Ingrese los minutos actuales: ";
			cin >> time.hour;

		} while (time.hour < 0 || time.hour > 59);
	}

	bool ActualPriceSettings::isAValidDate()
	{
		switch (date.month)
		{
		case 1: // Enero.
		case 3: // Marzo.
		case 5: // Mayo.
		case 7: // Julio.
		case 8: // Agosto.
		case 10: // Octubre.
		case 12: // Diciembre.
			return date.day <= 31;
			break;
			
		case 4:
		case 6:
		case 9:
		case 11:
			return date.day <= 30;
			break;

		case 2:
			if (date.year % 4 == 0)
			{
				return date.day <= 29;
			}
			else
			{
				return date.day <= 28;
			}
			break;

		default:
			return false;
			break;
		}
	}
}

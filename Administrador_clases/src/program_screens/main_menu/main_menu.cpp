#include "main_menu.h"

#include <iostream>
#include <ctime>
#include <fstream>

#include "managers/program_manager/program_manager.h"
#include "managers/screen_manager/screen_manager.h"

using std::cout;
using std::cin;


namespace administrador_clases
{
	DATE MainMenu::lastModificationDate = {};
	TIME MainMenu::lastModificationTime = {};

	float MainMenu::actualPrice = 0.0f;
	float MainMenu::actualFiveClassesPrice = 0.0f;


	MainMenu::MainMenu()
	{
		
	}
	MainMenu::~MainMenu()
	{

	}


	void MainMenu::setLastDate(DATE date)
	{
		lastModificationDate = date;
	}
	void MainMenu::setLastTime(TIME time)
	{
		lastModificationTime = time;
	}
	void MainMenu::setActualPrice(float price, float fiveClassesPrice)
	{
		actualPrice = price;
		actualFiveClassesPrice = fiveClassesPrice;
	}

	void MainMenu::update()
	{
		system("cls");
		cout << "---------- ADMINISTRADOR DE CLASES ----------\n\n"; // VER BIEN TEMA DE ACTUALIZACION DE PRECIO.
		cout << "Precio actual: $" << actualPrice << ".\n";
		cout << "Ultima actualizacion de precio: " << dateToString(DATE_FORMAT::COMPLETE) << "\n\n";

		cout << "  1. AJUSTAR PRECIO ACTUAL DE CADA CLASE\n"; // Ajustar por 5 clases. Pedir fecha y hora después.
		cout << "          2. VER TABLA DE COSTES\n"; // Muestra la tabla en base al precio actual.
		cout << "       3. CALCULAR COSTES DE CLASES\n"; // Se ingresa un valor y se verifica todo.
		cout << "     4. GENERAR TXT DE CLASES DEL MES\n"; // Con idea de escribir las fechas en todo el mes.
		cout << "          5. SALIR DEL PROGRAMA\n\n";
		cout << "Opcion elegida: ";
		cin >> option;

		if (option >= 1 && option <= 5)
		{
			enterOption();
		}
	}



	void MainMenu::enterOption()
	{
		switch (option)
		{
		case 1:
			// Carga menú de ajuste de precio.
			break;

		case 2:
			// Muestra la tabla de costes basada en el precio actual. Simplemente eso.
			break;

		case 3:
			// Se ingresan valores decididos por el usuario.
			// Se puede preguntar si se desean aplicar esos valores.
			// También puede preguntar si se desea generar un archivo de texto con esos costes.
			break;

		case 4:
			// Carga generador de txts para las clases del mes.
			break;

		case 5:
			ProgramManager::quit();
			break;
		}
	}

	string MainMenu::dateToString(DATE_FORMAT dateFormat)
	{
		string text = "";


		if (lastModificationDate.year == 0)
		{
			return "Precio no establecido";
		}
		else
		{
			switch (dateFormat)
			{
			case DATE_FORMAT::DD_MM_YYYY:
				if (lastModificationDate.day < 10)
				{
					text += "0";
				}

				text += lastModificationDate.day;
				text += "/";

				if (lastModificationDate.month < 10)
				{
					text += "0";
				}

				text += lastModificationDate.month;
				text += "/";
				text += lastModificationDate.year;
				break;

			case DATE_FORMAT::COMPLETE:
				text += lastModificationDate.dayOfWeek;
				text += " ";
				text += lastModificationDate.day;
				text += " de ";
				text += lastModificationDate.monthToString;
				text += " de ";
				text += lastModificationDate.year;
				break;
			}
		}


		return text;
	}
	string MainMenu::timeToString()
	{
		string text = "";


		if (lastModificationTime.hour < 10)
		{
			text += "0";
		}

		text += lastModificationTime.hour;
		text += ":";

		if (lastModificationTime.minute < 10)
		{
			text += "0";
		}

		text += lastModificationTime.minute;


		return text;
	}
}

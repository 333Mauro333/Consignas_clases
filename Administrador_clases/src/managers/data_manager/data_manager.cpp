#include "data_manager.h"

#include <fstream>

using std::ifstream;
using std::ofstream;
using std::ios;


namespace administrador_clases
{
	PRICE_INFORMATION DataManager::loadDataTimePrices()
	{
		ifstream structReader;
		PRICE_INFORMATION priceInformation = {};


		structReader.open("dat/price_information.dat", ios::in | ios::binary);

		if (structReader.good())
		{
			structReader.read((char*)&priceInformation, sizeof(PRICE_INFORMATION));
		}
		else
		{
			priceInformation = {};
		}

		structReader.close();


		return priceInformation;
	}

	void DataManager::saveDataTimePrices(DATE date, TIME time, float price, float fiveClassesPrice)
	{
		ofstream structWriter;
		PRICE_INFORMATION priceInformation = {};


		priceInformation.date = date;
		priceInformation.time = time;
		priceInformation.actualPrice = price;
		priceInformation.actualFiveClassesPrice = fiveClassesPrice;

		structWriter.open("dat/price_information.dat", ios::out | ios::binary);

		if (structWriter.good())
		{
			structWriter.write((char*)&priceInformation, sizeof(PRICE_INFORMATION));
		}

		structWriter.close();
	}
}
	
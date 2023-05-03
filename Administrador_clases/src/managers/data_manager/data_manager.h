#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "structs/price_information/price_information.h"


namespace administrador_clases
{
	class DataManager
	{
	public:
		static PRICE_INFORMATION loadDataTimePrices();

		static void saveDataTimePrices(DATE date, TIME time, float price, float fiveClassesPrice);
	};
}

#endif // !DATA_MANAGER_H

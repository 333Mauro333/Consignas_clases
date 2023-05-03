#ifndef PRICE_INFORMATION_H
#define PRICE_INFORMATION_H

#include "structs/date/date.h"
#include "structs/time/time.h"


namespace administrador_clases
{
	struct PRICE_INFORMATION
	{
		DATE date;
		TIME time;
		float actualPrice;
		float actualFiveClassesPrice;
	};
}

#endif // !PRICE_INFORMATION_H

#ifndef ACTUAL_PRICE_SETTINGS_H
#define ACTUAL_PRICE_SETTINGS_H

#include "screen/screen.h"
#include "structs/date/date.h"
#include "structs/time/time.h"


namespace administrador_clases
{
	class ActualPriceSettings : public Screen
	{
	public:
		ActualPriceSettings();
		~ActualPriceSettings();

		void update() override;

	private:
		float price;
		float priceForFiveClasses;

		DATE date;
		TIME time;

		void enterDate();
		void enterTime();

		bool isAValidDate();
	};
}

#endif // !ACTUAL_PRICE_SETTINGS_H

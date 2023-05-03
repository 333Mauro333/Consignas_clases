#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <string>

#include "screen/screen.h"

#include "structs/date/date.h"
#include "structs/time/time.h"
#include "structs/price_information/price_information.h"
#include "enums/date_format/date_format.h"

using std::string;


namespace administrador_clases
{
	class MainMenu : public Screen
	{
	public:
		MainMenu();
		~MainMenu();

		static void setLastDate(DATE date);
		static void setLastTime(TIME time);
		static void setActualPrice(float price, float fiveClassesPrice);

		void update() override;

	private:
		static DATE lastModificationDate;
		static TIME lastModificationTime;

		static float actualPrice;
		static float actualFiveClassesPrice;

		void enterOption();

		string dateToString(DATE_FORMAT dateFormat);
		string timeToString();
	};
}

#endif // !MAIN_MENU_H

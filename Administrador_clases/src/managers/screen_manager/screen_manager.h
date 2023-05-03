#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include "screen/screen.h"


namespace administrador_clases
{
	class ScreenManager
	{
	public:
		static void loadScreen(Screen* screen);
		static Screen* getActualScreen();

	private:
		static Screen* screen;
	};
}

#endif // !SCREEN_MANAGER_H

#include "screen_manager.h"

#include <cstddef>


namespace administrador_clases
{
	Screen* ScreenManager::screen = NULL;


	void ScreenManager::loadScreen(Screen* screen)
	{

	}
	Screen* ScreenManager::getActualScreen()
	{
		return screen;
	}
}

#include "program_manager.h"

#include "managers/screen_manager/screen_manager.h"
#include "program_screens/main_menu/main_menu.h"


namespace administrador_clases
{
	ProgramManager::ProgramManager()
	{
		inProgram = true;
	}
	ProgramManager::~ProgramManager()
	{

	}


	void ProgramManager::run()
	{
		init();

		while (inProgram)
		{
			update();
		}

		destroy();
	}

	void ProgramManager::quit()
	{
		inProgram = true;
	}


	void ProgramManager::init()
	{
		MainMenu::loadDataTimePrices();

		ScreenManager::loadScreen(new MainMenu());
	}
	void ProgramManager::update()
	{
		ScreenManager::getActualScreen()->update();
	}
	void ProgramManager::destroy()
	{
		delete ScreenManager::getActualScreen();
	}
}

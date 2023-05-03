#include "managers/program_manager/program_manager.h"

using administrador_clases::ProgramManager;


int main()
{
	ProgramManager* programManager = new ProgramManager();


	programManager->run();

	delete programManager;


	return 0;
}

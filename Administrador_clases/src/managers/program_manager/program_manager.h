#ifndef PROGRAM_MANAGER_H
#define PROGRAM_MANAGER_H

namespace administrador_clases
{
	class ProgramManager
	{
	public:
		ProgramManager();
		~ProgramManager();

		void run();
		
		static void quit();

	private:
		static bool inProgram;

		void init();
		void update();
		void destroy();
	};
}

#endif // !PROGRAM_MANAGER_H

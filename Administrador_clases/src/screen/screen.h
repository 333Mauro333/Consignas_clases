#ifndef SCREEN_H
#define SCREEN_H

namespace administrador_clases
{
	class Screen
	{
	public:
		Screen();
		virtual ~Screen();

		virtual void update() = 0;

	protected:
		int option;
	};
}

#endif // !SCREEN_H

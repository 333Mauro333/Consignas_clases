#ifndef DATE_H
#define DATE_H

#include <string>

using std::string;


namespace administrador_clases
{
	struct DATE
	{
		int day;
		int month;
		int year;

		string dayOfWeek;
		string monthToString;
	};
}

#endif // !DATE_H

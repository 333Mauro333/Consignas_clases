#ifndef PRICE_CALCULATOR_H
#define PRICE_CALCULATOR_H

#include "screen/screen.h"

#include <iostream>

using std::string;


namespace administrador_clases
{
	class PriceCalculator : public Screen
	{
	public:
		PriceCalculator();
		~PriceCalculator();

		void update() override;

	private:
		float priceForOneClass;
		float priceForFiveClasses;

		int askForNumber(string message, int spacesAfterInput = 0);
		void showCosts();
	};
}

#endif // !PRICE_CALCULATOR

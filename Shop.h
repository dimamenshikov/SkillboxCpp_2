#pragma once

#include"I_CommandHandler.h"
#include"Instrumentation.h"

using namespace std;

class Shop : public I_CommandHandler
{
public:
	Instrumentation* _instrumentation_ptr;
	int _quantityInstrumentation = 0;

	void (Shop::** _functions_ptr_ptr)() = new (void(Shop:: * [3])()){  &Shop::Information,
																					&Shop::InstrumentationInformation,
																					&Shop::Sorting };

	bool (Shop::** _typeSorting_ptr_ptr)(int) const = new (bool(Shop:: * [3])(int)const) {&Shop::SortingPrice,
																											&Shop::SortingQuantity,
																											&Shop::SortingAlphabetically };

	void Launch() override;
	 
	void Information();
	void InstrumentationInformation();
	void Sorting();

	bool SortingPrice(int) const;
	bool SortingQuantity(int) const;
	bool SortingAlphabetically(int) const;

	void AddInstrumentation(const Instrumentation* const);

	Shop();
	~Shop() override;
};
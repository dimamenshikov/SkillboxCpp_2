#pragma once

#include"I_Object.h"

using namespace std;

class Instrumentation : public I_Object
{
public:
	string _name = "", _manufacturer = "";
	double _cost = 0, _year = 0;
	int _quantityProduct = 0;

	void Information(bool full = false) const override;

	Instrumentation() = default;
	virtual ~Instrumentation() override;
};
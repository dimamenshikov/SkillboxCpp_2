#include "Instrumentation.h"

void Instrumentation::Information(bool full) const
{
	if (full)
	{
		cout << "\nНазвание:\t" << _name << "\n";
		cout << "Стоимость:\t" << _cost << "\n";
		cout << "Год:\t\t" << _year << "\n";
		cout << "Произведено:\t" << _manufacturer << "\n";
	}
	else
	{
		cout << _name;
		if (_name.length() > 15)
		{
			cout << "\t";
		}
		else if (_name.length() > 7)
		{
			cout << "\t\t";
		}
		else
		{
			cout << "\t\t\t";
		}
		cout << _quantityProduct << "\t\t\t" << _cost << "\n";
	}
}

Instrumentation:: ~Instrumentation() {}
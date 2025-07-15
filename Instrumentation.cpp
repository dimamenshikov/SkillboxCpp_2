#include "Instrumentation.h"

void Instrumentation::Information(bool full) const
{
	if (full)
	{
		cout << "\n��������:\t" << _name << "\n";
		cout << "���������:\t" << _cost << "\n";
		cout << "���:\t\t" << _year << "\n";
		cout << "�����������:\t" << _manufacturer << "\n";
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
#include "Shop.h"

void Shop::Launch()
{
	cout << "\nМагазин техники:\t(для выхода напишите выход)\n\n";
	int number;
Command:
	if (!InputCommand(&number, "Введите команду: информация/разновидность/сортировка\n", 0, 3))
	{
		if (_quit)
		{
			return;
		}
		goto Command;
	}
	(this->*_functions_ptr_ptr[number])();
	if (_quit)
	{
		return;
	}
	goto Command;
}

void Shop::InstrumentationInformation()
{
	int number;
	if (!InputInt("Введите номер разновидности товара ", &number, true))
	{
		return;
	}
	if (number > _quantityInstrumentation)
	{
		cout << "Нет такой разновидности\n";
		return;
	}
	_instrumentation_ptr[number - 1].Information(true);
}

void Shop::Information()
{
	cout << "\n\t№\t" << "Развидность\t\t" << "Количество\t\t" << "Цена\t\n";
	cout << "\t-----------------------------------------------------------------\n";
	for (int i = 0; i < _quantityInstrumentation; ++i)
	{
		cout << "\t" << i + 1 << "\t";
		_instrumentation_ptr[i].Information();
	}
	cout << "\n";
}

void Shop::Sorting()
{
	int number;
	if (!InputCommand(&number, "Введите команду: по цене/по количеству/по алфавиту\n", 1, 3))
	{
		return;
	}
	for (int i = 0; i < _quantityInstrumentation - 1; ++i)
	{
		for (int j = 0; j < _quantityInstrumentation - i - 1; ++j)
		{
			if ((this->*_typeSorting_ptr_ptr[number])(j))
			{
				Instrumentation temp = _instrumentation_ptr[j];
				_instrumentation_ptr[j] = _instrumentation_ptr[j + 1];
				_instrumentation_ptr[j + 1] = temp;
			}
		}
	}
}

bool Shop::SortingPrice(int i) const
{
	return _instrumentation_ptr[i]._cost > _instrumentation_ptr[i + 1]._cost;
}

bool Shop::SortingQuantity(int i) const
{
	return _instrumentation_ptr[i]._quantityProduct > _instrumentation_ptr[i + 1]._quantityProduct;
}

bool Shop::SortingAlphabetically(int i) const
{
	int shortLength = _instrumentation_ptr[i]._name.length() > _instrumentation_ptr[i + 1]._name.length() ? _instrumentation_ptr[i + 1]._name.length() : _instrumentation_ptr[i]._name.length();
	for (int j = 0; j < shortLength; ++j)
	{
		if (_instrumentation_ptr[i]._name[j] != _instrumentation_ptr[i + 1]._name[j])
		{
			return _instrumentation_ptr[i]._name[j] > _instrumentation_ptr[i + 1]._name[j];
		}
	}
	return _instrumentation_ptr[i]._name.length() > _instrumentation_ptr[i + 1]._name.length();
}

void Shop::AddInstrumentation(const Instrumentation* const instrumentation_ptr)
{
	++_quantityInstrumentation;
	Instrumentation* newInstrumentation_ptr = new Instrumentation[_quantityInstrumentation];
	newInstrumentation_ptr[_quantityInstrumentation - 1] = *instrumentation_ptr;
	for (int i = 0; i < _quantityInstrumentation - 1; ++i)
	{
		newInstrumentation_ptr[i] = _instrumentation_ptr[i];
	}
	delete[] _instrumentation_ptr;
	_instrumentation_ptr = newInstrumentation_ptr;
}

Shop::Shop() 
{
	_command_ptr_ptr = new string * [2];
	_command_ptr_ptr[0] = new string[3]{ "информация", "разновидность", "сортировка" };
	_command_ptr_ptr[1] = new string[3]{ "по цене", "по количеству", "по алфавиту" };
}

Shop::~Shop()
{
	delete[] _instrumentation_ptr;
	delete[] _functions_ptr_ptr;
	delete[] _typeSorting_ptr_ptr;
	delete[] _command_ptr_ptr[0];
	delete[] _command_ptr_ptr[1];
	delete[] _command_ptr_ptr;
}
#include "I_CommandHandler.h"

void I_CommandHandler::Launch(){}

bool I_CommandHandler::InputCommand(int* number, const string& _string, int indexCommand, int size)
{
	cout << _string;
	string command;
	getline(cin, command);
	if (command == "выход")
	{
		_quit = true;
		return false;
	}
	if (!FindCommand(command, number, indexCommand, size))
	{
		cout << "Некорректный ввод\n";
		return false;
	}
	return true;
}

bool I_CommandHandler::InputInt(const string& _string, int* result, bool positiveOnly)
{
	cout << _string;
	string inputInt;
	getline(cin, inputInt);
	if (inputInt == "выход")
	{
		_quit = true;
		return false;
	}
	if (!StringToInt(inputInt, result))
	{
		cout << "Некорректный ввод\n";
		return false;
	}
	if (*result <= 0 && positiveOnly)
	{
		cout << *result << " Не натуральное число\n";
		return false;
	}
	return true;
}

bool I_CommandHandler::InputDouble(const string& _string, double* result, bool positiveOnly)
{
	cout << _string;
	string inputDouble;
	getline(cin, inputDouble);
	if (inputDouble == "выход")
	{
		_quit = true;
		return false;
	}
	if (!StringToDouble(inputDouble, result))
	{
		cout << "Некорректный ввод\n";
		return false;
	}
	if (*result <= 0 && positiveOnly)
	{
		cout << *result << " Не натуральное число\n";
		return false;
	}
	return true;
}

bool I_CommandHandler::StringToInt(const string& _string, int* result)
{
	*result = 0;
	switch(_string.length())
	{
	case 0:
		return false;
	case 1:
		if (_string[0] == '-')
		{
			return false;
		}
		break;
	case 2:
		if (_string[0] == '0')
		{
			return false;
		}
		break;
	default:
		if (_string[0] == '0' || (_string[0] == '-' && _string[1] == '0'))
		{
			return false;
		}
		break;
	}
	bool minus = _string[0] == '-';
	for (int i = minus; i < _string.length(); ++i)
	{
		if (_string[i] < 48 || _string[i] > 57)
		{
			*result = 0;
			return false;
		}
		else
		{
			*result = *result * 10 + (_string[i] - 48);
		}
	}
	*result = minus ? -*result : *result;
	return true;
}

bool I_CommandHandler::StringToDouble(const string& _string, double* result)
{
	*result = 0;
	bool minus;
	switch(_string.length())
	{
	case 0:
		return false;
	case 1:
		if (_string[0] == '.' || _string[0] == '-')
		{
			return false;
		}
		break;
	case 2:
		if (_string[0] == '.' || _string[1] == '.' || _string[0] == '0')
		{
			return false;
		}
		break;
	default:
		minus = _string[0] == '-';
		if ((_string[minus] == '0' && _string[minus + 1] != '.') || _string[minus] == '.')
		{
			return false;
		}
		break;
	}
	minus = _string[0] == '-';
	bool point = false;
	for (int i = minus, j = 10; i < _string.length(); ++i)
	{
		if ((_string[i] < 48 && _string[i] != 46) || _string[i] > 57)
		{
			*result = 0;
			return false;
		}
		else
		{
			if (_string[i] != 46)
			{
				if (point)
				{
					*result += (double)(_string[i] - 48) / j;
					j *= 10;
				}
				else
				{
					*result = *result * 10 + (_string[i] - 48);
				}
			}
			else
			{
				if (point)
				{
					*result = 0;
					return false;
				}
				point = true;
			}
		}
	}
	*result = minus ? -*result : *result;
	return true;
}

bool I_CommandHandler::FindCommand(string command, int* number, int indexCommand, int size) const
{
	for (int i = 0; i < size; ++i)
	{
		if (_command_ptr_ptr[indexCommand][i] == command)
		{
			*number = i;
			return true;
		}
	}
	return false;
}

I_CommandHandler::~I_CommandHandler() {}
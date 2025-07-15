#pragma once

#include<iostream>
#include<string>

using namespace std;

class I_CommandHandler
{
public:
	string** _command_ptr_ptr = nullptr;
	bool _quit = false;

	virtual void Launch();

	bool InputCommand(int*, const string&, int, int);
	bool InputInt(const string&, int*, bool positiveOnly = false);
	bool InputDouble(const string&, double*, bool positiveOnly = false);

	bool StringToInt(const string&, int*);
	bool StringToDouble(const string&, double*);

	bool FindCommand(string, int*, int, int) const;

	I_CommandHandler() = default;
	virtual ~I_CommandHandler() = 0;
};
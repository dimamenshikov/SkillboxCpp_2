#pragma once

#include<iostream>

class I_Object
{
public:
	virtual void Information(bool full) const;

	I_Object() = default;
	virtual ~I_Object() = 0;
};


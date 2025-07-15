#pragma once

#include"Mechanical.h"
#include"Electric.h"

class CoffeeGrinder : public Electric, public Mechanical
{
public:
	CoffeeGrinder();
};
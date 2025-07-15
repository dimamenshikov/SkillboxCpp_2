#pragma once

#include"Mechanical.h"
#include"Electric.h"

class MeatGrinder : public Electric, public Mechanical
{
public:
	MeatGrinder();
};
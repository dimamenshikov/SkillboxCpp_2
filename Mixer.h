#pragma once

#include"Mechanical.h"
#include"Electric.h"

class Mixer : public Electric, public Mechanical
{
public:
	Mixer();
};


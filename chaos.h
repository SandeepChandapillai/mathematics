#pragma once

//System
#include <functional>


//Personal 
#include "matrix.h"
#include "la_pack.h"


class chaos
{
public:
	chaos(void);
	~chaos(void);

	double pitchFork(double x, double r) { return r * x - x * x * x; }








};


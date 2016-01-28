#pragma once
#include "func.h"

class numerical_error
{
public:
	numerical_error();
	~numerical_error();


	static double relativeError(double error, double trueValue) { return abs(error) / abs(trueValue); };
};


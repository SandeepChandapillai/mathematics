#pragma once

#include <functional>

#include "la_pack.h"
#include "matrix.h"
#include "analysis.h"
#include "func.h"


class non_linear
{
public:
	non_linear();
	~non_linear();


	double bestRootNonLinear(scalarFn_1 fn);

};


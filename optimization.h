#pragma once

#include "matrix.h"
#include "la_pack.h"
#include "func.h"

class optimization
{
public:
	optimization(void);
	~optimization(void);



	// CONVEX OPTIMIZATION 
	scalarFn_2 prespective(scalarFn_1 f);
	// Tests if function is convex in given range. 
	// Implementation , check if function have a value at mid point , less than the average at the ends. 
	bool isConvecFn_1D(scalarFn_1, double start, double end);

	/*
		Equality Constraints Lagrangian

		INPUT  : F and contraints C // COLUMN VECTORS 
		OUTPUT : a scalar function which takes in two vectors x and lambda and returns the Lagrangian	

		NOTE:
		constraintFunc will take in a matrix of double , will evaluate each of the constaints at x and return double
	*/
	std::function<double(matrix<double>, matrix<double>)> lagrangian(scalarFn_N objectiveFunc, std::function<matrix<double>(matrix<double>)>   constraintFunc);
	

private:
	la_pack la;



};


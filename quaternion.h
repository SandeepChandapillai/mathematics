#pragma once

/*
	Present the data using matrix class 
	Define all the operations on a quaternion ! 



*/


//
#include <vector>

// PERSONAL 
#include "matrix.h"
#include "la_pack.h"

class quaternion
{
public:
	
	quaternion(double a , double b , double c , double d);
	~quaternion();

	double returnRealPart();
	matDouble returnVectorPart();
	void print(); 
	quaternion operator*(const quaternion &rhs);
	double operator()(const long long rhs);

private:
	quaternion();
	matrix<double> _data;
	static void error(const char* p){ std::string str = "quaternion -> Error: "; std::cout << str << p << std::endl; }

};


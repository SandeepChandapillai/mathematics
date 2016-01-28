#include "quaternion.h"


quaternion::quaternion()
{
}


quaternion::~quaternion()
{
}


quaternion::quaternion(double a, double b, double c, double d)
{
	matDouble data(4, 1);
	_data = data; 
	_data(1, 1) = a; 
	_data(2, 1) = b;
	_data(3, 1) = c;
	_data(4, 1) = d;
}

double	quaternion::operator()(const long long  rhs)
{
	if (rhs <= 4 && rhs > 0 )
	{
		return _data(1, rhs);
	}
	else
	{
		error("operator() -> wrong indexing :: Only 1 to 4 ");
		return -10000;
	}
}

quaternion quaternion::operator*(const quaternion &rhs)   // UNIMPLEMENTED !! 
{
	quaternion data(0, 0, 0, 0);
	return data;//* rhs_data(1,1);
}


double quaternion::returnRealPart()
{
	return _data(1, 1);
}


matDouble quaternion::returnVectorPart()
{
	matDouble data(3, 1);
	data(1, 1) = _data(2, 1);
	data(2, 1) = _data(3, 1);
	data(3, 1) = _data(4, 1);
	return data; 
}

void quaternion::print()
{
	_data.print();
}

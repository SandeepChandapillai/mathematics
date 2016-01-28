#include "optimization.h"


optimization::optimization(void)
{
}


optimization::~optimization(void)
{
}


scalarFn_2 optimization::prespective(scalarFn_1 f)
{
	scalarFn_2 g; double t; 
	g = [f](double x, double t){ return t * f(x / t);  };
	return g; 
}

bool optimization::isConvecFn_1D(scalarFn_1 f, double start, double end)
{
	double midPoint = (end - start ) / 2; 
	double mean = ( f(end) + f(start) ) / 2; // Staright line between end and start .  
	return (mean > f(midPoint))? true : false; 
}



std::function<double(matrix<double>, matrix<double>)> optimization::lagrangian(scalarFn_N objectiveFunc, std::function<matrix<double>(matrix<double>)> constraintFunc)
{

	std::function<double(matrix<double>, matrix<double>)> fn = [objectiveFunc, constraintFunc](matDouble &x, matDouble &lambda)
	{
		la_pack la;
		matDouble & lValueHack = constraintFunc(x); // OPTIMIZE ?? 
		return objectiveFunc(x) - la.innerProduct(lambda, lValueHack);
	};
	return fn;
}

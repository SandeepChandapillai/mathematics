#pragma once


/*
This class always assumes that the favorable event occurs in the totalEvents 
There is no check to see if the fav Event belongs to the total Event


P(A) is meaningless if S in not know as P(A) = A / S ; 

*/
// SYSTEM
#include <functional>
#include <string>

// PERSONAL 
#include "func.h"
#include "analysis.h"
#include "matrix.h"
#include "la_pack.h"
#include "setMath.h"





template <class T>
class probability
{
public:
	probability(void);
	~probability(void);

	double getProbability(double favEvents, double totalEvents) { return favEvents / totalEvents; }
	double getProbability(setMath<T> favEvents, setMath<T>  totalEvents);


	/*
	P(A|B)

	Simple takes the intesection of A and B . 
	Returns the size of interection divided by size of B 
	*/
	double conditionalProbability(setMath<T>  A, setMath<T>  B, setMath<T>  S);


	/*
	P(B) = P(B|A1)*P(A1) + ..... P(B|An) * P(An)

	Where A is each element in S 
	*/

	double totalProbability(setMath<T>  B, setMath<T> S); // UNTESTED

	/*
	Gives 
	P(A|B) = P(B|A) * P(A ) / P(B) ; 
	
	*/
	double bayesTheorem(setMath<T> A, setMath<T> B, setMath<T> S);


	/*
	Maps an Event to a numerical value . 
	*/
	double randomVariable();



	// DATA MEMEBERS 

	//static setMath<int> DIE;

private:
	
};





template <class T>
probability<T>::probability(void)
{
	//DIE.insert(1);
}

template <class T>
probability<T>::~probability(void)
{
}


template <class T>
double probability<T>::totalProbability(setMath<T>  B, setMath<T> S)
{
	double probB = 0 ; 
	for (auto a : S._set)
	{
		setMath<T> tempA({ a });
		probB += conditionalProbability(B, tempA) * getProbability(tempA, S); 
	}

	return probB;
}


template <class T>
double probability<T>::getProbability(setMath<T> favEvents, setMath<T>  totalEvents)
{
	double result = totalEvents.size();
	return favEvents.size() / result; // Prevents Truncation Error .. Using DOuble instead of int

};




template <class T>
double probability<T>::conditionalProbability(setMath<T>  A, setMath<T>  B, setMath<T>  S)
{
	setMath<T> intersection = A.getIntersection(B);
	return getProbability(intersection, S) / (getProbability(B,S)); 

}



template <class T>
double probability<T>::bayesTheorem(setMath<T> A, setMath<T> B, setMath<T> S)
{
	double pB_A = conditionalProbability(A, B, S);
	double pB = getProbability(B, S);
	double pA = getProbability(A, S);

	return pB_A * pA / pB; 
}
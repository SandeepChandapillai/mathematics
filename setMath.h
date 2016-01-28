#pragma once


// Functions as a mathamatical Set 

// A Set is simply a collection of any objects.......

/*
Implementation 

A set is simply a collection of objects 
Simply a wrapper around a set 



Usage 
set<string> outcomes = {"head" , "tails"} 



*/

#include <iterator>
#include <set>
#include <iostream>
#include <algorithm>
#include <initializer_list>

template <class T>
class setMath
{
public:
	setMath() {}; 
	setMath(std::initializer_list<T> list) : _set(list) {} 
	~setMath();

	void insert(T elem); 
	int size();
	void print(); 
	setMath<T> getUnion(setMath<T> &rhs);
	setMath<T> getIntersection(setMath<T> &rhs);
	//setMath<T> beginElem();
	//setMath<T> endElem();
	
private: 
	std::set<T> _set;

};


template <class T>
setMath<T>::~setMath() {} 



template <class T>
void setMath<T>::insert(T elem)
{
	_set.insert(elem);
}


template <class T>
int setMath<T>::size()
{
	return _set.size(); 
}


template <class T>
setMath<T> setMath<T>::getUnion(setMath<T> &rhs)
{
	setMath<T> result; 
	result._set.insert(_set.begin(), _set.end());
	result._set.insert(rhs._set.begin(), rhs._set.end());
	return result; 
}

template <class T>
setMath<T> setMath<T>::getIntersection(setMath<T> &rhs)
{
	setMath<T> result;
	set_intersection(_set.begin(), _set.end(), rhs._set.begin(), rhs._set.end(), std::inserter(result._set , result._set.begin() ) );
	return result; 

}

template <class T>
void setMath<T>::print()
{
	for (auto i : _set)
	{
		std::cout << i << std::endl; 
	}
}
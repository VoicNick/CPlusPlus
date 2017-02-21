// Assignment 1 COMP 2618, Voicu Chirtes 
// Member-function definitions for class Shape.
// The class definition is in Shape.h
// Original Author: Bob Langelaan 
// Original Date: Sept. 20th, 2014
//
// Author: Voicu Chirtes
// Date: Apr. 27, 2015

#include "Shape.h"

int Shape::mObjectCount = 0;

// constructor
Shape::Shape(void)
:mNoOfSides(1)
{
	++Shape::mObjectCount;
}

// desstructor
Shape::~Shape(void)
{
	--Shape::mObjectCount;
}

// used to set mNoOfSides member
void Shape::setNoOfSides(const int & setVal)
{
	if (setVal > 0 )
	{
		this->mNoOfSides = setVal;
	}

	// otherwise just leave set to original value
}

// used to return current value of mNoOfSides member
int Shape::getNoOfSides() const
{
	return this->mNoOfSides;
}

// used to return current value of mObjectCount static member
int Shape::getObjectCount()
{
	return Shape::mObjectCount;
}

/* 
// This is a pure virtual method now, no need
// for an implementation in the base, abstract class.
// used to calculate and return area 
double Shape::Area(void) const
{
	return 0.0;
}

// Volume method moved into the ThreeDimensionalShapes class
// as only one such shape can have a volume
// used to calculate and return volume
double Shape::Volume(void) const
{
	return 0.0;
}

*/
// Assignment 1 COMP 2618, Voicu Chirtes
// Member-function definitions for class Circle.
// Class definition is in Circle.h file
// Original Author: Bob Langelaan
// Original Date: Sept. 20th, 2014
//
// Author: Voicu Chirtes
// Date: Apr. 27, 2015

#include "Circle.h"

const double Circle::pi = 3.141592654;  // init. static member

// constructor 
Circle::Circle(void)
:mRadius(0.0)
{
	this->setNoOfSides(1);  //  Why not init. this member in MIL ???
}

// used to set value for mRadius member
void Circle::setRadius(const double & setVal)
{
	if (setVal > 0.0) // Make sure input is a valid value
	{
		this->mRadius = setVal;
	}

	// otherwise just leave set to original value
}

// used to return current value of mRadius member
double Circle::getRadius (void) const
{
	return this->mRadius ;
}

// used top calculate and return area.
double Circle::Area (void) const
{
	return Circle::pi * this->mRadius * this->mRadius ;
}

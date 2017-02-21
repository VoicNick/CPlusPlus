// Assignment 1 COMP 2618, Voicu Chirtes
// Member-function definitions for class Cylinder.
// Class definition is in Cylinder.h file
// Original Author: Bob Langelaan
// Original Date: Sept. 20th, 2014
//
// Author: Voicu Chirtes
// Date: Apr. 27, 2015

#include "Cylinder.h"

const double Cylinder::pi = 3.141592654;  // init. static member

// constructor
Cylinder::Cylinder(void)
	: mHeight(0.0),
	mRadius(0.0)
{
	this->setNoOfSides(3);   // Why not init. this member in MIL ???
}

// used to set mHeight member
void Cylinder::setHeight(const double & setVal)
{
	if (setVal > 0.0 )  // Make sure input is a valid value
	{
		this->mHeight = setVal;
	}

	// otherwise just leave set to original value
}

// used to return current value of mHeight member
double Cylinder::getHeight (void) const
{
	return this->mHeight;
}

// used to set value for mRadius member
void Cylinder::setRadius(const double & setVal)
{
	if (setVal > 0.0) // Make sure input is a valid value
	{
		this->mRadius = setVal;
	}

	// otherwise just leave set to original value
}

// used to return current value of mRadius member
double Cylinder::getRadius(void) const
{
	return this->mRadius;
}

// used to caluclate and return area
double Cylinder::Area (void) const
{
	double TwoPiR = 2.0 * Cylinder::pi * this->mRadius;
	return ( TwoPiR * this->mRadius ) + ( TwoPiR * this->mHeight );
}

// used to claculate and return volume
double Cylinder::Volume (void) const
{
	return Cylinder::pi * this->mRadius * this->mRadius * this->mHeight;
}
// Assignment 1 COMP 2618, Voicu Chirtes
// Declaration of class Cylinder.
// Member functions are defined in Cylinder.cpp.
// Original Author: Bob Langelaan
// Original Date: Sept. 9th, 2006
//
// Author: Voicu Chirtes
// Date: Apr. 27, 2015

#pragma once
#include "ThreeDimensionalShapes.h"

class Cylinder :public ThreeDimensionalShapes
{
public:
	Cylinder(void); // constructor

	void setHeight(const double &); // set the height
	double getHeight() const; // get the height

	void setRadius(const double &);  //set the radius of base
	double getRadius() const;  // get the radius of base

	virtual double Area() const override;    // overrides Area()   method of Circle class
	virtual double Volume() const override;  // overrides Volume() method of Shape  class

protected:
	double mHeight;  // member used to represent height

	const static double pi; // Static member used in calculations
	// Only one of these instantiated for the whole class!

	double mRadius;  // member used to represent radius of base
};

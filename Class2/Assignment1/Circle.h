// Assignment 1 COMP 2618, Voicu Chirtes
// Declaration of class Circle.
// Member functions are defined in Circle.cpp.
// Original Author: Bob Langelaan 
// Original Date: Sept. 9th, 2006
//
// Author: Voicu Chirtes
// Date: Apr. 27, 2015

#pragma once
#include "TwoDimensionalShapes.h"

class Circle :public TwoDimensionalShapes
{
public:
	Circle(void); // constructor

	void setRadius(const double &);  //set the radius
	double getRadius() const;  // get the radius

	virtual double Area() const override;  // overrides Area() method of Shape class

protected:
	const static double pi; // Static member used in calculations
	                        // Only one of these instantiated for the whole class!
	double mRadius;  // member used to represent radius
};

// Assignment 1 COMP 2618, Voicu Chirtes
// Declaration of class ThreeDimensionalShapes. 
// Member functions are defined in ThreeDimensionalShapes.cpp.
// 
// Author: Voicu Chirtes
// Date: Apr. 27, 2015

#pragma once
#include "Shape.h"

class ThreeDimensionalShapes : public Shape
{
public:
	// calculate and return volume
	// made a pure virtual method here in the class as 
	// as only a three dimensional shape can have a volume and
	// it's implementation is dependent on the shape proprties
	// Makes ThreeDimensionalShapes an abstract class
	virtual double Volume() const = 0;   
};
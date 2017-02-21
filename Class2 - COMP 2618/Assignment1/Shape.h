// Assignment 1 COMP 2618, Voicu Chirtes
// Declaration of class Shape. Base class for  all other
// classes
// Member functions are defined in Shape.cpp.
// Original Author: Bob Langelaan
// Original Date: Sept. 9, 2006
//
// Author: Voicu Chirtes
// Date: Apr. 27, 2015

#pragma once

class Shape
{
public:
	Shape(void);  //constructor
	virtual ~Shape(void); //destructor

	void setNoOfSides(const int &);  // set the # of sides
	int getNoOfSides() const;        // get the # of sides

	static int getObjectCount();     // get the object count

	// calculate and return area 
	// made a pure virtual method here in the Shape class as each 
	// object for this assignent has at least two dimensions
	// makes Shape an abstract class
	virtual double Area() const = 0;     

	// Volume method moved into the ThreeDimensionalShapes class
	// as only one such shape can have a volume
	// virtual double Volume() const;   // calculate and return volume
	
protected:
	int mNoOfSides; // represents # of sides in Shape object
	static int mObjectCount; // a static member - counts the # of Shape 
	                         //          objects currently instantiated
	               // Only one of these instantiated for the whole class!
};

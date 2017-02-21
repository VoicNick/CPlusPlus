// Assignment 8 COMP 2617
// This is part of the solution for the Ex 9.5 as required
// for the Assignment 8
// This is the class impementation for Complex class, that models 
// complex numbers and basic arithmetic on complex numbers
// The class definition is included in the Complex.h file
//
// Author:	Voicu Chirtes
// Date:	Mar 30, 2015

#include <iostream>
#include <iomanip>
#include "Complex.h"

using namespace std;

//default constructor with default values
Complex::Complex(double realP, double imaginaryP)
	: realPart(realP),
	imaginaryPart(imaginaryP)
{
	// noting to do as we are using member initializing list baove
}

// accessor for the real part
double Complex::getRealPart() const
{
	return realPart;
}

//accessor for the imaginary part
double Complex::getImaginaryPart() const
{
	return imaginaryPart;
}

// setter for the real part
void Complex::setRealPart(double realP)
{
	realPart = realP;
}

// setter for the imaginary part
void Complex::setImaginaryPart(double imaginaryP)
{
	imaginaryPart = imaginaryP;
}

// display the Complex number in the format 
// ( realPart , imaginaryPart )
void Complex::display() const
{
	cout << setprecision(4) << fixed;
	cout << "( " << getRealPart() << " , " << getImaginaryPart() << " )";
}

// Adding two Complex numbers similar with the 
// += operation
const Complex & Complex::plusEq(const Complex & op)
{
	realPart += op.getRealPart();
	imaginaryPart += op.getImaginaryPart();
	return(*this);
}

// Substracting two Complex numbers similar with the 
// -= operation
const Complex & Complex::minusEq(const Complex & op)
{
	realPart -= op.getImaginaryPart();
	imaginaryPart -= op.getImaginaryPart();

	return (*this);
}


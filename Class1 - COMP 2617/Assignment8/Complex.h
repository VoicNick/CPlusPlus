// Assignment 8 COMP 2617
// This is part of the solution for the Ex 9.5 as required
// for the Assignment 8
// This is the class definition for Complex class, that models 
// complex numbers and basic arithmetic on complex numbers
//
// Author:	Voicu Chirtes
// Date:	Mar 30, 2015

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
	//default constructor with default values
	Complex(double = 1.0, double = 0.0);

	// accessor for the real part
	double getRealPart() const;

	//accessor for the imaginary part
	double getImaginaryPart() const;

	// setter for the real part
	void setRealPart(double);

	// setter for the imaginary part
	void setImaginaryPart(double);

	// display the Complex number in the format 
	// ( realPart , imaginaryPart )
	void display() const;

	// Adding two Complex numbers similar with the 
	// += operation
	const Complex &plusEq(const Complex &);

	// Substracting two Complex numbers similar with the 
	// -= operation
	const Complex &minusEq(const Complex &);

private:
	double realPart;
	double imaginaryPart;
};
#endif
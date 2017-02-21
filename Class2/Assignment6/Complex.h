// Assignment 6 COMP 2618 Starting Point: Complex.h
// Declaration of class Complex.
//
// Class Complex models and stores complex numbers
// There are two supported input and output fromat Modes:
//	Mode 1: '(' + Real part + ',' + Imaginary part + ')'
//	Mode 2: Real part + ' ' + Imaginary part + 'i'
// Input and output Modes are controlled via the ios::oct flag
// of the fmtflags of the specific input or output objects (cin, cout)
// ios::oct flag set (=1) means Mode 1 is expected/outputed
// ios::oct flag not set (=0) means Mode 2 is expected/outputed
//
// Member functions are defined in Complex.cpp.
// Original Author: Bob Langelaan 
// Original Date: Feb 19, 2014
//
// Author: Voicu Chirtes
// Date: June 9, 2015

#ifndef Complex_incl
#define Complex_incl

#include <iostream>
#include <exception>

class Complex  // Complex class
{

// We must offer friendship to the functions below because they need to access the
//    the private members of the Complex class object
	friend std::ostream & operator << (std::ostream & dest, const Complex & obj);
	friend std::istream & operator >> (std::istream & input, Complex & obj);

public:
	Complex (double real = 1.0, double imag = 0.0 );  // ctor with
	   // 2 default arguments
	 
	Complex & operator+= (const Complex & RHS ) ; //Adds RHS to the Complex object invoked with this method
	                                      //  (thereby modifying the Complex object) and returns the result
	                                      //  Overloads the "+=" operator
	Complex & operator-= (const Complex & RHS ) ; //Subtracts RHS from the Complex object invoked with this method
	                                      //  (thereby modifying the Complex object) and returns the result
	                                      //  Overloads the "-=" operator

	bool operator == (const Complex & RHS) const; // Overloads "==" operator

	double getReal(void);      // Returns real part
	double getImaginary(void); // Returns imaginary part

	void display(void); // Outputs to standard output stream the Complex object
	                    //   in the format: (real_part,imaginary_part)

private:

	double real_part, // represents real part of the Complex object
		imaginary_part;     // represents imaginary part of the Complex object
};

// overloads the binary "+" operator through a global function
Complex operator + (const Complex & LHS, const Complex & RHS );

// overloads the binary "-" operator through a global function
Complex operator - (const Complex & LHS, const Complex & RHS );

// overloads the binary "!=" operator through a global function
bool operator != (const Complex & LHS, const Complex & RHS);

// overloads the binary "<<" operator through a global friend function
std::ostream & operator << (std::ostream & dest, const Complex & obj);

// overloads the binary ">>" operator through a global friend function
std::istream & operator >> (std::istream & input, Complex & obj);

// exception class used as base for all exception classes 
// specific to the Complex class
class Complex_Class_Exception : public std::exception
{
public:
	//default constructor
	Complex_Class_Exception(const char * message = "Complex class general exception")
		: exception(message) {}
};

//exception to verify the corect input for Mode 1
class Invalid_Mode1_Complex_Value : public Complex_Class_Exception
{
public:
	Invalid_Mode1_Complex_Value()
		: Complex_Class_Exception("Invalid value for inputting Complex # using Mode 1") {}
};

//exception to verify the corect input for Mode 2
class Invalid_Mode2_Complex_Value : public Complex_Class_Exception
{
public:
	Invalid_Mode2_Complex_Value()
		: Complex_Class_Exception("Invalid value for inputting Complex # using Mode 2") {}
};

#endif
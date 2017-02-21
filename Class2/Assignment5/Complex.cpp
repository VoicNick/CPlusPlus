// Assignment 5 COMP 2618 Complex.cpp
// Member-function definitions for class Complex.

// Class Complex models and stores complex numbers
// There are two supported input and output fromat Modes:
//	Mode 1: '(' + Real part + ',' + Imaginary part + ')'
//	Mode 2: Real part + ' ' + Imaginary part + 'i'
// Input and output Modes are controlled via the ios::oct flag
// of the fmtflags of the specific input or output objects (cin, cout)
// ios::oct flag set (=1) means Mode 1 is expected/outputed
// ios::oct flag not set (=0) means Mode 2 is expected/outputed

// Class declaration is in Complex.h file
// Original Author: Bob Langelaan 
// Original Date: Feb 19, 2014
//
// Author: Voicu Chirtes
// Date: June 1, 2015

#include "Complex.h"
#include <iomanip>
using namespace std;

// format parameters used in the overloaded "<<" operator for dispay
const static int mode1Width = 10;
const static int mode1Precision = 2;
const static int mode2Width = 10; // currentelly not used
const static int mode2Precision = 4;

//ctor
Complex::Complex ( double real, double imag )
{
	this->real_part = real;
	this->imaginary_part = imag;
}

// overload the "+=" operator
Complex & Complex::operator += (const Complex & op )
{
	this->real_part += op.real_part;
	this->imaginary_part += op.imaginary_part;

	return (*this);
}

// overload the "-=" operator
Complex & Complex::operator -= (const Complex & op )
{
	this->real_part -= op.real_part;
	this->imaginary_part -= op.imaginary_part;

	return (*this);
}

// overload the "==" operator
bool Complex::operator == (const Complex & RHS) const
{
	if (this->real_part != RHS.real_part)
	{
		return false;
	}
	else if (this->imaginary_part != RHS.imaginary_part)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// return the real part of the complex #
double Complex::getReal(void)
{
	return this->real_part;
}

// return the imaginary part of the complex #
double Complex::getImaginary(void)
{
	return this->imaginary_part;
}

// display the complex #
void Complex::display (void)
{
   // set floating-point number format
   cout << fixed << setprecision(3);

   cout << "( " << this->getReal() << " , " << this->getImaginary() << " )";
}

// overloads the binary '+' operator through a global function
Complex operator + (const Complex & LHS, const Complex & RHS )
{
	Complex temp = LHS;
	temp += RHS; // uses the overloaded "+=" operator
	return temp;
}

// overloads the binary '-' operator through a global function
Complex operator - (const Complex & LHS, const Complex & RHS )
{
	Complex temp = LHS;
	temp -= RHS; // uses the overloaded "-=" operator
	return temp;
}

// overloads the binary "!=" operator through a global function
bool operator != (const Complex & LHS, const Complex & RHS)
{
	return !(LHS == RHS); // uses overloaded "==" operator
}

// overloads the binary "<<" operator through a global friend function
// see class documentation at top for supported modes/format of output
ostream & operator << (ostream & dest, const Complex & obj)
{
	// store flags in order to restore later
	ios::fmtflags origFlags = dest.flags();

	if (origFlags & ios::oct)	// check if hex bit is set
	{	// if true, result of & was 1, so it means the hex bit was set
		// in this case we display in format Mode 1: 
		// (Real part as: <sign> <internal spacing of 10 lenght>,  
		//		Imaginary part as: <sign> <internal spacing of 10 lenght>)
		
		dest << fixed << showpos << internal << setprecision(mode1Precision);
		dest << "(" << setw(mode1Width) << obj.real_part << "," << setw(mode1Width) << obj.imaginary_part << ")";
	}
	else
	{
		// if false, result of & was 0, so it means the hex bit was not set
		// in this case we display in format Mode 2: 
		// (Real part + " " + Imaginary part + "i")
		dest << fixed << setprecision(mode2Precision);
		dest << obj.real_part << " " << obj.imaginary_part << "i";
	}

	// setting flags back to how they were when entering the function
	dest.flags(origFlags); 

	return dest; // enables  cout << a << b << c
}

// overloads the binary ">>" operator through a global friend function
// see class documentation at top for supported modes/format of input
istream & operator >> (istream & input, Complex & obj)
{

	// store flags in order to restore later
	ios::fmtflags origFlags = input.flags();

	if (origFlags & ios::oct)	// check if hex bit is set
	{	// if true, result of & was 1, so it means the hex bit was set
		// in this case we expect a number in format Mode 1: 
		// (Real part + ',' + Imaginary part)
		
		/*
		// Implemention of checking of leading '(' not required for assingment, 
		// it needs more work:
		if (input.peek() != '(')
		{
			// invalid input for Mode 1
			// set failbit 
			input.clear(ios::failbit);
			return input;
		}
		*/
		input.ignore(INT_MAX, '('); // skip over '('
		input >> obj.real_part; // read the real component of the Complex #
		if (input.peek() != ',')
		{
			// invalid input for Mode 1
			// set failbit 
			input.clear(ios::failbit);
			return input;
		}
		input.ignore(2, ','); // skip over ','
		input >> obj.imaginary_part; // read the real component of the Complex #
		if (input.peek() != ')')
		{
			// invalid input for Mode 1
			// set failbit 
			input.clear(ios::failbit);
			return input;
		}
		input.ignore(2, ')'); // skip over ')'
		//input.ignore(); 
	}
	else
	{
		// if false, result of & was 0, so it means the hex bit was not set
		// in this case we expect a number in format Mode 2: 
		// (Real part + " " + Imaginary part + "i")
		
		input >> obj.real_part; // assume first value is the real part
		if (input.peek()=='i')
		{
			// if we got here we read the imaginary part first, no real part
			// input, so we set it to defult value of 1
			obj.imaginary_part = obj.real_part;
			obj.real_part = 1.0;
			input.ignore(); // skip over at end i
		}
		else
		{
			input >> obj.imaginary_part;
			if (input.peek() != 'i')
			{
				// invalid input for Mode 1
				// set failbit 
				input.clear(ios::failbit);
				return input;
			}
			input.ignore(); // skip over at end i
		}
	}

	// setting flags back to how they were when entering the function
	input.flags(origFlags);

	return input; // enables  cin >> a >> b >> c
}



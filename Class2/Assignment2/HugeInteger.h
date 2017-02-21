// HugerInteger interface file for Assignment 2: HugeInter.h
// Overload operators for HugeInteger class.
// Author: Bob Langelaan
// Date: January 30, 2014

// Author: Voicu Chirtes
// Date: May 5, 2015

#include <iostream>
#include <array>

class HugeInteger
{
// need to offer friendship to these 2 functions
	friend std::istream & operator >> (std::istream & src, HugeInteger & value);
	friend std::ostream & operator << (std::ostream & dest, const HugeInteger & value);
	friend bool operator +(const HugeInteger & RHS);

public:
	//ctor that converts a "long long" into a HugeInteger
	HugeInteger( long long value = 0LL ); //0LL is constant literal value 0
	                                      //   of type long long
	//ctor that converts a string into a HugeInteger
	HugeInteger( const char *str );

	//adds RHS into LHS (the object pointed to by the "this" pointer) and returns result
    HugeInteger & operator +=( const HugeInteger & RHS);

	//adds a "long long" (RHS) and LHS and puts result into a temp HugeInteger
	//   and returns result
	HugeInteger operator +( long long RHS) const; 

	//adds a string (which will be converted into a HugeInteger) with LHS into a temp 
	//       HugeInteger and returns result
	HugeInteger operator +( const char * RHS) const;

	//subtracts RHS from LHS (the object pointed to by the "this" pointer) and returns result
	HugeInteger & operator -=( const HugeInteger & RHS); 

	//subtracts a "long long" (RHS) from LHS and puts result into a temp HugeInteger 
	//    and returns result
	HugeInteger operator -( long long RHS) const; 

	//subtracts a string (which will be converted into a HugeInteger) from LHS 
	//    and puts result into a temp HugeInteger and returns result
	HugeInteger operator -( const char * RHS) const; 

	//calculates the negation of the object pointed to by the this pointer and returns result
	HugeInteger operator -(void) const;

	//calculates the absolute value of the object pointed to by the this pointer and returns result
	HugeInteger operator ~(void) const; // will overload ~ as abs operator

	//Is LHS (the object pointed to by the "this" pointer) equal to RHS
	bool operator ==( const HugeInteger & RHS) const;

	//Is LHS (the object pointed to by the "this" pointer) less than RHS
	bool operator <( const HugeInteger & RHS) const;

	//Is the object pointed to by the "this" pointer equal to zero
	bool operator !(void) const;

	//Convert a string into a HugeInteger
	void input( const char *str );

	// overload typecast to double
	operator double(void)const;

	// overload preincrement operator for the HugeInteger class
	HugeInteger & operator ++ (void);
	// overload postincrement operator for the HugeInteger class
	HugeInteger operator ++ (int);

	// overload predecrement operator for the HugeInteger class
	HugeInteger & operator -- (void);
	// overload postdecrement operator for the HugeInteger class
	HugeInteger operator -- (int);

private:
	bool negative;  // will be true if number is negative
	std::array<unsigned short,40> hugeInt; // each element in the array represents 
	                           //    one digit of the number
};

// Below are the implementations of the 5 inline global functions and the
//       prototypes for the 2 global functions that are implemented in
//       the HugeInteger.cpp file.

// NOTE: The 5 inline global functions should make use of the 3 public 
//       member functions that overload the ==, < and ! operators
//       Be careful to not re-invent the wheel!

//overloads the != operator for the HugeInteger class
inline bool operator !=( const HugeInteger & LHS, const HugeInteger &  RHS)
{
	// Voicu's implementation:
	return (!(LHS == RHS));
}

//overloads the > operator for the HugeInteger class
inline bool operator >( const HugeInteger & LHS, const HugeInteger & RHS)
{
	// Voicu's implementation:
	return (RHS<LHS);
}

//overloads the >= operator for the HugeInteger class
inline bool operator >=( const HugeInteger & LHS, const HugeInteger & RHS)
{
	// Voicu's implementation:
	return (!(LHS<RHS));
}

//overloads the <= operator for the HugeInteger class
inline bool operator <=( const HugeInteger & LHS, const HugeInteger &  RHS)
{
	// Voicu's implementation:
	return (!(RHS<LHS));
}

//overloads the unary + operator for the HugeInteger class
//  will return true if operand is != zero
inline bool operator +( const HugeInteger & RHS) // is not zero
{
	// Voicu's implementation:
	std::array<unsigned short, 40> temp = { 0 };
	return !((RHS.hugeInt == temp));
	//return !(RHS == 0);
}

//overloads the << and >> operators for the HugeInteger class
std::istream & operator >> (std::istream & src, HugeInteger & value);
std::ostream & operator << (std::ostream & dest, const HugeInteger & value);

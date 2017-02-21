// Assignment 4 COMP 2617: Fraction.cpp
// Member-function definitions for class Fraction.
// Author:  Voicu Chirtes
// Date: Feb 24, 2015

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>
using namespace std;

//Default constructor. Creates a Fraction = 0/1
Fraction::Fraction(void)
	: numerator(0),
	denominator(1)
{
	// empty body initialization using initializer list
}

// second ctor, which
// requires at least one long long argument
Fraction::Fraction(long long num, long long denom)
	: numerator(num),
	denominator(denom)
{
	simplify();
}

//Implementation of the plusEq() member function
//Performs similar operation as the += operator on the built-in types
const Fraction & Fraction::plusEq(const Fraction & op)
{
	// initial version of this function does not calculate in the most
	// efficient way, by finding the least common multiple
	// this can be inproved in a future version
	numerator = (numerator * op.denominator + op.numerator * denominator);
	denominator = denominator * op.denominator;

	//reduce the fraction to its simplest form
	simplify();

	return (*this);
}

//Implementation of the minusEq() member function
//Performs similar operation as the -= operator on the built-in types
const Fraction & Fraction::minusEq(const Fraction & op)
{
	// initial version of this function does not calculate in the most
	// efficient way, by finding the least common multiple
	// this can be inproved in a future version
	numerator = (numerator * op.denominator - op.numerator * denominator);
	denominator = denominator * op.denominator;

	//reduce the fraction to its simplest form
	simplify();

	return (*this);
}

//Implementation of the timesEq() member function
//Performs similar operation as the *= operator on the built-in types
const Fraction & Fraction::timesEq(const Fraction & op )
{
	numerator *= op.numerator;
	denominator *= op.denominator;

	simplify();  // will make sure that denominator is positive and
	             //   will invoke gcd() function to reduce fraction
	             //   as much as possible

	return (*this); // returns the object which invoked the method
}

//Implementation of the divideEq() member function
//Performs similar operation as the /= operator on the built-in types
const Fraction & Fraction::divideEq(const Fraction & op)
{
	numerator *= op.denominator;
	denominator *= op.numerator;

	//reduce the fraction to its simplest form
	simplify();

	return (*this);
}

// Implementation of the negate() member function 
// Returns the negation of the Fraction object invoked with 
// the method but does NOT modify the actual Fraction object invoked
Fraction Fraction::negate(void)const
{
	return (Fraction(-numerator,denominator));
}

// Returns numerator
long long Fraction::getNum(void)const
{
	return numerator;
}

// Returns denominator
long long Fraction::getDenom(void)const
{
	return denominator;
}

// Implementation of the display() member function that outputs 
// to standard output stream the Fraction object 
// in the format: numerator/denominator
void Fraction::display(void)const
{
	cout << numerator << "/" << denominator;
}

// this method reduces the Fraction objects as much as possible. 
// It also ensures that the denominator is positive.
void Fraction::simplify(void)
{
	//smallest possible GCD is 1
	const int MIN_GCD = 1;

	long long fractionGCD = gcd(numerator, denominator);

	// if they have a GCD greater than 1, simplify
	if (fractionGCD > MIN_GCD)
	{
		numerator /= fractionGCD;
		denominator /= fractionGCD;
	}

	//check denominator is positive, else flip signs
	if (denominator < 0)
	{
		denominator = -denominator;
		numerator = -numerator;
	}
}
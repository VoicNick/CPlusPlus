//Assignment 2b COMP 2617
//
// This is the solution for Assignemnt 2c, Chapter 4 Ex 34c 
// This program calculates the value of e to the power of x given the formula
// e^x = 1 + x/1! + x/2! + x/3!..., for a user input x between 1 to 709 inclusive
// with a level of accuracy, number of terms until the term value is less than 1.0E-20 
//
// Author:	Voicu Chirtes
// Date:	Feb 8, 2015

#include <iostream> // using a standard C++ library
#include <iomanip> // using a standard C++ library

using namespace std;

int main() //function main begins program execution
{
	const int X_MIN = 1;	// the min number of terms for calculating e^x value
	const int X_MAX = 709;	// the max number of terms for calculating e^x value
	const int DISPLAY_PRECISION = 12; // the precision for displaying e^x value
	const double E_POW_X_PRECISION = 1.0E-20; // precision for calculating e^x, smallest term

	double x = 0; // the x for calculating e^x
	double result = 1;
	double lastTerm = 1;
	int countTerms = 1; //the number of terms

	cout << "Input a value for x between " << X_MIN << " and "
		<< X_MAX << ": ";
	cin >> x;

	// ensure valid input
	while (cin.rdstate() || (x < X_MIN) || (x > X_MAX))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cerr << "Input a value for x between " << X_MIN << " and "
			<< X_MAX << ": ";
		cin >> x;
	}

	while (lastTerm > E_POW_X_PRECISION)
	{
		lastTerm = lastTerm  * (x / countTerms);
		countTerms++;
		result += lastTerm;
	}

	cout << setprecision(DISPLAY_PRECISION); //display settings

	cout << "\ne raised to the " << x << " power is: " << result << '\n' << endl;
	cout << "The number of terms computed is " << countTerms << '\n' << endl;
}

//Assignment 2b COMP 2617
//
// This is the solution for Assignemnt 2b, Chapter 4 Ex 34b 
// This program calculates the value of e given the formula
// e = 1 + 1/1! + 1/2! + 1/3! + ...
// with a level of accuracy, number of terms between 5 to 13 inclusive
//
// Author:	Voicu Chirtes
// Date:	Feb 8, 2015

#include <iostream> // using a standard C++ library
#include <iomanip>

using namespace std;

int main() //function main begins program execution
{
	const int E_MIN_PRECISION = 5;	// the min number of terms for calculating e value
	const int E_MAX_PRECISION = 13;	// the max number of terms for calculating e value
	const int DISPLAY_PRECISION = 11; // the precision for displaying e value

	int precision = 0; // the number of terms to compute e value for 
	double result = 1; // this will store the calculated result, initialized with first element, 1
	double lastTerm = 1;
	int countTerms = 1; //the number of terms

	cout << "The number of terms to compute is (" << E_MIN_PRECISION << " to "
		<< E_MAX_PRECISION << " are valid values): ";
	cin >> precision;
	
	// ensure valid input
	while (cin.rdstate() || (precision < E_MIN_PRECISION) || (precision > E_MAX_PRECISION))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cerr << "The number of terms to compute is (" << E_MIN_PRECISION << " to "
			<< E_MAX_PRECISION << " are valid values): ";
		cin >> precision;
	}

	// the loop needs to run until (precision - 1), as first element is 1, already initialized in the result
	for (int i = 1; i < precision; i++)
	{
		lastTerm = lastTerm  * (1 / (double)countTerms);
		countTerms++;
		result += lastTerm;
	}

	cout << fixed << setprecision(DISPLAY_PRECISION); //display settings for e value

	cout << "\nThe value of e is " << result << '\n' << endl;
}
// GCD.h contains the gcd() template function that 
// determines the Greatest Common Divisor for two arguments
// this is part of the Assignment 4 COMP 2617
// Author: Voicu Chirtes
// Date: Feb 23, 2015

// template that returns GCD of two arguments
template <typename T>
T gcd(T n1, T n2)
{
	//smallest possible GCD is 1
	const T MIN_GCD = 1;

	//convert both arguments to positive values
	n1 = (n1 < 0) ? -n1 : n1;
	n2 = (n2 < 0) ? -n2 : n2;

	//start searching at smallest argument and go down to 1
	T result = (n1 < n2) ? n1 : n2;

	while ((result > MIN_GCD) && ((n1 % result != 0) || (n2 % result != 0)))
	{
		result--;
	}

	return result;
}
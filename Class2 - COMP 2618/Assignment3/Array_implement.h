// Assignment 3 COMP 2618, Voicu Chirtes
// This is the Template class implementation for the 
// Array class template as required on the Assignment 3
// the class definition is in Array.h file
//
// Author: Voicu Chirtes
// Date: May 5, 2015

#include <iostream>
#include <iomanip>
#include <stdexcept> 

#include "Array.h" // Array class definition
using namespace std;

// initializing the static data member that tracks the
// number of objects CURRENTLY instantiated from this template
template <typename T, size_t S>
int Array<T,S>::arrayCount = 0;

template <typename T, size_t S>
Array<T,S>::Array()
{
	// increment number of objects instantiated from this template
	arrayCount++;
	// nothing else to do here, will rely on type ctor to initialize
} // end Array default constructor


// destructor for class Array
template <typename T, size_t S>
Array<T,S>::~Array()
{
	// decrement number of objects instantiated from this template
	arrayCount--;
} // end destructor

// return number of elements of Array
template <typename T, size_t S>
size_t Array<T, S>::getSize() const
{
   return this->size; // number of elements in Array
} // end function getSize

// determine if two Arrays are equal and
// return true, otherwise return false
template <typename T, size_t S>
bool Array<T, S>::operator==(const Array<T, S> &right) const
{
   if ( this->size != right.size ){
      return false; // arrays of different number of elements
   }

   for ( size_t i = 0; i < this->size; ++i ){
	   if (this->theArray[i] != right.theArray[i])
	  {
         return false; // Array contents are not equal
	  }
   }

   return true; // Arrays are equal
} // end function operator==

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
template <typename T, size_t S>
T & Array<T, S>::operator[](int subscript)
{
   // check for subscript out-of-range error
   if ( subscript < 0 || subscript >= this->size ){
      throw out_of_range( "Subscript out of range" );
   }

   return this->theArray[ subscript ]; // reference return
} // end function operator[]

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
template <typename T, size_t S>
T Array<T, S>::operator[](int subscript) const
{
   // check for subscript out-of-range error
   if ( subscript < 0 || subscript >= this->size ){
      throw out_of_range( "Subscript out of range" );
   }

   return this->theArray[ subscript ]; // returns copy of this element
} // end function operator[]

// input the array elements
template <typename T, size_t S>
void Array<T,S>::inputArray()
{
	for (size_t i = 0; i < this->size; ++i)
	{
		cin >> this->theArray[i];
	}
}

// output the array elements
template <typename T, size_t S>
void Array<T, S>::outputArray() const
{
	for (size_t i = 0; i < this->size; ++i)
	{
		cout << this->theArray[i] << " ";
	}
	cout << endl;
}

// returns the number of objects CURRENTLY instantiated from this template
template <typename T, size_t S>
int Array<T,S>::getArrayCount()
{
	return arrayCount;
}

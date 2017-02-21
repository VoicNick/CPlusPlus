// Assignment 3 COMP 2618, Voicu Chirtes
// This is the Template class definition for the 
// Array class template as required on the Assignment 3
// the class implementation is in Array_implement.h file
//
// Author: Voicu Chirtes
// Date: May 5, 2015

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename elementType = int, size_t numberOfElements = 5>
class Array
{
public:
   explicit Array(); // default constructor
   ~Array(); // destructor

   size_t getSize() const; // return size

   bool operator==( const Array & ) const; // equality operator

   // inequality operator; returns opposite of == operator
   bool operator!=( const Array &right ) const  
   { 
      return ! ( *this == right ); // invokes Array::operator==
   } // end function operator!=
   
   // subscript operator for non-const objects returns modifiable lvalue
   elementType &operator[](int);

   // subscript operator for const objects returns rvalue
   elementType operator[](int) const;

   void inputArray(); // input the array elements
   void outputArray() const; // output the array elements

   // returns the number of objects CURRENTLY instantiated from this template
   static int getArrayCount(); 

private:
	// C-style array size
   size_t size=numberOfElements; 
   // C-style based array
   elementType theArray[numberOfElements];
   // tracks the number of objects CURRENTLY instantiated from this template
   static int arrayCount;
}; // end class Array

#include "Array_implement.h"

#endif
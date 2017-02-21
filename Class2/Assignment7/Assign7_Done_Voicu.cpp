// Assignment 7: Assign07.cpp, Voicu Chirtes
// Original date: November 28, 2014
// Original Author: Bob Langelaan
// 
// Date: June 16, 2015
// Author: Voicu Chirtes

// Note: This site will be usefull for this assignment:
// http://www.cplusplus.com/reference/
// Note that algorithms are under the "Other" category

#include <iostream>
#include <ctime>
#include <random> // needed to generate random #'s the C++ 11 manner
#include <vector>   // parts 1 to 5
#include <list>     // parts 6, 7 & 10
#include <deque>    // parts 8 & 9
#include <set>      // parts 11 & 13
#include <algorithm>

using namespace std;

const size_t four_billion = 4000000000;
const size_t four_hundred_million = 400000000;
const size_t forty_million = 40000000;
const size_t four_million = 4000000;
const size_t four_hundred_thousand = 400000;
const size_t forty_thousand = 40000;
const size_t one_thousand = 1000;
const size_t four_hundred = 400;

int main()
{

	time_t start_time;    /* used to store starting time */
	time_t end_time;      /* used to store end time */
	time_t total_time;    /* used to compute total time to compute solution */

	int part = 1; // used to display current part 

	default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<size_t> randomInt(1, four_billion); // 1 to 4 billion

	// Part 1 - Goal: To populate a vector of 40 million elements with random values between 
	//          1 and 4 billion and sort them using the sort() algorithm.

	// NOTE: The vector is created/initialized with with 40 million elements (size() == 40 million)

	start_time = time(NULL); // record start time

	{

		vector<size_t> v1(forty_million);

		for (int i = 0; i < forty_million; ++i){
			v1[i] = randomInt(engine);// random number 1 to 4 billion
		}

		sort(v1.begin(), v1.end());

	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;

	// Part 2 - Goal: To populate a vector of 40 million elements with random values between 
	//          1 and 4 billion and sort them using a stable_sort() algorithm

	// NOTE: The vector is created/initialized with with 40 million elements (size() == 40 million)

	start_time = time(NULL); // record start time

	{
		vector<size_t> v2(forty_million);

		for (int i = 0; i < forty_million; ++i)
		{
			v2[i] = randomInt(engine);// random number 1 to 4 billion
		}

		stable_sort(v2.begin(), v2.end());
	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;

	// Part 3 - Goal: To populate a vector of 40 million elements with random values between 
	//          1 and 4 billion and then sort them using the sort() algorithm

	// NOTE: The vector is created/initialized empty (size() == 0)

	start_time = time(NULL); // record start time

	{
		vector<size_t> v3; // vector with size 0

		for (int i = 0; i < forty_million; ++i)
		{
			v3.push_back(randomInt(engine));// random number 1 to 4 billion
		}

		sort(v3.begin(), v3.end());
	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;

	// Part 4 - Goal: To populate a vector of 40 million elements with random values between 
	//          1 and 4 billion while using some of the heap algorithms demonstrated in Fig. 16.12

	// Add elements to vector using push_back and push_heap.  When all elements have been added to the vector
	//          finish with sort_heap.

	// NOTE: The vector is created/initialized empty (size == 0)

	start_time = time(NULL); // record start time

	{
		vector<size_t> v4; //vector with size 0

		for (int i = 0; i < forty_million; ++i)
		{
			v4.push_back(randomInt(engine));// random number 1 to 4 billion
			push_heap(v4.begin(), v4.end());
		}

		sort_heap(v4.begin(), v4.end());
	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;

	// Part 5 - Goal: To populate a vector of 40 million elements with random values between 
	//          1 and 4 billion and use some of the heap algorithms demonstrated in Fig. 16.12

	// This time add elements to vector using push_back.  When all elements have been added to the vector
	//          finish with make_heap and then sort_heap.

	// NOTE: The vector is created/initialized empty (size == 0)

	start_time = time(NULL); // record start time

	{
		vector<size_t> v5; //vector with size 0

		for (int i = 0; i < forty_million; ++i)
		{
			v5.push_back(randomInt(engine));// random number 1 to 4 billion
		}
		make_heap(v5.begin(), v5.end());
		sort_heap(v5.begin(), v5.end());
	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;

	// Part 6 - Goal: To populate a list of 40 thousand elements with random values between 
	//          1 and 4 billion. No sort will be necessary since new values will be merged into the main
	//          list one element at a time.

	// Create a second list to which you will add one item and then use the list mmember function merge and _NOT_ the merge()
	//          algorithm to merge into the main list.  Repeat until all of the elements have been added to the main list.

	// NOTE: The 2 lists are created/initialized empty (size == 0)

	start_time = time(NULL); // record start time

	{
		list <size_t> l6_1, l6_2; // two empty lists

		for (int i = 0; i < forty_thousand; ++i)
		{
			l6_2.push_back(randomInt(engine));
			l6_1.merge(l6_2); // l6_2 is always sorted as it has only one element
		}
	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;

	// Part 7 - Goal: To populate a list of 400 thousand elements with random values between 1 and 4 billion. No 
	//          sort will be necessary because new elements will be merged into the main list 400 elements at a time.

	// Create a second list to which you will add 400 new items, sort() and then use merge() to merge into the main list.
	//          Repeat 1000 times (400 * 1000 == 400 thousand).  Again, as with Part 6, you will be using the list member 
	//          function merge and not the merge() algorithm. Hint: Use nested for loops.

	// NOTE: The 2 lists are created/initialized empty (size == 0)

	start_time = time(NULL); // record start time

	{
		list<int> l7_1, l7_2; // two empty lists

		for (int i = 0; i < one_thousand; ++i)
		{
			for (int j = 0; j < four_hundred; ++j)
			{
				l7_2.push_back(randomInt(engine));
			}
			l7_2.sort();
			l7_1.merge(l7_2);
		}
	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;

	// Part 8 - Goal: To populate a deque of 40 million elements with random values between 
	//          1 and 4 billion and then sort using the sort() algorithm

	// NOTE: The deque is created/initialized with 40 million elements (size() == 40 million)

	start_time = time(NULL); // record start time

	{
		deque<int> d7(forty_million); //deque with 40 milion elements

		for (int i = 0; i < forty_million; ++i)
		{
			d7.insert(d7.end(),randomInt(engine));
		}

		sort(d7.begin(), d7.end());
	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;

	// Part 9 - Goal: To populate a deque of 40 million elements with random values between 
	//          1 and 4 billion and then sort via sort() algorithm

	// Add elements to deque with push_back method.

	// NOTE: The deque is created/initialized empty (size() == 0)

	start_time = time(NULL); // record start time

	{
		deque<int> d9; //empty deque

		for (int i = 0; i < forty_million; ++i)
		{
			d9.push_back(randomInt(engine));
		}

		sort(d9.begin(), d9.end());
		// You supply missing contents here :)

	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;
	
	// Part 10 - Goal: To populate a C-style array of 40 million elements with random values between 
	//          1 and 4 billion and then sort via sort() algorithm. Note that you should use the new 
	//          operator to allocate the array.

	// NOTE: The array is created/initialized with with 40 million elements using new operator.

	start_time = time(NULL); // record start time

	{
		int *a10 = new int[forty_million]; // forty milion elements on heap

		for (int i = 0; i < forty_million; ++i)
		{
			a10[i] = randomInt(engine);
		}

		sort(a10, a10+forty_million);

		// release memory, a bit redundant as it goes out of scobe after next line
		delete[] a10; 
	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;
	
	// Part 11 - Goal: To populate a multiset of 4 million elements with random values between 
	//          1 and 4 billion.  Note that multiset automatically sorts data so no explicit sort is required.

	// NOTE: The multiset is created/initialized with 0 elements (size() == 0)

	start_time = time(NULL); // record start time

	{
		multiset<int> m11;

		for (int i = 0; i < four_million; ++i)
		{
			m11.insert(randomInt(engine));
		}
	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;

	// Part 12 - Goal: To populate a list of 4 million elements with random values between 
	//          1 and 4 billion.  Then sort the list using the sort() member function (not the sort() algorithm).
	//          Lastly use the unique() member function to remove duplicates.

	// NOTE: The list is created/initialized with 0 elements (size() == 0)

	start_time = time(NULL); // record start time

	{
		list<int> l12;

		for (int i = 0; i < four_million; ++i)
		{
			l12.push_back(randomInt(engine));
		}

		l12.sort(); // sort list
		l12.unique(); // remove duplicates
		
	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;

	// Part 13 - Goal: To populate a set of 4 million elements with random values between 
	//          1 and 4 billion.  This container automatically sorts values and does not insert duplicates.

	// NOTE: The set is created/initialized with 0 elements (size() == 0)

	start_time = time(NULL); // record start time

	{
		set<int> s13;

		for (int i = 0; i < four_million; ++i)
		{
			s13.insert(randomInt(engine));
		}
	}

	end_time = time(NULL); // record end time
	total_time = end_time - start_time; // calculate time to compute
	cout << "It took " << static_cast<long>(total_time) << " seconds to compute Part " << part++ << "\n" << endl;

	system("pause");

} // end main

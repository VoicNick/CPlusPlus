//Assignment 3 COMP 2617
// This program generates and tests multiplication
// for numbers 0 to 9 and gives feedback with random
// comments.
//
// This is the solution for Assigment , Chapter 6 Ex 58 
//
// Author:	Voicu Chirtes
// Date:	Feb 18, 2015

// standard C++ libraries
# include <iostream> 
# include <cstdlib> 
# include <ctime> 
# include <string>

using namespace std;

//multiplication tests function
void multiplication(); 

// print correct message
void correctMessage(); 

//print incorect message
void incorrectMessage(); 

//get an int from input
int getAnswer();


int main() //function main begins program execution
{
	multiplication();
}

//multiplication tests function
void multiplication()
{
	//we generate numbers 1 to 9
	const int SCALING_FACTOR = 10;
	const int SHIFT = 0;
	const int EXIT_CONDITION = -1;

	int answer = 0;

	//seed the rand to get different numbers
	srand(static_cast<unsigned int>(time(0)));

	cout << "Enter -1 to End." << endl;
	while (answer != EXIT_CONDITION)
	{
		int number1 = SHIFT + rand() % SCALING_FACTOR;
		int number2 = SHIFT + rand() % SCALING_FACTOR;
		cout << "How much is " << number1 << " times " 
			<< number2 << " (" << EXIT_CONDITION <<" to End)? ";

		answer = getAnswer();

		while ((answer != (number1*number2))  && (answer != EXIT_CONDITION))
		{
			incorrectMessage();
			cout << "? ";
			answer = getAnswer();

		} //end inner while loop

		if (answer == (number1*number2))
		{
			correctMessage();
		}
		else
		{
			cout << "\nThat's all for now. Bye." << endl;
			// incorrectMessage();
		}
	} // end main while loop
} //end multiplication() function

// print correct message
void correctMessage()
{
	const int GOOD_RESPONSES_COUNT = 4;
	const string GOOD_RESPONSES[GOOD_RESPONSES_COUNT] =
	{
		"Very good!",
		"Excellent!",
		"Nice work!",
		"Keep up the good work!"
	};
	cout << GOOD_RESPONSES[rand() % GOOD_RESPONSES_COUNT] << '\n' << endl;
} //end correctMessage() function

//print incorect message
void incorrectMessage()
{
	const int BAD_RESPONSES_COUNT = 4;
	const string BAD_RESPONSES[BAD_RESPONSES_COUNT] =
	{
		"No.Please try again.",
		"Wrong.Try once more.",
		"Don't give up!",
		"No.Keep trying."
	};
	cout << BAD_RESPONSES[rand() % BAD_RESPONSES_COUNT] << endl;

} //end incorectMessage() function

//get an int from input
int getAnswer()
{
	int response;
	cin >> response;

	//validate the answer
	while (cin.rdstate())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cerr << "Invalid input entered - try again: ";
		cin >> response;
	}
	return response;
} //end getAnswer() function
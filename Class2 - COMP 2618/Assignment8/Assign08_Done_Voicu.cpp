// Assignment 8 COMP 2618
// Exercise 21.11 of the text - the hangman game
//
// Author: Voicu Chirtes
// Date: June 29, 2015

#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>
using namespace std;

//function used to draw the hangman
void draw(int i);

int main()
{
	// max words in the pool (array) of words
	const size_t MAX_WORDS = 10; 

	//max guesses, correct and incorrect
	const int MAX_GUESSES = 50;

	//max incorect guesses
	const int MAX_INCORRECT_GUESSES = 7;

	//the pool of possible words to guess
	array <string, MAX_WORDS> words =
	{ "REVERSE", "VECTOR", "EXERCISE", "LIBRARY", "OBJECT",
	"INHERIT", "BINARY", "SCOPE", "EXACTLY", "STREAM" };

	//enum to keep track of game status
	enum Status { CONTINUE, WON, LOST, QUIT };
	Status gameStatus = CONTINUE;

	default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> randomInt(0, MAX_WORDS - 1);

	//main program loop, until quit
	while (QUIT != gameStatus)
	{
		//index for guessed lettters array
		int guessNo = 0; 
		int incorrectGuesses = 0;

		//pick a random word
		string correctWord = words[randomInt(engine)];

		//guessed word, build using ? wildcard
		string guessedWord(correctWord.length(), '?');

		//store guessed letters
		array <char, MAX_GUESSES> letters = {};

		cout << "Guess the word: " << string(correctWord.length(), 'X') << endl << endl;

		//one game loop, until win or loose
		while (CONTINUE == gameStatus)
		{
			char tempLetter;
			bool existingLetter = false;
			bool invalidLetter = false;

			//read and validate a letter
			do
			{
				cout << "\nGuess a letter: " << guessedWord << "\n?";
				cin >> tempLetter;

				//read and make letter to upper case
				tempLetter = toupper(tempLetter);

				//ensure is a letter only
				if (!isalpha(tempLetter))
				{
					cout << "Letters only\n";
					invalidLetter = true;
				}
				else
				{
					invalidLetter = false;
				}

				//ensure is not already guessed
				existingLetter = false;
				for (char letter : letters)
				{
					if (letter == tempLetter)
					{
						existingLetter = true;
						cout << "'" << tempLetter << "' was already guessed.  Try another letter\n";
					}
				}
			} while (existingLetter || invalidLetter);


			letters[guessNo] = tempLetter;

			// if letter is correct update guessed word
			bool correctLetter = false;
			for (unsigned int i = 0; i <= correctWord.length(); i++)
			{
				if (correctWord[i] == letters[guessNo])
				{
					guessedWord[i] = correctWord[i];
					correctLetter = true;
				}
			}
			cout << endl;

			++guessNo;

			if (!correctLetter)
			{
				incorrectGuesses++;
			}

			//drwaw hangman
			draw(incorrectGuesses);

			cout << "\nYour guesses:" << endl;

			for (char letter : letters)
			{
				cout << " " << letter;
			}

			//if word is guessed status is WON
			if (guessedWord == correctWord)
			{
				gameStatus = WON;
				cout << "\nWord: " << correctWord
					<< "\n\n\nCongratulations!!!You guessed my word.\n\n " << endl;
			}
			else
			{
				// verify if we reached max guesses limit
				if (incorrectGuesses >= MAX_INCORRECT_GUESSES)
				{
					gameStatus = LOST;
					cout << "\n\nSorry - you have run out of guesses ;-(\n"
						<< "The correct answer was : " << correctWord
						<< "\n\n...GAME OVER...\n\n\n";
				}
			}

		} // end one game loop, until win or loose

		cout << "Play again ? (y/n) ";
		char answer;
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			gameStatus = CONTINUE;
		}
		else
		{
			gameStatus = QUIT;
		}
	}//end main program loop


	return 0;
}


void draw(int i)
{
	switch (i)
	{
	case 1:
		cout << " o" << endl;
		break;
	case 2:
		cout << " o\n/" << endl;
		break;
	case 3:
		cout << " o\n/|" << endl;
		break;
	case 4:
		cout << " o" << endl << "/|\\" << endl;
		break;
	case 5:
		cout << " o\n/|\\\n |" << endl;
		break;
	case 6:
		cout << " o\n/|\\\n |\n/" << endl;
		break;
	case 7:
		cout << " o\n/|\\\n |\n/ \\ " << endl;
		break;
	default:
		cout << "";
		break;
	}

}

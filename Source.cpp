#include <iostream>
#include <ctime>
#include <string>
using namespace std;

//GridSize variables to make the grid as large or as small as the user wants
int GridSizeX = 8;
int GridSizeY = 8;
int GridSize = GridSizeX * GridSizeY;

//These variables initialize the 8x8 grid
int High = GridSize;
int Low = 1;

//Variable to handle how many guesses it takes
int HCounter;
int RCounter;
int LCounter;
int BCounter;

//Variable to hold the guesses
int HGuess;
int BGuess;
int RGuess;


//Variable to hold the actual position of the enemy
int Real;



//Boolean variable to handle the loop
bool HLoop;
bool BLoop;
bool LLoop;
bool RLoop;
bool YNLoop = true;

string YNAnswer;

int main()
{
	//Randomizer seed to make each play through truly random
	srand(time(NULL));

	do {
		// Lines 47-60: Resets the values so the program can be played multiple times
		HLoop = false;
		BLoop = false;
		LLoop = false;
		RLoop = false;
		HCounter = 1;
		RCounter = 1;
		LCounter = 1;
		BCounter = 1;
		HGuess = 0;
		BGuess = 0;
		RGuess = 0;
		High = GridSize;
		Low = 1;
		
		//The real position is randomly chosen at first
		Real = rand() % (GridSize - 1) + 1;

		//Human input:
		cout << "*********************************" << endl;
		cout << "************  Human  ************" << endl;
		cout << "************  Guess  ************" << endl;
		cout << "*********************************" << endl;

		cout << endl << "You are going to guess a number between 1 and " << GridSize << endl;

		//While the human has guessed incorrectly...
		while (HLoop == false)
		{
			//Ask for a guess...
			cout << "What is your guess, human?" << endl << "Guess: ";
			cin >> HGuess;

			//If the Human guesses too high...
			if (HGuess > Real)
			{
				cout << "Guess is too high. Try again." << endl << endl;

				//Adds to guesses
				HCounter += 1;
				//Makes sure the enemy is not found yet
				HLoop = false;
			}
			//If the Human guesses too low...
			else if (HGuess < Real)
			{
				cout << "Guess is too low. Try again." << endl << endl;

				//Adds to guesses
				HCounter += 1;
				//Makes sure the enemy is not found yet
				HLoop = false;

			}
			//If Human has found the enemy...
			else
			{
				cout << "Correct! Next Skynet Loading..." << endl;
				//End the loop and neutralize the enemy
				HLoop = true;
			}
		}

		cout << "*********************************" << endl;
		cout << "************  Random ************" << endl;
		cout << "************  Guess  ************" << endl;
		cout << "*********************************" << endl;

		//While Random Skynet has not found the enemy yet...
		while (RLoop == false)
		{
			//Guess a random number
			RGuess = rand() % (GridSize - 1) + 1;

			//If that random guess is the real answer...
			if (RGuess == Real)
			{
				//End the loop
				cout << "Enemy at " << RGuess << "." << endl;
				cout << "Next Skynet Loading..." << endl;
				RLoop = true;
			}
			//If that random guess is not the real answer...
			else
			{
				cout << "Enemy not at " << RGuess << ". Recalculating..." << endl;
				RCounter += 1;
				RLoop = false;
			}
		}



		cout << "*********************************" << endl;
		cout << "************  Linear ************" << endl;
		cout << "************  Guess  ************" << endl;
		cout << "*********************************" << endl;

		//While Linear Skynet has not found the enemy...
		while (LLoop == false)
		{
			//If Linear Skynet has found the enemy...
			if (LCounter == Real)
			{
				cout << "Enemy at " << LCounter << "." << endl;
				//End the loop
				cout << "Next Skynet loading..." << endl;
				LLoop = true;
			}
			//If Linear Skynet has not found the enemy...
			else
			{
				//Keep the loop going until the counter equals the real answer
				cout << "Enemy not at " << LCounter << ". Recalculating..." << endl;
				LCounter += 1;
				LLoop = false;
			}
		}



		cout << "*********************************" << endl;
		cout << "************  Binary ************" << endl;
		cout << "************  Guess  ************" << endl;
		cout << "*********************************" << endl;

		//Initializes Binary Guess
		BGuess = ((High - Low) / 2) + Low;

		//While the enemy is not found...
		while (BLoop == false)
		{
			//...give the current guess...
			cout << "Target: " << BGuess << endl;

			//...and if Binary Skynet guesses too high...
			if (BGuess > Real)
			{
				//The guess becomes the new high
				High = BGuess;
				//Skynet uses its binary search system to get a new guess
				BGuess = ((High - Low) / 2) + Low;
				cout << "Enemy position is at a lower position. Recalculating..." << endl << "-------------------------------------------------" << endl;

				//Adds to guesses
				BCounter += 1;
				//Makes sure the enemy is not found yet
				BLoop = false;
			}
			//If skynet guesses too low...
			else if (BGuess < Real)
			{
				//The guess becomes the new low
				Low = BGuess;
				//Skynet uses its binary search system to get a new guess
				BGuess = ((High - Low) / 2) + Low;
				cout << "Enemy is at a higher position. Recalculating..." << endl << "-------------------------------------------------" << endl;
				//Adds to guesses

				BCounter += 1;
				//Makes sure the enemy is not found yet
				BLoop = false;

			}
			//If Skynet has found the enemy...
			else
			{
				cout << "Correct! Final results loading..." << endl;
				//End the loop and neutralize the enemy
				BLoop = true;
			}
		}

		//Outputs the final "scores" of each run
		cout << "Human was able to locate the enemy in " << HCounter << " tries in a(n) " << GridSizeX << "x" << GridSizeY << " grid." << endl;
		cout << "Random Skynet was able to locate the enemy in " << RCounter << " tries in a(n) " << GridSizeX << "x" << GridSizeY << " grid." << endl;
		cout << "Linear Skynet was able to locate the enemy in " << LCounter << " tries in a(n) " << GridSizeX << "x" << GridSizeY << " grid." << endl;
		cout << "Binary Skynet was able to locate the enemy in " << BCounter << " tries in a(n) " << GridSizeX << "x" << GridSizeY << " grid." << endl << endl;

		cout << "Would you like to play again?" << endl;
		cout << "Answer (Y/N): ";
		cin >> YNAnswer;

		//Checks to see if the player wants to run the program again
		if (YNAnswer == "Y")
		{
			YNLoop = true;
		}
		else if (YNAnswer == "N")
		{
			YNLoop = false;
		}
		else
		{
			cout << "...I'm going to assume you want to continue";
			YNLoop = true;
		}
	} while (YNLoop == true);
}
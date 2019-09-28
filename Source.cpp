#include <iostream>
#include <ctime>
using namespace std;

//GridSize variables to make the grid as large or as small as the user wants
int GridSizeX = 7;
int GridSizeY = 5;
int GridSize = GridSizeX * GridSizeY;

//These variables initialize the 8x8 grid
int High = GridSize;
int Low = 1;

//Variable to handle how many guesses it takes
int counter = 1;

//Variable to hold the guesses
int HGuess;
int BGuess;
int RGuess;


//Variable to hold the actual position of the enemy
int Real;



//Boolean variable to handle the loop
bool HLoop = false;
bool BLoop = false;
bool LLoop = false;
bool RLoop = false;



int main()
{
	//Randomizer seed to make each play through truly random
	srand(time(NULL));

	//The real position and Skynet's guess are randomly chosen at first
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
			cout << "Guess is too high. Try again." << endl;
		
			//Adds to guesses
			counter += 1;
			//Makes sure the enemy is not found yet
			HLoop = false;
		}
		//If the Human guesses too low...
		else if (HGuess < Real)
		{
			cout << "Guess is too low. Try again." << endl;

			//Adds to guesses
			counter += 1;
			//Makes sure the enemy is not found yet
			HLoop = false;

		}
		//If Human has found the enemy...
		else
		{
			cout << "Correct!" << endl;
			//End the loop and neutralize the enemy
			HLoop = true;
		}
	}

	cout << "Human has found the enemy in " << counter << " tries" << endl << endl << endl;

	//Resets the counter to use again
	counter = 0;

	cout << "*********************************" << endl;
	cout << "************  Binary ************" << endl;
	cout << "************  Guess  ************" << endl;
	cout << "*********************************" << endl;

	//Initializes Binary Guess
	BGuess = ((High - Low) / 2) + Low;

	cout << "Enemy at: " << Real << endl << endl;

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
			BGuess= ((High - Low) / 2) + Low;
			cout << "Enemy position is at a lower position. Recalculating..." << endl << "-------------------------------------------------" << endl;

			//Adds to guesses
			counter += 1;
			//Makes sure the enemy is not found yet
			BLoop = false;
		}
		//If skynet guesses too low...
		else if (BGuess< Real)
		{
			//The guess becomes the new low
			Low = BGuess;
			//Skynet uses its binary search system to get a new guess
			BGuess = ((High - Low) / 2) + Low;
			cout << "Enemy is at a higher position. Recalculating..." << endl << "-------------------------------------------------" << endl;
			//Adds to guesses

			counter += 1;
			//Makes sure the enemy is not found yet
			BLoop = false;

		}
		//If Skynet has found the enemy...
		else
		{
			//End the loop and neutralize the enemy
			BLoop = true;
		}
	}
	cout << "Enemy spotted at " << BGuess << ". Binary Skynet was able to locate the enemy in " << counter << " tries in a(n) " << GridSizeX << "x" << GridSizeY <<" grid." << endl << endl << endl;

	counter = 1;


	cout << "*********************************" << endl;
	cout << "************  Linear ************" << endl;
	cout << "************  Guess  ************" << endl;
	cout << "*********************************" << endl;

	//While Linear Skynet has 
	while (LLoop == false)
	{
		if (counter == Real)
		{
			cout << "Linear Skynet found the enemy at " << counter << " in " << counter << " tries." << endl << endl << endl;
			LLoop = true;
		}

		else
		{
			cout << "Enemy not at " << counter << ". Recalculating..." << endl;
			counter += 1;
			LLoop = false;
		}
	}

	counter = 0;


	cout << "*********************************" << endl;
	cout << "************  Random ************" << endl;
	cout << "************  Guess  ************" << endl;
	cout << "*********************************" << endl;
	
	while (RLoop == false)
	{
		counter += 1;
		RGuess = rand() % (GridSize - 1) + 1;
		if (RGuess == Real)
		{
			cout << "Random Skynet found the enemy at " << RGuess << " in " << counter << " tries." << endl;
			RLoop = true;
		}
		else
		{
			cout << RGuess << endl;
			RLoop = false;
		}
	}
}
#include <iostream>
#include <ctime>
using namespace std;

//These variables initialize the 8x8 grid
int High = 64;
int Low = 1;

//Variable to hold the Skynet guess
int Guess;
//Variable to hold the actual position of the enemy
int Real;

//Boolean variable to handle the loop
bool Loop = 0;

//Variable to handle how many guesses it takes
int counting = 1;

int main()
{
	//Randomizer seed to make each play through truly random
	srand(time(NULL));

	//The real position and Skynet's guess are randomly chosen at first
	Real = rand() % 63 + 1;
	Guess = rand() % 63 + 1;

	cout << "Enemy at: " << Real << endl << endl;

	//While the enemy is not found...
	while (Loop == 0)
	{
		//...give the current guess...
		cout << "Target: " << Guess << endl;

		//...and if Skynet guesses too high...
		if (Guess > Real)
		{
			//The guess becomes the new high
			High = Guess;
			//Skynet uses its binary search system to get a new guess
			Guess = ((High - Low) / 2) + Low;
			cout << "Enemy position is at a lower position. Recalculating..." << endl << "-------------------------------------------------" << endl;

			//Adds to guesses
			counting += 1;
			//Makes sure the enemy is not found yet
			Loop = 0;
		}
		//If skynet guesses too low...
		else if (Guess < Real)
		{
			//The guess becomes the new low
			Low = Guess;
			//Skynet uses its binary search system to get a new guess
			Guess = ((High - Low) / 2) + Low;
			cout << "Enemy is at a higher position. Recalculating..." << endl << "-------------------------------------------------" << endl;
			//Adds to guesses

			counting += 1;
			//Makes sure the enemy is not found yet
			Loop = 0;

		}
		//If Skynet has found theenemy...
		else
		{
			//End the loop and neutralize the enemy
			Loop = 1;
		}
	}
	cout << "Enemy spotted at " << Guess << ". Skynet was able to locate the enemy in " << counting << " tries in an 8x8 grid." << endl;
}
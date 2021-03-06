#include "stdafx.h"
#include <iostream>
#include <random> // for std::random_device and std::mt19937


int getGuess(int lives)
{
	std::cout << "Guess #" << lives << ": ";
	int guess;
	std::cin >> guess;
	return guess;
}

void giveHint(int guess, int answer)
{
	if (guess < answer)
	{
		std::cout << "Higher" << std::endl;
	}
	else
	{
		std::cout << "Lower" << std::endl;
	}
}


bool playAgain()
{
	char reply{ ' ' };
	while (true)
	{
		std::cout << "Would you like to play again? (y/n) : ";
		std::cin >> reply;

		if (reply == 'y')
		{
			return true;
		}
		else if (reply == 'n')
		{
			return false;
		}

	}


}


int main()
{
	bool stillPlaying{ true };
	while (stillPlaying)
	{
		std::random_device rd;
		std::mt19937 mersenne(rd()); // Create a mersenne twister, seeded using the random device

									 // Create a reusable random number generator that generates uniform numbers between 1 and 6
		std::uniform_int_distribution<> die(1, 100);

		std::cout << "Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is." << std::endl;

		int answer{ die(mersenne) };

		for (int lives{ 1 }; lives <= 7; ++lives)
		{
			int guess{ getGuess(lives) };
			if (guess == answer)
			{
				std::cout << "Correct! You win!" << std::endl;
				return playAgain();
			}
			else
			{
				giveHint(guess, answer);
			}
		}
		stillPlaying = playAgain();
	}
	
	
}
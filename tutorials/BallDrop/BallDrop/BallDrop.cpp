// BallDrop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "constants.h"

double getHeight()
{
	std::cout << "Enter the initial height: ";
	double initialHeight;
	std::cin >> initialHeight;
	return initialHeight;
}

void printHeight(int time, double height)
{
	std::cout << "At " << time << " seconds the ball is at a height of " << height << std::endl;
}

double calculateHeight(int time, double height)
{
	double currentHeight{ height - ((myConstants::gravity * (time * time)) / 2) };
	if (currentHeight >= 0.0)
	{
		return currentHeight;
	}
	return 0.0;
}


int main()
{
	double height{ getHeight() };
	int time{ 0 };
	while (height > 0.0) 
	{
		height = calculateHeight(time, height);
		printHeight(time, height);
		time += 1;
		
	}


    return 0;
}


// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int getUserInput();
int getMathematicalOperation();
int calculateResult(int input1, char op, int input2);
void printResult(int result);

int getUserInput()
{
	std::cout << "Enter number: ";
	int input;
	std::cin >> input;
	return input;
}

int getMathematicalOperation()
{
	char op = ' ';
	while (op == ' ')
	{
		std::cout << "Enter an operator: ";
		char input;
		std::cin >> input;
		if (input == '+'|| input == '-' || input == '*' || input == '/')
		{
			op = input;
		}
	}
	return op;

}

int calculateResult(int input1, char op, int input2)
{
	if (op == '+')
	{
		return (input1 + input2);
	}
	if (op == '-')
	{
		return (input1 - input2);
	}
	if (op == '*')
	{
		return (input1 * input2);
	}
	if (op == '/')
	{
		if (input2 == 0)
		{
			std::cout << "Are you trying to crash me?" << std::endl;
			return 0;
		}
		return (input1 / input2);
	}
	return 0;
}

void printResult(int result)
{
	std::cout << "Your result is: " << result << std::endl;
}

int main()
{
	int input1;
	int input2;
	char op;
	int result;

	input1 = getUserInput();

	op = getMathematicalOperation();

	input2 = getUserInput();

	result = calculateResult(input1, op, input2);

	printResult(result);

	return 0;
}


// FogCreek_HashApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
#include <stdint.h>

int64_t hash(std::string s)
{
	int64_t h = 7;
    std::string letters = "acdegilmnoprstuw";

	for(int i = 0; i < s.length(); i++) {
		char t = letters.find(s.at(i));
		//check that letter being converted is in allowable letters 
		if ( t == -1){
			std::cout << s.at(i);
			std::cout << " is not an allowable character.\n";
			h = 0;
			i = s.length();
		}
		else 
			h = (h * 37 + letters.find(s.at(i)));
    }
    return h;
}

void findHashInput(int64_t j)
{
	std::string charReturned = "";
	std::string letters = "acdegilmnoprstuw";
	double tryUnHash = 0;
	double b = 0;

	for (int i = 0; i < 15; i++)
	{
		//reverse hash logic
		tryUnHash = double(j - i) / 37.0;
		//determine if a fractional part is assigned to a, b is assigned interger portion
		double a = std::modf(tryUnHash, &b);

		//if this iteration meets all criteria recursively call findHashInput
		if (a == 0 && tryUnHash >= 7)
		{
			charReturned = letters.at(i);
			findHashInput(tryUnHash);
			std::cout << charReturned;
			i = 15;
		}

	}

	//return charReturned;
}


int _tmain(int argc, _TCHAR* argv[])
{
	std::string inputString = "n";
	int64_t outputHash = 0;
	int64_t inputNumber = 0;
	//std::string outputString = "";
	std::string inputHash = "";
	std::string inputChar = "n";

	//allow user to perform conversions multiple times
	while (inputChar == "n"){
		//ask user which action they want to perform
		std::cout << "Press One (1) to produce a hash code\n";
		std::cout << "Press Two (2) to find a string from a hash code\n";
		std::cin >> inputChar;
		//retrieve string from user
		if (inputChar == "1"){
			std::cout << "From these characters \'acdegilmnoprstuw\' \n please enter the string you'd like to produce a hash for: ";
			std::cin >> inputString;

			outputHash = hash(inputString);
			std::cout << outputHash;
		}
		else if (inputChar == "2")
		{
			//retrieve hash code from user
			std::cout << "Please enter the hash code you'd like to produce a string for: ";
			std::cin >> inputHash;
			//convert hash code from string to int
			std::stringstream convert(inputHash);
			if(!(convert >> inputNumber))
				inputNumber = 0;
			
			findHashInput(inputNumber);
		}
		else 
		{
			std::cout << "You did not enter a valid option.\n";
		}
		std::cout << "\nWould you like to exit? y/n\n";
		std::cin >> inputChar;
		if (!(inputChar == "y" || inputChar == "n"))
		{
			std::cout << "You did not enter a valid option.\nProgram exiting";
			inputChar = "n";
		}
	}

	return 0;
}





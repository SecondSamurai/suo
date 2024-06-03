// ClassTime.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "TimesClass.h"

#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	char UserExit;
	TimeClass UserTime;
	do
	{
		std::cin.clear();
		UserExit = 0;

		std::string dt, ddt;

		std::cout << "1 - Time difference" << std::endl;
		std::cout << "2 - Time plus" << std::endl;
		std::cout << "3 - Time Minus" << std::endl;
		std::cout << "4 - Time Multiplu" << std::endl;
		std::cout << "5 - Time to minutes" << std::endl;
		std::cout << "6 - Time to seconds" << std::endl;
		std::cout << "q - Exit" <<std::endl;
		
		std::cin >> UserExit;

		switch (UserExit)
		{
		case '1': 
			std::cout << "Date One ";
			std::cin.get();
			getline(std::cin, dt);

			std::cout << "Date Two ";
			getline(std::cin, ddt);

			std::cout <<  UserTime.TimeDifference(dt, ddt) << std::endl; 
			break;
		case '2': 
			std::cout << "Date One ";
			std::cin.get();
			getline(std::cin, dt);

			std::cout << "Date Two ";
			getline(std::cin, ddt);

			std::cout << UserTime.TimePlus(dt, ddt) << std::endl; 
			break;
		case '3': 
			std::cout << "Date One ";
			std::cin.get();
			getline(std::cin, dt);

			std::cout << "Date Two ";
			getline(std::cin, ddt);

			std::cout << UserTime.TimeMinus(dt, ddt) << std::endl; 
			break;
		case '4': 
			std::cout << "Date One ";
			std::cin.get();
			getline(std::cin, dt);

			std::cout << "Date Two ";
			getline(std::cin, ddt);

			std::cout << UserTime.TimeMultipli(dt, ddt) << std::endl; 
			break;
		case '5': 
			std::cout << "Date One ";
			std::cin.get();
			getline(std::cin, dt);

			std::cout << "Date Two ";
			getline(std::cin, ddt);

			std::cout << UserTime.TimeToMinute(dt) << std::endl; 
			break;
		case '6': 
			std::cout << "Date One ";
			std::cin.get();
			getline(std::cin, dt);

			std::cout << "Date Two ";
			getline(std::cin, ddt);

			std::cout << UserTime.TimeToSecond(dt) << std::endl; 
			break;
		default: break;
		}
	}
	while (UserExit != 'q');
	return EXIT_SUCCESS;
}
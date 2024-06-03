// ClassTriad.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

#include "ClassTriad.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char ExUS;
	Triad date_, _date;
	do
	{
		ExUS = 0;

		std::cout << "1 - Add parrametr" << std::endl;
		std::cout << "2 - Show parrametr" << std::endl;
		std::cout << "3 - Change mode" << std::endl;
		std::cout << "4 - Big or small" << std::endl;
		std::cout << "q - Exit" << std::endl;
		
		std::cin >> ExUS;
		if (ExUS == '1')
			std::cin >> date_;
		if (ExUS == '2')
			std::cout << date_ << std::endl;
		if (ExUS == '3')
		{	
			std::cin.clear();
			std::string Format;
			std::cin >> Format;
			date_.chFormat(Format);
		}
		if (ExUS == '4')
		{	
			std::cin.clear();
			std::cout << "Date one: ";
			std::cin >> date_;
			std::cout << std::endl;
			std::cin.clear();
			std::cout << "Date Two: ";
			std::cin >> _date;
			if (date_ > _date)
				std::cout << "\t " << date_ << " is big" << std::endl;
			if (date_ < _date)
				std::cout << "\t " << _date << " is big" << std::endl;
			if (date_ == _date)
				std::cout << "\t " << date_ << " and " << _date  << " equal" << std::endl;
			if (date_ != _date)
				std::cout << "\t " << date_ << " and " << _date  << " aren't equal" << std::endl;
		}

		std::cin.clear();
	} while(ExUS != 'q');

	return EXIT_SUCCESS;
}


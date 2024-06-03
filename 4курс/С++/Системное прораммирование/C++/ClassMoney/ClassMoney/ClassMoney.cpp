// ClassTime.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ClassMoney.h"

#include <iostream>
#include <string>
//#include <conio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	char UserExit;
	MoneyClass UserMoney;
	do
	{
		
		std::cout << "1 - Plus: " << std::endl;
		std::cout << "2 - Minus" << std::endl;
		std::cout << "3 - Multipli" << std::endl;
		std::cout << "4 - Divide" << std::endl;
		std::cout << "5 - Difference" << std::endl;
		std::cout << "q - Exit" << std::endl;
		std::cin  >> UserExit;

		std::string UInE, UInO;
		if(UserExit == '1')
		{
			std::cout << "Value 1 ";
			std::cin >> UInE;
			std::cout << "Value 2 ";
			std::cin >> UInO;
			std::cout << UserMoney.moneyPlus(UInE, UInO) << std::endl;
		}
		if(UserExit == '2')
		{
			std::cout << "Value 1 ";
			std::cin >> UInE;
			std::cout << "Value 2 ";
			std::cin >> UInO;
			std::cout << UserMoney.moneyMinus(UInE, UInO) << std::endl;
		}
		if(UserExit == '3')
		{
			std::cout << "Value 1 ";
			std::cin >> UInE;
			std::cout << "Value 2 ";
			std::cin >> UInO;
			std::cout << UserMoney.moneyMiltipli(UInE, UInO) << std::endl;
		}
		if(UserExit == '4')
		{
			std::cout << "Value 1 ";
			std::cin >> UInE;
			std::cout << "Value 2 ";
			std::cin >> UInO;
			std::cout << UserMoney.moneyDivide(UInE, UInO) << std::endl;
		}
		if(UserExit == '5')
		{
			std::cout << "Value 1 ";
			std::cin >> UInE;
			std::cout << "Value 2 ";
			std::cin >> UInO;
			std::cout << UserMoney.moneyDifirence(UInE, UInO) << std::endl;
		}
		/*std::cout << UserMoney.moneyPlus("12.55", "12,66") << std::endl;
		std::cout << UserMoney.moneyMinus("12.55", "10,56") << std::endl;
		std::cout << UserMoney.moneyMiltipli("12.55", "12,6633") << std::endl;
		std::cout << UserMoney.moneyDivide("12.55", "3") << std::endl;
		std::cout << UserMoney.moneyDifirence("12.55", "10.57") << std::endl;*/

		std::cin.clear();
		//UserExit = getch();
	}
	while (UserExit != 'q');
	return EXIT_SUCCESS;
}
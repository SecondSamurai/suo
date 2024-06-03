// ClassGoods.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ClassGoods.h"

#include <iostream>
#include <string>
//#include <conio.h>

//#include "functions.h"



int _tmain(int argc, _TCHAR* argv[])
{
	char UserExit, wait_, ChMode;

	GoodsClass UserGoods;
	do
	{
		UserExit = 0;

		std::cout << "1 - Create goods" << std::endl;
		std::cout << "2 - Show now goods" << std::endl;
		std::cout << "3 - Show all goods" << std::endl;
		std::cout << "4 - Change requisite" << std::endl;
		std::cout << "5 - Make Delay Goods" << std::endl;
		std::cout << "9 - Save Goods" << std::endl;
		std::cout << "q - Exit" << std::endl;
		
		//UserExit = std::cin.get();
		std::cin >> UserExit;
		std::cin.clear();

		if (UserExit == '1')
			UserGoods.createGoods();
		if (UserExit == '2')
			UserGoods.ShGoods();
		if (UserExit == '3')
			UserGoods.ShGoods_t();
		if (UserExit == '4')
		{
			do
			{
				ChMode = 0;

				std::cout << "\t1 - Name" << std::endl;
				std::cout << "\t2 - Number" << std::endl;
				std::cout << "\t3 - Timer" << std::endl;
				std::cout << "\t4 - Price" << std::endl;
				std::cout << "\t5 - Date" << std::endl;
				std::cout << "\t6 - Consignment" << std::endl;
				std::cout << "\t0 - All" << std::endl;
				std::cout << "\tb - Back" << std::endl;

				std::cin >> ChMode;
				std::cin.clear();

				UserGoods.ChGoods(ChMode);
			}
			while (ChMode != 'b');
		}
		if (UserExit == '5')
		{
			do
			{
				ChMode = 0;

				std::cout << "\t1 - Date Now and Your Date" << std::endl;
				std::cout << "\t2 - Your Date and Your Date" << std::endl;
				std::cout << "\t3 - Date Goods and Your Date" << std::endl;
				std::cout << "\t4 - Date Goods and Date Now" << std::endl;
				std::cout << "\t5 - Date Now and Date Goods" << std::endl;
				std::cout << "\t0 - Back to First Price" << std::endl;
				std::cout << "\tb - Back" << std::endl;

				std::cin >> ChMode;
				std::cin.clear();

				UserGoods.DelayGoods_Switch(ChMode);
			}
			while (ChMode != 'b');
		}
		if (UserExit == '9')
			UserGoods.SaveGoods();

		std::cout << "Press for contune_" << std::endl;
		wait_ = std::cin.get();
		std::cin.clear();
		//system("cls");
	}
	while (UserExit != 'q');
	return EXIT_SUCCESS;
}
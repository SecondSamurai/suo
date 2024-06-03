// ClassPersonList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "ClassPersonList.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char UeXS;

	PersonList HlFow;
	do
	{
		UeXS = 0;
		std::cout << "1 - Add Person" << std::endl;
		std::cout << "2 - Show Cards Person" << std::endl;
		std::cout << "3 - Find Person" << std::endl;
		std::cout << "4 - Delete Preson" << std::endl;
		std::cout << "5 - Associate Person" << std::endl;
		std::cout << "6 - Zodiac Person" << std::endl;
		std::cout << "q - Exit" << std::endl;

		std::cin >> UeXS;
		if (UeXS == '1')
			HlFow.CreatePerson();
		if (UeXS == '2')
			HlFow.Show_Cards();
		if (UeXS == '3')
			HlFow.FindPerson();
		if (UeXS == '4')
			HlFow.DeletePerson();
		if (UeXS == '5')
		{
			char UeXS__ ;
			UeXS__ = 0;
			std::cout << "\t1 - Association" << std::endl;
			std::cout << "\t2 - Crossingn" << std::endl;
			std::cout << "\t3 - Difference" << std::endl;
			std::cout << "\tb - Back" << std::endl;
			std::cin >> UeXS__;
			HlFow.AssociatePerson(UeXS__);
		}
		if (UeXS == '6')
			HlFow.ZodiacPerson();
		std::cin.clear();

		//закончил на зодиаке строка 233
		//для обединения использовать слияние например 1 + 1 = 1 1, а для даты использовать вычитание даты
	}while (UeXS != 'q');
	return EXIT_SUCCESS;
}


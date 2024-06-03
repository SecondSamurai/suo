#ifndef CLASSPERSONLIST_H
#define CLASSPERSONLIST_H

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

#include "F_Helper.h"
#include "AM_rKey.h"

class PersonList
{
public:
	std::string PersonName;		//Фамилия Персоны
	std::string PersonDate;		//Дата рождения Персоны
	
	PersonList();
	~PersonList(){};

	void CreatePerson ();
	void Show_Cards ();
	void DeletePerson ();
	void FindPerson ();
	void AssociatePerson (char sQ);
	void ZodiacPerson ();

protected:
	unsigned int __timerPn;
	std::vector < std::string > __CardFile;
	std::string __CF_buf;
	std::string __PD_buf;

private:
	void Association (int num_i, int num_j);
	void Crossingn (int num_i, int num_j);
	void Difference (int num_i, int num_j);
	marray < std::string, std::string > __Zodiac;
	bool HSH_repeat(std::string source_);
	std::string HSH_KU(std::string source_);
	std::string __VDivider(unsigned int position, int pos_f);
	std::string FindPerson_Del (std::string source_);

};

PersonList::PersonList()
{
	__timerPn = 0;
	__Zodiac["Aries"] = "21.03 - 20.04";
	__Zodiac["Taurus"] = "21.04 - 21.05";
	__Zodiac["Twin"] = "22.05 - 21.06";
	__Zodiac["Crayfish"] = "22.06 - 23.07";
	__Zodiac["Lion"] = "24.07 - 23.08";
	__Zodiac["Maiden"] = "24.08 - 23.09";
	__Zodiac["Scales"] = "24.09 - 23.10";
	__Zodiac["Scorpion"] = "24.10 - 22.11";
	__Zodiac["Sagittarius"] = "23.11 - 21.12";
	__Zodiac["Capricorn"] = "22.12 - 20.01";
	__Zodiac["Aquarius"] = "21.01 - 19.02";
	__Zodiac["Fish"] = "20.02 - 20.03";
}

void PersonList::CreatePerson ()
{
	std::cout << std::endl << "FOR EXIT ENTER 'EXIT'" << std::endl;
	std::cin.get();
	do {
		bool exCrl = false;
		do
		{
			std::cin.clear();
			std::cout << std::endl << "Second Name: ";
			std::getline(std::cin, __CF_buf);
			if (__CF_buf.size() > 1) 
			{
				Ecq_23(__CF_buf);
				if (Resolve_(__CF_buf))
				{
					if (DownKW(__CF_buf) != "exit") 
					{
						if (HSH_repeat(__CF_buf))
						{
							std::cout << "Date: ";
							do
							{
								std::getline(std::cin, __PD_buf);
								std::cin.clear();
								if (!dtEntCont(__PD_buf, __PD_buf))
									std::cout << "Encorrect enter, try again"<< std::endl;
								else
									break;
							}while(true);

							
							__CardFile.push_back(__CF_buf + "|" + __PD_buf + "|" + HSH_KU(__CF_buf) + "|");
							__timerPn++;
							exCrl = true;
							std::cout << "DONE" << std::endl;
							std::cout << "\nFOR EXIT ENTER 'EXIT'" << std::endl;
						}
						else
						{
							std::cout << "Second name mast be Unique" << std::endl;
						}
					}
					else
					{
						break;
					}
				}
			}
			std::cin.clear();
		} while (!exCrl);
	} while (DownKW(__CF_buf) != "exit");
}

void PersonList::Show_Cards ()
{
	if (__CardFile.size() == 0)
	{
		std::cout << "You haven't created Person" << std::endl;
		return;
	}

	std::vector < std::string > :: iterator it;
	int timer_ = 0;
	for (it = __CardFile.begin(); it != __CardFile.end(); it++, timer_++) 
	{
		std::cout << "#: " << timer_ << std::endl; 
		int timer__ = 0;
		std::string tmVale = *it , RmValue;
		for (int i = 0; i < tmVale.size(); i++)
		{
			if (tmVale.at(i) != '|')
			{
				RmValue += tmVale.at(i);
			}
			if (tmVale.at(i) == '|')
			{
				timer__++;
				if (timer__ == 1)
					std::cout << "\tSecond Name: " << RmValue << std::endl;
				if (timer__ == 2)
					std::cout << "\tDate: " << RmValue << std::endl;
				if (timer__ > 2)
					break;
				RmValue.clear();
			}
		}
	}
}

void PersonList::DeletePerson ()
{
	if (__timerPn == 0)
	{
		std::cout << "You hasn't created Person" << std::endl;
		return;
	}
	std::cin.clear();
	std::cin.get();
	std::cout << "For delete Enter Number Card or Second Name, or 'exit' for cancel" << std::endl;

	std::getline(std::cin, __CF_buf);
	if (__CF_buf.size() > 0) 
	{
		Ecq_23(__CF_buf);
		if (Resolve_(__CF_buf, true))
		{
			std::string resUlt = FindPerson_Del(__CF_buf);
			if(resUlt != "")
			{
				std::cin.clear();
				std::cout << "\tFor Delete press y" << std::endl;
				std::string RedE;
				std::getline(std::cin, RedE);
				if (RedE == "y" || RedE == "Y")
				{
					__CardFile.erase(__CardFile.begin() + toInt(resUlt));
					__timerPn --;
				}
			}
		}
	}
	std::cin.clear();
}

void PersonList::FindPerson ()
{
	if (__timerPn == 0)
	{
		std::cout << "You hasn't created Person" << std::endl;
		return;
	}
	std::cout << "For Find person Enter Number Card or Second Name" << std::endl;
	std::cin.clear();
	
	std::cin.get();
	std::getline(std::cin, __CF_buf);
	if (__CF_buf.size() > 0) 
	{
		Ecq_23(__CF_buf);
		if (Resolve_(__CF_buf, true))
		{
			if (!isNumber(__CF_buf))
			{
				int i = 0;
				for (i; i < __timerPn; i++) 
				{
					if (__VDivider(i, 3) == HSH_KU(__CF_buf))
					{
						std::cout << "#: " << i << std::endl;
						std::cout << "\tName Person: " << __VDivider(i, 1) << std::endl;
						std::cout << "\tDate: " << __VDivider(i, 2) << std::endl;
					}
				}
			}
			else
			{
				int i = 0;
				std::vector < std::string > :: iterator it;
				for (it = __CardFile.begin(); it != __CardFile.end(); it++, i++) 
				{
					if(i == toInt(__CF_buf))
					{
						std::cout << "#: " << i << std::endl;
						std::cout << "\tName Person: " << __VDivider(i, 1) << std::endl;
						std::cout << "\tDate: " << __VDivider(i, 2) << std::endl;
					}
				}
			}
		}
	}
	std::cin.clear();
}

void PersonList::AssociatePerson (char sQ)
{
	if (sQ == 'b' || sQ == 'B') return;

	if (__timerPn == 0)
	{
		std::cout << "You hasn't created Person" << std::endl;
		return;
	}
	
	std::string F_pStr, S_pStr;
	std::cin.clear();
	std::cin.get();
	std::cout << "For Find Enter Number Card or Second Name, or 'EXIT' for cancel" << std::endl;

	bool exCrl = false;
	do
	{
		std::cout << "First Card" << std::endl;
		std::getline(std::cin, __CF_buf);
		if (__CF_buf.size() > 0) 
		{
			Ecq_23(__CF_buf);
			if (Resolve_(__CF_buf, true))
			{
				if (DownKW(__CF_buf) != "exit") 
				{
					F_pStr = FindPerson_Del(__CF_buf);
					if(F_pStr != "") exCrl = true;
				}
				else return;
			}
			else std::cout << "Incorrect Enter, try again or enter 'EXIT'" << std::endl;
		}
	} while (!exCrl);
	
	exCrl = false;
	do
	{
		std::cout << "Second Card" << std::endl;
		std::getline(std::cin, __CF_buf);
		if (__CF_buf.size() > 0) 
		{
			Ecq_23(__CF_buf);
			if (Resolve_(__CF_buf, true))
			{
				if (DownKW(__CF_buf) != "exit") 
				{
					S_pStr = FindPerson_Del(__CF_buf);
					if(S_pStr != "" && F_pStr != S_pStr) exCrl = true;
				}
				else return;
			}
			else std::cout << "Incorrect Enter, try again or enter 'EXIT'" << std::endl;
		}
		std::cin.clear();
	} while (!exCrl);

	switch (sQ)
	{
	case '1' : Association(toInt(F_pStr), toInt(S_pStr)); break;
	case '2' : Crossingn(toInt(F_pStr), toInt(S_pStr)); break;
	case '3' : Difference(toInt(F_pStr), toInt(S_pStr)); break;
	default : Association(toInt(F_pStr), toInt(S_pStr)); break;
	}
}

void PersonList::ZodiacPerson ()
{
	if (__timerPn == 0)
	{
		std::cout << "You hasn't created Person" << std::endl;
		return;
	}
	std::cin.clear();
	std::cin.get();
	std::cout << "For Find Enter Number Card or Second Name, or 'exit' for cancel" << std::endl;

	std::getline(std::cin, __CF_buf);
	if (__CF_buf.size() > 0) 
	{
		Ecq_23(__CF_buf);
		if (Resolve_(__CF_buf, true))
		{
			std::string resUlt = FindPerson_Del(__CF_buf);
			if(resUlt != "")
			{
				resUlt = __VDivider(toInt(resUlt), 2);

				int month = dtValCont(resUlt, 2);
				int day = dtValCont(resUlt, 1);

				const char * arrZodiak[12] = {"Aries", "Taurus", "Twin", "Crayfish", "Lion", "Maiden", "Scales", "Scorpion", "Sagittarius", "Capricorn", "Aquarius", "Fish"};
				char zodiak[20];

				if ( (month == 3 && day >= 21) || (month == 4 && day <= 20) )
					strcpy(zodiak, arrZodiak[0]);	// Овен
				else
				if ( (month == 4 && day >= 21) || (month == 5 && day <= 20) )
					strcpy(zodiak, arrZodiak[1]);	// Телец
				else
				if ( (month == 5 && day >= 21) || (month == 6 && day <= 21) )
					strcpy(zodiak, arrZodiak[2]);	// Близнецы
				else
				if ( (month == 6 && day >= 22) || (month == 7 && day <= 22) )
					strcpy(zodiak, arrZodiak[3]);	// Рак
				else
				if ( (month == 7 && day >= 23) || (month == 8 && day <= 23) )
					strcpy(zodiak, arrZodiak[4]);	// Лев
				else
				if ( (month == 8 && day >= 24) || (month == 9 && day <= 23) )
					strcpy(zodiak, arrZodiak[5]);	// Дева
				else
				if ( (month == 9 && day >= 24) || (month == 10 && day <= 22) )
					strcpy(zodiak, arrZodiak[6]);	// Весы
				else
				if ( (month == 10 && day >= 23) || (month == 11 && day <= 22) )
					strcpy(zodiak, arrZodiak[7]);	// Скорпион
				else
				if ( (month == 11 && day >= 23) || (month == 12 && day <= 21) )
					strcpy(zodiak, arrZodiak[8]);	// Стрелец
				else
				if ( (month == 12 && day >= 22) || (month == 1 && day <= 20) )
					strcpy(zodiak, arrZodiak[9]);	// Козерог
				else
				if ( (month == 1 && day >= 21) || (month == 2 && day <= 19) )
					strcpy(zodiak, arrZodiak[10]);	// Водолей
				else
				if ( (month == 2 && day >= 20) || (month == 3 && day <= 20) )
					strcpy(zodiak, arrZodiak[11]);	// Рыбы

				std::cout << "Zodiac: " << zodiak << " " << __Zodiac[zodiak] << std::endl;
			}
		}
	}
	std::cin.clear();
}

void PersonList::Association(int num_i, int num_j)
{
	std::vector < std::string > __VHSH;

	std::string f_nPostr = __VDivider(num_i, 1) + " ";
	std::string S_nPostr = __VDivider(num_j, 1) + " ";
	std::string TempF, newSF, newSS;
	for (int i = 0; i < f_nPostr.size(); i++)
	{
		if (f_nPostr.at(i) == ' ')
		{
			newSF += TempF + " ";
			__VHSH.push_back(HSH_KU(TempF));
			TempF.clear();
		}
		else TempF += f_nPostr.at(i);
	}
	TempF.clear();
	for (int j = 0; j < S_nPostr.size(); j++)
	{
		if (S_nPostr.at(j) == ' ')
		{
			bool treA = true;
			std::vector < std::string > :: iterator it;
			for (it = __VHSH.begin(); it != __VHSH.end(); it++)
				if (*it == HSH_KU(TempF))
				{
					treA = false;
					break;
				}
			if (treA)
				newSS += TempF + " ";
			TempF.clear();
		}
		else TempF += S_nPostr.at(j);
	}
	newSF += newSS;
	Ecq_23(newSF);
	std::cout << "Result Association = " << newSF << std::endl;
	__CardFile.insert(__CardFile.begin() + num_i, newSF + "|" + __VDivider(num_i, 2) + "|" + HSH_KU(newSF) + "|");	  //вставляет эллемент на позицию
	__CardFile.erase(__CardFile.begin() + num_i + 1);
}

void PersonList::Crossingn(int num_i, int num_j)
{
	std::vector < std::string > __VHSH;

	std::string f_nPostr = __VDivider(num_i, 1) + " ";
	std::string S_nPostr = __VDivider(num_j, 1) + " ";
	std::string TempF, newSF, newSS;
	for (int i = 0; i < f_nPostr.size(); i++)
	{
		if (f_nPostr.at(i) == ' ')
		{
			newSF += TempF + " ";
			__VHSH.push_back(HSH_KU(TempF));
			TempF.clear();
		}
		else TempF += f_nPostr.at(i);
	}
	TempF.clear();
	for (int j = 0; j < S_nPostr.size(); j++)
	{
		if (S_nPostr.at(j) == ' ')
		{
			std::vector < std::string > :: iterator it;
			for (it = __VHSH.begin(); it != __VHSH.end(); it++)
				if (*it == HSH_KU(TempF))
					newSS += TempF + " ";

			TempF.clear();
		}
		else TempF += S_nPostr.at(j);
	}
	if (newSS.size() > 1)
	{
		newSF = newSS;
		Ecq_23(newSF);
		std::cout << "Result Crossingn = " << newSF << std::endl;
		__CardFile.insert(__CardFile.begin() + num_i, newSF + "|" + __VDivider(num_i, 2) + "|" + HSH_KU(newSF) + "|");	  //вставляет эллемент на позицию
		__CardFile.erase(__CardFile.begin() + num_i + 1);
	}
	else
		std::cout << "Cards have nothing in common" << std::endl;
}

void PersonList::Difference(int num_i, int num_j)
{
	std::vector < std::string > __VHSH;

	std::string f_nPostr = __VDivider(num_i, 1) + " ";
	std::string S_nPostr = __VDivider(num_j, 1) + " ";
	std::string TempF, newSF, newSS;

	for (int i = 0; i < S_nPostr.size(); i++)
	{
		if (S_nPostr.at(i) == ' ')
		{
			newSF += TempF + " ";
			__VHSH.push_back(HSH_KU(TempF));
			TempF.clear();
		}
		else TempF += S_nPostr.at(i);
	}
	TempF.clear();
	for (int j = 0; j < f_nPostr.size(); j++)
	{
		if (f_nPostr.at(j) == ' ')
		{
			bool Ex_a = true;
			std::vector < std::string > :: iterator it;
			for (it = __VHSH.begin(); it != __VHSH.end(); it++)
			{
				if (*it == HSH_KU(TempF))
				{
					Ex_a = false;
					break;
				}
			}
			if (Ex_a)
				newSS += TempF + " ";
			TempF.clear();
		}
		else TempF += f_nPostr.at(j);
	}
	if (newSS != "" || newSS != " ")
	{
		newSF = newSS;
		Ecq_23(newSF);
		std::cout << "Result Crossingn = " << newSF << std::endl;
		__CardFile.insert(__CardFile.begin() + num_i, newSF + "|" + __VDivider(num_i, 2) + "|" + HSH_KU(newSF) + "|");	  //вставляет эллемент на позицию
		__CardFile.erase(__CardFile.begin() + num_i + 1);
	}
	else
		std::cout << "Cards identical" << std::endl;
}


bool PersonList::HSH_repeat(std::string source_)
{
	for (int i = 0; i <= __timerPn; i++)
	{
		std::string TStr_tm = __VDivider(i, 3);
		if (HSH_KU(source_) == TStr_tm)
			return false;
	}
	return true;
}

std::string PersonList::FindPerson_Del (std::string source_)
{
	if (!isNumber(source_))
	{
		int i = 0;
		for (i; i < __timerPn; i++) 
		{
			if (__VDivider(i, 3) == HSH_KU(source_))
			{
				std::cout << "#: " << i << std::endl;
				std::cout << "\tName Person: " << __VDivider(i, 1) << std::endl;
				std::cout << "\tDate: " << __VDivider(i, 2) << std::endl;
				return toString(i);
			}
		}
		std::cout << "Nothing is found" << std::endl;
		return "";
	}
	else
	{
		int i = 0;
		std::vector < std::string > :: iterator it;
		for (it = __CardFile.begin(); it != __CardFile.end(); it++, i++) 
		{
			if(i == toInt(source_))
			{
				std::cout << "#: " << i << std::endl;
				std::cout << "\tName Person: " << __VDivider(i, 1) << std::endl;
				std::cout << "\tDate: " << __VDivider(i, 2) << std::endl;
				return toString(i);
			}
		}
			std::cout << "Nothing is found" << std::endl;
			return "";
	}
	return "";
}

std::string PersonList::HSH_KU(std::string source_)
{
	std::string WorkS_;
	unsigned long int tempolary = 0;

	source_ = DownKW(source_);

	for (int i = 0; i < source_.size(); i++)
	{
		tempolary = source_.at(i) * 1024 / 4 * 124 * M_PI / M_SQRT1_2 * source_.at(i) / M_LOG2E;
		tempolary = Round(tempolary, 3);
		WorkS_ += "%" + toString(tempolary);
	}
	return WorkS_;
}

std::string PersonList::__VDivider(unsigned int string_pos, int value_pos)
{
	value_pos--;
	if (value_pos < 0 || value_pos > 3)
		return "";
		
	std::string tmVale;
	std::vector < std::string > :: iterator it;
	int timer_ = 0;

	for (it = __CardFile.begin(); it != __CardFile.end(); it++, timer_++) 
	{
		if (timer_ == string_pos)
		{
			tmVale = "";
			std::string RValue = *it;
			int timer__ = 0;
			for (int i = 0; i < RValue.size(); i++)
			{
				if (timer__ == value_pos)
				{
					for (int j = i; RValue.at(j) != '|'; j++)
						tmVale += RValue.at(j);
					break;
				}
				if (RValue.at(i) == '|')
					timer__++;
			}
		}
	}
	return tmVale;
}

#endif
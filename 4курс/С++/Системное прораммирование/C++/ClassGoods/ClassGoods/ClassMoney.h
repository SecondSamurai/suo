#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "functions.h"

#define MAX_TIMER 80063

class MoneyClass {

private:
	std::string f_OutString;
	long _rub;
	int _kopek;
	float _summatr;

	friend std::ostream& operator << (std::ostream& streamE, const MoneyClass & f_inS);

public:

	MoneyClass()
	{
		_rub = 0;
		_kopek = 0;
		_summatr = 0.0;
		f_OutString = "";
	}
	~MoneyClass(){}


	std::string toString_M()
	{
		return f_OutString;
	}

	bool isMoney(std::string & source_)
	{
		int timer_Po = 0;
		for (int i = 0; i < source_.size(); i++)
		{
			if(source_.at(i) == 46)
			{
				timer_Po ++;
			}
			if (timer_Po > 1)
			{
				return false;
			}
			if (!SymbExR(source_.at(i)))
			{
				return false;
			}
		}
		if (timer_Po == 0)
		{
			source_+=".00";
		}
		return true;
	}

	std::string moneyPlus(std::string string_first = "0.0", std::string string_second = "0.0")
	{
		if (!isMoney(string_first) || !isMoney(string_second))
			return "0.0";

		int ruble_F = abs(toFloat(string_first)), ruble_S = abs(toFloat(string_second));

		int kopek_F_int = abs(intPositionKopek(string_first));
		int kopek_S_int = abs(intPositionKopek(string_second));

		int tempInt = 0;		

		tempInt = ruble_F + ruble_S;
		f_OutString = toString(tempInt) + ".";

		tempInt = kopek_F_int + kopek_S_int;
		f_OutString += toString(tempInt);
		
		f_OutString = kopekMaxControl(f_OutString);
		return f_OutString;
	}

	std::string moneyMiltipli(std::string string_first = "0.0", std::string string_second = "0.0")
	{
		if (!isMoney(string_first) || !isMoney(string_second))
			return "0.0";

		int ruble_F = abs(toFloat(string_first)), ruble_S = abs(toFloat(string_second));

		int kopek_F_int = abs(intPositionKopek(string_first));
		int kopek_S_int = abs(intPositionKopek(string_second, true));

		int tempInt = 0;

		tempInt = cantMultZero(ruble_F) * cantMultZero(ruble_S);
		f_OutString = toString(tempInt) + ".";

		
		if (kopek_S_int == 0)
			tempInt = cantMultZero(kopek_F_int) * cantMultZero(ruble_S);
		else
			tempInt = cantMultZero(kopek_F_int) * cantMultZero(kopek_S_int);
		f_OutString += toString(tempInt);
		
		f_OutString = kopekMaxControl(f_OutString);
		return f_OutString;
	}
	
	std::string moneyMinus(std::string string_first = "0.0", std::string string_second = "0.0")
	{
		if (!isMoney(string_first) || !isMoney(string_second))
			return "0.0";

		int ruble_F = abs(toFloat(string_first)), ruble_S = abs(toFloat(string_second));

		int kopek_F_int = abs(intPositionKopek(string_first));
		int kopek_S_int = abs(intPositionKopek(string_second));

		int tempRuble = 0, tempKopek = 0;

		if (ruble_F > ruble_S && kopek_F_int > kopek_S_int)
		{
			tempRuble = ruble_F - ruble_S;
			tempKopek = kopek_F_int - kopek_S_int;
		}
		if (ruble_F > ruble_S && kopek_F_int < kopek_S_int)
		{
			tempRuble = ruble_F - ruble_S - 1;
			tempKopek = 100 - abs(kopek_F_int - kopek_S_int);
		}
		if (ruble_F < ruble_S && kopek_F_int > kopek_S_int)
		{
			tempRuble = ruble_F - ruble_S;
			tempKopek = kopek_F_int - kopek_S_int;
		}
		if (ruble_F < ruble_S && kopek_F_int < kopek_S_int)
		{
			tempRuble = ruble_F - ruble_S + 1;
			tempKopek = 100 - abs(kopek_F_int - kopek_S_int);
		}


		if (ruble_F == ruble_S && kopek_F_int > kopek_S_int)
		{
			tempRuble = 0;
			tempKopek = kopek_F_int - kopek_S_int;
		}
		if (ruble_F == ruble_S && kopek_F_int < kopek_S_int)
		{
			tempRuble = -1;
			tempKopek = 100 - abs(kopek_F_int - kopek_S_int);
		}
		if (ruble_F > ruble_S && kopek_F_int == kopek_S_int)
		{
			tempRuble = ruble_F - ruble_S;
			tempKopek = 0;
		}
		if (ruble_F < ruble_S && kopek_F_int == kopek_S_int)
		{
			tempRuble = ruble_F - ruble_S;
			tempKopek = 0;
		}
		if (ruble_F == ruble_S && kopek_F_int == kopek_S_int)
		{
			tempRuble = 0;
			tempKopek = 0;
		}


		f_OutString = toString(tempRuble) + ".";
		f_OutString += toString(tempKopek);

		return f_OutString;
	}

	std::string moneyDivide(std::string string_first = "0.0", std::string string_second = "0.0")
	{
		if (!isMoney(string_first) || !isMoney(string_second))
			return "0.0";

		int ruble_F = abs(toFloat(string_first)), ruble_S = abs(toFloat(string_second));

		int kopek_F_int = abs(intPositionKopek(string_first, true));
		int kopek_S_int = abs(intPositionKopek(string_second, true));

		int tempInt = 0;

		tempInt = cantMultZero(ruble_F) / cantMultZero(ruble_S);
		f_OutString = toString(tempInt) + ".";

		if (kopek_S_int == 0)
			tempInt = cantMultZero(kopek_F_int) / cantMultZero(ruble_S);
		else
			tempInt = cantMultZero(kopek_F_int) / cantMultZero(kopek_S_int);
		f_OutString += toString(tempInt);
		
		f_OutString = kopekMaxControl(f_OutString);
		return f_OutString;
	}
	
	std::string moneyDifirence(std::string string_first = "0.0", std::string string_second = "0.0")
	{
		if (!isMoney(string_first) || !isMoney(string_second))
			return "0.0";

		int ruble_F = abs(toFloat(string_first)), ruble_S = abs(toFloat(string_second));

		int kopek_F_int = abs(intPositionKopek(string_first));
		int kopek_S_int = abs(intPositionKopek(string_second));

		int tempRuble = 0, tempKopek = 0;

		if (ruble_F > ruble_S && kopek_F_int > kopek_S_int)
		{
			tempRuble = ruble_F - ruble_S;
			tempKopek = kopek_F_int - kopek_S_int;
		}
		if (ruble_F > ruble_S && kopek_F_int < kopek_S_int)
		{
			tempRuble = ruble_F - ruble_S - 1;
			tempKopek = 100 - abs(kopek_F_int - kopek_S_int);
		}
		if (ruble_F < ruble_S && kopek_F_int > kopek_S_int)
		{
			tempRuble = ruble_F - ruble_S;
			tempKopek = kopek_F_int - kopek_S_int;
		}
		if (ruble_F < ruble_S && kopek_F_int < kopek_S_int)
		{
			tempRuble = ruble_F - ruble_S + 1;
			tempKopek = 100 - abs(kopek_F_int - kopek_S_int);
		}


		if (ruble_F == ruble_S && kopek_F_int > kopek_S_int)
		{
			tempRuble = 0;
			tempKopek = kopek_F_int - kopek_S_int;
		}
		if (ruble_F == ruble_S && kopek_F_int < kopek_S_int)
		{
			tempRuble = -1;
			tempKopek = 100 - abs(kopek_F_int - kopek_S_int);
		}
		if (ruble_F > ruble_S && kopek_F_int == kopek_S_int)
		{
			tempRuble = ruble_F - ruble_S;
			tempKopek = 0;
		}
		if (ruble_F < ruble_S && kopek_F_int == kopek_S_int)
		{
			tempRuble = ruble_F - ruble_S;
			tempKopek = 0;
		}
		if (ruble_F == ruble_S && kopek_F_int == kopek_S_int)
		{
			tempRuble = 0;
			tempKopek = 0;
		}


		f_OutString = toString(abs(tempRuble)) + ".";
		f_OutString += toString(abs(tempKopek));

		return f_OutString;
	}

private:
	std::string kopekMaxControl(std::string source_)
	{
		int ruble_int = toInt(source_);
 		int kopek_int = intPositionKopek(source_);

		if (kopek_int == 0 )
			return source_;
		if (kopek_int > 100)
		{
			ruble_int += (int)kopek_int / 100;
			kopek_int = kopek_int % 100;
			source_ = toString(ruble_int) + "." + zerroNdQt(toString(kopek_int));
		}
		if (kopek_int == 100)
		{
			ruble_int += 1;
			kopek_int = 00;
			source_ = toString(ruble_int) + "." + toString(kopek_int);
		}
		if (kopek_int < 100)
		{
			source_ = toString(ruble_int) + "." + toString(kopek_int);
		}
		return source_;
	}

	int cantMultZero(int sourceInt)
	{
/*		if (sourceInt == 0)
			sourceInt++;*/
		return sourceInt;
	}

	int intPositionKopek(std::string source_, const bool multi_ = false)
	{
		std::string kopek_F = "";

		for (int i = 0; i < source_.size(); i++)
		{
			if (source_.at(i) == ',')
			{
				source_ = source_.replace(source_.find(','), 1, ".");
				for (int j = i + 1; j < source_.size(); j++)
					kopek_F += source_.at(j);
				break;
			}
			if (source_.at(i) == '.')
			{
				for (int j = i + 1; j < source_.size(); j++)
					kopek_F += source_.at(j);
				break;
			}
		}
		int kopek_F_int = __Round(toInt(kopek_F), 2);
		return kopek_F_int;
	}

	bool SymbExR(char Symbol_, int tupical_ = 0)
	{
		if (tupical_ == 0)
		{
			if ((Symbol_ > 47 && Symbol_ < 58) || (Symbol_ == 46))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if ((Symbol_ > 47 && Symbol_ < 58))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
	}
};

std::ostream& operator << (std::ostream& streamE, const MoneyClass & f_inS)
{
	streamE << f_inS.f_OutString;
	return streamE;
}

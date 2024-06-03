#ifndef CLASSTRIAD_H
#define CLASSTRIAD_H


#include <iostream>
#include <string>

#include "F_Helper.h"

class Triad
{
public:
	int _tD;
	int _tM;
	int _tY;

	std::string outStream(int _hourStr = 0, int _minuteStr = 0, int _secondStr = 0);

	Triad (std::string Type_ = "d.m.y");
	void chFormat (std::string& source_);
	void CorrectDate (std::string stringMain);

	bool DiffDt (const Triad& tr_O, const Triad& tr_T);

	Triad operator = (const std::string& f_inS)
	{ 
		CorrectDate(f_inS);
		return * this; 
	}
	Triad operator = (const Triad& f_inS)
	{ return * this; }

	friend bool operator == (Triad const& a, Triad const& b);
	friend bool operator != (Triad const& a, Triad const& b);
	friend bool operator > (Triad const& a, Triad const& b);
	friend bool operator < (Triad const& a, Triad const& b);
	friend bool operator >= (Triad const& a, Triad const& b);
	friend bool operator <= (Triad const& a, Triad const& b);
	friend std::ostream& operator << (std::ostream& streamE, const Triad& f_inS);
	friend std::istream& operator >> (std::ostream& streamE, const Triad& f_inS);

private:
	void Correct(std::string& source_);
	std::string OutForm;
};



Triad::Triad(std::string Type_)
{
	Correct(Type_);
	OutForm = Type_;
	_tD = 0;
	_tM = 0;
	_tY = 0;
}

void Triad::Correct (std::string& source_)
{
	for (int i = 0; i < source_.size(); i++)
	{
		if (i % 2 == 0)
		{
			if (source_.at(i) != 'd' && source_.at(i) != 'm' && source_.at(i) != 'y')
			{
				switch (i)
				{
				case 0: source_.replace(i, 1, "d"); break;
				case 2: source_.replace(i, 1, "m"); break;
				case 4: source_.replace(i, 1, "y"); break;
				default: break;
				}
			}
		}
		else
			if (source_.at(i) != '-' || source_.at(i) != '.' || source_.at(i) != ':' || source_.at(i) != ';' || source_.at(i) != ',' || source_.at(i) != '/')
				source_.replace(i, 1, ".");
	}
}

void Triad::chFormat (std::string& source_)
{
	Correct(source_);
	OutForm = source_;
}

void Triad::CorrectDate(std::string stringMain)
{
	for (int i = 0; i < stringMain.length(); i++)
	{
		if (isPeref(stringMain.at(i)))
			stringMain.at(i) = '.';
		else
			if (!isNumber(stringMain.at(i)))
				stringMain.at(i) = 0;
	}
	stringMain += '.';

	int dayInt = 0, mounthInt = 0, yearInt = 0, tem_I = 0;
	std::string tem_S = "";

	for (int i = 0; i < stringMain.size(); i++)
	{
		if (stringMain[i] != '.')
			tem_S += stringMain[i];
		else 
		{
			tem_I = atoi(tem_S.c_str());
			if (tem_I > 1582 && tem_I < 4903)
				yearInt = tem_I;
			if (tem_I > 0 && tem_I < 13)
			{
				if (i > 2 && i < 8)
					mounthInt = tem_I;
			}
			if (tem_I > 0 && tem_I < 32) 
			{
				if (i < 3 || i > 7)
					dayInt = tem_I;
			}
			tem_S.clear();	
		}
	}
	if (yearInt < 1)
		yearInt = 1582;
	if (mounthInt < 1) 
		mounthInt = 1;
	if (dayInt < 1)
		dayInt = 1;

	switch (mounthInt)
	{
	case 2: 
		if ((yearInt %4 == 0 && yearInt %100 != 0) || (yearInt %400 == 0))
		{
			if (dayInt > 29)
				dayInt = 29;
		}
		else
			if (dayInt > 28)
				dayInt = 28;
		break;
	case 4: 
		if (dayInt > 30)
			dayInt = 30;
		break;
	case 6: 
		if (dayInt > 30)
			dayInt = 30;
		break;
	case 9: 
		if (dayInt > 30)
			dayInt = 30;
		break;
	case 11: 
		if (dayInt > 30)
			dayInt = 30;
		break;
	default : break;
	}
	_tD = dayInt;
	_tM = mounthInt;
	_tY = yearInt;
}

bool DiffDt (const Triad& tr_O, const Triad& tr_T, int dt_)
{
	int DtO = tr_O._tY * 10000 + tr_O._tM * 100 + tr_O._tD;
	int DtT = tr_T._tY * 10000 + tr_T._tM * 100 + tr_T._tD;
	
	if (dt_ == 1)
	{
		if (DtO == DtT)
			return true;
		else
			return false;
	}
	if (dt_ == 2)
	{
		if (DtO != DtT)
			return true;
		else
			return false;
	}
	if (dt_ == 3)
	{
		if (DtO < DtT)
			return true;
		else
			return false;
	}
	if (dt_ == 4)
	{
		if (DtO > DtT)
			return true;
		else
			return false;
	}
	if (dt_ == 5)
	{
		if (DtO <= DtT)
			return true;
		else
			return false;
	}
	if (dt_ == 6)
	{
		if (DtO >= DtT)
			return true;
		else
			return false;
	}
	return false;

}

std::string Triad::outStream(int _hourStr, int _minuteStr, int _secondStr)
{
	std::string WorkString = "";
	for (int i = 0; i < OutForm.size(); i++)
	{
		switch (OutForm.at(i))
		{
			case 'd': 
				WorkString += toString(_hourStr);
				break;
			case 'm': 
				WorkString += toString(_minuteStr);
				break;
			case 'y':
				WorkString += toString(_secondStr);
				break;
			default: 
				WorkString += OutForm.at(i);
				break;
		}
	}
	return WorkString;
}


std::ostream& operator << (std::ostream& streamE, Triad& f_inS)
{
	streamE << f_inS.outStream(f_inS._tD, f_inS._tM, f_inS._tY);
	return streamE;
}

std::istream& operator >> (std::istream& streamE, Triad& f_inS)
{
	std::string ee;
	streamE >> ee;
	f_inS.CorrectDate(ee);
	return streamE;
}

bool operator == (Triad const& a, Triad const& b)
{
	return DiffDt(a, b, 1);;
}

bool operator != (Triad const& a, Triad const& b)
{
	return DiffDt(a, b, 2);
}

bool operator < (Triad const& a, Triad const& b)
{
	return DiffDt(a, b, 3);
}

bool operator > (Triad const& a, Triad const& b)
{
	return DiffDt(a, b, 4);
}

bool operator <= (Triad const& a, Triad const& b)
{
	return DiffDt(a, b, 5);
}

bool operator >= (Triad const& a, Triad const& b)
{
	return DiffDt(a, b, 6);
}
#endif
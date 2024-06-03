#ifndef F_HELPER_H
#define F_HELPER_H

#include <string>
#include <iostream>
#include <sstream>
#include <atltime.h>

#include <cctype>
#include <ctype.h>

#include <cstddef>
#include <map>

#define _USE_MATH_DEFINES
#include <math.h>


#define RAND_U_V 32767
#define RAND_D_V -32767


//типизация
inline std::string toString(int valInt)
{
	std::ostringstream putStr;
	putStr << valInt;
	return putStr.str();
}
inline std::string toString(long valInt)
{
	std::ostringstream putStr;
	putStr << valInt;
	return putStr.str();
}
inline std::string toString(char* valInt)
{
	std::ostringstream putStr;
	putStr << valInt;
	return putStr.str();
}
inline std::string toString(float valInt)
{
	std::ostringstream putStr;
	putStr << valInt;
	return putStr.str();
}
inline std::string toString(double valInt)
{
	std::ostringstream putStr;
	putStr << valInt;
	return putStr.str();
}
inline std::string toString(unsigned int valInt)
{
	std::ostringstream putStr;
	putStr << valInt;
	return putStr.str();
}
inline std::string toString(unsigned long int valInt)
{
	std::ostringstream putStr;
	putStr << valInt;
	return putStr.str();
}
inline char* _toString(int valInt)
{
	char *pStr;
	char buffer[16];
	pStr = itoa(valInt, buffer, 10);
	return pStr;
}
inline char* toChar(std::string valInt)
{
	char* resUlt_ = new char[valInt.size()];
	for(int i = 0; i < valInt.size(); i++)
		resUlt_ += valInt.at(i);
	return resUlt_;
}
inline int toInt(std::string valInt)
{
	int valueInt = 0;
	valueInt = atoi(valInt.c_str());
	return valueInt;
}
inline int toInt(char* valInt)
{
	int valueInt = 0;
	valueInt = atoi(valInt);
	return valueInt;
}
inline int toInt(float valInt)
{
	return (int)valInt;
}
inline int toInt(double valInt)
{
	return (int)valInt;
}
inline float toFloat(std::string valInt)
{
	float valueInt = 0;
	valueInt = atof(valInt.c_str());
	return valueInt;
}
inline float toFloat(int valInt)
{
	return (float)valInt;
}
inline double toDouble(std::string valInt)
{
	double valueInt = 0;
	valueInt = atof(valInt.c_str());
	return valueInt;
}
inline double toDouble(int valInt)
{
	return (double)valInt;
}

//добавляет ноль в начале
inline void zerroNdQt(std::string & source_)
{
	if(source_.size() == 1)
	{
		std::string s_s = '0' + source_;
		source_ = s_s;
	}
}
inline std::string zerroNdQt(std::string source_)
{
	if(source_.size() == 1)
	{
		std::string s_s = '0' + source_;
		source_ = s_s;
	}
	return source_;
}
inline char* zerroNdQt(char * source_)
{
	if(strlen(source_)== 1)
	{
		char *s_s='0' + source_;
		source_ = s_s;
	}
	return source_;
}

//Строка наоборот
char * Revers(char * source_)
{
	char * tmpStr_;
	for(int i = strlen(source_) - 1; i > -1; i--)
		tmpStr_ += source_[i];
	return tmpStr_;
}
std::string Revers(std::string source_)
{
	std::string tmpStr_;
	for(int i = source_.size() - 1; i > -1; i--)
		tmpStr_ += source_.at(i);
	return tmpStr_;
}

//округляет в меньшую сторону
float Round(float Argument, int Precision)
{ 
	float div = 1.0;
	if(Precision < 0) while(Precision++) div /= 10.0;
	else while(Precision--) div *= 10.0;
	return floor(Argument * div + 0.5) / div;
}
double Round(double Argument, int Precision)
{ 
	double div = 1.0;
	if(Precision < 0) while(Precision++) div /= 10.0;
	else while(Precision--) div *= 10.0;
	return floor(Argument * div + 0.5) / div;
}
int Round(int Argument, int Precision)
{
	if (toString(Argument).size() < toString(Precision).size())
	{
		return Argument;
	}

	int div = 0;
	if(Precision < 0) Precision = abs(Precision);
	std::string konst = toString(Argument);

	std::string tmCh, tmSh;

	for(int i = konst.size() - 1; i > -1; i--)
	{
		if (i == konst.size() - 1 - Precision)
		{
			for(int j = tmSh.size() - 1; j > -1; j--)
				tmCh += konst.at(j);
			break;
		}
		tmSh += konst.at(i);
	}
	tmCh = Revers(tmCh);
	tmSh = Revers(tmSh);

	konst = tmCh + "." + tmSh;
	int cellw = toInt(Round(toFloat(konst), 2));
	return cellw;
}
int Round(unsigned int Argument, int Precision)
{
	if (toString(Argument).size() < toString(Precision).size())
	{
		return Argument;
	}

	int div = 0;
	if(Precision < 0) Precision = abs(Precision);
	std::string konst = toString(Argument);

	std::string tmCh, tmSh;

	for(int i = konst.size() - 1; i > -1; i--)
	{
		if (i == konst.size() - 1 - Precision)
		{
			for(int j = tmSh.size() - 1; j > -1; j--)
				tmCh += konst.at(j);
			break;
		}
		tmSh += konst.at(i);
	}
	tmCh = Revers(tmCh);
	tmSh = Revers(tmSh);

	konst = tmCh + "." + tmSh;
	int cellw = toInt(Round(toFloat(konst), 2));
	return cellw;
}
int Round(unsigned long int Argument, int Precision)
{
	if (toString(Argument).size() < toString(Precision).size())
	{
		return Argument;
	}

	int div = 0;
	if(Precision < 0) Precision = abs(Precision);
	std::string konst = toString(Argument);

	std::string tmCh, tmSh;

	for(int i = konst.size() - 1; i > -1; i--)
	{
		if (i == konst.size() - 1 - Precision)
		{
			for(int j = tmSh.size() - 1; j > -1; j--)
				tmCh += konst.at(j);
			break;
		}
		tmSh += konst.at(i);
	}
	tmCh = Revers(tmCh);
	tmSh = Revers(tmSh);

	konst = tmCh + "." + tmSh;
	int cellw = toInt(Round(toFloat(konst), 2));
	return cellw;
}

//округляет в меньшую сторону
float _Round(float Argument, int Precision)
{ 
	float div = 1.0;
	if(Precision < 0) while(Precision++) div /= 10.0;
	else while(Precision--) div *= 10.0;
	return ceil(Argument * div + 0.5) / div;
}
double _Round(double Argument, int Precision)
{ 
	double div = 1.0;
	if(Precision < 0) while(Precision++) div /= 10.0;
	else while(Precision--) div *= 10.0;
	return ceil(Argument * div + 0.5) / div;
}
int _Round(int Argument, int Precision)
{
	if (toString(Argument).size() < toString(Precision).size())
	{
		return Argument;
	}

	int div = 0;
	if(Precision < 0) Precision = abs(Precision);
	std::string konst = toString(Argument);

	std::string tmCh, tmSh;

	for(int i = konst.size() - 1; i > -1; i--)
	{
		if (i == konst.size() - 1 - Precision)
		{
			for(int j = tmSh.size() - 1; j > -1; j--)
				tmCh += konst.at(j);
			break;
		}
		tmSh += konst.at(i);
	}
	tmCh = Revers(tmCh);

	tmSh = Revers(tmSh);

	konst = tmCh + "." + tmSh;
	int cellw = toInt(Round(toFloat(konst), 0));
	return cellw;
}
//специальное округление для копеек
int __Round(int Argument, int Precision)
{
	if (toString(Argument).size() < toString(Precision).size())
	{
		return Argument;
	}
	if (toString(Argument).size() < 4)
	{
		return Argument;
	}
	int div = 0;
	if(Precision < 0) Precision = abs(Precision);
	std::string konst = toString(Argument);

	std::string tmCh, tmSh;

	for(int i = konst.size() - 1; i > -1; i--)
	{
		if (i == konst.size() - 1 - Precision)
		{
			for(int j = tmSh.size() - 1; j > -1; j--)
				tmCh += konst.at(j);
			break;
		}
		tmSh += konst.at(i);
	}
	tmCh = Revers(tmCh);
/*	if (tmSh == "00" || tmSh == "0")
	{
		tmSh = Revers(tmSh);
		konst = tmCh + "0";
		int cellw = toInt(konst);
		return cellw;
	}
	else
	{*/
		tmSh = Revers(tmSh);
		konst = tmCh + "." + tmSh;
		int cellw = toInt(Round(toFloat(konst), 0));
		return cellw;
	//}
}

//подсчитает колличество заданных символов
int p_divW(std::string source_, char Ch_i = 23)	
{
	int timer_ = 0;
	for(int i = 0; i < source_.size(); i++)
	{
		if (source_.at(i) == Ch_i)
		{
			timer_++;
		}
	}
	return timer_;
}

//вернет символы от введеной позиции до следующей
char * divW(char *source_, char Ch_i = 23, int pos_=0)
{
	int timer__ = 1;
	char * tmSource_ = "";
	for(int i = 0; i<strlen(source_); i++)
	{
		tmSource_ += source_[i];
		if (source_[i] == Ch_i)
		{
			tmSource_ == "";
			timer__ ++;
		}
		if (timer__ == pos_)
		{
			return tmSource_;
		}
	}
	return source_;
}
std::string divW(std::string source_, char Ch_i = 23, int pos_=0)
{
	int timer__ = 0;
	std::string tmSource_ = "";
	for(int i = 0; i < source_.size(); i++)
	{
		if (source_.at(i) != Ch_i)
		{
			tmSource_ += source_.at(i);
		}
		else
		{
			timer__ ++;
			if (timer__ != pos_)
			{
				tmSource_ = "";
			}
		}
		if (timer__ == pos_)
		{
			return tmSource_;
		}
	}
	return source_;
}

//проверяет корректность ввода даты
bool dtEntCont(std::string stringMain, std::string & dateGoods__)
{
	for (int i = 0; i < stringMain.length(); i++)
	{
		if (stringMain[i] == '/')
		{
			stringMain[i] = '.';
		}
		if (stringMain[i] ==  '-')
		{
			stringMain[i] = '.';
		}
	}
	stringMain += '.';

	int dayInt = 0, mounthInt = 0, yearInt = 0, tem_I = 0;
	std::string tem_S = "";

	for (int i = 0; i < stringMain.length(); i++)
	{
		if (stringMain[i] != '.')
			tem_S += stringMain[i];
		else 
		{
			tem_I = atoi(tem_S.c_str());
			if (tem_I > 1582 && tem_I < 4903)
			{
				yearInt = tem_I;
			}
			if (tem_I > 0 && tem_I < 13)
			{
				if (i > 2 && i < 8)
				{
					mounthInt = tem_I;
				}
			}
			if (tem_I > 0 && tem_I < 32) 
			{
				if (i < 3 || i > 7)
				{
					dayInt = tem_I;
				}
			}
			tem_S = "";	
		}
	}
	if (yearInt < 1 || mounthInt < 1 || dayInt < 1)
		return false;

	switch (mounthInt)
	{
	case 2: 
		if ((yearInt %4 == 0 && yearInt %100 != 0) || (yearInt %400 == 0))
		{
			if (dayInt > 29)
			{
				std::cout<<yearInt % 4<<std::endl;
				printf("In Febrary of this year there have to be no more than 29 days\n"); 
				return false;
			}
		}
		else
		{
			if (dayInt > 28)
			{
				std::cout<<yearInt % 4<<std::endl;
				printf("In Febrary of this year there have to be no more than 28 days\n"); 
				return false;
			}
		}
		break;
	case 4: 
		if (dayInt > 30)
		{
			printf("In April of this year there have to be no more than 30 days\n"); 
			return false;
		}
		break;
	case 6: 
		if (dayInt > 30)
		{
			printf("In June of this year there have to be no more than 30 days\n"); 
			return false;
		}
		break;
	case 9: 
		if (dayInt > 30)
		{
			printf("In September of this year there have to be no more than 30 days\n"); 
			return false;
		}
		break;
	case 11: 
		if (dayInt > 30)
		{
			printf("In November of this year there have to be no more than 30 days\n"); 
			return false;
		}
		break;
		default : break;
	}
	dateGoods__ = zerroNdQt(toString(dayInt)) + "." + zerroNdQt(toString(mounthInt)) + "." + toString(yearInt);
	//printf("\t%d.%d.%d\n", dayInt, mounthInt, yearInt);
	return true;
}

//выдает нужный реквизит даты
int dtValCont(std::string stringMain, int value_)
{
	for (int i = 0; i < stringMain.size(); i++)
	{
		if (stringMain.at(i) == '/')
			stringMain.at(i) = '.';
		if (stringMain.at(i) ==  '-')
			stringMain.at(i) = '.';
	}
	stringMain += '.';

	int dayInt = 0, mounthInt = 0, yearInt = 0, tem_I = 0;
	std::string tem_S = "";

	for (int i = 0; i < stringMain.length(); i++)
	{
		if (stringMain[i] != '.')
			tem_S += stringMain[i];
		else 
		{
			tem_I = atoi(tem_S.c_str());
			if (tem_I > 1582 && tem_I < 4903)
				yearInt = tem_I;
			if (tem_I > 0 && tem_I < 13)
				if (i > 2 && i < 8)
					mounthInt = tem_I;
			if (tem_I > 0 && tem_I < 32) 
				if (i < 3 || i > 7)
					dayInt = tem_I;
			tem_S = "";	
		}
	}
	if (yearInt < 1 || mounthInt < 1 || dayInt < 1)
		return 0;

	switch (value_)
	{
	case 1: return dayInt; 
	case 2: return mounthInt; 
	case 3: return yearInt;
	default: return 0;
	}
}

//разница между двумя датами
int tDtIntDif_B(std::string Source_dO, std::string Source_dS, bool return_max = false)
{
	Source_dO += ".";
	Source_dS += ".";

	int y_int_O = 0;
	int y_int_S = 0;

	//считаем месяц
	if (toInt(divW(Source_dO, 46, 3)) > toInt(divW(Source_dS, 46, 3)))	//если год ПЕРВОЙ даты БОЛЬШЕ года ВТОРОЙ даты то
	{
		int tmp_int = 0;
		for (int i = toInt(divW(Source_dS, 46, 3)); i < toInt(divW(Source_dO, 46, 3)) + 1; i++)
		{
			if (((i %4 == 0 && i %100 != 0) || (i %400 == 0)))
			{
				tmp_int++;
			}
		}
		y_int_O = toInt(divW(Source_dO, 46, 3)) % toInt(divW(Source_dS, 46, 3)) * 365 + tmp_int;
	}
	if (toInt(divW(Source_dO, 46, 3)) < toInt(divW(Source_dS, 46, 3)))	//если год ВТОРОЙ даты БОЛЬШЕ года ПЕРВОЙ даты то
	{
		int tmp_int = 0;
		for (int i = toInt(divW(Source_dO, 46, 3)); i < toInt(divW(Source_dS, 46, 3)) + 1; i++)
		{
			if (((i % 4 == 0 && i %100 != 0) || (i %400 == 0)))
			{
				tmp_int++;
			}
		}
		y_int_S = toInt(divW(Source_dS, 46, 3)) % toInt(divW(Source_dO, 46, 3)) * 365 + tmp_int;
	}

	//считаем месяца
	int dateMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (toInt(divW(Source_dO, 46, 2)) > toInt(divW(Source_dS, 46, 2)))	//если месяц ПЕРВОЙ даты БОЛЬШЕ месяца ВТОРОЙ даты то
	{
		int tmp_int = 0;
		int tmp_intCd = 0;

		int m_int_O = toInt(divW(Source_dO, 46, 2))-1;
		for (int i = 0; i < m_int_O; i++)
			tmp_int += dateMonth[i];

		int m_int_S = toInt(divW(Source_dS, 46, 2))-1;
		for (int i = 0; i < m_int_S; i++)
			tmp_intCd += dateMonth[i];

		y_int_O += tmp_int - tmp_intCd;
	}
	if (toInt(divW(Source_dO, 46, 2)) < toInt(divW(Source_dS, 46, 2)))	//если месяц ПЕРВОЙ даты МЕНЬШЕ месяца ВТОРОЙ даты то
	{
		int tmp_int = 0;
		int tmp_intCd = 0;

		int m_int_O = toInt(divW(Source_dO, 46, 2))-1;
		for (int i = 0; i < m_int_O; i++)
			tmp_int += dateMonth[i];

		int m_int_S = toInt(divW(Source_dS, 46, 2))-1;
		for (int i = 0; i < m_int_S; i++)
			tmp_intCd += dateMonth[i];

		y_int_S += tmp_intCd - tmp_int;
	}

	//считаем дни
	if (toInt(divW(Source_dO, 46, 1)) > toInt(divW(Source_dS, 46, 1)))	//если день ПЕРВОЙ даты БОЛЬШЕ дня ВТОРОЙ даты то
	{
		y_int_O += toInt(divW(Source_dO, 46, 1)) - toInt(divW(Source_dS, 46, 1));
	}
	if (toInt(divW(Source_dO, 46, 1)) < toInt(divW(Source_dS, 46, 1)))	//если день ПЕРВОЙ даты МЕНЬШЕ дня ВТОРОЙ даты то
	{
		y_int_S += toInt(divW(Source_dS, 46, 1))  - toInt(divW(Source_dO, 46, 1));
	}

	if (return_max)
	{
		if(y_int_S > y_int_O)
			return y_int_S;
		if(y_int_S < y_int_O)
			return y_int_O;
		if(y_int_S == y_int_O)
			return y_int_O;
	}
	return y_int_O;
}

//системное время 
std::string sysTime(char deEl = ':', int _mode = 0)
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	std::string resultTime;
	if (_mode == 0)
	{
		resultTime = zerroNdQt(toString(st.wDay)) + deEl + zerroNdQt(toString(st.wMonth)) + deEl + toString(st.wYear);
		return resultTime;
	}
}

//найти процент от суммы
float IntProc(int _MaInt, int Procent_, int round = 0)
{
	float maint_ = _MaInt / 100 * Procent_;
	if (round != 0)
	{
		maint_ = Round(maint_, round);
	}
	return maint_;
}
float IntProc(float _MaInt, int Procent_, int round = 0)
{
	float maint_ = _MaInt / 100 * Procent_;
	if (round != 0)
	{
		maint_ = Round(maint_, round);
	}
	return maint_;
}
double IntProc(double _MaInt, int Procent_, int round = 0)
{
	double maint_ = _MaInt / 100 * Procent_;
	if (round != 0)
	{
		maint_ = Round(maint_, round);
	}
	return maint_;
}

//очистить пробелы вначале и в конце
void Ecq_23(std::string & source_)
{
    size_t index;
    size_t strBegin = source_.find_first_not_of(' ');
    size_t strEnd = source_.find_last_not_of(' ');
    while(((index=source_.find(' ')) != std::string::npos)&&(index<strBegin))
        source_.erase(index, 1);
    while((index=source_.find(' ', strEnd)) != std::string::npos)
        source_.erase(index, 1);
}

//Разрешенный Ввод
bool Resolve_(char * source_)
{
	char *_Resolve = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM '";
	for (int i = 0; i < strlen(source_); i++)
	{
		int j = strlen(_Resolve);
		for (j; j > -1; j --)
		{
			if (source_[i] == _Resolve[j])
			{
				break;
			}
		}
		if (j == 0)
			return false;
	}
	return true;
}
bool Resolve_(std::string source_)
{
	std::string _Resolve = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM '";
	for (int i = 0; i < source_.size(); i++)
	{
		int j = _Resolve.size() - 1;
		for (j; j > -1; j --)
		{
			if (source_.at(i) == _Resolve.at(j))
			{
				break;
			}
		}
		if (j < 0)
			return false;
	}
	return true;
}
bool Resolve_(std::string source_, bool re)
{
	std::string _Resolve = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM '1234567890";
	for (int i = 0; i < source_.size(); i++)
	{
		int j = _Resolve.size() - 1;
		for (j; j > -1; j --)
		{
			if (source_.at(i) == _Resolve.at(j))
			{
				break;
			}
		}
		if (j < 0)
			return false;
	}
	return true;
}

//выдает рандом
int RandInt (int f_V = 0, int maX = 1)
{

	if (f_V > RAND_U_V)
		f_V = RAND_U_V;
	if (f_V < RAND_D_V)
		f_V = RAND_D_V;
	if (f_V == 0)
		f_V = RAND_U_V;
	if (maX == 1)
		return rand() % f_V;
	else
	{
		int GTmI = 0;
		maX = abs(maX);
		for(int i = 0; i < maX; i++)
		{
			GTmI += ((rand() % (int)(f_V / 3) + 1) * (rand() % f_V) / M_E * M_LOG2E * M_PI_2 / M_SQRT1_2);
			GTmI *= rand() % 8 + 1 * M_E;
		}
		return GTmI;
	}
}
int RandInt_l (int f_V, int s_V, int maX = 1)
{
	if (s_V > RAND_U_V)
		s_V = RAND_U_V;
	if (s_V < RAND_D_V)
		s_V = RAND_D_V;
	if (s_V == 0)
		s_V = RAND_U_V;
		
	if (f_V > RAND_U_V)
		f_V = RAND_U_V;
	if (f_V < RAND_D_V)
		f_V = RAND_D_V;
	if (f_V == 0)
		f_V = RAND_U_V;
	if (maX == 1)
		return s_V + rand() % f_V;
	else
	{
		int GTmI = 0, GTmJ = 0;
		maX = abs(maX);
		for(int i = 0; i < maX; i++)
		{
			GTmI += (s_V + rand() % f_V) / (s_V + rand() % s_V + 3);
			GTmI *= s_V + 3;
		}
		return s_V + rand() % f_V;
	}
}

//Нижний регистр
char* DownKW(char* source_)
{
	char table[27] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
	for(int i = 0; i < sizeof(source_) -1 ; i++)
		source_[i] = table[source_[i]];
	return source_;
}
std::string DownKW(std::string source_)
{
	std::string LTable_ = "qwertyuiopasdfghjklzxcvbnm";
	std::string UTable_ = "QWERTYUIOPASDFGHJKLZXCVBNM";
	std::string source_Cont;
	for(int i=0; i < source_.size(); i++)
	{
		int j;
		for(j = 0; j < LTable_.size(); j++)
		{
			if (source_.at(i) == UTable_.at(j))
			{
				source_Cont += LTable_.at(j);
				break;
			}
		}
		if (j == LTable_.size())
			source_Cont += source_.at(i);
	}
	return source_Cont;
}

//Проверка на цифры
bool isNumber(std::string source_)
{
	for (int i = 0; i < source_.size(); i++)
	{
		if ((source_.at(i) < 48 || source_.at(i) > 57))
		{
			return false;
		}
	}
	return true;
}
#endif
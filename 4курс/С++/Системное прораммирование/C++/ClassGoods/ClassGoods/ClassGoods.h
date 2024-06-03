#ifndef CLASS_GOODS_H
#define CLASS_GOODS_H

#include <iostream>

#include <string>
#include <sstream>

#include <atltime.h>
#include <direct.h>
#include <fstream>

#include <algorithm>

#include "TimesClass.h"
#include "functions.h"

#define ST_P_FILE "teset.dxt"
#define PUTH_ "E:\\"
#define GOODS_P_FILE "goods.dxt"


class MoneyClass {

public:
	MoneyClass()
	{
		_rub = 0;
		_kopek = 0;
		_summatr = 0.0;
		f_OutString = "";
	}

	friend std::ostream& operator << (std::ostream& streamE, const MoneyClass & f_inS);
	bool isMoney(std::string & source_);
	std::string f_OutString;
	std::string toString_M();	
	std::string moneyPlus(std::string string_first = "0.0", std::string string_second = "0.0");
	std::string moneyMiltipli(std::string string_first = "0.0", std::string string_second = "0.0");
	std::string moneyMinus(std::string string_first = "0.0", std::string string_second = "0.0");
	std::string moneyDivide(std::string string_first = "0.0", std::string string_second = "0.0");
	std::string moneyDifirence(std::string string_first = "0.0", std::string string_second = "0.0");

private:
	long _rub;
	int _kopek;
	float _summatr;

	bool SymbExR(char Symbol_, int tupical_ = 0);
	int cantMultZero(int sourceInt);
	int intPositionKopek(std::string source_, const bool multi_ = false);
	std::string kopekMaxControl(std::string source_);
};

int MoneyClass::cantMultZero(int sourceInt)
{
/*		if (sourceInt == 0)
		sourceInt++;*/
	return sourceInt;
}

int MoneyClass::intPositionKopek(std::string source_, const bool multi_)
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

bool MoneyClass::isMoney(std::string & source_)
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

bool MoneyClass::SymbExR(char Symbol_, int tupical_)
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

std::string MoneyClass::toString_M()
{
	return f_OutString;
}

std::string MoneyClass::moneyPlus(std::string string_first, std::string string_second)
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

std::string MoneyClass::moneyMiltipli(std::string string_first, std::string string_second)
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

std::string MoneyClass::moneyMinus(std::string string_first, std::string string_second)
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

std::string MoneyClass::moneyDivide(std::string string_first, std::string string_second)
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

std::string MoneyClass::moneyDifirence(std::string string_first, std::string string_second)
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

std::string MoneyClass::kopekMaxControl(std::string source_)
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

std::ostream& operator << (std::ostream& streamE, const MoneyClass & f_inS)
{
	streamE << f_inS.f_OutString;
	return streamE;
}



class GoodsClass {

public:
	int numberGoods_;				//Номер товара
	int consignmentGoods_;			//Номер номенклатуры/номер документа
	int timerGoods;					//Количество товаров

	double priceGoods_;				//Цена

	std::string nameGoods_;			//Имя товара
	std::string dateGoods_;			//Дата оформления

	GoodsClass()
	{
		numberGoods_ = 0;
		nameGoods_ = "";
		dateGoods_ = "00.00.0000";
		priceGoods_ = 0;
		priceGoods_TmC = 0;
		consignmentGoods_ = 0;
		timerGoods = 0;
	}

	void createGoods();
	void ShGoods();
	void SaveGoods();
	void ShGoods_t();
	void ChGoods(char ChModeT_ = '0');
	void DelayGoods_Switch(char ChMode = '2');
	void DelayGoods_(std::string dT_O = "", std::string dT_S = "");

protected: 
	std::string delayGoods_;		//Просрочка
	std::string goodsCont;			//Товары
	MoneyClass symGoods_;			//Общая стоимость
	double priceGoods_TmC;			//Копия Цена

private:
	std::string p_fileString;
	std::string p_fileStringGoods;
	std::string enTimLine();
	bool FileExists(std::string source_ = ST_P_FILE);
	bool AQLCreateDirectory(LPCTSTR sPathTo);
	int posArrSr();
	int autoNumberGoods();
	int autoNumberConsignment();
	int intNum();
	double PriceIn();
	bool SymbExR(char Symbol_, int tupical_ = 0);
	void nameGoods();
//ofstream для записи ifstream для чтения ЗАПОМНИ наконец
/*	GoodsClass(std::string source_ = ST_P_FILE, int trigger_ = 0)
	{
		if (source_ == ST_P_FILE || source_ == "0" || source_ == "")
		{
			if (!FileExists(ST_P_FILE))
			{
				std::ofstream streamFile(source_);
				streamFile.close();
			}
			p_fileString = source_;
		}
		else
		{
			if (trigger_ == 1)
			{
				for (int i = 0; i < source_.size(); i++)
					if (source_.at(i) == '/')
						source_ = source_.replace(i, 1, "\\");

			}
			else
			{
				std::string tempString = "";
				for (int i = source_.size() - 1; i >= 0; i--)
				{
					if (source_.at(i) != '/' || source_.at(i) != '\\')
						tempString += source_.at(i);
				}

				source_ = tempString;
				tempString = "";

				for (int i = source_.size() - 1; i >= 0; i--)
						tempString += source_.at(i);

				source_ = tempString;
			}
			
			if (!FileExists(source_))
			{
				if (trigger_ == 1)
				{
					LPCTSTR sPathTo = (LPCTSTR) source_.c_str();
					AQLCreateDirectory(sPathTo);
					p_fileString = source_;
				}
				else
				{
					std::ofstream streamFile(source_);
					if (streamFile.is_open())
						p_fileString = source_;
					else
						std::cout << "Cant create file" << std::endl;
					streamFile.close();
				}
			}
			else
				p_fileString = source_;
		}
		p_fileStringGoods = GOODS_P_FILE;
		std::ofstream streamFile(GOODS_P_FILE);
		streamFile.close();*/


	//Изменить текущий товар
};

void GoodsClass::createGoods()
{
	if (nameGoods_ != "")
	{
		char choise_;
		std::cout << "You have not kept goods. Do you want to continue?y/n" << std::endl;
		std::cin >> choise_;
		if (choise_  == 'n')
		{
			return;
		}
	}

	std::cout << "Name Goods: ";
	nameGoods();
		
	std::cout << "Number Goods: ";
	numberGoods_ = intNum();

	std::cout << "Date Receipt: ";
	dateGoods_ = enTimLine();
		
	std::cout << "Price Goods: ";
	PriceIn();
		
	std::cout << "Number Document: ";
	consignmentGoods_ = intNum();

	std::cout << "Timer Goods: ";
	timerGoods = intNum();

	symGoods_.moneyMiltipli(toString(priceGoods_), toString(timerGoods));
	return ;
}

void GoodsClass::ShGoods()
{
	std::cout << "Goods #" << numberGoods_ << std::endl;
	std::cout << "\tName: " << nameGoods_ << std::endl;
	std::cout << "\tDate: " << dateGoods_ << std::endl;
	std::cout << "\tPrice: " << priceGoods_ << std::endl;
	std::cout << "\tNumber: " << consignmentGoods_ << std::endl;
	std::cout << "\tTimer: " << timerGoods << std::endl;
	std::cout << "\tSumm: " << symGoods_ << std::endl;
}

void GoodsClass::SaveGoods()
{
	int GoodsNow = goodsCont.size(), goods_int = 0;
	goodsCont = "{"+toString(posArrSr()) + "=[" + toString(numberGoods_) + "]" + "[" + nameGoods_ + "]" + "[" +  dateGoods_ + "]" + "[" + toString(priceGoods_) + "]" + "[" + toString(consignmentGoods_) + "]" + "[" + toString(timerGoods) + "]" + "[" + symGoods_.toString_M() + "]}";

	numberGoods_ = 0;
	nameGoods_ = "";
	dateGoods_ = "00.00.0000";
	priceGoods_ = 0.0;
	consignmentGoods_ = 0;
	timerGoods = 0;
}

void GoodsClass::ShGoods_t()
{
	std::string tmpOut;
	if (goodsCont == "")
		return;

	for (int i = 0; i < goodsCont.size(); i++)
	{
		if(goodsCont.at(i) == '{')
		{
			tmpOut="";
			std::string temp1="";

			int j = 0;
			for(j; goodsCont.at(j) != '}'; j++)
			{
				tmpOut += goodsCont.at(j);
			}
			i=j;
			int timer_ = 0;
			for(int tjI = 0; tjI < tmpOut.size(); tjI++)
			{
				temp1 = "";
				if (tmpOut.at(tjI) == '[')
				{
					int tjIInt = 0;
					for(tjIInt = tjI+1; tmpOut.at(tjIInt) != ']'; tjIInt++)
					{
						temp1 += tmpOut.at(tjIInt);
					}
					tjI = tjIInt;
					
					switch (timer_)
					{
					case 0: 
						std::cout << "Goods #" << temp1 << std::endl;
						break;
					case 1: 
						std::cout << "\tName: " << temp1 << std::endl;
						break;
					case 2: 
						std::cout << "\tDate: " << temp1 << std::endl;
						break;
					case 3: 
						std::cout << "\tPrice: " << temp1 << std::endl;
						break;
					case 4: 
						std::cout << "\tNumber: " << temp1 << std::endl;
						break;
					case 5: 
						std::cout << "\tTimer: " << temp1 << std::endl;
						break;
					case 6: 
						std::cout << "\tSumm: " << temp1 << std::endl;
						break;
					default : break;
					}
					timer_++;
				}
			}
		}
	}
		/*std::cout << "Goods #" << poStrInG[i][j++] << std::endl;
		std::cout << "\tName: " << poStrInG[i][j++] << std::endl;
		std::cout << "\tDate: " << poStrInG[i][j++] << std::endl;
		std::cout << "\tPrice: " << poStrInG[i][j++] << std::endl;
		std::cout << "\tNumber: " << poStrInG[i][j++] << std::endl;
		std::cout << "\tTimer: " << poStrInG[i][j++] << std::endl;
		std::cout << "\tSumm: " << poStrInG[i][j++] << std::endl;*/
			
		std::cout << "\n" << std::endl;
}

void GoodsClass::ChGoods(char ChModeT_)
{
	if (nameGoods_.size() < 3)
	{
		std::cout << "You cant change Goods requisite while you haven't create Goods"<< std::endl;
		return;
	}
	switch (ChModeT_)
	{
		case '1': 
			std::cout << "Name Goods: " << nameGoods_ << "-> ";
			nameGoods();
			break;
		case '2': 
			std::cout << "Number Goods: " << numberGoods_ << "-> ";
			numberGoods_ = intNum();
			break;
		case '3': 
			std::cout << "Timer Goods: " << timerGoods << "-> ";
			timerGoods = intNum();
			symGoods_.moneyMiltipli(toString(priceGoods_), toString(timerGoods));
			break;
		case '4': 
			std::cout << "Price Goods: " << priceGoods_ << "-> ";
			PriceIn();
			symGoods_.moneyMiltipli(toString(priceGoods_), toString(timerGoods));
			break;
		case '5': 
			std::cout << "Date Receipt: " << dateGoods_ << "-> ";
			dateGoods_ = enTimLine();
			break;
		case '6': 
			std::cout << "Number Document: " << consignmentGoods_ << "-> ";
			consignmentGoods_ = intNum();
			break;
		case '0': 
			std::cout << "Name Goods: " << numberGoods_ << "-> ";
			nameGoods();
			std::cout << "Number Goods: " << numberGoods_ << "-> ";
			numberGoods_ = intNum();
			std::cout << "Timer Goods: " << timerGoods << "-> ";
			timerGoods = intNum();
			std::cout << "Price Goods: " << priceGoods_ << "-> ";
			PriceIn();
			symGoods_.moneyMiltipli(toString(priceGoods_), toString(timerGoods));
			std::cout << "Date Receipt: " << dateGoods_ << "-> ";
			dateGoods_ = enTimLine();
			std::cout << "Number Document: " << consignmentGoods_ << "-> ";
			consignmentGoods_ = intNum();
			break;
		default : return;
	}
}

void GoodsClass::DelayGoods_Switch(char ChMode)
{
	if (nameGoods_.size() < 3)
	{
		std::cout << "You cant change Goods requisite while you haven't create Goods"<< std::endl;
		return;
	}
	std::string dT_O = "", dT_S = "";
	switch (ChMode)
	{
		case '1': 
			std::cout << "Begin Date: " << sysTime('.') << " End Date: ";
			dT_O = sysTime('.');
			dT_S = enTimLine();

			DelayGoods_(dT_O, dT_S);
			break;
		case '2': 
			std::cout << "Begin Date: ";
			dT_O = enTimLine();

			std::cout << " End Date: ";
			dT_S = enTimLine();

			DelayGoods_(dT_O, dT_S);
			break;
		case '3': 
			std::cout << "Begin Date: " << dateGoods_ << " End Date: ";
			dT_O = dateGoods_;
			dT_S = enTimLine();

			DelayGoods_(dT_O, dT_S);
			break;
		case '4': 
			std::cout << "Begin Date: " << dateGoods_ << " End Date: " << sysTime('.');
			dT_O = dateGoods_;
			dT_S = sysTime('.');

			DelayGoods_(dT_O, dT_S);
			break;
		case '5': 
			std::cout << "Begin Date: " << sysTime('.') << " End Date: " << dateGoods_;
			dT_O = sysTime('.');
			dT_S = dateGoods_;

			DelayGoods_(dT_O, dT_S);
			break;
		case '0':
			priceGoods_ = priceGoods_TmC;
			symGoods_.moneyMiltipli(toString(priceGoods_TmC), toString(timerGoods));
			break;
		default: return;
	}
}

void GoodsClass::DelayGoods_(std::string dT_O, std::string dT_S)
{
	if (dT_O.size() == 0)
		dT_O = sysTime('.');
	if (dT_S.size() == 0)
		dT_S = dateGoods_;

	//int days_ofDelay = tDtIntDif_B(dT_O, dT_S);
	double DelayIndWx = (IntProc(priceGoods_TmC, 1, 2) * tDtIntDif_B(dT_O, dT_S));
	priceGoods_ -= DelayIndWx;
	symGoods_.moneyMiltipli(toString(priceGoods_), toString(timerGoods));
	std::cout << "\n New Delay = " << DelayIndWx << " New Price = " << priceGoods_ << std::endl;
}

void GoodsClass::nameGoods()
{
	bool exit_ = false;
	std::string OutStr_;
	while (!exit_)
	{
		OutStr_ = "";
		std::getline(std::cin, OutStr_);
		if (OutStr_.size() > 3)
		{
			nameGoods_ = OutStr_;
			exit_ = true;
		}
		std::cin.clear();
	}
}

bool GoodsClass::FileExists(std::string source_)
{
	LPCTSTR fname = (LPCTSTR) source_.c_str();
	return::GetFileAttributes(fname) != DWORD(-1);
}	

bool GoodsClass::AQLCreateDirectory(LPCTSTR sPathTo)
{
	bool bRet = sPathTo ? TRUE : FALSE;
	while( bRet && (bRet = CreateDirectory(sPathTo, NULL)) == FALSE)
	{
		__try 
		{
			int k = lstrlen( sPathTo);
			if( k >= MAX_PATH) 
				break;
				LPTSTR   sTemp = LPTSTR( _alloca( (k + 1) * sizeof(TCHAR)));
			lstrcpy( sTemp, sPathTo);
				
			while( k && sTemp[ k] != TCHAR('\\') && sTemp[ k] != TCHAR('/')) --k;
				if( k <= 0) break;
					sTemp[ k] = TCHAR( '\0');
				
			bRet = AQLCreateDirectory(sTemp);
		} 
		__except( GetExceptionCode() == STATUS_STACK_OVERFLOW) 
		{
			break; 
		}
	}
	return bRet;
}

bool GoodsClass::SymbExR(char Symbol_, int tupical_)
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
	
int GoodsClass::posArrSr()
{
	if (goodsCont == "")
	{
		return 0;
	}
	int pos_ = 0;
	std::string tempStr = "", tmpOut="";

	for (int i = 0; i < goodsCont.size(); i++)
	{
		tempStr = goodsCont.at(i);
		if(goodsCont.at(i) == '{')
		{
			tmpOut = "";
			for(int j = 0; tempStr.at(j) != '='; j++)
			{
				tmpOut += tempStr.at(j);
			}
			pos_ = toInt(tmpOut);
		}
	}
	return pos_;
}

int GoodsClass::autoNumberGoods()
{
	std::ifstream streamFile(p_fileStringGoods, std::ios_base::in);
	int outInt = 0;

	if (streamFile.is_open())
	{
		int timer_ = 0;
		std::string bufString;

		while(std::getline(streamFile, bufString))
		{
			timer_ = bufString.find("|");
			std::string tempString = "";

			for (int i = timer_; i < bufString.size(); i++)
				tempString += bufString.at(i);

			outInt = toInt(tempString) + 1;
			bufString = "";
		}
	}
	streamFile.close();
	return outInt;
}

int GoodsClass::autoNumberConsignment()
{
	std::ifstream streamFile(p_fileStringGoods, std::ios_base::in);
	int outInt = 0;

	if (streamFile.is_open())
	{
		int timer_ = 0;
		std::string bufString;
		while(std::getline(streamFile, bufString))
		{
			timer_ = bufString.find("|");
			std::string tempString = "";

			for (int i = timer_; i < bufString.size(); i++)
				tempString += bufString.at(i);

			outInt = toInt(tempString) + 1;
			bufString = "";
		}
	}
	streamFile.close();
	return outInt;
}

int GoodsClass::intNum()
{
	int outInt_;
	bool exit_ = false;
	std::string tempOut="";

	while (!exit_)
	{
		std::string tempStr = "";
		std::getline(std::cin, tempStr);
		for (int i = 0; i < tempStr.size(); i++)
		{
			if (!SymbExR(tempStr.at(i), 1))
			{
				std::cin.clear();
				std::cout << "Error, try again" << std::endl;
				exit_ = false;
				break;
			}
			else
			{
				tempOut+=tempStr.at(i);
				if(exit_!=true)
				{
					exit_ = true;
				}
			}
		}
	}
	outInt_ = toInt(tempOut);
	return outInt_;
}

double GoodsClass::PriceIn()
{
	bool exit_ = false;
	std::string tempOut="";

	while (!exit_)
	{
		int timer_ = 0;
		std::string tempStr = "";
		std::getline(std::cin, tempStr);
		for (int i = 0; i < tempStr.size(); i++)
		{
			if (tempStr.at(i) == '.')
			{
				timer_++;
			}
			if (!SymbExR(tempStr.at(i)))
			{
				std::cin.clear();
				std::cout << "Error, try again" << std::endl;
				exit_ = false;
				break;
			}
			else
			{
				tempOut+=tempStr.at(i);
				if(exit_!=true)
				{
					exit_ = true;
				}
			}
		}
		if (timer_ > 1)
		{
			std::cin.clear();
			std::cout << "Error, try again" << std::endl;
			if(exit_==true)
			{
				exit_ = false;
			}
		}
		if (exit_ == true)
		{
			if (timer_ == 0)
			{
				tempOut+=".00";
			}
			if ( timer_ == 1)
			{
				tempOut = toString(Round(toDouble(tempOut), 2));
				int timer__ = 0;
				for (int i = tempOut.find('.') + 1; i < tempOut.size(); i ++)
					timer__++;
				if (timer__ > 2)
				{
					tempOut = tempOut.substr(0, timer__ + tempOut.find('.'));
				}
			}
		}
	}
		

	priceGoods_ = _Round(toDouble(tempOut), 2);
	priceGoods_TmC = priceGoods_;
	return priceGoods_;
}

std::string GoodsClass::enTimLine()
{
	bool exit_ = false;
	std::string tempOut="";

	std::string dateGoods__;
	while (!exit_)
	{
		dateGoods__="";
		std::getline(std::cin, dateGoods__);

		if (!dtEntCont(dateGoods__, dateGoods__))
		{
			std::cout << "Try to enter date in one of a format:\n\tDD.MM.YYYY\tDD-MM-YYYY\tDD/MM/YYYY";
			std::cout << "\n\tYYYY.MM.DD\tYYYY-MM-DD\tYYYY/MM/DD " << std::endl;
			std::cin.clear();
		}
		else
		{
			exit_ = true;
		}
	}

	return dateGoods__;
}

#endif
#include <iostream>
#include <string>
#include <sstream>
#include <atltime.h>
#include <cmath>


#define MAX_TIMER 80063


class TimeClass {

private:
	int _minute;
	int _hour;
	int _second;

	friend std::string enTimLine();
	friend std::ostream& operator << (std::ostream& streamE, const TimeClass & f_inS);
	friend bool corEnter(char temp_string, int natureDate = 0);
	friend bool operator ==(TimeClass const & a, TimeClass const & b);
	friend bool operator !=(TimeClass const & a, TimeClass const & b);
	friend bool operator >(TimeClass const & a, TimeClass const & b);
	friend bool operator <(TimeClass const & a, TimeClass const & b);
	friend bool operator >=(TimeClass const & a, TimeClass const & b);
	friend bool operator <=(TimeClass const & a, TimeClass const & b);

	std::string toString(int valInt)
	{
		std::ostringstream putStr;
		putStr << valInt;
		return putStr.str();
	}
	std::string toString(float valInt)
	{
		std::ostringstream putStr;
		putStr << valInt;
		return putStr.str();
	}
	int toInt(std::string valInt)
	{
		int valueInt = 0;
		valueInt = atoi(valInt.c_str());
		return valueInt;
	}
	void systemTime ()
	{
		SYSTEMTIME st;
		GetSystemTime(&st);

		this->_hour = st.wHour + 3; 
		this->_minute = st.wMinute; 
		this->_second = st.wSecond;
	}

	
public:
	std::string f_OutString;
	std::string f_OutSimbol;
	std::string WorkString;


	TimeClass(std::string inString = "h:m:s") 
	{
		_hour = 0; 
		_minute = 0; 
		_second = 0;

		if (inString.size() != 0)
			this->f_OutSimbol = preapairString(inString);
		WorkString = "0";
		f_OutString = "0";
	}
	~TimeClass(){};


	std::string toStr()
	{
		return WorkString;
	}

	TimeClass toStrT(TimeClass tcIn)
	{
		std::string entered = tcIn.toStr();
		return WorkString;
	}

//Время в настоящем
	std::string TimeNowStr() 
	{
		systemTime();
		return outStream(toString(_hour), toString(_minute), toString(_second));
	}
	
	std::string TimeNowInt() 
	{
		systemTime();
		int temp_int_Time = cantMultZero(_second) * cantMultZero(_minute) * cantMultZero(_hour);
		return f_OutString = toString(temp_int_Time);
	}

//Перевод времени
	std::string TimeInterpeInt(std::string timeIntOut)
	{
		_hour = 0;
		_minute = 0;
		_second = 0;

		int timer_ = 0;
		
		if (timeIntOut.size() == 0)
			return WorkString = "0";

		for(int i = 0; i < timeIntOut.size(); i++)
			if (corEnter(timeIntOut.at(i)))
				timer_++;

		if (timer_ > 3 || timer_ < 0)
			return WorkString = "0";

		if (timer_ == 2)
			for(int i = timeIntOut.size(); i > timeIntOut.size() - 1; i--)
				if (!corEnter(timeIntOut.at(i-1), 1))
					timeIntOut += "0";

		if (timer_ == 1)
		{
			for(int i = timeIntOut.size(); i > timeIntOut.size() - 2; i--)
				if (corEnter(timeIntOut.at(i-1), 1))
					timeIntOut += ":0";
				else
					timeIntOut += "0:0";
		}
		if (timer_ == 0)
			timeIntOut += ":0:0";


		for (int i = 0; i < f_OutSimbol.size(); i++)
		{
			switch (f_OutSimbol.at(i))
			{
				case 'h': 
					_hour = timeMaxControl(intPosition(timeIntOut, f_OutSimbol.at(i)), f_OutSimbol.at(i));
					break;
				case 'm': 
					_minute = timeMaxControl(intPosition(timeIntOut, f_OutSimbol.at(i)), f_OutSimbol.at(i));
					break;
				case 's':
					_second = timeMaxControl(intPosition(timeIntOut, f_OutSimbol.at(i)), f_OutSimbol.at(i));
					break;
				default: 
					break;
			}
		}
		if (_second == 0 && _minute == 0 && _hour == 0)
			return WorkString = toString(0);
			
		_second = cantMultZero(_second);
		_minute = cantMultZero(_minute);
		_hour = cantMultZero(_hour);

		int temp_int_Time = _second * _minute * _hour;
		return WorkString = toString(temp_int_Time);
	}

	std::string TimeInterpeStr(std::string timeIntOut = "0")
	{
		int timer_ = 0;
		for(int i = 0; i < timeIntOut.size(); i++)
			if (corEnter(timeIntOut.at(i)) == true)
				timer_++;
		if (timer_ != 0)
			return outStream();

		if (MAX_TIMER < toInt(timeIntOut))
			return outStream();
		int abseo = toInt(timeIntOut);

		int sourceHour_ = 0;
		for (int secondTimer = 1; secondTimer < 60; secondTimer++)
		{
			int temp_Int = 0;
			for (int minuteTimer = 1; minuteTimer < 60; minuteTimer++)
			{
				for (int hourTimer = 1; hourTimer < 24; hourTimer++)
				{
					temp_Int = hourTimer * minuteTimer * secondTimer;
					if (temp_Int == abseo)
					{
						sourceHour_ = hourTimer;
						break;
					}
				}
			}
		}

		int sourceMinute_ = 0;
		for (int secondTimer = 1; secondTimer < 60; secondTimer++)
		{
			int temp_Int = 0;
			for (int minuteTimer = 1; minuteTimer < 60; minuteTimer++)
			{
				temp_Int = sourceHour_ * minuteTimer * secondTimer;
				if (temp_Int == abseo)
				{
					sourceMinute_ = minuteTimer;
					break;
				}
			}
		}
		
		int sourceSecond_ = 0;
		for (int secondTimer = 1; secondTimer < 60; secondTimer++)
		{
			int temp_Int = 0;
			temp_Int = sourceHour_ * sourceMinute_ * secondTimer;
			if (temp_Int == abseo)
			{
				sourceSecond_ = secondTimer;
				break;
			}
		}

		return outStream(toString(sourceHour_), toString(sourceMinute_), toString(sourceSecond_));
	}


//Оператор =
	TimeClass swap(TimeClass & f_inS)
	{
		std::swap(WorkString, f_inS.WorkString);
		std::swap(f_OutString, f_inS.f_OutString);
		std::swap(_minute, f_inS._minute);
		std::swap(_hour, f_inS._hour);
		std::swap(_second, f_inS._second);
		std::swap(f_OutSimbol, f_inS.f_OutSimbol);
		return f_inS;
	}

	void swap_(const TimeClass & f_inS)
	{
		WorkString = f_inS.WorkString;
		f_OutString = f_inS.f_OutString;
		_minute = f_inS._minute;
		_hour = f_inS._hour;
		_second = f_inS._second;
		f_OutSimbol = f_inS.f_OutSimbol;
	}

	TimeClass operator = (const std::string & f_inS)
	{
		this-> WorkString = f_inS;
		return *this;
	}

	TimeClass operator = (const TimeClass & f_inS)
	{
		swap_(f_inS);
        return *this;
	}

//Бинарные операторы
	TimeClass operator + (const TimeClass & f_inS)
	{
		return this->TimePlus(WorkString, f_inS.WorkString);
	}
	TimeClass operator - (const TimeClass & f_inS)
	{
		return this->TimeMinus(WorkString, f_inS.WorkString);
	}
	TimeClass operator * (TimeClass & f_inS)
	{
		return this->TimeMultipli(WorkString, f_inS.WorkString);
	}
	TimeClass operator / (TimeClass & f_inS)
	{
		return this->TimeDivide(WorkString, f_inS.WorkString);
	}

	std::string enTimLine()
	{

	}

//Действия над временем
	std::string TimeDifference(std::string timeIn = "", std::string timeOut = "0")
	{
		int timeIn_int, timeOut_int;

		if (timeIn == "")
		{
			timeIn = WorkString;
		}

		if (needInterpre(timeIn) == true) timeIn_int = toInt(TimeInterpeInt(timeIn));
		else timeIn_int = toInt(timeIn);
		
		if (needInterpre(timeOut) == true) timeOut_int = toInt(TimeInterpeInt(timeOut));
		else timeOut_int = toInt(timeOut);

		timeIn_int = timeIn_int - timeOut_int;
		timeIn_int = abs(timeIn_int);

		return WorkString =  toString(timeIn_int);
	}

	std::string TimePlus(std::string timeIn = "", std::string timeOut = "0")
	{
		int timeIn_int, timeOut_int;

		if (timeIn == "")
			timeIn = WorkString;

		if (needInterpre(timeIn) == true) timeIn_int = toInt(TimeInterpeInt(timeIn));
		else timeIn_int = toInt(timeIn);
		
		if (needInterpre(timeOut) == true) timeOut_int = toInt(TimeInterpeInt(timeOut));
		else timeOut_int = toInt(timeOut);

		timeIn_int = timeIn_int + timeOut_int;

		return WorkString = toString(timeIn_int);
	}

	std::string TimeMinus(std::string timeIn = "", std::string timeOut = "0")
	{
		int timeIn_int, timeOut_int;

		if (timeIn == "")
			timeIn = WorkString;

		if (needInterpre(timeIn) == true) timeIn_int = toInt(TimeInterpeInt(timeIn));
		else timeIn_int = toInt(timeIn);
		
		if (needInterpre(timeOut) == true) timeOut_int = toInt(TimeInterpeInt(timeOut));
		else timeOut_int = toInt(timeOut);

		timeIn_int = timeIn_int - timeOut_int;

		return WorkString = toString(timeIn_int);
	}

	std::string TimeMultipli(std::string timeIn = "", std::string timeOut = "0")
	{
		int timeIn_int, timeOut_int;

		if (timeIn == "")
			timeIn = WorkString;

		if (needInterpre(timeIn) == true) timeIn_int = toInt(TimeInterpeInt(timeIn));
		else timeIn_int = toInt(timeIn);
		
		if (needInterpre(timeOut) == true) timeOut_int = toInt(TimeInterpeInt(timeOut));
		else timeOut_int = toInt(timeOut);

		timeIn_int = timeIn_int * timeOut_int;

		return WorkString = toString(timeIn_int);
	}

	std::string TimeDivide(std::string timeIn = "", std::string timeOut = "0")
	{
		int timeIn_int = 0, timeOut_int = 0;

		if (timeIn == "")
			timeIn = WorkString;

		if (needInterpre(timeIn) == true) timeIn_int = toInt(TimeInterpeInt(timeIn));
		else timeIn_int = cantMultZero(toInt(timeIn));
		
		if (needInterpre(timeOut) == true) timeOut_int = toInt(TimeInterpeInt(timeOut));
		else timeOut_int = cantMultZero(toInt(timeOut));

		timeIn_int = timeIn_int / timeOut_int;

		return WorkString = toString(timeIn_int);
	}

	std::string TimeСompare(std::string timeIn = "", std::string timeOut = "0")
	{
		int timeIn_int, timeOut_int;

		if (timeIn == "")
			timeIn = WorkString;

		if (needInterpre(timeIn) == true) timeIn_int = toInt(TimeInterpeInt(timeIn));
		else timeIn_int = toInt(timeIn);
		
		if (needInterpre(timeOut) == true) timeOut_int = toInt(TimeInterpeInt(timeOut));
		else timeOut_int = toInt(timeOut);

		if (timeIn_int <= timeOut_int)
			return WorkString = toString(timeOut_int);

		return WorkString = toString(timeIn_int);
	}

	std::string TimeToMinute(std::string timeIntOut = "")
	{
		if (timeIntOut == "")
			timeIntOut = WorkString;

		if (!needInterpre(timeIntOut))
		{
			int timeIn_int = toInt(timeIntOut) / 60;
			return toString(timeIn_int);
		}

		_hour = 0;
		_minute = 0;
		_second = 0;

		int timer_ = 0;
		
		if (timeIntOut.size() == 0)
			return WorkString = "0";

		for(int i = 0; i < timeIntOut.size(); i++)
			if (corEnter(timeIntOut.at(i)))
				timer_++;

		if (timer_ > 3 || timer_ < 0)
			return WorkString = "0";

		if (timer_ == 2)
			for(int i = timeIntOut.size(); i > timeIntOut.size() - 2; i--)
				if (!corEnter(timeIntOut.at(i-1), 1))
					timeIntOut += "0";

		if (timer_ == 1)
		{
			for(int i = timeIntOut.size(); i > timeIntOut.size() - 2; i--)
				if (corEnter(timeIntOut.at(i-1), 1))
					timeIntOut += ":0";
				else
					timeIntOut += "0:0";
		}
		if (timer_ == 0)
			timeIntOut += ":0:0";


		for (int i = 0; i < f_OutSimbol.size(); i++)
		{
			switch (f_OutSimbol.at(i))
			{
				case 'h': 
					_hour = timeMaxControl(intPosition(timeIntOut, f_OutSimbol.at(i)), f_OutSimbol.at(i));
					break;
				case 'm': 
					_minute = timeMaxControl(intPosition(timeIntOut, f_OutSimbol.at(i)), f_OutSimbol.at(i));
					break;
				case 's':
					_second = timeMaxControl(intPosition(timeIntOut, f_OutSimbol.at(i)), f_OutSimbol.at(i));
					break;
				default: 
					break;
			}
		}
		if (_second == 0 && _minute == 0 && _hour == 0)
			return WorkString = toString(0);
			
		_second = cantMultZero(_second);
		_minute = cantMultZero(_minute);
		_hour = cantMultZero(_hour);

		if (_second > 49)
			_second = 1;
		else
			_second = 0;

		int temp_int_Time = (_minute * _hour) + _second;

		return WorkString = toString(temp_int_Time);
	}

	std::string TimeToSecond(std::string timeIn = "")
	{
		int timeIn_int;

		if (timeIn == "")
			timeIn = WorkString;

		if (needInterpre(timeIn) == true) timeIn_int = toInt(TimeInterpeInt(timeIn));
		else timeIn_int = toInt(timeIn);

		return WorkString = toString(timeIn_int);
	}


private:
	bool corEnter(char temp_string, int natureDate = 0)
	{
		std::string resolve_;
		if (natureDate == 0) resolve_ = "1234567890.-/:;";
		if (natureDate == 1) resolve_ = "1234567890";
		else resolve_ = ".-/:;";

		if (natureDate == 9) resolve_ = "hms.-/:;";

		bool mainSol = false;

		int t_i = 0;
		while (t_i < resolve_.length())
		{
			if (temp_string == resolve_[t_i])
			{
				mainSol = true;
				break;
			}
			else 
				if (mainSol != false)
					mainSol = false;
			t_i++;
			if (t_i == resolve_.length())
				return false;
		}
		return mainSol;
	}

	bool needInterpre(std::string source_)
	{
		for(int i = 0; i < source_.size(); i++)
			if (corEnter(source_.at(i)) == true)
				return true;
		return false;
	}
	
	int timeMaxControl(int sourceInt, char sourceChar)
	{
		switch (sourceChar)
		{
			case 'h':
				if (sourceInt > 23)
				{
					int divide_int = sourceInt % 24;
					sourceInt = divide_int;
				}
				break;
			case 'm':
				if (sourceInt > 59)
				{
					int divide_int = sourceInt % 60;
					sourceInt = divide_int;
				}
				break;
			case 's':
				if (sourceInt > 59)
				{
					int divide_int = sourceInt % 60;
					sourceInt = divide_int;
				}
				break;
			default:
				break;
		}
		return sourceInt;
	}

	int cantMultZero(int sourceInt)
	{
		if (sourceInt == 0)
			sourceInt++;
		return sourceInt;
	}
	
	int intPosition(std::string sourceString, char positionStr)
	{
		int positionInt = 0, timer_ = 0;
		int i = 0;
		std::string tempStr = "";

		for (i = 0; i < f_OutSimbol.size(); i++)
		{
			if (corEnter(sourceString.at(i), 2) == true)
				timer_ = i;
			if (f_OutSimbol.at(i) == positionStr)
			{
				if (i > 3) 
					timer_ = i+1;
				break;
			}
		}

		if (corEnter(sourceString.at(timer_), 2) == true)
			timer_ ++;

		for (int i = timer_; i < sourceString.size(); i++)
		{
			if (corEnter(sourceString.at(i), 1) == true)
				tempStr += sourceString.at(i);
			else 
				break;
		}

		positionInt = atoi(tempStr.c_str());
		return positionInt;
	}

	std::string preapairString(std::string sourceString)
	{

		return sourceString;
	}

	std::string outStream(std::string _hourStr = "0", std::string _minuteStr = "0", std::string _secondStr = "0")
	{
		WorkString = "";
		for (int i = 0; i < f_OutSimbol.size(); i++)
		{
			switch (f_OutSimbol.at(i))
			{
				case 'h': 
					WorkString += _hourStr;
					break;
				case 'm': 
					WorkString += _minuteStr;
					break;
				case 's':
					WorkString += _secondStr;
					break;
				default: 
					WorkString += f_OutSimbol.at(i);
					break;
			}
		}
		return WorkString;
	}
};

//Унарные операторы 
std::ostream& operator << (std::ostream& streamE, const TimeClass & f_inS)
{
	streamE << f_inS.WorkString;
	return streamE;
}

bool operator == (TimeClass const & a, TimeClass const & b)
{
	if (a.WorkString == b.WorkString)
		return true;
	else
		return false;
}

bool operator !=(TimeClass const & a, TimeClass const & b)
{
	if (a.WorkString == b.WorkString)
		return false;
	else
		return true;
}

bool operator <(TimeClass const & a, TimeClass const & b)
{
	if (a.WorkString < b.WorkString)
		return true;
	else
		return false;
}

bool operator >(TimeClass const & a, TimeClass const & b)
{
	if (a.WorkString > b.WorkString)
		return true;
	else
		return false;
}

bool operator <=(TimeClass const & a, TimeClass const & b)
{
	if (a.WorkString <= b.WorkString)
		return true;
	else
		return false;
}

bool operator >=(TimeClass const & a, TimeClass const & b)
{
	if (a.WorkString >= b.WorkString)
		return true;
	else
		return false;
}
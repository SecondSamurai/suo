#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Date {
public:
	Date();
	void setDate(int, int, int);
	int getDay();
	int getMonth();
	int getYear();
private:
	int EDay;
	int EMonth;
	int EYear;
	int enrDate;
	int yesDate;
	int checkEDay(int);
};

class Payment {
public:
	Payment();
	void newEmpl();
	void View();
	void experince();
	void charges();
	void retention();
	void clearPay();
private:
	string Name;
	string SecondName;
	string Patronymic;
	float Salary;
	Date enrDate;
	Date yesDate;
	float AcPercent;
	int Tax;
	int WorkDays;
	int SWorkDays;
	float Charg;
	float Ret;
	float SumClear;
};

bool ret = true, ret1 = true;
int p, o, dy, mn, yr, q, D, Dy, k, l, M, Y;

Payment::Payment() { Salary = AcPercent = Tax = WorkDays = SWorkDays = Charg = Ret = 0; }
Date::Date() { EDay = EMonth = EYear = 0; }

void Payment::newEmpl() {

	while (ret1 == true) {
		cout << "Вы в меню записи сотрудника, что вы хотите сделать : \n"
			<< "1 - Внести ФИО сотрудника. \t" << " 2 - Ввести оклад сотрудника. \n"
			<< "3 - Ввести дату. \t\t" << " 4 - Ввести надбавку. \n"
			<< "5 - Ввести колиество рабочих дней. " << " 6 - Ввести количество отработанных дней. \n"
			<< "7 - Завершить операцию. \n";
		cin >> q;
		switch (q) {
		case 1:
			cout << "Введите Фамилию сотрудника : ";
			cin.ignore(255, '\n');
			getline(cin, SecondName);

			cout << "Введите Имя сотрудника : ";
			cin.ignore(255, '\n');
			getline(cin, Name);

			cout << "Введите Отчество сотрудника : ";
			cin.ignore(255, '\n');
			getline(cin, Patronymic);
			break;
		case 2:
			cout << "Введите оклад сотрудника : ";
			cin >> Salary;
			break;
		case 3:
			cout << "Введите дату : " << endl;
			cout << "День : ";
			cin >> dy;
			cout << "Месяц : ";
			cin >> mn;
			cout << "Год : ";
			cin >> yr;
			cout << "Это \n"
				<< "1 - дата зачисления сотрудника в штат. \n"
				<< "2 - сегодняшняя дата. \n";
			cin >> p;
			switch (p) {
				case 1:
					cout << "Дата зачисления сотрудника в штат : ";
					enrDate.setDate(dy, mn, yr);
					cout << endl;
					continue;
				case 2:
					cout << "Сегодняшняя дата : ";
					yesDate.setDate(dy, mn, yr);
					cout << endl;
					continue;
			}
			break;
		case 4:
			cout << "Процент надбавки : ";
			cin >> AcPercent;
			break;
		case 5:
			cout << "Количество рабочих дней : ";
			cin >> WorkDays;
			break;
		case 6:
			cout << "Количество отработанных дней : ";
			cin >> SWorkDays;
			break;
		case 7:
			ret1 = false;
			break;
		}
	}

}

void Payment::View() {

	cout << Name << SecondName << Patronymic << endl;
	cout << Salary << endl;
	cout << enrDate.getDay() << "." << enrDate.getMonth() << "." << enrDate.getYear() << endl;
	cout << yesDate.getDay() << "." << yesDate.getMonth() << "." << yesDate.getYear() << endl;
	cout << AcPercent << endl;
	cout << WorkDays << endl;
	cout << SWorkDays << endl;

	system("pause");
}

void Payment::experince() {

	cout << "Вычисление стажа : " << endl;

	if (yesDate.getYear() > enrDate.getYear())
		Y = yesDate.getYear() - enrDate.getYear();

		M = yesDate.getMonth() - enrDate.getMonth();

		if (Y == 0 && M > 0 && yesDate.getDay() <= enrDate.getDay()) {
			D = yesDate.getDay() - enrDate.getDay();
			D = enrDate.getDay() + D;
			cout << "Стаж сотрудника : " << D << " дней.";
		}
		if (Y > 0 && yesDate.getDay() <= enrDate.getDay()) {
			D = yesDate.getDay() - enrDate.getDay();
			D = enrDate.getDay() + D;
			Dy = Y * 365;
			if (M >= 1 && D < 31) {
				M -= 1;
			}
			if (D > 30) {
				M += 1;
				D -= 30;
			}
			cout << "Стаж сотрудника : " << Dy << " дней. Или \n" << Y << " лет  " << M << " месяцев и " << D << " дней.";
		}
		else {
			D = yesDate.getDay() - enrDate.getDay();
			Dy = Y * 365;
			if (M = 1 && D < 31) 
				M -= 1;
			if (D > 30) {
				M += 1;
				D -= 30;
			}
			cout << "Стаж сотрудника : " << Dy << " дней. Или \n" << Y << " лет  " << M << " месяцев и " << D << " дней.";
		}
	system("pause");
}

void Payment::charges() {
	
	cout << "Вычисление начисленной суммы  " << endl;
	system("pause");

	Charg = Salary / WorkDays;
	Charg *= SWorkDays;
	l = (Charg / 100) * AcPercent;
	Charg += l;

	cout << "Начисленная сумма : " << Charg << endl;
	system("pause");
}

void Payment::retention() {

	cout << "Вычисление удержанной суммы  " << endl;
	system("pause");

	k = Charg / 100;
	Tax = Charg / 100 * 13;
	Ret = k + Tax;

	cout << "Удержанная сумма : " << Ret << endl;
	system("pause");
}

void Payment::clearPay() {
	cout << "Вычисление выручки " << endl;
	system("pause");

	SumClear = Charg - Ret;

	cout << "Выручка : " << SumClear << endl;
	system("pause");
}

void Date::setDate(int dy, int mn, int yr) {

	if (mn > 0 && mn <= 12) {
		EMonth = mn;
	}
	else {
		EMonth = 1;
		cout << "Значение месяца " << mn
			<< " неверно, установлено значение месяца - " << EMonth
			<< endl;
	}
	if (yr >= 1965) {
		EYear = yr;
	}
	else {
		EYear = 1965;
		cout << "Значение года " << yr
			<< " неверно, установлено значение года - " << EYear
			<< endl;
	}
	EDay = checkEDay(dy);

	cout << EDay << "." << EMonth << "." << EYear;

	cout << endl;
}

int Date::checkEDay(int dy) {

	static int daysPerMonth[13] =
	{ 0, 31, 28, 31, 30,
		31, 30, 31, 31,
		30, 31, 30 , 31 };

	if (dy > 0 && dy <= daysPerMonth[EMonth])
		return dy;

	if (EMonth == 2 && dy == 29
		&& (EYear % 400 == 0 || (EYear % 4 == 0 && EYear % 100 != 0)))
		return dy;

	cout << "Значение дня " << dy
		<< " неверно, установлено значение 1. " << endl;
	return 1;
}

int Date::getDay() {

	return EDay;
}

int Date::getMonth() {

	return EMonth;
}

int Date::getYear() {

	return EYear;
}

int main() {

	setlocale(0, " ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Payment t;

	cout << "Выполнил Мочалов Егор П-31" << endl;

	while (ret == true) {
		cout << "Что вы хотите сделать : \n"
			<< "1 - Зачислить сотрудника в штат. \t" << " 2 - Просмотр данных сотрудника. \n"
			<< "3 - Вычислить стаж. \t" << " 4 - Вычислить начисленную сумму. \n"
			<< "5 -  Вычислить удержанную сумму. " << " 6 - Вычислить сумму, выдаваемую на руки. \n"
			<< "7 - Завершить программу. \n";
		cin >> o;
		switch (o) {
		case 1:
 			t.newEmpl();
			break;
		case 2:
			t.View();
			break;
		case 3:
			t.experince();
			break;
		case 4:
			t.charges();
			break;
		case 5:
			t.retention();
			break;
		case 6:
			t.clearPay();
			break;
		case 7:
			ret = false;
			return 0;
			break;
		}
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include <Windows.h>
using namespace std;

class Account {
	public:
		Account();
		void InitAccount();
		void Change();
		void View();
		void Withdraw();
		void Put();
		void Percent();
		void ToDollars();
		void ToEuro();
		void SumCursive(float Summ);
		void Clean();
	private:
		string Name;
		int Number;
		float AcPercent;
		float Summ;
		char s[100] = "\0";
};

int p;
float q, o, pr, doll, eur, numb;
bool ret = true, ret1 = true;

Account::Account() { Number = AcPercent = Summ = 0; }


void Account::InitAccount() {

	cout << "Инициализация аккаунта. Введите данные : " << endl;
	while (ret1 == true) {

		cout << "Введите Фамилию : ";
		cin.ignore(255, '\n');
		getline(cin, Name);

		cout << "Введите номер счёта : ";
		cin >> Number;

		if (!cin.good()) {
			cout << "В номере счёта не может быть букв." << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
			continue;
		}
		else {
			ret1 = false;
		}
		cout << "Введите процент начисления : ";
		cin >> AcPercent;
		if (!cin.good()) {
			cout << "Процент начисления не может быть буквой." << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
			continue;
		}
		else {
			ret1 = false;
		}
		cout << "Сумма(в рублях) : ";
		cin >> Summ;
		if (!cin.good()) {
			cout << "В поле сумма не может быть букв." << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
			continue;
		}
		else {
			ret1 = false;
		}
		numb = Summ;
	}

	cout << "Инициализация завершена.";
}

void Account::Change() {

	cout << "Введите Фамилию нового владельца счёта : ";
	cin.ignore(255, '\n');
	getline(cin, Name);
}

void Account::View() {

	cout << "Ваш счёт : " << endl;

	cout << "Владелец : " << Name << endl;
	cout << "Номер счёта : " << Number << endl;
	cout << "Процент начисления : " << AcPercent << endl;
	cout << "Баланс : " << Summ << endl;

	system("pause");
}

void Account::Withdraw() {

	ret1 = true;

	while (ret1 == true) {

		cout << "Введите сумму, которую хотите снять : ";
		cin >> o;
		if (!cin.good()) {
			cout << "В поле сумма не может быть букв." << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
		}
		if (o > Summ) {
			cout << "Недостаточно средств для снятия! " << endl;
			ret1 = true;
		}
		else {
			ret1 = false;
		}
	}

		Summ -= o;

		cout << "Ваш баланс : " << Summ << endl;

		numb = Summ;

	system("pause");

}

void Account::Put() {

	ret1 = true;

	while (ret1 == true) {

		cout << "Введите сумму, которую хотите положить на счёт : ";
		cin >> q;
		if (!cin.good()) {
			cout << "В поле сумма не может быть букв." << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
		}
		else {
			ret1 = false;
		}
	}

	Summ += q;

	cout << "Ваш баланс : " << Summ << endl;

	numb = Summ;

	system("pause");
}

void Account::Percent() {

	pr = Summ / 100 * AcPercent;

	Summ += pr;

	cout << "Ваш баланс после начисления процентов : " << Summ;

	numb = Summ;

	system("pause");
}

void Account::ToDollars() {

	doll = Summ / 58, 18;

	cout << "Перевод в доллары выполнен. \n "
		<< "Ваш баланс в долларах : " << doll << endl;

	system("pause");
}

void Account::ToEuro() {

	eur = Summ / 55, 53;

	cout << "Перевод в евро выполнен. \n "
		<< "Ваш баланс в евро : " << eur << endl;

	system("pause");
}

void Account::SumCursive(float Summ) {

	int position = 0;
	int x[6];
	int div = 100000;
	float var = numb;
	int rest;
	for (int i = 0; i < 6; i++)
	{
		rest = var / div;
		x[i] = rest;
		var = var - rest * div;
		div = div / 10;
	}


	switch (x[0])
	{
		case 1: strcpy(s, "сто тысяч "); break;
		case 2: strcpy(s, "двести тысяч "); break;
		case 3: strcpy(s, "триста тысяч "); break;
		case 4: strcpy(s, "четыреста тысяч "); break;
		case 5: strcpy(s, "пятьсот тысяч "); break;
		case 6: strcpy(s, "шестьсот тысяч "); break;
		case 7: strcpy(s, "семьсот тысяч "); break;
		case 8: strcpy(s, "восемьсот тысяч "); break;
		case 9: strcpy(s, "девятьсот тысяч "); break;
		default: break;
	}
	position = strlen(s);

	switch (x[1])
	{
		case 1:
			switch (x[2])
			{
				case 0: strcpy(s + position, " десять тысяч "); break;
				case 1: strcpy(s + position, " одиннадцать тысяч "); break;
				case 2: strcpy(s + position, " двенадцать тысяч "); break;
				case 3: strcpy(s + position, " тринадцать тысяч "); break;
				case 4: strcpy(s + position, " четырнадцать тысяч"); break;
				case 5: strcpy(s + position, " пятнадцать тысяч "); break;
				case 6: strcpy(s + position, " шестнадцать тысяч"); break;
				case 7: strcpy(s + position, " семнадцать тысяч "); break;
				case 8: strcpy(s + position, " восемнадцать тысяч "); break;
				case 9: strcpy(s + position, " девятнадцать тысяч "); break;
			}
			x[2] = 0;
			position = strlen(s);
			break;
		case 2: strcpy(s + position, " двадцать тысяч "); break;
		case 3: strcpy(s + position, " тридцать тысяч "); break;
		case 4: strcpy(s + position, " сорок тысяч "); break;
		case 5: strcpy(s + position, " пятьдесят тысяч "); break;
		case 6: strcpy(s + position, " шестьдесят тысяч "); break;
		case 7: strcpy(s + position, " семьдесят тысяч "); break;
		case 8: strcpy(s + position, " восемьдесят тысяч "); break;
		case 9: strcpy(s + position, " девяносто тысяч "); break;
		default: break;
	}
	position = strlen(s);

	switch (x[2])
	{
		case 1: strcpy(s + position, " одна тысяча "); break;
		case 2: strcpy(s + position, " две тысячи "); break;
		case 3: strcpy(s + position, " три тысячи "); break;
		case 4: strcpy(s + position, " четыре тысячи "); break;
		case 5: strcpy(s + position, " пять тысяч "); break;
		case 6: strcpy(s + position, " шесть тысяч "); break;
		case 7: strcpy(s + position, " семь тысяч "); break;
		case 8: strcpy(s + position, " восемь тысяч "); break;
		case 9: strcpy(s + position, " девять тысяч "); break;
		default: break;
	}
	position = strlen(s);

	switch (x[3])
	{
		case 1: strcpy(s + position, " сто "); break;
		case 2: strcpy(s + position, " двести "); break;
		case 3: strcpy(s + position, " триста "); break;
		case 4: strcpy(s + position, " четыреста "); break;
		case 5: strcpy(s + position, " пятьсот "); break;
		case 6: strcpy(s + position, " шестьсот "); break;
		case 7: strcpy(s + position, " семьсот "); break;
		case 8: strcpy(s + position, " восемьсот "); break;
		case 9: strcpy(s + position, " девятьсот "); break;
		default: break;
	}
	position = strlen(s);

	switch (x[4])
	{
		case 1:
			switch (x[5])
			{
				case 0: strcpy(s + position, " десять "); break;
				case 1: strcpy(s + position, " одиннадцать "); break;
				case 2: strcpy(s + position, " двенадцать "); break;
				case 3: strcpy(s + position, " тринадцать "); break;
				case 4: strcpy(s + position, " четырнадцать "); break;
				case 5: strcpy(s + position, " пятнадцать "); break;
				case 6: strcpy(s + position, " шестнадцать "); break;
				case 7: strcpy(s + position, " семнадцать "); break;
				case 8: strcpy(s + position, " восемнадцать "); break;
				case 9: strcpy(s + position, " девятнадцать "); break;
			}
			x[5] = 0;
			position = strlen(s);
			break;
		case 2: strcpy(s + position, " двадцать "); break;
		case 3: strcpy(s + position, " тридцать "); break;
		case 4: strcpy(s + position, " сорок "); break;
		case 5: strcpy(s + position, " пятьдесят "); break;
		case 6: strcpy(s + position, " шестьдесят "); break;
		case 7: strcpy(s + position, " семьдесят "); break;
		case 8: strcpy(s + position, " восемьдесят "); break;
		case 9: strcpy(s + position, " девяносто "); break;
		default: break;
	}
	position = strlen(s);

	switch (x[5]) {
		case 1: strcpy(s + position, " один "); break;
		case 2: strcpy(s + position, " два "); break;
		case 3: strcpy(s + position, " три "); break;
		case 4: strcpy(s + position, " четыре "); break;
		case 5: strcpy(s + position, " пять "); break;
		case 6: strcpy(s + position, " шесть "); break;
		case 7: strcpy(s + position, " семь "); break;
		case 8: strcpy(s + position, " восемь "); break;
		case 9: strcpy(s + position, " девять "); break;
		default: break;
	}
	position = strlen(s);

	cout << Summ << " " << s << endl;

	cin.get();

	system("pause");
}

void Account::Clean() {

	for (int j = 0; j != 100; j++) {
		s[j] = '\0';
	}
}

int main() {
	setlocale(0, " ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Выполнил Мочалов Егор П-31" << endl;

	Account t;

	while (ret == true) {

		cout << "Что вы хотите сделать \n"
			<< "1 - Создать счет \n"
			<< "2 - Изменить владельца счёта \n"
			<< "3 - Вывести информаицию о счёте \n"
			<< "4 - Снять деньги \n"
			<< "5 - Положить деньги \n"
			<< "6 - Начислить проценты \n"
			<< "7 - Перевести в доллары \n"
			<< "8 - Перевести в евро \n"
			<< "9 - Вывести сумму прописью \n"
			<< "10 - Повторить программу \n"
			<< "11 - Завершить программу \n";
		cin >> p;
		switch (p)
		{
		case 1:
			t.InitAccount();
			break;
		case 2:
			t.Change();
			break;
		case 3:
			t.View();
			break;
		case 4:
			t.Withdraw();
			break;
		case 5:
			t.Put();
			break;
		case 6:
			t.Percent();
			break;
		case 7:
			t.ToDollars();
			break;
		case 8:
			t.ToEuro();
			break;
		case 9:
			t.SumCursive(numb);
			t.Clean();
			break;
		case 10:
			ret = true;
			cin.clear();
			break;
		case 11:
			ret = false;
			return 0;
			break;
		}
	}
}

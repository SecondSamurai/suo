#pragma once
#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

class Number {
protected:
	float numb;
	float numb1;
public:
	float sum();
	float division();
};

class Real : public Number {
public:
	Real() : Number() {};
	float exponentiation();
	float logariphm();
};

int p;
bool ret = true, ret1 = true;


float Number::sum()
{
	ret1 = true;
	while (ret1 == true) {
		cout << "Введите первое значение : ";
		cin >> numb;
		if (!cin.good()) {
			cout << "Только цифры!!!" << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
		}
		else {
			ret1 = false;
		}
	}
	ret1 = true;
	while (ret1 == true) {
		cout << "Введите второе значение : ";
		cin >> numb1;
		if (!cin.good()) {
			cout << "Только цифры!!!" << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
		}
		else {
			ret1 = false;
		}
	}

	numb += numb1;
	cout << numb << endl;
	system("pause");
	return 0;
}

float Number::division()
{
	ret1 = true;

	while (ret1 == true) {
		cout << "Введите первое значение : ";
		cin >> numb;
		if (!cin.good()) {
			cout << "Только цифры!!!" << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
		}
		else {
			ret1 = false;
		}
	}
	ret1 = true;

	while (ret1 == true) {
		cout << "Введите второе значение : ";
		cin >> numb1;
		if (!cin.good()) {
			cout << "Только цифры!!!" << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
		}
		else if (numb1 == 0) {
			cout << "На ноль делить нельзя!" << endl;
			ret1 = true;
		}
		else {
			ret1 = false;
		}
	}

	numb /= numb1;
	cout << numb << endl;
	system("pause");
	return 0;
}

float Real::exponentiation()
{
	ret1 = true;
	while (ret1 == true) {
		cout << "Введите первое значение : ";
		cin >> numb;
		if (!cin.good()) {
			cout << "Только цифры!!!" << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
		}
		else {
			ret1 = false;
		}
	}
	ret1 = true;
	while (ret1 == true) {
		cout << "Введите второе значение : ";
		cin >> numb1;
		if (!cin.good()) {
			cout << "Только цифры!!!" << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
		}
		else {
			ret1 = false;
		}
	}

	cout << pow(numb, numb1) << endl;
	system("pause");
	return 0;
}

float Real::logariphm()
{
	ret1 = true;

	while (ret1 == true) {
		cout << "Введите  значение : ";
		cin >> numb;
		if (!cin.good()) {
			cout << "Только цифры!!!" << endl;
			cin.clear();
			cin.ignore(255, '\n');
			ret1 = true;
		}
		else if (numb <= 0) {
			cout << "Такого логарифма не существует!" << endl;
			ret1 = true;
		}
		else {
			ret1 = false;
		}
	}

	cout << log(numb) << endl;
	system("pause");
	return 0;
}

int main() 
{
	setlocale(0, " ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Выполнил Мочалов Егор П-31." << endl;

	ret1 = true;

	Real t;
	while (ret == true)
	{
		ret1 = true;

		while (ret1 == true) {
			cout << "1 - Сложить \n"
				<< "2 - Разделить \n"
				<< "3 - Возвести в степень \n"
				<< "4 - Вычислить логарифм \n"
				<< "5 - Завершить программу \n";
			cin >> p;
			if (!cin.good()) {
				cout << "Только цифры!!!" << endl;
				cin.clear();
				cin.ignore(255, '\n');
				ret1 = true;
			}
			else if (p > 5) {
				ret1 = true;
			}
			else {
				ret1 = false;
			}
		}

		switch (p)
		{
		case 1:
			t.sum();
			break;
		case 2:
			t.division();
			break;
		case 3:
			t.exponentiation();
			break;
		case 4:
			t.logariphm();
			break;
		case 5:
			ret = false;
			return 0;
			break;
		}
	}
}


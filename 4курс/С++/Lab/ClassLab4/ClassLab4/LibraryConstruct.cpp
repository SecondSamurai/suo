#include "Header.h"
#include "Library.cpp"

Library::Library() { year = price = 0; }

void Library::newBook() 
{

	cout << "Введите фамилию автора книги : ";
	cin.ignore(255, '\n');
	getline(cin, Author);

	cout << "Введите название книги : ";
	cin.ignore(255, '\n');
	getline(cin, Title);

	cout << "Введите год издания книги : ";
	cin >> year;

	cout << "Введите название издательства : ";
	cin.ignore(255, '\n');
	getline(cin, publisher);

	cout << "Введите цену книги : ";
	cin >> price;

	system("pause");
}

void Library::getBook() 
{
	cout << "Автор : " << Author << endl;
	cout << "Книга : " << Title << endl;
	cout << "Год издания  : " << year << endl;
	cout << "Издательство : " << publisher << endl;
	cout << "Цена книги  : " << price << endl;

	system("pause");
}
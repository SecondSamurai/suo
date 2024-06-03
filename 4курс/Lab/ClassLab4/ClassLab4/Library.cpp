#include "Header.h"

class Library {
protected:
	string Author;
	string Title;
	int year;
	string publisher;
	float price;
public:
	Library();
	void newBook();
	void getBook();
};
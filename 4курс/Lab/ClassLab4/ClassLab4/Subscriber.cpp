#include "Header.h"
#include "Library.cpp"
#include "LibraryConstruct.cpp"

class Subscriber : public Library 
{
private:
	string secondName;
	int libNumber;

public:
	Subscriber() : Library () {}
	
};
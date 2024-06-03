#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

struct Stack
{
	string word;
	string numb;
	Stack* next;
} *t;

typedef Stack* pStack,*p;
pStack Head = NULL;
string words, numbs;


Stack* InStack(Stack * Head, string numbs, string words)
{


	Stack *t = new Stack;

	t->word = words;
	t->next = Head;
	t->numb = numbs;
	t->next = Head;
	system("pause");
	return t;
}

void View(Stack *Head)
{
	Stack *t = Head;
	while (t != NULL)
	{
		cout << " " << t->numb << endl;
		cout << " " << t->word << endl;
		t = t->next;
	}
	system("pause");
}

void Clear(Stack **Head)
{
	while (*Head != NULL)
	{
		t = *Head;
		*Head = (*Head)->next;
		delete t;
	}
}

void Import(Stack* Head)
{
	ofstream fout;
	fout.open("Wn.txt");
	Stack* t = Head;
	if (fout.is_open())
	{
		cout << "Файл открыт" << endl;
	}
	while (t != NULL)
	{
		fout << t->numb << endl;
		fout << t->word << endl;
		t = t->next;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	cout << "Выполнил Мочалов Егор П-31" << endl;

	ifstream in("words.txt");
	ifstream in1("numb.txt");

	if (in.is_open() && in1.is_open())
	{
		while (getline(in, words) && getline(in1, numbs))
		{
			cout << numbs << endl;
			cout << words << endl;
			Head = InStack(Head, numbs, words);
		}
	}

	in.close();
	in1.close();

	int kod;
	bool o = true;
	while (o == true)
	{
		cout << "\n\tВнести содержимое стека в файл - 1.\n\tПросмотр стека - 2.\n\tОчистка - 3.\n\tПовторить программу - 4.\n\tЗавершить работу - 0. : ";
		cin >> kod;
		switch (kod)
		{
		case 1:
			Import(Head);
			break;
		case 2:
			if (!Head)
			{
				cout << "Стек пуст!" << endl;
				break;
			}
			cout << "------Stack------" << endl;
			View(Head);
			break;
		case 3:
			Clear(&Head);
			cout << "Очистка выполнена" << endl;
			break;
		case 4:
			o = true;
			break;
		case 0:
			o = false;
			break;
		}
	}
	system("pause");
	return 0;
}
#include "ConcretePublisher.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include "ISubscriber.h"
#include "ConcreteSubscriber.h"
using namespace std;

ConcretePublisher::ConcretePublisher(char *a)
{
	count++;
	clc = 0;

	name = new char[25];
	article = new char[600];
	all_text_magazine = new char[5000];

	for (int i = 0; i < 25; i++)
	{
		this->name[i] = a[i];
	}
	path = new char[25];
	toTXT(name, path);

	ifstream fin;
	try
	{
		fin.open(path);
		if (!fin.is_open())
			throw 1;
	}
	catch (int i)
	{
		cout << "Отсутствует входной файл с ифнормацией о журнале " << name << endl;
		exit(1);
	}
	int i = 0;
	do
	{
		fin.get(all_text_magazine[i]);
		i++;
	} while (!fin.eof());
	all_text_magazine[i - 1] = '\0';
	fin.close();
}

void ConcretePublisher::get_latest_info()
{
	int i = 0;
	do
	{
		article[i] = all_text_magazine[clc];
		i++;	clc++;
	} while (all_text_magazine[clc] != '#');
	clc++;
	article[i] = '\0';
}

void ConcretePublisher::subscribe(ISubscriber &subscriber)
{
	this->address.Push_Back(&subscriber);
}

void ConcretePublisher::unsubscribe(ISubscriber &subscriber)
{
	this->address.Remove(&subscriber);
}

void ConcretePublisher::notify()
{
	for (int i=0; i<address.ret_size(); i++)
	{
		address[i]->update(name, article);
	}
}

bool ConcretePublisher::plus_or_minus(ISubscriber &subscriber)
{
	return address.is_there(&subscriber);
}

void ConcretePublisher::some_logic(ConcretePublisher *a)
{
	const int kol_vo_statei = 10;
	while (cntr_for_artcl<kol_vo_statei && !_kbhit())
	{
		for (int i = 0; i < count; i++)
		{
			a[i].get_latest_info();
			a[i].notify();
		}
		Sleep(5000);
		cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
		cntr_for_artcl++;
	}
}

int ConcretePublisher::count = 0;			// начальная инициализация статической переменной
int ConcretePublisher::cntr_for_artcl = 0;

ConcretePublisher::~ConcretePublisher()
{
	delete[] name;
	delete[] article;
	delete[] all_text_magazine;
}

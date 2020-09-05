#include "ConcreteSubscriber.h"
#include <windows.h>
#include <iostream>
#include <fstream>

HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
ConcreteSubscriber::ConcreteSubscriber(char *a)
{
	counter++;
	name = new char[25];
	for (int i = 0; i < 25; i++)
	{
		this->name[i] = a[i];
	}
	path = new char[25];
	toTXT(name, path);
}
char* ConcreteSubscriber::ret_name()
{
	return name;
}
void ConcreteSubscriber::update(char *name, char *article)
{
	SetConsoleTextAttribute(hConsoleHandle, 13);
	cout << "Свежий выпуск журнала " << name << " для " << this->name << endl;
	SetConsoleTextAttribute(hConsoleHandle, 15);
	cout << article << endl;
	ofstream fout; 
	fout.open(this->path, ios::app);
	fout << name;
	fout << article << endl;
	fout.close();
}
void ConcreteSubscriber::clear_file()
{
	ofstream clear; clear.open(path);	clear.close();	//онли для того, чтобы отчистить выходной файл, после предыдущего запуска
}
ConcreteSubscriber::~ConcreteSubscriber()
{
	delete[] name;
	delete[] path;
}
int ConcreteSubscriber::counter = 0;

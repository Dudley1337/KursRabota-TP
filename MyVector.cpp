#include <iostream>
#include "MyVector.h"
using namespace std;

template <class T>
MyVector<T>::MyVector()
{
	mas = new T[0];
	Size = 0;
}
template <class T>
void MyVector<T>::Push_Back(const T &val)
{
	T *buf = new T[Size + 1];
	for (int i = 0; i<Size; i++)
	{
		*(buf + i) = *(mas + i);
	}
	*(buf + Size) = val;
	Size++;
	delete[] mas;
	mas = buf;
}
template <class T>
void MyVector<T>::Remove(const T &val)
{
	T *buf = new T[Size + 1];
	int Position;
	bool was_found = false;
	for (int i = 0; i<Size; i++)
	{
		if (*(mas + i) == val)
		{
			Position = i;
			was_found = true;
		}
	}
	if (was_found)
	{
		for (int i = 0; i<Position; i++)
		{
			*(buf + i) = *(mas + i);
		}
		for (int i = Position + 1; i<Size; i++)
		{
			*(buf + i - 1) = *(mas + i);
		}
		Size--;
		delete[] mas;
		mas = buf;
	}
}
template <class T>
int MyVector<T>::ret_size()
{
	return Size;
}
template <class T>
void MyVector<T>::show()
{
	for (int i = 0; i<Size; i++)
	{
		cout << *(mas + i) << endl;
	}
}
template<class T>
bool MyVector<T>::is_there(const T &arg)
{
	for (int i = 0; i<Size; i++)
	{
		if (*(mas + i) == arg)
			return true;
	}
	return false;
}
template <class T>
T& MyVector<T>::operator[](int n)
{
	if (n<0 || n >= Size)
	{
		cout << "\nВыход за пределы массива!"; exit(1);
	}
	return mas[n];
}
template <class T>
MyVector<T>::~MyVector()
{
	delete[] mas;
}

#pragma once
#include "MyVector.cpp"
template <class T>
class MyVector
{
private:
	int Size;
	T *mas;
public:
	MyVector();
	void Push_Back(const T&);
	void Remove(const T&);
	int ret_size();
	void show();
	bool is_there(const T&);
	T& operator[](int);
	~MyVector();
};
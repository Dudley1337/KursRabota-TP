#pragma once
class ConcretePublisher : public IPublisher
{
private:
	char *name;
	char *all_text_magazine;
	char *article;
	int clc;					//счётчик для файла
	char *path;					//путь для файла
	MyVector<class ISubscriber *> address;
	static int count;			// для подсчёта количества созданных объектов класса 
	static int cntr_for_artcl;	// для цикла, где уведомления подписчикам 
public:
	ConcretePublisher(char *);
	void get_latest_info();
	void subscribe(ISubscriber &) override;
	void unsubscribe(ISubscriber &) override;
	void notify() override;
	bool plus_or_minus(ISubscriber &);
	static void some_logic(ConcretePublisher *);
	~ConcretePublisher();
};
#include "ConcretePublisher.cpp"

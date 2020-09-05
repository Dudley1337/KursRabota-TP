#pragma once
class ConcreteSubscriber : public ISubscriber
{
private:
	char *name;
	char *path;
public:
	ConcreteSubscriber(char *);
	char* ret_name();
	static int counter;
	void update(char *name, char *article) override;
	void clear_file();
	~ConcreteSubscriber();
};
#include "ConcreteSubscriber.cpp"

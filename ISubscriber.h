#pragma once
#include "ConcreteSubscriber.h"
class ISubscriber
{
public:
	void virtual update(char *, char *) = 0;
};
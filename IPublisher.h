#pragma once
#include "ConcretePublisher.h"
class IPublisher
{
public:
	void virtual subscribe(ISubscriber &) = 0;
	void virtual unsubscribe() = 0;
	void virtual notify() = 0;
};
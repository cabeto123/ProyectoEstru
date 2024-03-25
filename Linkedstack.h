#pragma once
#include "TDAPila.h"
class Linkedstack :public TDAPila
{
public:
	Linkedstack();
	Node* tope;
	virtual void push(Object*) override;
	virtual Object* pop() override;
	virtual Object* top() override;
	virtual bool isEmpty() override;
	virtual void clear() override;
	virtual void print()  override;

};


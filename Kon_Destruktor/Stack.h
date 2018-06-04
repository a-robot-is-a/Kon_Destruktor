#pragma once

#include <iostream>
using namespace std;
#include <string>

namespace mySpace{

class Stack {

private:

	int top;
	int cap;
	string *stack;

public:

	Stack(int cap);
	~Stack();

	void push(string x);	

	int size();
	
	string topElement();

	void pull();	
};
}

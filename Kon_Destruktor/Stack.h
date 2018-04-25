#pragma once

#include <iostream>
using namespace std;
#include <string>

class Stack {

private:

	int top;
	int cap;
	string *stack;

public:

	Stack(int cap);

	void push(string x);	

	int size();
	
	string topElement();

	void pull();	
};
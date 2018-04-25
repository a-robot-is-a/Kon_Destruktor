#pragma once

#include <iostream>
using namespace std;
#include <string>

class Queues {

private:
	int arraySize;
	string element;
	string *queue;

	int rear;
	int front;

public:

	Queues(int aS);

	void add(string e);	

	void print();	

	void remove();	

	string firstOne();
	
};

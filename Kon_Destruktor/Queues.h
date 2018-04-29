#pragma once

#include <iostream>
using namespace std;
#include <string>

namespace mySpace{

class Queues {

private:

	int arraySize;
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
}

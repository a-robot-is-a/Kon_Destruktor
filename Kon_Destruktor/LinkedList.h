#pragma once

#include <iostream>
using namespace std;
#include <string>

namespace mySpace{

class LinkedList {

private:

	struct node
	{
		int index;
		string data;
		node *next;
	};

	node *root;
	node *neuesElement;
	node *ptr;

public:

	LinkedList(int index, string s);

	void newElement(int index, string s);
	void loeschen(int in);
	void ausgabe();

};
}

#pragma once

#include <iostream>
using namespace std;
#include <string>

class LinkedList {

private:

	struct nod
	{
		int index;
		string data;
		nod *next;
	};

	nod *root;
	nod *neuesElement;
	nod *ptr;

	int ind;
	string dat;

public:

	LinkedList();

	void newElement(int index, string s);
	void loeschen(int in);
	void ausgabe();

};
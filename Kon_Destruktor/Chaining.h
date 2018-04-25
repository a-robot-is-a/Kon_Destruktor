#pragma once

#include <iostream>
using namespace std;
#include <string>

#include <map>
#include <numeric>	// fuer accumulate in hashFunc()
#include <sstream>

class Chaining {

private:

	struct node
	{
		string data;
		node *next;
	};

	node *root;
	node *neuesElement;
	node *ptr;

	pair<int, node*> x;
	map<int, node*> m;

	string colorIndex, obj;
	int index;

public:

	Chaining();

	int hashFunc();
	int hashTable(string color, string objekt);
	void getHashTable();
	void getList(int in);
	string getTableIndexesAndListDataToStore();
};
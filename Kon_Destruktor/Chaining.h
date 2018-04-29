#pragma once

#include <iostream>
using namespace std;
#include <string>

#include <map>
#include <numeric>	// fuer accumulate in hashFunc()
#include <sstream>

namespace Space{

class Chaining {

private:

	struct no
	{
		string data;
		no *next;
	};

	no *ro;
	no *nEle;
	no *pt;

	pair<int, no*> x;
	map<int, no*> m;

	string colorIndex, obj;
	int index;

public:

	Chaining(string color, string object);

	int hashFunc();
	int nextElement(string color, string object);
	void getHashTable();
	void getList(int in);
	string getTableIndexesAndListDataToStore();
};
}

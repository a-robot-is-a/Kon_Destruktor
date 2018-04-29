#pragma once

#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>

namespace mySpace{

class FileOperation 
{

private:


	fstream stream;
	vector<string> myVec;

public:

	void schreiben(string str);

	void lesen();

	void ausgabe();	
};
}

#pragma once

#include <fstream>	// read and write
#include <vector>

class FileOperation {


public:

	void schreiben(string str)
	{	
		ofstream write;
		write.open("Daten.txt");
		write << str;
		write.close();
	}

	void lesen()
	{
		{
			cout << "\nReading from file...\n" << endl;

			ifstream fileSt;
			string rdStr;

			vector<string> myVec;

			fileSt.open("Daten.txt");

			while (true)
			{
				getline(fileSt, rdStr, ' ');

				myVec.push_back(rdStr);

				if (fileSt.eof())
				{
					break;
				}
			}

			fileSt.close();

			// Verarbeiten
			int i = 0;

			for (i; i < myVec.size(); i++)
			{
				cout << myVec[i];

				i++;

				for (i; i< myVec.size(); i++)
				{
					cout << " " << "Listenelement " << myVec[i];
				}
			}
		}
	}
};
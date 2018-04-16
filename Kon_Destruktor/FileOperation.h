#pragma once

#include <fstream>	// read and write
#include <vector>

class FileOperation {

private:

	fstream stream;

public:

	void schreiben(string str)
	{
		cout << "\nWriting to file...\n" << endl;

		stream.open("Daten.txt", ios::out);
		stream << str;
		stream.close();
	}

	void lesen()
	{
		{
			cout << "\nReading from file...\n" << endl;

			string rdStr;

			vector<string> myVec;

			stream.open("Daten.txt", ios::in);

			while (true)
			{
				getline(stream, rdStr, ' ');

				myVec.push_back(rdStr);

				if (stream.eof())
				{
					break;
				}
			}

			stream.close();

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
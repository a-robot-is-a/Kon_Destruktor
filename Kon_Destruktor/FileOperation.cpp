#include "FileOperation.h"

	void FileOperation::schreiben(string str)
	{
		cout << "\n Writing Index and list elements to file ...\n" << endl;

		stream.open("Daten.txt", ios::out);
		stream << str;
		stream.close();
	}

	void FileOperation::lesen()
	{
		{
			cout << "\n Reading from file...\n" << endl;

			string rdStr;

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
		}
		ausgabe();
	}
			
	void FileOperation::ausgabe()
	{
		int i = 0;

		for (i; i < myVec.size(); i++)
		{
			cout << myVec[i];

			i++;

			for (i; i < myVec.size(); i++)
			{
				cout << " " << "Listenelement " << myVec[i];
			}
		}
	}


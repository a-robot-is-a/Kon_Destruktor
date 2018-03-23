#pragma once

/*
gefunden auf: https://www.hackerearth.com/practice/data-structures
*/

class HashTable {

public:
	/*
	// O (26 * N), wobei N die Größe der Zeichenkette ist und 26 mögliche Zeichen
	void countFre(string S)
	{
		for (char c = 'a'; c <= 'z'; ++c)
		{
			int frequency = 0;
			for (unsigned int i = 0; i < S.length(); ++i)
			{
				if (S[i] == c)
				{
					frequency++;
				}
			}

			if (frequency > 0)
			{
				cout << "\n\t" << c << " x "<< frequency << endl;
			}
		}
	}
	*/

	// The complexity of this approach is O(N) where N is the size of the string.

	int Frequency[26];

	int hashFunc(char c)
	{
		return (c - 'a');
	}

	void countFre(string S)
	{
		for (int i = 0; i < 26; i++)
		{
			Frequency[i] = 0;
		}
		for (unsigned int i = 0; i < S.length(); ++i)
		{
			int index = hashFunc(S[i]);	// 0 1 0 1 2 3
			Frequency[index]++;	// 1 2 3 4 5 6	:)
		}
		for (int i = 0; i < 26; ++i)
		{
			if (Frequency[i] > 0)
			{
				cout << "\n\t" << (char)(i + 'a') << " x " << Frequency[i] << endl;
			}
		}
	}
};

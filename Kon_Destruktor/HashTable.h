#pragma once

/*
gefunden auf: https://www.hackerearth.com/practice/data-structures
*/

class HashTable {

private:
	int *Frequency = nullptr;

public:
	// O (26 * N), wobei N die Größe der Zeichenkette ist und 26 mögliche Zeichen
	void countFre(string S)
	{
		for (char c = 'a'; c <= 'z'; ++c)
		{
			int frequency = 0;
			for (unsigned int i = 0; i < S.length(); ++i)
				if (S[i] == c)
					frequency++;
			cout << c << ' ' << frequency << endl;
		}
	}


/*
	HashTable()
	{
		Frequency = new int[26];
	}

	int hashFunc(char c)
	{
		return (c - 'a');
	}

	void countFre(string S)
	{
		for (int i = 0; i < S.length(); ++i)
		{
			int index = hashFunc(S[i]);
			Frequency[index]++;
		}
		for (int i = 0; i < 26; ++i)
			cout << (char)(i + ’a’) << ‘ ‘ << Frequency[i] << endl;
	}
*/
};

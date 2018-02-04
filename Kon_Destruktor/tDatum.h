#pragma once

class tDatum {

public:
	int Tag;
	int Monat;
	int Jahr;

	tDatum();

	tDatum(int Tag, int Monat, int Jahr)
	{
		this->Tag = Tag;
		this->Monat = Monat;
		this-> Jahr = Jahr;
	}	

	~tDatum();

	int Ausgabe() {
		cout << Tag, Monat, Jahr;
		return 0;
	}
};

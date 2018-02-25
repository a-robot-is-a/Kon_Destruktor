#pragma once

/*
	gefunden auf: https://www.hackerearth.com/practice/data-structures
*/

class Stack {

private:
	int top = 0;
	int cap;
	string *stack = nullptr;	// Einen Zeiger fuer das Array definieren

public:

	Stack(int cap)
	{
		this->cap = cap;
		stack = new string[cap];	// Ein Datenobjekt auf dem Heap anlegen
		stack[top] = {};	// Initialisierung um Nebeneffekte zu vermeiden
	}

	void push(string x)
	{
		if (top == cap)     //If the top position is the last of position of the stack, this means that the stack is full.
		{
			cerr << "\n Stack is full. Overflow condition!" << endl;
		}
		else
		{
			top = top + 1;        //Incrementing the top position 
			stack[top] = x;       //Inserting an element on incremented position  
		}
	}

	int size()
	{
		return top;
	}

	string topElement()
	{
		return stack[top];
	}

	// Pruefen, ob ein Stack leer ist

	bool isEmpty()
	{
		if (top == 0)  //Stack is empty
			return true;
		else
			return false;
	}

	// Das oberste Element vom Stack nehmen

	void pull()
	{
		if (isEmpty())
		{
			cerr << "\n Stack is empty. Underflow condition!" << endl;
		}
		else
		{
			stack[top] = "";
			top = top - 1;
		}
	}
};

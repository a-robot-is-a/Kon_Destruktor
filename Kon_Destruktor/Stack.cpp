/*
	gefunden auf: https://www.hackerearth.com/practice/data-structures
*/

#include "Stack.h"
using namespace mySpace;


	int cap;
	int top;
	string *stack = nullptr;	// Einen Zeiger fuer das Array definieren

	Stack::Stack(int ca):cap(ca)
	{
		top = 0;
		stack = new string[cap];	// Ein Datenobjekt auf dem Heap anlegen
		stack[top] = {};	// Initialisierung um Nebeneffekte zu vermeiden
	}

	void Stack::push(string x)
	{
		if (top == cap)     //If the top position is the last of position of the stack, this means that the stack is full.
		{
			cerr << "\n Stack is full. Overflow condition!" << endl;
		}
		else
                {
                        stack[top] = x;       //Inserting an element on incremented position  
                        top = top + 1;        //Incrementing the top position 
                }
	}

	int Stack::size()
	{
		return top;
	}

	string Stack::topElement()
	{
		string out = stack[top];
		return out;
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

	void Stack::pull()
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

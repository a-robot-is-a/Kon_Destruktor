#pragma once

/*
	gefunden auf: https://www.hackerearth.com/practice/data-structures
	/stacks/basics-of-stacks/tutorial/
*/

class Stack {

protected:
	int top = -1;
	int cap;
	int *stack = nullptr;	// Einen Zeiger fuer das Array definieren

public:

	Stack(int cap)
	{
		this->cap = cap;
		this->stack = new int[cap];	// Ein Datenobjekt auf dem Heap anlegen
	}

	void push(int x)
	{
		if (top == cap - 1)     //If the top position is the last of position of the stack, this means that the stack is full.
		{
			cout << "\n Stack is full. Overflow condition!" << endl;
		}
		else
		{
			top = top + 1;        //Incrementing the top position 
			stack[top] = x;       //Inserting an element on incremented position  
		}
	}

	int size()
	{
		return top + 1;
	}

	int topElement()
	{
		return stack[top];
	}
};

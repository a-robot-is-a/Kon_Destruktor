#pragma once

/*
	gefunden auf: https://www.hackerearth.com/practice/data-structures
	/stacks/basics-of-stacks/tutorial/
*/

class Stack {

protected:
	int top = -1;

public:
	void push(int stack[], int x, int n)
	{
		if (top == n - 1)       //If the top position is the last of position of the stack, this means that the stack is full.
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

	int topElement(int stack[])
	{
		return stack[top];
	}
};

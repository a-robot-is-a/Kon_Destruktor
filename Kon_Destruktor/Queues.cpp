/*
	gefunden auf: https://www.hackerearth.com/practice/data-structures
*/

#include "Queues.h"
using namespace mySpace;

	int arraySize;
	//string element;
	string *queue = nullptr;

	int rear;
	int front;

	
	Queues::Queues(int aS):arraySize(aS),front(0),rear(0)
	{
		queue = new string[arraySize];
		for (int i = 0; i < arraySize; i++)
		{
			queue[i] = "NULL";
		}
	}

	void Queues::add(string e)
	{
		if (front == arraySize)	// if queue is full
		{
			cerr << "\n\tNo more space in the hallway :)" << endl;
		}
		else    // add the element on the first position
		{			
			queue[front] = e;
			front++;
		}
	}

	void Queues::print()
	{
		for (int i = 0; i < arraySize; i++)
		{
			cout << "\n\t" << queue[i] << endl;
		}
	}

	void Queues::remove()
	{
		if (queue[rear] == "nobody")
		{
			cerr << "\n\tNobody in the hallway :)" << endl; // Underflow-exception
		}
		else
		{
			// remove the first element and move up
			
			for (int i = 1; i < arraySize; i++)
			{
				queue[i - 1] = queue[i];
			}
			front--;
			queue[front] = "nobody";
		}
	}

	string Queues::firstOne()
	{
		return queue[0];
	}


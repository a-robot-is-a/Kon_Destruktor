/*
	gefunden auf: https://www.hackerearth.com/practice/data-structures
*/

#include "Queues.h"

	int arraySize;
	string element;
	string *queue = nullptr;

	int rear = 0;
	int front = 0;
	
	Queues::Queues(int aS):arraySize(aS)
	{
		queue = new string[arraySize];
		for (int i = 0; i < arraySize; i++)
		{
			queue[i] = "NULL";
		}
	}

	void Queues::add(string e)
	{
		if (arraySize == rear)	// if queue is full
		{
			cerr << "\n\tNo more space in the hallway :)" << endl;
		}
		else    // add the element on the last position
		{
			element = e;
			queue[rear] = element;
			rear++;
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
		if (queue[front] == "unbekannt")
		{
			cerr << "\n\tNobody in the hallway :)" << endl; // Underflow-exception
		}
		else
		{
			queue[front] = "unbekannt";	// remove the first element
										
			if (queue[front] == "unbekannt")	// and move up
			{
				for (int i = 1; i < arraySize; i++)
				{
					queue[i - 1] = queue[i];
					rear = i - 2;
					queue[i] = "unbekannt";	// reset the place to "0"
				}
			}
		}
	}

	string Queues::firstOne()
	{
		return queue[front];
	}


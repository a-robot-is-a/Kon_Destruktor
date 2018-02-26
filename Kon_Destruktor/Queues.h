#pragma once

/*
	gefunden auf: https://www.hackerearth.com/practice/data-structures
*/


class Queues {

private:
	int arraySize;
	string element;
	string *queue = nullptr;

	int rear = 0;
	int front = 0;

public:
	
	Queues(int aS)
	{
		arraySize = aS;
		queue = new string[arraySize];
		for (int i = 0; i < arraySize; i++)
		{
			queue[i] = "NULL";
		}
	}

	void add(string e)
	{
		if (arraySize + 1 == rear)	// if queue is full
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

	void print()
	{
		for (int i = 0; i < arraySize; i++)
		{
			cout << "\n\t" << queue[i] << endl;
		}
	}

	void remove()
	{
		queue[front] = "unbekannt";	// remove the first element

		// move up
		if (queue[front] == "unbekannt")
		{
			for (int i = 1; i < arraySize; i++)
			{
				queue[i - 1] = queue[i];
			}
		}		
	}


	string firstOne() {
		return queue[front];
	}


	// this function adds an element to the back of the queue

	void enqueue() {
		if (rear == arraySize)            // Queue is full
			cout << ("OverFlow\n");
		else {
			queue[rear] = element;    // Add the element to the back
			rear++;
		}
	}

	// this function removes the element from the front of the queue

	void dequeue(int queue[], int& front, int rear) {
		if (front == rear)            // Queue is empty
			cout << ("UnderFlow\n");
		else {
			queue[front] = 0;        // Delete the front element
			front++;
		}
	}

	// This function returns the front element of the queue.

	int Front(int queue[], int front) {
		return queue[front];
	}

	// This function returns the size of a queue or the number of elements in a queue.

	int size(int front, int rear) {
		return (rear - front);
	}

	// If a queue is empty, this function returns 'true', else it returns 'false'.

	bool isEmpty(int front, int rear) {
		return (front == rear);
	}

};
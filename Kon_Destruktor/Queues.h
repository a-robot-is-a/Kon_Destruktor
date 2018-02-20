#pragma once

/*
	gefunden auf: https://www.hackerearth.com/practice/data-structures
*/


class Queues {

public:

	// this function adds an element to the back of the queue

	void enqueue(int queue[], int element, int& rear, int arraySize) {
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
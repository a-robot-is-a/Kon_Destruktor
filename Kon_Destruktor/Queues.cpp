#include "Queues.h"

Queues::Queues()
{}

void Queues::init()
{
	root = new node();
	root->data = "root";
	root->next = NULL;

	ptr = root;
	cout << "\n\t\tNew Queue: " << root << endl;
}

void Queues::enter(string s)
{
	neuesElement = new node();
	neuesElement->data = s;
	neuesElement->next = NULL;

	ptr->next = neuesElement;	
	ptr = neuesElement;
	cout << "\n\t\tNew Link: " << ptr->data << endl;
}

bool Queues::isempty()
{
	if (root->next == nullptr)
	{
		cout << "\n\t\tQueue is empty" << endl;
		empty = true;
	}
	else 
	{ 
		cout << "\n\t\tQueue is not empty" << endl;
		empty = false;
	}
	return empty;
}

string Queues::front()
{
	if (root->next != NULL)
	{
		return root->next->data;
	}
}

void Queues::remove()
{
	cout << "\n\t\tRemoving the first one..." << endl;

	if (root->next != NULL)
	{
		node *tmp = root->next->next;
		//delete root->next;
		root->next = tmp;
	}

	if (isempty() == true) // check if last node deleted
	{
		ptr = root;
	}
}

void Queues::ausgabe()
{
	cout << "\n\t\tIn der Schlange sind: " << endl;

	/*
	for (; ptr != NULL; ptr = ptr->next)
	{
		cout << "\n\t\t" << ptr << " " << ptr->data
			<< " => " << ptr->next << endl;
	}
	*/

	if (root->next == NULL)
	{
		cout << "\n\t\tKeine Daten" << endl;
	}
	else
	{
		while (root != NULL)
		{
			cout << "\n\t\t" << root << " " << root->data
				<< " => " << root->next << endl;

			root = root->next;
		}
	}
}


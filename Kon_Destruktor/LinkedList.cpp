#include "LinkedList.h"
using namespace mySpace;


	LinkedList::LinkedList(int index, string s)
	{
		neuesElement = new node();
                neuesElement->index = index;
                neuesElement->data = s;
                neuesElement->next = NULL;

                ptr = root = neuesElement;
	}

	void LinkedList::newElement(int index, string s)
	{
		neuesElement = new node();
		neuesElement->index = index;
		neuesElement->data = s;
		neuesElement->next = NULL;

		ptr->next = neuesElement;	// das letzte Element zeigt auf das neue Element
		ptr = neuesElement;			// das neue Element wird zum Letzten
	}


	void LinkedList::loeschen(int in)
	{
		node *zeiger = root;

		if (zeiger->next != NULL)
		{
			while (zeiger->next != NULL)
			{
				if (zeiger->next->index == in && zeiger->next->next != NULL)
				{
					zeiger->next = zeiger->next->next;
					break;
				}
				else
				{
					if (zeiger->next->index == in && zeiger->next->next == NULL) // delete tail
					{
						ptr = zeiger;
						delete (zeiger->next->next); // help the garbage collection :)
						zeiger->next = NULL;
						break;
					}
					else
					{
						if (zeiger->index == in)
						{
							zeiger = root->next;
							delete root;
							root = zeiger;
							break;
						}
					}
				}
				zeiger = zeiger->next;
			}
		}
		else
		{
			if (zeiger->next == nullptr)
			{
				ptr = nullptr;
				root = nullptr;

				cout << "\n\t\tListe komplett geloescht." << endl;
			}
		}
	}

	void LinkedList::ausgabe()
	{
		if (root == NULL)
		{
			cout << "\n\t\tKeine Daten" << endl;
		}
		else
		{
			while (root != NULL)
			{
				cout << "\n\t\t" << root << " " << root->index << " "
					<< root->data << " => " << root->next << endl;

				root = root->next;
			}
		}
	}


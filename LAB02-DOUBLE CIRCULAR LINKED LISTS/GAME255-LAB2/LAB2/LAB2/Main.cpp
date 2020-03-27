#include "CDList.h"

#include <iostream>
#include <string>

using namespace std;

template <typename T>
void CDList<T>::getJosephusPosition(int m)
{
	//Declare two pointers to two nodes and set them equal to head
	Node *ptr1 = head;
	Node *ptr2 = head;

	//Loop until there is only one node
	while (size() != 1) {

		//Declare a counter and set equal to 1
		int counter = 1;

		//Loop until counter equals m
		while (counter != m) {

			//Set second pointer equal to first pointer and first pointer to the next node 
			ptr2 = ptr1;
			ptr1 = ptr1->next;
			counter++;
		}
			//Declare a temp node pointer and set equal to first pointer
			Node *temp_ptr = ptr1;

			//Print value of node to be deleted
			cout << ptr1->value << " was killed." << endl;

			//Relink nodes and erase temp node
			ptr2->next = ptr1->next;
			ptr1 = ptr1->next;
			ptr1->prev = ptr2;
			erase(temp_ptr);
		}

	//Print value of last node
	cout << "Last person left standing is " << ptr2->value << endl;
}

int main()
{
	CDList<string> sentence;
	CDList<string>::Iterator word = sentence.begin();

	for (int i = 0; i < 8; i++)
	{
		sentence.push_back("Person " + to_string(i + 1));
	}

	sentence.getJosephusPosition(2);

	system("pause");
}

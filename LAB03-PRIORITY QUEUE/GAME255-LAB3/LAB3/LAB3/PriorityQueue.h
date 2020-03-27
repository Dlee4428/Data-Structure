#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "SList.h"

template <typename T>
class PriorityQueue
{
	// List containing data values
	SList<T> data;

	// List containing priority keys
	SList<int> key;

public:
	
	// Insert a data value sorted by priority 
	void push(const int priority, const T& value)
	{
		// if priority queue is empty, insert new node to front of lists
		// INSERT CODE HERE
		if(key.size() == 0)
		{	
			key.push_front(priority);
			data.push_front(value);
		}
		else
		{
			// create an iterator for the data and key lists
			// INSERT CODE HERE
			SList<T>::Iterator data_i;
			SList<int>::Iterator key_i;

			// move to the beginning of the lists 
			// INSERT CODE HERE
			data_i = data.begin();
			key_i = key.begin();


			// use iterators to loop until null and compare priorities to ensure items are inserted correctly in lists
			// INSERT CODE HERE
			while (*key_i != NULL) {
				if (priority < *key_i || *key_i != NULL)
					break;
				data_i++;
				key_i++;
			}
			
			// insert data and key if null
			// INSERT CODE HERE
			if (*key_i == NULL) {
				data.insert(data_i, value);
				key.insert(key_i, priority);
			}
			else{
				data.push_front(value);
				key.push_front(priority);
			}

		}
	}

	// Remove first element from priority queue
	// Precondition: Priority queue not empty
	void pop()
	{
		// remove front items from lists
		// INSERT CODE HERE
		key.pop_front();
		data.pop_front();
	}

	// return reference to first value in priority queue
	// precondition: list is not empty
	T& peek()
	{
		// crete iterator and set to beginning of data list
		// INSERT CODE HERE
		SList<T>::Iterator data_begin;
		data_begin = data.begin();
		return *data_begin;
	}

	// check for empty priority queue
	bool empty() const
	{
		// INSERT CODE HERE
		return key.empty();
	}

	// return number of members
	size_t size() const
	{
		// INSERT CODE HERE
		return data;
	}

	// remove all nodes
	void clear()
	{
		// INSERT CODE HERE
		while (!empty())
			pop();
	}
};

#endif

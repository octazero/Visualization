#ifndef List_h
#define List_h

#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

class LinkedList
{
public:
	struct Point
	{
		int x;
		int y;
	};
	class Node {
	public:

		int data;
		Node *  next;
		Point nodePosition;
		Node()
		{
			next = NULL;
		}

		Node(int dataValue)
		{
			data = dataValue;
			next = NULL;
		}
	};
	typedef Node * NodePointer;

public:
	LinkedList()
	{
		first = NULL, mySize = 0;
	}
	bool empty()
	{
		return mySize == 0;
	}
	void insert(int dataVal, int index)
	{
		if (index < 0 || index > mySize)
		{
			cerr << "Illegal location to insert -- " << index << endl;
			return;
		}
		mySize++;
		LinkedList::NodePointer newPtr = new Node(dataVal),
		predPtr = first;
		if (index == 0)
		{
			newPtr->next = first;
			first = newPtr;
		}
		else 
		{
			for (int i = 1; i < index; i++)
				predPtr = predPtr->next;
			newPtr->next = predPtr->next;
			predPtr->next = newPtr;
		}
	}
	void erase(int index)
	{
		if (index < 0 || index >= mySize)
		{
			cerr << "Illegal location to delete -- " << index << endl;
			return;
		}
		mySize--;
		LinkedList::NodePointer ptr,
		predPtr = first;
		if (index == 0)
		{
			ptr = first;
			first = ptr->next;
			delete ptr;
		}
		else 
		{
			for (int i = 1; i < index; i++)
				predPtr = predPtr->next;
			ptr = predPtr->next;
			predPtr->next = ptr->next;
			delete ptr;
		}
	}
	int search(int dataVal)
	{
		int loc;
		LinkedList::NodePointer tempP = first;
		for (loc = 0; loc < mySize; loc++)
		if (tempP->data == dataVal)
			return loc;
		else
			tempP = tempP->next;
		return -1;
	}
	Node* getn(int index)
	{
		LinkedList::NodePointer ptr = first;
		for (int i = 0; i < index; i++)
		{
			ptr = ptr->next;
		}
		return ptr;
	}
	int get(int index)
	{
		LinkedList::NodePointer ptr = first;
		for (int i = 0; i < index; i++)
		{
			ptr = ptr->next;
		}
		return ptr->data;
	}
	void set(int index,int value)
	{
		LinkedList::NodePointer ptr = first;
		for (int i = 0; i < index; i++)
		{
			ptr = ptr->next;
		}
		ptr->data=value;

	}
	void mergesort(int *ar, int l, int h)
	{
		int mid;
		if (l < h)
		{
			mid = (l + h) / 2;
			mergesort(ar, l, mid);
			mergesort(ar, mid + 1, h);
			Merge(ar, l, h, mid);
		}
	}
	void Merge(int *a, int low, int mid, int high)
	{
		int i = low, k = low, j = mid + 1, c[100];

		while (i <= mid && j <= high)
		{
			if (a[i] < a[j])
			{
				c[k] = a[i];
				j++;
				k++;
			}
			if (a[j] <= a[i])
			{
				c[k] = a[j];
				i++;
				k++;
			}
		}
		while (j <= high)
		{
			c[k] = a[j];
			j++;
			k++;
		}
		while (i <= mid)
		{
			c[k] = a[i];
			i++;
			k++;
		}
		for (int i = low; i < k; i++)
		{
			a[i] = c[i];
		}
	}
	void Quicksort(int high, int low)
	{
		if (low > high)
			return;
		else
		{
			int p=low;
			int i = low; int j = high;
			while (i < j)
			{

				if (get(j) <= get(p) && get(i) > get(p))
				{
					int temp = get(j);
					set(j, get(i));
					set(i, temp);
				}
				if (get(i) <= get(p))
					i++;
				if (get(j) > get(p))
					j--;
			}
			int temp = get(p);
			set(p, get(j));
			set(j, temp);
			Quicksort(j - 1, low);
			Quicksort(high, j + 1);
		}
	}
public:
	NodePointer first;
	int mySize;
};


#endif
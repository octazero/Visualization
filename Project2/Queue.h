#include <iostream>
using namespace std;
class myQueue
{
public:
	class Node
	{
	public:

		Node * next;
		Node(int Data)
		{
			this->Data = Data;
			next = NULL;
		}
		int getData()
		{
			return Data;
		}

		int Data;
	};
	myQueue()
	{
		myBack = myFront = NULL;
		size = 0;
	}
	myQueue(const myQueue & Other)
	{
		myFront = new Node(Other.myFront->Data);
	}
	bool empty()
	{
		return (myFront == NULL);
	}
	void Enqueque(int Data)
	{
		if (empty())
		{
			myFront = new Node(Data);
			myBack = myFront;
		}
		else if (myBack == myFront)
		{
			myBack = new Node(Data);
			myFront->next = myBack;
		}
		else
		{
			ptr = new Node(Data);
			myBack->next = ptr;
			myBack = ptr; 
		}
		size++;
	}
	bool Dequeue()
	{
		if (empty())
		{
			return false;
		}
		else if (myBack == myFront)
		{
			myBack = myFront = NULL;
		}
		else
		{

			ptr = myFront;
			myFront = myFront->next;
			
			delete ptr;
		}
		size--;
		return true;
	}
	int operator[](int x)
	{
		if (x < 0)
			return -99999;
		ptr = myFront;

		for (int i = 0; i < x; i++)
		{
			ptr = ptr->next;
		}
		return ptr->getData();
	}
public:
	Node *myFront, *myBack, *ptr;
	int size;
};
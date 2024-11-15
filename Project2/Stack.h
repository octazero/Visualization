#include <iostream>
using namespace std;
class myStack
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
	myStack()
	{
		myFront = NULL;
		size = 0;
	}
	myStack(const myStack & Other)
	{
		myFront = new Node(Other.myFront->Data);
	}
	bool empty()
	{
		return (myFront == NULL);
	}
	void Push(int Data)
	{
		if (empty())
		{
			myFront = new Node(Data);
		}
		else
		{
			ptr = new Node(Data);
			ptr->next = myFront;
			myFront = ptr;
		}
		size++;
	}
	bool Pop()
	{
		if (empty())
		{
			return false;
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

		for (int i = x-1; i>=0; i--)
		{
			ptr = ptr->next;
		}
		return ptr->getData();
	}
public:
	Node *myFront, *ptr;
	int size;
};